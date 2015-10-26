function setup() {
  var serial = new p5.SerialPort();
  var output = 'h';

  function setup() {
    createCanvas(400, 300);
    serial.on('data', serialEvent);
    serial.on('error', serialError);

    serial.open('/dev/cu.usbmodem1421');
  }

  function mousePressed() {
    // send a message to control the LED
    serial.write(output);
    if (output == 'h') {
      output = 'l';
    } else {
      output = 'h';
    }
  }

  function serialEvent() {
    var input = serial.readLine();
    if (input.length > 0) {
      // println(input);
      if (input !== "Hello?") {
        var numbers = split(input, ",");
        println(numbers);
      }
      serial.write('f'); // random byte to add something to ino buffer to start loop
      // serial.write(key);
    }
  }

  function serialError(err) {
    println(err);
  }

  function draw() {
    if (mouseIsPressed) {
      var lightBright = int(map(mouseY, 0, height, 0, 255));
      serial.write(lightBright);
    }
  }
}

function draw() {

}