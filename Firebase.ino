//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "mqtt-7755b.firebaseio.com"
#define FIREBASE_AUTH "YpFnZ43vYLUJGh3iuB2OJEWQjbqbJAM7jBKmKlGG"
#define WIFI_SSID "Anuj"
#define WIFI_PASSWORD "Anujdev1"

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void loop()
{
  Firebase.stream("a1");
  if (Firebase.available())
  {
    int a = Firebase.getInt("a1");
    Serial.println(a);
    switch (a)
    {
      case 1: digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        break;
      case 2: digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        break;
    }
  }
}
