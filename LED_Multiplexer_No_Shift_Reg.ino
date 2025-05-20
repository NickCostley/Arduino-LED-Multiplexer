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

const int column[6] = {14, 15, 16, 17, 18, 19}; // Cathodes (negative) / transistors 14(A0) = 
const int row[8] = {6, 7, 8, 9, 10, 11, 12, 13}; // Anodes (positive) 6 = top, 13 = bottom of board


void setup() {
  for (int i = 6; i < 14; i++){
    pinMode(row[i], OUTPUT);               // Anode 
  }
    for (int i = 14; i < 20; i++){
    pinMode(column[i], OUTPUT);               // Cathode Transistor Pins  
  }
}

void loop() {
  display();
}

int disp[8][6] = {
{1, 0, 1, 0, 1, 0},
{0, 1, 0, 1, 0, 1},
{1, 0, 1, 0, 1, 0},
{0, 1, 0, 1, 0, 1},
{1, 0, 1, 0, 1, 0},
{0, 1, 0, 1, 0, 1},
{1, 0, 1, 0, 1, 0},
{0, 1, 0, 1, 0, 1}
};

bool disp2[8][6] = {
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1}
};


void display(){
  for (int f = 0; f < 1000; f++){
    for (int i = 0; i < 8; i++){
      digitalWrite(row[i], HIGH);   // Turn on this row
      for (int j = 0; j < 6; j++){
        if (disp[i][j] == 1){          // 'If pixel is high' 
          digitalWrite(column[j], HIGH);  // Turn on a transistor
          delay(1);
        }
        else {
          digitalWrite(column[j], LOW);
        }
      }
      digitalWrite(row[i], LOW);
      //delay(1);
      for (int j = 0; j < 6; j++){
        digitalWrite(column[j], LOW);
      }
    }
  }
}


