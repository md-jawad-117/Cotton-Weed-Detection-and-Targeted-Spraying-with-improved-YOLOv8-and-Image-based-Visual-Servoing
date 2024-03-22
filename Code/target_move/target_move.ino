#include <Servo.h>
#include <math.h>


Servo pan;
Servo tilt;
// Servo left_base;
// Servo left_base;  // create servo object to control a servo
float Ti=310;
float Tj=265;

float Tx;
float Ty;
float Dw;  //difference x
float Dh;  //difference y


int pan_pos = 90;
float pan_deg;
float pan_final; 

int tilt_pos = 90;
float tilt_deg; 
float tilt_final;

float deltaX;
float deltaY;

float dia_p;
float dia_cm;
float pixel=0.046875;

float hei = 32.2;


void setup() {
Serial.begin(9600);
pan.attach(9);
tilt.attach(10);
pan.write(90);
tilt.write(90);

delay(100);

}

void loop() 

{
    if (Serial.available() > 0) 
    {
   
        String data = Serial.readStringUntil('\n');
        int commaIndex = data.indexOf(',');
        String xString = data.substring(0, commaIndex);
        String yString = data.substring(commaIndex + 1);
        Tx = xString.toFloat();
        Ty = yString.toFloat();
        Serial.print(Tx);
        Serial.print(" ");
        Serial.println(Ty);

        Dw = Tx-Ti;
        Dh = Ty-Tj;
        Serial.print(Dw);
        Serial.print(" ");
        Serial.println(Dh);
       
        
        pan_deg = atan(Dw/Dh);
        pan_deg = degrees(pan_deg);
        pan_final=pan_pos-pan_deg;
        pan.write(pan_final+1);
        Serial.print(pan_deg);
        Serial.print(" ");
        Serial.println(pan_final);

        deltaX = Tx - Ti;
        deltaY = Ty - Tj;
        dia_p = sqrt(sq(deltaX) + sq(deltaY));
        dia_cm = dia_p * pixel;
        tilt_deg = atan(dia_cm/hei);
        tilt_deg = degrees(tilt_deg);
        
//        tilt_final=tilt_pos-tilt_deg;
        tilt.write(tilt_pos-tilt_deg-1);
        Serial.print(tilt_deg);
        Serial.print(" ");
        Serial.println(tilt_final);
        Serial.println("");
//        delay(700);
//        

    }
}
 
