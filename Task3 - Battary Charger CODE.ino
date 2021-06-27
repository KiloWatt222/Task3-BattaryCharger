int analogInput = A1;
int start = 2;
int pwm = 3;
int led_y = 5;
int led_g = 8;
int ch_time = 10000;
float Vout = 0.00;
float Vin = 0.00;
float R1 = 10000.00; // resistance of R1 (100K) 
float R2 = 1000.00; // resistance of R2 (10K) 
int val = 0;
void setup(){
   pinMode(analogInput, INPUT); //assigning the input port
   Serial.begin(9600); //BaudRate
   pinMode (start,OUTPUT);
   pinMode (pwm,OUTPUT);
   pinMode (led_y,OUTPUT);
   pinMode (led_g,OUTPUT);
}
void loop(){
   // voltmeter cod....................................
   {
   val = analogRead(analogInput);//reads the analog input
   Vout = (val * 5.00) / 1024.00; // formula for calculating voltage out i.e. V+, here 5.00
   Vin = Vout / (R2/(R1+R2)); // formula for calculating voltage in i.e. GND
   if (Vin<0.09)//condition 
   {
     Vin=0.00;//statement to quash undesired reading !
  }
  Serial.print("\t Voltage of the given source = ");
  Serial.print(Vin);
  delay(1000); //for maintaining the speed of the output in serial moniter 
   }
   // 1.2v battery charger................................
   {
    if ((Vin >= 0.70)&&(Vin <= 1.30)){
      digitalWrite (start,HIGH);
      analogWrite (pwm,32);
      digitalWrite (led_y,HIGH);
      delay (ch_time);
    }
    else{
     digitalWrite (start,LOW);
     analogWrite (pwm,0);
     digitalWrite (led_y,LOW);
     digitalWrite (led_g,LOW); 
    }
   }
   {
    if ((Vin >= 1.31)&&(Vin <= 2.00)){
     digitalWrite (start,LOW);
     analogWrite (pwm,0);
     digitalWrite (led_y,HIGH);
     digitalWrite (led_g,HIGH);
     delay (ch_time);
    }
    else{
     digitalWrite (start,LOW);
     analogWrite (pwm,0);
     digitalWrite (led_y,LOW);
     digitalWrite (led_g,LOW); 
    }
   }
   
   // 3.7v battery charger................................
   {
    if ((Vin >= 3.00)&&(Vin <= 4.10)){
      digitalWrite (start,HIGH);
      analogWrite (pwm,95);
      digitalWrite (led_y,HIGH);
      delay (ch_time);
    }
    else{
     digitalWrite (start,LOW);
     analogWrite (pwm,0);
     digitalWrite (led_y,LOW);
     digitalWrite (led_g,LOW); 
    }
   }
   {
    if ((Vin >= 4.11)&&(Vin <= 4.60)){
     digitalWrite (start,LOW);
     analogWrite (pwm,0);
     digitalWrite (led_y,HIGH);
     digitalWrite (led_g,HIGH);
     delay (ch_time);
    }
    else{
     digitalWrite (start,LOW);
     analogWrite (pwm,0);
     digitalWrite (led_y,LOW);
     digitalWrite (led_g,LOW); 
    }
   }

   // 7.4 v battery charger................................
   {
    if ((Vin >= 6.00)&&(Vin <= 7.40)){
      digitalWrite (start,HIGH);
      analogWrite (pwm,167);
      digitalWrite (led_y,HIGH);
      delay (ch_time);
    }
    else{
     digitalWrite (start,LOW);
     analogWrite (pwm,0);
     digitalWrite (led_y,LOW);
     digitalWrite (led_g,LOW); 
    }
   }
   {
    if ((Vin >= 7.41)&&(Vin <= 8.00)){
     digitalWrite (start,LOW);
     analogWrite (pwm,0);
     digitalWrite (led_y,HIGH);
     digitalWrite (led_g,HIGH);
     delay (ch_time);
    }
    else{
     digitalWrite (start,LOW);
     analogWrite (pwm,0);
     digitalWrite (led_y,LOW);
     digitalWrite (led_g,LOW); 
    }
   }

   // 9 v battery charger................................
   {
    if ((Vin >= 8.40)&&(Vin <= 9.60)){
      digitalWrite (start,HIGH);
      analogWrite (pwm,210);
      digitalWrite (led_y,HIGH);
      delay (ch_time);
    }
    else{
     digitalWrite (start,LOW);
     analogWrite (pwm,0);
     digitalWrite (led_y,LOW);
     digitalWrite (led_g,LOW); 
    }
   }
   {
    if ((Vin >= 9.61)&&(Vin <= 10.20)){
     digitalWrite (start,LOW);
     analogWrite (pwm,0);
     digitalWrite (led_y,HIGH);
     digitalWrite (led_g,HIGH);
     delay (ch_time);
    }
    else{
     digitalWrite (start,LOW);
     analogWrite (pwm,0);
     digitalWrite (led_y,LOW);
     digitalWrite (led_g,LOW); 
    }
   }
    

    
  
   
}