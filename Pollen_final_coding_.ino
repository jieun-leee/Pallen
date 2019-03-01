
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
unsigned long timepoint;

int redPin = 13;
int greenPin = 15;
int bluePin = 0;
int buttonPin = 12;
const int hallPin = 2; // the number of the hall effect sensor pin
int hallState = 0; // variable for reading the hall sensor status

bool pillDespensed = 0; // rather the pill has been dispensed



void setup()
{
  myservo.attach(14);  // attaches the servo on GIO2 to the servo object
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(hallPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin); //read the button to see if it is pressed

  if (buttonState == LOW) { //LOW BUTTON STATE STANDS IN FOR POLLEN HIGH
    setColor(255, 051, 153);  // set the LED Color to Pink
    myservo.write(50); //move to max position
      delay(2000);          //wait a bit for the servo to do its thing

    pillDespensed = 1; // tells that there is a pill waiting
    while (digitalRead(hallPin) == LOW) {// as long as lid is closed, nothing happens/ code waits here
      int i;
      i++;
    }


  }


  if (pillDespensed == 1) {
    hallState = digitalRead(hallPin);
    if (hallState == LOW) {
      setColor(0, 0, 0);  // set the LED Color to Pink
      myservo.write(0); //move servo back to start
      delay(1500);          //give the servo a moment to move
      pillDespensed = 0;

    }

  }

}



void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

