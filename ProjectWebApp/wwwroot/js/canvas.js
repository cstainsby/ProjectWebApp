// url to the tutorial I used -> https://developer.mozilla.org/en-US/docs/Web/API/WebGL_API/Tutorial
// and helpful youtube video -> https://www.youtube.com/watch?v=kB0ZVUrI4Aw

// vertex shader string 
const vsSource = `
    attribute vec4 aVertexPosition;

    uniform mat4 uModelViewMatrix;
    uniform mat4 uProjectionMatrix;

    void SetupCanvas() {
      gl_Position = uProjectionMatrix * uModelViewMatrix * aVertexPosition;
    }
  `;

// fragmentation shader string
const fsSource = `
    void SetupCanvas() {
      gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    }
  `;


function SetupCanvas() {
    var canvas = document.getElementById("#glCanvas");
    // get webgl
    var gl = canvas.getContext("webgl"); 

    // webgl is incompadible with some browsers, alert user if gl didnt load properly
    if (!gl) {
        alert("Browser likley doesnt support webgl");
        return;
    }

    gl.clearColor(0.0, 0.0, 0.0, 1);
    gl.clear(gl.COLOR_BUFFER_BIT);

    // create shaders
    var vertexShader = gl.createShader(gl.VERTEX_SHADER);
    var fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);

    gl.shaderSource(vertexShader, vsSource);
    gl.shaderSource(fragmentShader, fsSource);

    // compile shaders 
    gl.compileShader(vertexShader);
    if (!gl.getShaderParameter(vertexShader, gl.COMPILE_STATUS)) {
        alert("error compiling vertex shader");
        return;
    }

    gl.compileShader(fragmentShader);
    if (!gl.getShaderParameter(fragmentShader, gl.COMPILE_STATUS)) {
        alert("error compiling fragmentation shader");
        return;
    }

    var program = gl.createProgram();
    gl.attachShader(program, vertexShader);
    gl.attachShader(program, fragmentShader);
    gl.linkProgram(program);

    if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
        alert("error linking program");
        return;
    }



    // Create buffer 
    var triangleVerts =
        [// X, Y
            0.0, 0.5,
            -0.5, -0.5,
            0.5, -0.5
        ];

    var triangleVertexBufferObject = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, triangleVertexBufferObject);
    gl.bufferData(
        gl.ARRAY_BUFFER,
        new Float32Array(triangleVertices),
        gl.STATIC_DRAW
    );

    var positionAttribLocation = g1.getAttribLocation(program, 'vertPostion');
    gl.vertesAttribPointer(
        positionAttribLocation // attribute location
        2, // number of elements
        gl.FLOAT, // type of element
        gl.FALSE,
        2 * Float32Array.BYTES_PER_ELEMENT, // size of induvidual vertex
        0 // how many bytes inside the buffer to start from
    );

    gl.enableVertexAttribArray(positionAttribLocation);

    // Main Render Loop
    gl.useProgram(program);
    gl.drawArrays(
        gl.TRIANGLES,
        0, // skip none of the points
        3 // three points
    );
};

// when loaded use Setup Canvas as a constructor for the canvas 
window.onload = SetupCanvas;