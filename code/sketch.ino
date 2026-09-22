#include <LiquidCrystal.h>
#include <EEPROM.h>
#define buzzer 8
#include <Servo.h>
LiquidCrystal lcd(6,7,10,11,12,13);
Servo motor;
# define r1 2
# define r2 3
# define r3 4
# define r4 5
# define c1 A0
# define c2 A1
# define c3 A2
# define c4 A3

void setup(){
  motor.attach(9);
  lcd.begin(16,2);
  pinMode(buzzer,OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);
  pinMode(c1,INPUT_PULLUP);
  pinMode(c2,INPUT_PULLUP);
  pinMode(c3,INPUT_PULLUP);
  pinMode(c4,INPUT_PULLUP);
  EEPROM.write(0,'1');
  EEPROM.write(1,'9');
  EEPROM.write(2,'8');
  EEPROM.write(3,'1');
  char x=EEPROM.read(0);
  char y=EEPROM.read(1);
  char z=EEPROM.read(2);
  char a=EEPROM.read(3);}
char getkey(){
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  delay(2);
  if (digitalRead(c1)==LOW){
    return '1';
 }
  if (digitalRead(c2)==LOW){
     return '2';}
  if (digitalRead(c3)==LOW){
    return '3';
    }
  if (digitalRead(c4)==LOW){
    return 'A';
    }
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  delay(2);
  if (digitalRead(c1)==LOW){
    return '4';
    }
  if (digitalRead(c2)==LOW){
      return '5';}
  if (digitalRead(c3)==LOW){
    return '6';
    }
  if (digitalRead(c4)==LOW){
    return 'B';
    }
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  digitalWrite(r4,HIGH);
  delay(2);
  if (digitalRead(c1)==LOW){
    return '7';
    }
  if (digitalRead(c2)==LOW){
    return '8';
    }
  if (digitalRead(c3)==LOW){
    return '9';
    }
  if (digitalRead(c4)==LOW){
    return 'C';
    }
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,LOW);
  delay(2);
  if (digitalRead(c1)==LOW){
    return '*';
    }
  if (digitalRead(c2)==LOW){
    return '0';
    }
  if (digitalRead(c3)==LOW){
    return '#';
    }
  if (digitalRead(c4)==LOW){
    return 'D';  }
  return '\0';
}
void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("enter password");
  delay(300);
  char password[5];
  for(int i=0;i<4;i++){
    password[i]=EEPROM.read(i);
  }
  char storedpassword[5];
  lcd.setCursor(0,1);
  for(int i=0;i<4;i++){
    storedpassword[i]='\0';
    while(storedpassword[i]=='\0'){
      storedpassword[i]=getkey();}
      lcd.print(storedpassword[i]);
      delay(300);
  }
  boolean c=true;
  for(int i=0;i<4;i++){
    if(storedpassword[i]!=password[i]){
      c=false;
    }
  }
  lcd.clear();
  if(c){
    lcd.setCursor(0,0);
    lcd.print("Access Granted");
    delay(300);
    lcd.clear();
    motor.write(90);
    delay(500);
    motor.write(0);
    
}
else{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Wrong password");
delay(300);
lcd.setCursor(0,1);
lcd.print("Please check once");
delay(300);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Reset Password");
delay(300);
lcd.setCursor(0,1);
lcd.print("Press #");
delay(300);
lcd.clear();
char ch='\0';
while(ch=='\0'){
  ch=getkey();
}
delay(300);
char password[5];
if (ch=='#'){
  for(int i=0;i<4;i++){
    char j='\0';
    while(j=='\0'){
      j=getkey();
      }
      password[i]=j;
      lcd.print(j);
      delay(300);
}
for(int i=0;i<4;i++){
  EEPROM.write(i,password[i]);
}}
digitalWrite(buzzer,HIGH);
delay(5000);
digitalWrite(buzzer,LOW);
}}
