# Session Enhancements Module

This module enhances the session time slot field (`field_time_slot`) on the 'session' content type by constraining date options to match the referenced event's date range.

## Features

### 1. Event-Based Date Constraints
- When an event is selected, the date picker options are limited to the event's date range
- Start and end date fields will only allow dates within the event's duration
- Uses HTML5 `min` and `max` attributes for native browser date validation
- Updates dynamically via AJAX when the event selection changes

### 2. Remove Seconds from Time Fields
- Time inputs are limited to hour and minute precision (HH:MM format)
- Seconds field is hidden and step is set to 60 seconds (1 minute)
- Scheduling to the minute is sufficient for most use cases

## Technical Implementation

### PHP Components
- **hook_form_alter()**: Modifies session node forms to add date constraints
- **AJAX callback**: Updates date constraints when event selection changes
- **Helper functions**: Handle date constraint setting and seconds removal

### JavaScript Components
- **Time format enforcement**: Ensures time inputs don't include seconds
- **Step attribute management**: Sets time inputs to minute-level precision

## Usage

1. Enable the module: `drush en session_enhancements -y`
2. Create or edit a session node
3. Select an event - date picker will be constrained to the event's date range
4. Time fields will only accept minute-level precision

## Files Structure

```
session_enhancements/
├── session_enhancements.info.yml     # Module definition
├── session_enhancements.module       # PHP hooks and functions
├── session_enhancements.libraries.yml # JavaScript library definition
├── js/
│   └── session_enhancements.js       # Client-side enhancements
└── README.md                         # This documentation
```

## Dependencies

- Drupal Core 10+
- Node module
- Datetime Range module

## Configuration

No additional configuration is required. The module works automatically on session content type forms.
