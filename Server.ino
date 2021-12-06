/* Liblaries */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include "Color.h"
#include "mainpage.h"

/* Network settings */
const char* ssid = "<WIFI-NAME>";
const char* password = "<WIFI-PASSWORD>";
IPAddress ip(192,168,0,9);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

const int redLED    = 12;   // D6 GPIO12
const int greenLED  = 13;   // D7 GPIO13
const int blueLED   = 15;   // D8 GPIO15
const int fanPIN    = 04;   // D2 GPIO4
const int ledPIN    = 16;   // D0 GPIO16 BUILT-IN LED

/* Objects */
ESP8266WebServer server(80);
Color createColor(redLED, greenLED, blueLED);

void setup(void) {
  /* Wait 10sec before start */
  delay(10000);

  /* Turn on LED */
  pinMode(ledPIN, OUTPUT);
  digitalWrite(ledPIN, HIGH);

  /* Init fan pin */
  Serial.println("Initializing Fan");
  pinMode(fanPIN, OUTPUT);

  /* Begin some (un)important things */
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet);

  /* Wait for WiFi connection */
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  /* Show some important information on Serial Monitor */
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  /* Set IP in webPage */
  webPage.replace("{IP_ADDRESS}", WiFi.localIP().toString());

  /* Show website (in browser), than send RGB code */
  server.on("/", []() {
    server.send(200, "text/html", webPage);
    Serial.println("Loaded main page");
  });

  /* Rainbow color mode */
  server.on("/lightup", []() {
    server.send(200, "text/html", webPage);
    createColor.rainbow();
    Serial.print("Pressed: ");
    Serial.println("lightup");
  });

  /* Turn off LED */
  server.on("/off", []() {
    server.send(200, "text/html", webPage);
    createColor.off();
  });

  /* Set color from RGB value */
  server.on("/color", []() {
    if (server.method() != HTTP_POST) {
      server.send(405, "text/json", "{\"message\": \"Method Not Allowed\"");
    } else {
      StaticJsonDocument<200> doc;
      deserializeJson(doc, server.arg("plain"));
      Serial.println(server.arg("plain"));
      createColor.Custom(doc["color"]["red"], doc["color"]["green"], doc["color"]["blue"]);
    }
  });

  /* Set fan speed / Turn on/off fan */
  server.on("/fan", []() {
    if (!server.hasArg("speed")) {
      if (digitalRead(fanPIN) == HIGH) {
        server.send(200, "text/json", "{\"state\": false}");
        digitalWrite(fanPIN, LOW);
      } else {
        server.send(200, "text/json", "{\"state\": true}");
        digitalWrite(fanPIN, HIGH);
      }
    } else {
      analogWrite(fanPIN, server.arg("speed").toInt());
      StaticJsonDocument<200> doc;
      doc["status"] = "done";
      doc["speed"] = server.arg("speed");
      String resp;
      serializeJson(doc, resp);
      server.send(200, "text/json", resp);
    }
  });

  /* Start web serevr */
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();

  /* Check for serial input */
  if (Serial.available() > 0) {
    String incomingString = Serial.readString();
    incomingString.trim();
    Serial.print("I received: ");
    Serial.println(incomingString);

    /* Read results from RGB pins */
    if (incomingString.equals("read")) {
      int R = analogRead(redLED);
      int G = analogRead(greenLED);
      int B = analogRead(blueLED);
      Serial.print("RED: ");
      Serial.println(R);
      Serial.print("GREEN: ");
      Serial.println(G);
      Serial.print("BLUE: ");
      Serial.println(B);
    }
    /* Turn on fan via serial command*/
    else if (incomingString.equals("fan on")) {
      digitalWrite(fanPIN, HIGH);
      Serial.println("Fan ON");
    }
    /* Turn off fan via serial command */
    else if (incomingString.equals("fan off")) {
      digitalWrite(fanPIN, LOW);
      Serial.println("Fan OFF");
    }
  }
}
