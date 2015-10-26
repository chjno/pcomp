var serial = new p5.SerialPort();
var canvas;
var dotDiam = 20;
var presses = [0, 0, 0, 0, 0, 0];
var chordToPlay;
var sounds = [];
var rand;
var compArray = 0;
var alfaPresses = 255;
var count = 0;
var chordCol = [255, 255, 255, 255];
var alfa = 255;
var toggle = false;
var chordName;
var audioA;
var audioAm;
var audioE;
var audioEm;
var audioD;
var audioDm;
var audioG;
var audioF;
var audioC;
var harder = false;
var diffAlfa = 255;

var yFret1 = 40;
var yFret2 = 140;
var yFret3 = 240;
var xString1 = 18;
var xString2 = 51;
var xString3 = 84;
var xString4 = 117;
var xString5 = 150;
var xString6 = 184;

var chordA = [0, 0, 2, 2, 2, 0];
var chordAm = [0, 0, 2, 2, 1, 0];
var chordE = [0, 2, 2, 1, 0, 0];
var chordEm = [0, 2, 2, 0, 0, 0];
var chordD = [0, 0, 0, 2, 3, 2];
var chordDm = [0, 0, 0, 2, 3, 1];
var chordG = [3, 2, 0, 0, 0, 3];
var chordF = [0, 0, 3, 2, 1, 1];
var chordC = [0, 3, 2, 0, 1, 0];

var xVals = [xString1, xString2, xString3, xString4, xString5, xString6];
var yVals = [yFret1, yFret2, yFret3];
var chords = [chordA, chordAm, chordE, chordEm, chordD, chordDm, chordG, chordF, chordC];
var chordNames = ['A', 'Am', 'E', 'Em', 'D', 'Dm', 'G', 'F', 'C'];

function preload() {
  audioA = loadSound("sounds/A.m4a");
  audioAm = loadSound("sounds/Am.m4a");
  audioE = loadSound("sounds/E.m4a");
  audioEm = loadSound("sounds/Em.m4a");
  audioD = loadSound("sounds/D.m4a");
  audioDm = loadSound("sounds/Dm.m4a");
  audioG = loadSound("sounds/G.m4a");
  audioF = loadSound("sounds/F.m4a");
  audioC = loadSound("sounds/C.m4a");
}

function setup() {
  createCanvas(500, 650);
  serial.on('data', serialEvent);
  serial.open('/dev/cu.usbmodem1421');

  sounds.push(new Audio(audioA));
  sounds.push(new Audio(audioAm));
  sounds.push(new Audio(audioE));
  sounds.push(new Audio(audioEm));
  sounds.push(new Audio(audioD));
  sounds.push(new Audio(audioDm));
  sounds.push(new Audio(audioG));
  sounds.push(new Audio(audioF));
  sounds.push(new Audio(audioC));

  difficulty = createButton('Harder!');
  difficulty.mousePressed(changeButton);
  difficulty.position(95, 400);

  setChord();
}

function serialEvent() {
  var input = serial.readLine();
  if (input.length > 0) {
    presses = split(input, '');
    for (var i = 0; i < presses.length; i++) {
      presses[i] = int(presses[i]);
    }
    // print(input);
    // print(presses);

  }
}

function Audio(input) {
  this.sound = input;
  this.play = function() {
    this.sound.play();
  };
}

function setChord() {
  rand = floor(random() * (chords.length - 0.5));
  while (chords[rand] == chordToPlay) {
    rand = floor(random() * (chords.length - 0.5));
    // print('next');
  }
  chordToPlay = chords[rand];
}

function changeButton() {
  if (harder) {
    difficulty.html('Harder!');
  } else {
    difficulty.html('Easier!');
  }
  harder = !harder;
}

function mousePressed() {
  toggle = true;
}

function draw() {
  background(150);
  chordName = chordNames[rand];
  fill(0);
  textSize(48);
  text(chordName, 110, 200);

  translate(250, 0);
  fretboard();
  noStroke();

  for (var i = 0; i < 6; i++) {
    fill(chordCol[0], chordCol[1], chordCol[2], chordCol[3]);
    if (chordToPlay[i] !== 0) {
      ellipse(xVals[i], yVals[chordToPlay[i] - 1], dotDiam, dotDiam);
    }
    if (presses[i] == chordToPlay[i]) {
      compArray += 1;
    }
    if (presses[i] !== 0 && presses[i] == chordToPlay[i]) {
      fill(0, 255, 0, alfaPresses);
      ellipse(xVals[i], yVals[presses[i] - 1], dotDiam, dotDiam);
    } else if (presses[i] !== 0 && presses[i] !== chordToPlay[i]) {
      fill(255, 0, 0, alfaPresses);
      ellipse(xVals[i], yVals[presses[i] - 1], dotDiam, dotDiam);
    }
  }
  if (compArray == 6) {
    // if (toggle) {
    if (count === 0) {
      sounds[rand].play();
    }
    count++;
    alfaPresses = 0;
    chordCol = [0, 255, 0, 255];

  }
  if (harder) {
    chordCol[3] = 0;
  } else {
    chordCol[3] = 255;
  }
  if (count > 0) {
    count++;

    if (count > 15 && count < 29) {
      chordCol[3] = 0;
    }
    if (count > 30 && count < 69) {
      chordCol[3] = 255;
    }

    if (count > 70) {
      setChord();
      chordCol = [255, 255, 255, diffAlfa];
      compArray = 0;
      toggle = false;
      alfaPresses = 255;
      count = 0;
    }

    // print(count);
  }
  compArray = 0;
}