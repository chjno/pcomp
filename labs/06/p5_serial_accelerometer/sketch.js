var serial = new p5.SerialPort();
var hPos = 0
var vPos = 0;
var ballColor;
var portName;

function setup() {
  createCanvas(640, 480);
  serial.on('data', serialEvent);
  serial.open('/dev/cu.usbmodem1411');
}

function draw() {
  backgroud(0, 255, 0);
  fill(ballColor);
  ellipse(hPos, vPos, 50, 50);
}

function serialEvent() {
  var input = serial.readStringUntil('\r\n');
  if (input.length > 0) {
    // println(input);
    var sensors = split(input, ',');
    // println(sensors);
    if (sensors.length > 2) {
      hPos = sensors[0];
      vPos = sensors[1];
      ballColor = int(sensors[2]) * 255;
    }
  }
}