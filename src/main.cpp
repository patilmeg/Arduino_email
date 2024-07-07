/*
 * EMailSender library for Arduino, esp8266 and esp32
 * Simple esp32 Gmail send example
 *
 * https://www.mischianti.org/category/my-libraries/emailsender-send-email-with-attachments/
 *
 */
/*
#include "Arduino.h"
#include <EMailSender.h>
#include <WiFiS3.h>
#include <secrets.h>

//const char* ssid = "<YOUR-SSID>";
//const char* password = "<YOUR-PASSWD>";

uint8_t connection_state = 0;
uint16_t reconnect_interval = 10000;

EMailSender emailSend(SECRET_MAIL, SECRET_MAILPASS);

uint8_t WiFiConnect(const char* nSSID = nullptr, const char* nPassword = nullptr)
{
    static uint16_t attempt = 0;
    Serial.print("Connecting to ");
    if(nSSID) {
        WiFi.begin(nSSID, nPassword);
        Serial.println(nSSID);
    }

    uint8_t i = 0;
    while(WiFi.status()!= WL_CONNECTED && i++ < 50)
    {
        delay(200);
        Serial.print(".");
    }
    ++attempt;
    Serial.println("");
    if(i == 51) {
        Serial.print("Connection: TIMEOUT on attempt: ");
        Serial.println(attempt);
        if(attempt % 2 == 0)
            Serial.println("Check if access point available or SSID and Password\r\n");
        return false;
    }
    Serial.println("Connection: ESTABLISHED");
    Serial.print("Got IP address: ");
    Serial.println(WiFi.localIP());
    return true;
}

void Awaits()
{
    uint32_t ts = millis();
    while(!connection_state)
    {
        delay(50);
        if(millis() > (ts + reconnect_interval) && !connection_state){
            connection_state = WiFiConnect();
            ts = millis();
        }
    }
}

void setup()
{
    Serial.begin(9800);

    connection_state = WiFiConnect(SECRET_SSID, SECRET_PASS);
    if(!connection_state)  // if not connected to WIFI
        Awaits();          // constantly trying to connect

    EMailSender::EMailMessage message;
    message.subject = "Hello kitty";
    message.message = "Arduino says meow meow meow";

    EMailSender::Response resp = emailSend.send("ole@salscheider.org", message);

    Serial.println("Sending status: ");

    Serial.println(resp.status);
    Serial.println(resp.code);
    Serial.println(resp.desc);
}

void loop()
{

}
*/