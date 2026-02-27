# View Mode Page Access Control

This module extends the `view_mode_page` module to add permission-based access control to view mode pages.

## How it works

The module implements a custom access checker that restricts access to view_mode_page routes to users with the **"access review pages"** permission.

## Implementation Details

### Files Added:
- `src/Access/ViewModePageAccessChecker.php` - Custom access checker service
- `src/Routing/RouteSubscriber.php` - Route subscriber to modify view_mode_page routes
- `session_enhancements.services.yml` - Service definitions
- `session_enhancements.permissions.yml` - Permission definitions

### What happens:
1. The RouteSubscriber modifies the `view_mode_page.display_entity` route
2. It removes the default `_permission: 'access content'` requirement
3. It adds a custom `_view_mode_page_access: 'TRUE'` requirement
4. The ViewModePageAccessChecker service handles this custom requirement
5. Only users with the 'access review pages' permission are granted access

## Usage

After enabling this functionality:
- Users with the 'access review pages' permission can access view_mode_page URLs
- All other users will receive an "Access denied" message
- The access control is cached properly using Drupal's cache contexts
- Permissions can be managed through the standard Drupal permissions UI at `/admin/people/permissions`

## Activation

To activate this access control:
1. Clear the cache: `drush cr`
2. The access restrictions will be automatically applied to all view_mode_page routes

## Deactivation

To remove the access restrictions, simply disable the session_enhancements module or remove the RouteSubscriber and AccessChecker classes.
