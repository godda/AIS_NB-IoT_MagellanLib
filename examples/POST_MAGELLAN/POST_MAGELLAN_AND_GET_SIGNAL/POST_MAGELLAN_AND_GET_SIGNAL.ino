#include "Magellan.h"
Magellan magel;
char auth[]="your key"; 		//Token Key you can get from magellan platform

String payload;
 signal NBsig;              //Variable for store network signal data
void setup() {
  Serial.begin(9600);
  magel.begin(auth);           //init Magellan LIB
}

void loop() {
 
  NBsig = magel.getSignal();    //get signal data
  Serial.println(NBsig.csq);    //show csq value
  Serial.println(NBsig.rssi);   //show rssi value
  Serial.println(NBsig.ber);    //show ber value
 
  /*
  	Example send random temperature and humidity to Magellan IoT platform
  */
  String Temperature=String(random(0,100));
  String Humidity=String(random(0,100));

  payload="{\"Temperature\":"+Temperature+",\"Humidity\":"+Humidity+"}";       //please provide payload with json format

  magel.post(payload);                            							   //post payload data to Magellan IoT platform
  
}
