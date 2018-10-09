
#include <Wire.h>

const float resolution = 5.0 / 1023.0;

const int address[] = {3, 4, 5, 6};
const int enable = 2;
const int led = 13;
const int adc = A0;
void set_channel(const int);
float convert(const int);

float buf[17];
/*
class SC_STACK {
  private:
    unsigned byte *_buf;
  public:
    SC_STACK(const unsigned int buf_size_bytes) {
      _buf = (byte*) calloc (buf_size_bytes, sizeof(byte));
    }
};
*/
void setup() {
  // put your setup code here, to run once:
  for (int i = 0 ; i < sizeof(address) ; i++) {
    pinMode(address[i], OUTPUT);
  }
  pinMode(enable, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  Serial.println("\n\nHello World!\n\n");
  Wire.begin();
  Wire.setClock(100000);
}

void loop() {

  static const int pause = 500; // ms

  while (Wire.available()) Wire.read();  // Clear buffer

  Wire.beginTransmission(0x69);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.requestFrom(0x69, 16 * 2);

  byte counter = 0;

  Wire.read();

  while (Wire.available()) { // slave may send less than requested
    unsigned int value   = ((unsigned int)(Wire.read() << 8 ) & 0xFF00);
    //unsigned int value   = ((unsigned int)(Wire.read())     ) & 0x00FF;
    unsigned int value2  = ((unsigned int)(Wire.read())     ) & 0x00FF;
    unsigned int value3 = value | value2;
    float corrected = (float)value3 / 4096.0 * 5.0;
    Serial.print(corrected, 2);
    //Serial.print(value2, DEC);
    //Serial.print(value3, DEC);
    Serial.print('\t');
    //Serial.print(value2, DEC);
    //Serial.print('\t');

    buf[counter++]     = corrected;
  }

  Serial.println();
  Serial.flush();

  delay(pause);

}

void set_channel(const int channel) {
  byte logic = (byte)(channel - 1);
  //Serial.println(logic, BIN);
  digitalWrite(enable, LOW);
  for (int i = 0 ; i < sizeof(address) ; i++) {
    digitalWrite(address[i], bitRead(logic, i));
  }
  digitalWrite(enable, HIGH);
  delay(10);
  return;
}

float convert(const int raw) {
  static const float resolution = 5.0 / 1023.0;
  float out = (float)(raw);
  out *= resolution;
  return out;
}

