/*
bool Off[8][6] = {
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0}
};

bool On[8][6] = {
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1}
};
*/

// A0 A1 A2 A3 A4 A5 2 3 4 5 6 7 8 9 10 11 12 13
// 14 15 16 17 18 19

const int SER = 12;
const int LATCH = 11;
const int CLK = 13;
const int column[6] = {14, 15, 16, 17, 18, 19};
const int row[8] = {6, 7, 8, 9, 10, 11, 12, 13}

int bin = 0;

void setup() {
  for (int i = 6; i < 14; i++){
    pinMode(row[i], OUTPUT);               // Anode 
  }
    for (int i = 14; i < 20; i++){
    pinMode(column[i], OUTPUT);               // Cathode Transistor Pins  
  }
}

void loop() {

}


void display(){
  for (int f = 0; f < 1000; f++){
    for (int i = 2; i < 8; i++){      // Loops through different transistors being active.
      digitalWrite(LATCH, LOW);       // All anodes are set low to prevent unintentional activation.
      for (int j = 0; j < 8; j++){
        if (a[j][i-2] == 1){          // 'If pixel is high'
          digitalWrite(LATCH, HIGH);
          digtalWrite(i, HIGH);
          delay(100);
          digitalWrite(i, LOW);
          bin = pow(2,j);
          shiftOut(SER, CLK, MSBFIRST, bin);
        }
        else {
          digitalWrite(i, LOW);
          digitalWrite(LATCH, LOW);
        }
      }
      digitalWrite(i, LOW);
    }
  }
}

// Transistor on, Latch off.
// Shift in serial bits, Latch on
