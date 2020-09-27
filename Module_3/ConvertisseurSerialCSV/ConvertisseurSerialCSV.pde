//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;

void setup() {
  udSerial = new Serial(this, Serial.list()[0], 9600);
  output = createWriter("Battements.csv");
}

void draw() {
    if (udSerial.available() > 0) {
      String SenVal = udSerial.readStringUntil(',');
      if (SenVal != null) {
        output.print(SenVal);
        output.print(" ");
        output.println(day() +" "+ month() +" en "+ year() +" a "+ hour() +" : "+ minute() +" : "+ second());
      }      
    }
  }
  
void keyPressed(){
    output.flush();
      output.close();
      exit(); 
}
