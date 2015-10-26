function fretboard() {
  

  fill(168, 150, 70);
  rect(0, 0, 200, 650);

  // white thing
  strokeWeight(15);
  stroke(255);
  // line(5, 0, 195, 0);
  rect(8, 0, 184, 1);

  // frets
  stroke(90);
  for (var fret = 0; fret < 6; fret++) {
    // line(5, 90 + 100 * fret, 195, 90 + 100 * fret);
    rect(8, 90 + 100 * fret, 184, 1);
  }

  // strings
  strokeWeight(7);
  stroke(205);
  for (var string = 0; string < 6; string++) {
    line(18 + 33 * string, 0, 18 + 33 * string, 650);
  }
}