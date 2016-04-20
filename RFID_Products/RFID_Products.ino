#include <SoftwareSerial.h>

byte data[5];  
int val = 0;
int product1[5] = {0x01, 0x07, 0x65, 0x3E, 0xF9};
int product2[5] = {0x01, 0x07, 0x65, 0x9C, 0xD1};
int product3[5] = {0x01, 0x07, 0x65, 0x45, 0xA8};
int product4[5] = {0x01, 0x07, 0x65, 0x46, 0xC7};
int product5[5] = {0x01, 0x07, 0x65, 0x5F, 0xDB};

//New serial connection pins for Xbee module (Rx, Tx)
SoftwareSerial newserial =  SoftwareSerial(7, 8);

void setup()
{
   Serial.begin(19200);
   newserial.begin(19200);
   delay(500);
   Serial.flush();
}

 void loop()
{
   val = Serial.read();
   while (val != 0xff)
   {  //On Successful read, first byte will always be 0xFF
      val = Serial.read();
      delay(1000);
   }
   
   //we already read the header (0xff)
   Serial.read();              // reserved
   Serial.read();              // length
   Serial.read();              // command (indicates tag data)
   data[0] = Serial.read();    // we read data 1
   data[1] = Serial.read();    // we read data 2
   data[2] = Serial.read();    // we read data 3
   data[3] = Serial.read();    // we read data 4
   data[4] = Serial.read();    // we read data 5
   Serial.read();              // checksum
   
   // Indentify RFID Card
   boolean product1Card = true;
   boolean product2Card = true;
   boolean product3Card = true;
   boolean product4Card = true;
   boolean product5Card = true;
   
   //boolean d_card = true;
   //Serial.print("Card found - Code: ");
   for (int i=0; i<5; i++)
   {
     if (data[i] != product1[i]) product1Card = false;
     if (data[i] != product2[i]) product2Card = false;
     if (data[i] != product3[i]) product3Card = false;
     if (data[i] != product4[i]) product4Card = false;
     if (data[i] != product5[i]) product5Card = false;
   }
   if (product1Card)
   { 
     newserial.println("Product1");
     delay(500);
   }
   if (product2Card)
   {
     newserial.println("Product2");
     delay(500);
   }  
   if (product3Card)
   {
     newserial.println("Product3");
     delay(500);
   }
   if (product4Card)
   {
     newserial.println("Product4");
     delay(500);
   }
   if (product5Card)
   {
     newserial.println("Product5");
     delay(500);
   }
}

