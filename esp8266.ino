/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-esp8266-input-data-html-form/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*********/

#include <Arduino.h>
#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>
#define trigPin 4
#define echoPin 5
AsyncWebServer server(80);

// REPLACE WITH YOUR NETWORK CREDENTIALS
const char* ssid = "nazwa wifi";
const char* password = "haslo wifi";

const char* PARAM_INPUT_1 = "input1";
const char* PARAM_INPUT_2 = "input2";
const char* PARAM_INPUT_3 = "input3";

bool hello = false;
bool o = false;
bool i = false;
bool ha = false;
bool zd = false;
bool przed = false;
bool za = false;
bool lewo = false;
bool prawo = false;


// HTML web page to handle 3 input fields (input1, input2, input3)
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>ESP Input Form</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  </head><body>
  <form action="/get">
    input1: <input type="text" name="input1" id="inp">
    <input type="submit" value="Submit" id="but">
  </form><br>
  <form action="/get">
    input2: <input type="text" name="input2" id="inppa">
    <input type="submit" value="Submit" id="butt">
  </form><br>
  <form action="/get">
    input3: <input type="text" name="input3">
    <input type="submit" value="Submit">
  </form>
</body></html>)rawliteral";

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void setup() {
  pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
  pinMode(16, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(0, HIGH);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Failed!");
    return;
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Send web page with input fields to client
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  // Send a GET request to <ESP_IP>/get?input1=<inputMessage>
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    String inputParam;
    // GET input1 value on <ESP_IP>/get?input1=<inputMessage>
    if (request->hasParam(PARAM_INPUT_1)) {
      inputMessage = request->getParam(PARAM_INPUT_1)->value();
      inputParam = PARAM_INPUT_1;
    }
    
    // GET input2 value on <ESP_IP>/get?input2=<inputMessage>
    else if (request->hasParam(PARAM_INPUT_2)) {
      inputMessage = request->getParam(PARAM_INPUT_2)->value();
      inputParam = PARAM_INPUT_2;
    }
    // GET input3 value on <ESP_IP>/get?input3=<inputMessage>
    else if (request->hasParam(PARAM_INPUT_3)) {
      inputMessage = request->getParam(PARAM_INPUT_3)->value();
      inputParam = PARAM_INPUT_3;
    }
    else {
      inputMessage = "No message sent";
      inputParam = "none";
    }

    Serial.println(inputMessage);
    request->send(200, "text/html", "HTTP GET request sent to your ESP on input field (" 
                                     + inputParam + ") with value: " + inputMessage +
                                     "<br><a href=\"/\">Return to Home Page</a>");
    if((inputMessage.indexOf("Hello")>= 0) || (inputMessage.indexOf("hello")>= 0) || (inputMessage.indexOf("Hi")>= 0) || (inputMessage.indexOf("hi")>= 0) || 
    (inputMessage.indexOf("yes")>= 0) || (inputMessage.indexOf("Yes")>= 0) || (inputMessage.indexOf("good")>= 0) || (inputMessage.indexOf("Good")>= 0) || (inputMessage.indexOf("like")>= 0) || 
    (inputMessage.indexOf("Like")>= 0) || (inputMessage.indexOf("Thank")>= 0) || (inputMessage.indexOf("thank")>= 0) || (inputMessage.indexOf("nice")>= 0) || (inputMessage.indexOf("Nice")>= 0)
     || (inputMessage.indexOf("Well")>= 0) || (inputMessage.indexOf("well")>= 0) || (inputMessage.indexOf("right")>= 0) || (inputMessage.indexOf("Right")>= 0) || (inputMessage.indexOf("happy")>= 0)
      || (inputMessage.indexOf("Happy")>= 0) || (inputMessage.indexOf("kind")>= 0) || (inputMessage.indexOf("Kind")>= 0) || (inputMessage.indexOf("love")>= 0) || (inputMessage.indexOf("Love")>= 0)
       || (inputMessage.indexOf("Enjoy")>= 0) || (inputMessage.indexOf("enjoy")>= 0)){
      o = true;
    }
    if((inputMessage.indexOf("Suprise")>= 0) || (inputMessage.indexOf("suprise")>= 0) || (inputMessage.indexOf("know")>= 0) || (inputMessage.indexOf("Know")>= 0) || (inputMessage.indexOf("interesting")>= 0)
     || (inputMessage.indexOf("Interesting")>= 0) || (inputMessage.indexOf("knowledge")>= 0) || (inputMessage.indexOf("Knowledge")>= 0) || (inputMessage.indexOf("learn")>= 0) || (inputMessage.indexOf("Learn")>= 0)
      || (inputMessage.indexOf("unexpected")>= 0) || (inputMessage.indexOf("Unexpected")>= 0)){
        i = true;
      }
    if((o == true) & (i == true)){
      ha = true;
    }
    if((o == true) & (i == false)){
      ha = true;
    }
    if((o == false) & (i == true)){
      zd = true;
    }
    if(inputMessage.indexOf("Prosto")>= 0){
      hello = true;
    }
    if(inputMessage.indexOf("Przed")>= 0){
      przed = true;
    }
    if(inputMessage.indexOf("Za")>= 0){
      za = true;
    }
    if(inputMessage.indexOf("Lewo")>= 0){
      lewo = true;
    }
    if(inputMessage.indexOf("Prawo")>= 0){
      prawo = true;
    }
  });
  server.onNotFound(notFound);
  server.begin();
}

void loop() {

  if(hello == true) {
    long czas, dystans;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
 
    czas = pulseIn(echoPin, HIGH);
    dystans = czas / 58;
    bool pr = false;
    digitalWrite(14, HIGH);
    digitalWrite(16, HIGH);
    if(dystans < 20){
    pr = true;
    } 
    if(pr == true) {
       digitalWrite(16, LOW);
       digitalWrite(14, LOW);
       hello = false;
    }
}
  if(przed == true){
    digitalWrite(14, HIGH);
    digitalWrite(16, HIGH);
    delay(1000);
    digitalWrite(16, LOW);
    digitalWrite(14, LOW);
    przed = false;
  }
  if(za == true){
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    za = false;
  }
  if(lewo == true){
    digitalWrite(14, HIGH);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    digitalWrite(14, LOW);
    lewo = false;
  }
  if(prawo == true){
    digitalWrite(12, HIGH);
    digitalWrite(16, HIGH);
    delay(1000);
    digitalWrite(16, LOW);
    digitalWrite(12, LOW);
    prawo = false;
  }
  if(ha == true)
  {
    digitalWrite(14, HIGH);
    digitalWrite(13, HIGH);
    delay(300);
    digitalWrite(13, LOW);
    digitalWrite(14, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(16, HIGH);
    delay(300);
    digitalWrite(16, LOW);
    digitalWrite(12, LOW);
    ha = false;
  }
  if(zd == true){
    digitalWrite(0, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    delay(300);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(14, HIGH);
    digitalWrite(16, HIGH);
    delay(300);
    digitalWrite(16, LOW);
    digitalWrite(14, LOW);

    delay(1000);
    digitalWrite(0, HIGH);
    zd = false;
  }
  o = false;
  i = false;
  
}
