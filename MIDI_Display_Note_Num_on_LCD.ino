#include <MIDI.h>                      //Initializes MIDI library   
#include <LiquidCrystal.h>             //Initializes LCD library 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Sets LCD pins

int delayTime = 400;                   //Global variable for delay time

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);       //Sets MIDI baud rate and tells serial port to look for MIDI messages on all channels
  lcd.begin(2,16);                     //Sets the size of the LCD screen (2 rows of 16 characters each)
}

void loop() {
  int type, channel, number;
  if (MIDI.read()) {                   //Looks for incoming MIDI messages
    byte type = MIDI.getType();        //Establishes variable for Swith/Case argument
    switch (type) {                    //Sets up Switch/Case argumnet
      case NoteOn:                     //Establishes MIDI command type to look for
        channel = MIDI.getChannel();
        number = MIDI.getData1();
        lcd.setCursor(0,0);
        lcd.print(String("Note On") + (",Note#") + number);
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;
/*      case NoteOff:
        channel = MIDI.getChannel();
        lcd.setCursor(0,0);
        lcd.print("Note Off");
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;*/
     case AfterTouchPoly:
        channel = MIDI.getChannel();
        lcd.setCursor(0,0);
        lcd.print("After Touch Poly:");
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;
      case ControlChange:
        channel = MIDI.getChannel();
        number = MIDI.getData1();
        lcd.setCursor(0,0);
        lcd.print(String("Ctl.Ch") + (", CC#") + number);
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;
      case ProgramChange:
        channel = MIDI.getChannel();
        number = MIDI.getData1();
        lcd.setCursor(0,0);
        lcd.print(String("Prog.Ch") + (",Pgrm#") + number);
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;
      case AfterTouchChannel:
        channel = MIDI.getChannel();
        lcd.setCursor(0,0);
        lcd.print("After Touch Channel");
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;
      case PitchBend:
        channel = MIDI.getChannel();
        lcd.setCursor(0,0);
        lcd.print("Pitch Bend");
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;
      case SystemExclusive:
        channel = MIDI.getChannel();
        lcd.setCursor(0,0);
        lcd.print("Sysex");
        lcd.setCursor(0,1);
        lcd.print(String("Chan ") + channel + (",Value ") + MIDI.getData2());
        delay(delayTime);
        lcd.clear();
        break;
    }
  }
}
