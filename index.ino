#include "Wire.h"
#include <UIPEthernet.h>
#define TMP102_ADDRESS 72


byte foctet, soctet;
int val;
float temp;
float finally_temp;
EthernetServer serveur(80);


void setup()
{
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  IPAddress ip(192, 168, 0, 17);
  Wire.begin();
  Serial.begin(115200);
  while (!Serial);
  Ethernet.begin(mac, ip);
  serveur.begin();

}

void loop()
{
  
  EthernetClient client = serveur.available();
  if (client)
  {

    Wire.beginTransmission(TMP102_ADDRESS);
    Wire.write(0x00);
    Wire.endTransmission();
    Wire.requestFrom(TMP102_ADDRESS, 2);
    Wire.endTransmission();

    foctet = (Wire.read());
    soctet = (Wire.read());
    val = foctet;
    if ((foctet & 0x80) > 0)
    {
      val |= 0x0F00;
    }
    val <<= 4;
    val |= (soctet >> 4);
    temp = val * 0.0625;
    finally_temp = temp - 5;
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println();
    client.println(finally_temp);
    delay(10);
    client.stop();
    
  }
}
