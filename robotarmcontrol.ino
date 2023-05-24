#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

SoftwareSerial Bluetooth(3, 2);
int Positionservo1, Positionservo2, Positionservo3, Positionservo4, Positionservo5;
int PositionPservo1, PositionPservo2, PositionPservo3, PositionPservo4, PositionPservo5;
int ServoPS1[50], ServoPS2[50], ServoPS3[50], ServoPS4[50], ServoPS5[50];
int velocity = 30;
int dizin = 0;
int veri;
int k = 0;

void setup() {
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(7);
  servo4.attach(8);
  servo5.attach(9);
  Bluetooth.begin(9600); 
  Serial.begin(9600);
  //Robot kol servolarının başlangıç açıları
  PositionPservo1 = 90;
  servo1.write(PositionPservo1);
  PositionPservo2 = 150;
  servo2.write(PositionPservo2);
  PositionPservo3 = 90;
  servo3.write(PositionPservo3);
  PositionPservo4 = 120;
  servo4.write(PositionPservo4);
  PositionPservo5 = 180;
  servo5.write(PositionPservo5);
}

void loop() {
  // gelen datayı kontrol et
  if (Bluetooth.available() > 0) {
    veri = Bluetooth.read();  // datayı oku

    if (veri == 0) {
      k = 0;
    }
    if (veri == 1) {
      k = 1;
    }
    if (veri == 12) {
      k = 12;
    }
    if (veri == 14) {
      k = 14;
    }
    if (veri == 16) {
      k = 16;
    }
    if (veri == 17) {
      k = 17;
    }
    if (veri == 18) {
      k = 18;
    }
    if (veri == 19) {
      k = 19;
    }
    if (veri == 20) {
      k = 20;
    }
    if (veri == 21) {
      k = 21;
    }
    if (veri == 22) {
      k = 22;
    }
    if (veri == 23) {
      k = 23;
    }
    if (veri == 26) {
      k = 26;
    }
    if (veri == 27) {
      k = 27;
    }
    

    while (k == 16) {
      if (Bluetooth.available() > 0) {
        k = Bluetooth.read();
      }
      servo1.write(PositionPservo1);
      PositionPservo1++;
      delay(velocity);
    }
    
    while (k == 17) {
      if (Bluetooth.available() > 0) {
        k = Bluetooth.read();
      }
      servo1.write(PositionPservo1);
      PositionPservo1--;
      delay(velocity);
    }
    
    while (k == 19) {
      if (Bluetooth.available() > 0) {
        k = Bluetooth.read();
      }
      servo2.write(PositionPservo2);
      PositionPservo2++;
      delay(velocity);
    }
    while (k == 18) {
      if (Bluetooth.available() > 0) {
        k = Bluetooth.read();
      }
      servo2.write(PositionPservo2);
      PositionPservo2--;
      delay(velocity);
    }
    
    while (k == 20) {
      if (Bluetooth.available() > 0) {
        k = Bluetooth.read();
      }
      servo3.write(PositionPservo3);
      PositionPservo3++;
      delay(velocity);
    }
    while (k == 21) {
      if (Bluetooth.available() > 0) {
        k = Bluetooth.read();
      }
      servo3.write(PositionPservo3);
      PositionPservo3--;
      delay(velocity);
    }
    
    while (k == 23) {
      if (Bluetooth.available() > 0) {
        k = Bluetooth.read();
      }
      servo4.write(PositionPservo4);
      PositionPservo4++;
      delay(velocity);
    }
    while (k == 22) {
      if (Bluetooth.available() > 0) {
        k = Bluetooth.read();
      }
      servo4.write(PositionPservo4);
      PositionPservo4--;
      delay(velocity);
    }
    
    while (k == 26) {
      if (Bluetooth.available() > 0) {
        k = Bluetooth.read();
      }
      servo5.write(PositionPservo5);
      PositionPservo5++;
      delay(velocity);
    }
    while (k == 27) {
      if (Bluetooth.available() > 0) {
        k = Bluetooth.read();
      }
      servo5.write(PositionPservo5);
      PositionPservo5--;
      delay(velocity);
    }

    // Arm velocity sliderı değiştiğinde
    if (veri > 101 & veri < 250) {
      velocity = veri / 10; //servo hız ayarını değiştir
    }

    // save butonuna basıldığında
    if (k == 12) {

      ServoPS1[dizin] = PositionPservo1;  // pozisyonları dizinin içine kaydet
      ServoPS2[dizin] = PositionPservo2;
      ServoPS3[dizin] = PositionPservo3;
      ServoPS4[dizin] = PositionPservo4;
      ServoPS5[dizin] = PositionPservo5;
      
      dizin++;                        // dizi dizinini arttır
      k = 0;
    }

    // Run butonuna basıldığında
    if (k == 14) {
      CalistirAdim();
      
      // Reset butonuna basıldığında
      if (veri != 14) {
       
       
        memset(ServoPS1, 0, sizeof(ServoPS1)); //data dizinini 0 ayarla
        memset(ServoPS2, 0, sizeof(ServoPS2));
        memset(ServoPS3, 0, sizeof(ServoPS3));
        memset(ServoPS4, 0, sizeof(ServoPS4));
        memset(ServoPS5, 0, sizeof(ServoPS5));
        dizin = 0;  //dizini 0 yap
      }
    }
  }

}

void CalistirAdim() {
  
  while (veri != 13) {  
    for (int i = 0; i <= dizin - 2; i++) {  
      if (Bluetooth.available() > 0) {      
        veri = Bluetooth.read();                                                                                                                                                                                      
        if (veri == 15) {           
          while (veri != 14) {         
            if (Bluetooth.available() > 0) {
              veri = Bluetooth.read();
              if (veri == 13) {
                break;
              }
            }
          }
        }
       
        if (veri > 100 & veri < 150) {
          velocity = veri / 10; 
        }
       
      
      }
      
      
      
      // Servo 1
      if (ServoPS1[i] == ServoPS1[i + 1]) {
      }
      if (ServoPS1[i] > ServoPS1[i + 1]) {
        for ( int j = ServoPS1[i]; j >= ServoPS1[i + 1]; j--) {
          servo1.write(j);
          delay(velocity);
        }
      }
      if (ServoPS1[i] < ServoPS1[i + 1]) {
        for ( int j = ServoPS1[i]; j <= ServoPS1[i + 1]; j++) {
          servo1.write(j);
          delay(velocity);
        }
      }

      // Servo 2
      if (ServoPS2[i] == ServoPS2[i + 1]) {
      }
      if (ServoPS2[i] > ServoPS2[i + 1]) {
        for ( int j = ServoPS2[i]; j >= ServoPS2[i + 1]; j--) {
          servo2.write(j);
          delay(velocity);
        }
      }
      if (ServoPS2[i] < ServoPS2[i + 1]) {
        for ( int j = ServoPS2[i]; j <= ServoPS2[i + 1]; j++) {
          servo2.write(j);
          delay(velocity);
        }
      }

      // Servo 3
      if (ServoPS3[i] == ServoPS3[i + 1]) {
      }
      if (ServoPS3[i] > ServoPS3[i + 1]) {
        for ( int j = ServoPS3[i]; j >= ServoPS3[i + 1]; j--) {
          servo3.write(j);
          delay(velocity);
        }
      }
      if (ServoPS3[i] < ServoPS3[i + 1]) {
        for ( int j = ServoPS3[i]; j <= ServoPS3[i + 1]; j++) {
          servo3.write(j);
          delay(velocity);
        }
      }

      // Servo 4
      if (ServoPS4[i] == ServoPS4[i + 1]) {
      }
      if (ServoPS4[i] > ServoPS4[i + 1]) {
        for ( int j = ServoPS4[i]; j >= ServoPS4[i + 1]; j--) {
          servo4.write(j);
          delay(velocity);
        }
      }
      if (ServoPS4[i] < ServoPS4[i + 1]) {
        for ( int j = ServoPS4[i]; j <= ServoPS4[i + 1]; j++) {
          servo4.write(j);
          delay(velocity);
        }
      } 
      
      if (ServoPS5[i] == ServoPS5[i + 1]) {
      }
      if (ServoPS5[i] > ServoPS5[i + 1]) {
        for ( int j = ServoPS5[i]; j >= ServoPS5[i + 1]; j--) {
          servo5.write(j);
          delay(velocity);
        }
      }
      if (ServoPS5[i] < ServoPS5[i + 1]) {
        for ( int j = ServoPS5[i]; j <= ServoPS5[i + 1]; j++) {
          servo5.write(j);
          delay(velocity);
        }
      }
    }
  }
}
