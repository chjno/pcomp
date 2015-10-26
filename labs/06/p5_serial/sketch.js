// copies serial library from p5 IDE into var serial
var serial = new p5.SerialPort();
var portName = '/dev/cu.usbmodem1411';

function setup() {
  createCanvas(400,300);
  
  serial.on('data', serialEvent);
  serial.on('open', portOpen);
  
  // call open function from serial library
  serial.open(portName);
}

function draw() {
  
}

function portOpen() {
  println('Yes, the port is open');
}

function serialEvent() {
  var input = serial.readLine();
  println(input);
}