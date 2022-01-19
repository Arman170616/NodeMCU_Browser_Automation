



#include <ESP8266WiFi.h>

const char* ssid = "";   // SSID i.e Service Set Identifier is the name of your WIFI
const char* password = "";  // Your WiFi password, in case you have open networkcomment the whole statement. 

int ledPin = 13;   // GPIO13 or for NodeMCU you can directly write D?

WiFiServer(80);  // Creates a Server that listens for incoming connectings on the specified port, here in this case is 80


void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  //Connect to WIFI Network
  Serial.println();
  Serial.println();
  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    
 }

 Serial.println("");
 Serial.println("WiFi Connected");

 //start the server

 server.begin();
 Serial.println(("Server Started");


//print the IP Address

Serial.print("Use this URL to Connect: ");    //print() prints whatever you send in. println() does the same thing, only after using println, anything new that is printed gets printed in next line.
Serial.print("http://");
Serial.print(WiFi.localIP());   //gets the WiFi Shield's IP Address and Print the IP Address of Serial Monitor.
Serial.println("/");

}




void loop() {
  // Check if a client has connected
  
  WiFiClient client = server.available();
  if(!clinet) {
    return;
    
  }

  //Wait untill the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
    
 }


// Read the first line of the request

String request = client.readStringUntil("\r");
Serial.println(request);
client.flush();


//Match the request

int value = LOW;
if(request.index0f("/LED=ON") != -1) {
  digitalWrite(ledPin, HIGH);
  value = HIGH;
}
if (request.index0f("/LED=0FF") != -1){
  digitalWrite(ledPin, HIGH);
  value = HIGH;
  
}


// set ledPin According to the request

// digitalWrite(ledPin, value);


// Return the respone 

client.println("HTTP/1.0 200 OK");
client.println("Content-Type: text/html");
client.println(""); // do not forget this one
client.println("<!DOCTYPE HTML>");
client.println("<html>");

client.print("LED pin is now: ");

if(value == HIGH){
  client.print("On");
  } else {
    client.print("Off");
 }
 client.println("<br></br>");
 client.println("<a href=\"LED=ON\"\><button>Turn On </button></a>");
 client.println("<a href=\"LED=OFF\"\><button>Turn Off </button></a></br>");
 client.println("</html>");

 delay(1);
 serial.println("client disconnected");
 serial.println("");





