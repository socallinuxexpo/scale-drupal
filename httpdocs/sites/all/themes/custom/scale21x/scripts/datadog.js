  (function(h,o,u,n,d) {
    h=h[d]=h[d]||{q:[],onReady:function(c){h.q.push(c)}}
    d=o.createElement(u);d.async=1;d.src=n
    n=o.getElementsByTagName(u)[0];n.parentNode.insertBefore(d,n)
  })(window,document,'script','https://www.datadoghq-browser-agent.com/us1/v4/datadog-rum.js','DD_RUM')
  window.DD_RUM.onReady(function() {
    window.DD_RUM.init({
      clientToken: 'pub084ef041bce8b024db51baa75cbc31f8',
      applicationId: '59b6a081-926d-46c7-812e-895157ce2678',
      site: 'datadoghq.com',
      service: 'scale-website',
      env: 'prod',
      // Specify a version number to identify the deployed version of your application in Datadog 
      // version: '1.0.0', 
      sessionSampleRate: 100,
      sessionReplaySampleRate: 0,
      trackUserInteractions: true,
      trackResources: true,
      trackLongTasks: true,
      defaultPrivacyLevel: 'mask-user-input',
    });

    window.DD_RUM.startSessionReplayRecording();
  })
