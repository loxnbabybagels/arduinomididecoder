#include <MIDI.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char* midiMessage[] = {
  "Chan 1 Note Off", "Chan 1 Note On"
};

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  lcd.begin(2,16);
}

void loop() { 
  int message;
  MIDI.read(); 
  message = MIDI.getType();  
  if (message == NoteOff)
  {
    lcd.print(midiMessage[0]);
    delay(500);
    lcd.clear();
    }
    else if (message == NoteOn)
    {
    lcd.print(midiMessage[1]);
    delay(500);
    lcd.clear();
    }  
}
