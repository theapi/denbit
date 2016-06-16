
const char index_html[] PROGMEM = R"=====(

<html>
<head>

<style> 

 
body {
  padding:0;
  margin:0;
    background-color: #32c9d6;
}
 
#ball
{
  -webkit-transition: all;
  transition: all;
  position:absolute;
  width:100px;
  height:100px;
  border-radius: 50%;
  background: white;
}
 
    </style> 
    
<script>

var connection = new WebSocket('ws://' + location.hostname + ':81/', ['arduino']);
connection.onopen = function () {
    connection.send('Connect ' + new Date());
};
connection.onerror = function (error) {
    console.log('WebSocket Error ', error);
};
connection.onmessage = function (e) {
    console.log('Server: ', e.data);
};
function sendRGB() {
    var r = parseInt(document.getElementById('r').value).toString(16);
    var g = parseInt(document.getElementById('g').value).toString(16);
    var b = parseInt(document.getElementById('b').value).toString(16);
    if (r.length < 2) {
        r = '0' + r;
    }
    if (g.length < 2) {
        g = '0' + g;
    }
    if (b.length < 2) {
        b = '0' + b;
    }
    var rgb = '#' + r + g + b;
    console.log('RGB: ' + rgb);
    connection.send(rgb);
}


if ( !window.requestAnimationFrame ) {
 
    window.requestAnimationFrame = ( function() {
 
        return window.webkitRequestAnimationFrame ||
        window.mozRequestAnimationFrame ||
        window.oRequestAnimationFrame ||
        window.msRequestAnimationFrame ||
        function( /* function FrameRequestCallback */ callback, /* DOMElement Element */ element ) {
 
            window.setTimeout( callback, 1000 / 60 );
 
        };
 
    } )();
 
}
 
 
 
var ball;
var w;
var h;
var alpha;
 
function init()
{
    ball = document.getElementById("ball");
   w = window.innerWidth;
     h = window.innerHeight;
  
  ball.style.left = (w/2)-50+"px";
  ball.style.top = (h/2)-50+"px";
  ball.velocity = {x:0,y:0}
  ball.position = {x:0,y:0}
    
    if (window.DeviceOrientationEvent) {
      window.addEventListener("deviceorientation", function(event) {
        // beta is the front-to-back tilt in degrees, where front is positive
        ball.velocity.y = Math.round(event.beta);
        // gamma is the left-to-right tilt in degrees, where right is positive
        ball.velocity.x = Math.round(event.gamma);
        // alpha is the compass direction the device is facing in degrees
        alpha = Math.round(event.alpha);
  
        connection.send("#" + ball.velocity.x + "," + ball.velocity.y + "," + alpha);
      })
    };
    
    update();
}
 
function update()
{
        ball.position.x += ball.velocity.x;
        ball.position.y += ball.velocity.y;
        
        if(ball.position.x > (w-100) && ball.velocity.x > 0)
      {
         ball.position.x = w-100;
      }
      
      if(ball.position.x < 0 && ball.velocity.x < 0)
      {
        ball.position.x = 0;
      }
      
      if(ball.position.y > (h-100) && ball.velocity.y > 0)
      {
         ball.position.y = h-100;
      }
      
      if(ball.position.y < 0 && ball.velocity.y < 0)
      {
         ball.position.y = 0;
      }
    
    ball.style.top = ball.position.y + "px"
        ball.style.left = ball.position.x + "px"

 
    
    requestAnimationFrame( update );//KEEP ANIMATING
}


</script>
</head>
<body onload="init()">
    <div id="ball"></div>
   
</body>




</body>
</html>

)=====";
