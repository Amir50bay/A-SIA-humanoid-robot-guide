// ============================================================
// legacy_flprog_code.ino — A-SIA Humanoid Robotic Guide
// Original FLProg-generated Arduino sketch
// Preserved as-is — auto-generated variable names retained
//
// This file is the primary source from which the restored
// src/ modules were derived. Do not edit.
// ============================================================

#define  REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT
#include "flprogUtilites.h"
#include <RemoteXY.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include "DHT_NEW.h"
#include <iarduino_RTC.h>
#include <SoftwareSerial.h>
#include <DFPlayerMega.h>
Servo _SM3;
Servo _SM2;
Servo _SM6;
Servo _SM5;
LiquidCrystal_I2C _lcd1(0x27, 16, 2);
int _dispTempLength1=0;
boolean _isNeedClearDisp1;
DHT _dht2;
iarduino_RTC   _RTC1(RTC_DS1302, 23, 27, 25);
Servo _SM1;
Servo _SM4;
Servo _SM7;
#define REMOTEXY_SERIAL Serial1
#define REMOTEXY_SERIAL_SPEED 9600
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377
#define REMOTEXY_ACCESS_PASSWORD "7777777"
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = {255, 7, 0, 27, 0, 119, 1, 17, 0, 0, 0, 24, 1, 106, 200, 1, 1, 21, 0, 67, 73, 46, 26, 10, 4, 12, 31, 11, 129, 5, 48, 65, 7, 1, 208, 144, 209, 131, 208, 176, 32, 209, 130, 208, 181, 208, 188, 208, 191, 208, 181, 209, 128, 208, 176, 209, 130, 209, 131, 209, 128, 208, 176, 209, 129, 209, 139, 0, 129, 5, 61, 61, 7, 1, 208, 144, 209, 131, 208, 176, 32, 209, 139, 208, 187, 210, 147, 208, 176, 208, 187, 208, 180, 209, 139, 208, 187, 209, 139, 210, 147, 209, 139, 0, 129, 38, 4, 30, 12, 12, 65, 45, 83, 73, 65, 0, 129, 23, 16, 62, 11, 31, 65, 115, 105, 97, 32, 45, 32, 115, 109, 97, 114, 116, 32, 0, 129, 5, 29, 96, 12, 31, 105, 110, 116, 101, 108, 108, 105, 103, 101, 110, 116, 32, 97, 110, 100, 114, 111, 105, 100, 0, 67, 73, 59, 26, 10, 4, 12, 31, 11, 129, 18, 75, 42, 7, 1, 211, 168, 209, 128, 209, 130, 32, 209, 129, 208, 181, 208, 189, 209, 129, 208, 190, 209, 128, 209, 139, 0, 129, 6, 89, 54, 7, 1, 208, 148, 209, 139, 208, 177, 209, 139, 209, 129, 32, 209, 129, 208, 181, 208, 189, 209, 129, 208, 190, 209, 128, 209, 139, 0, 129, 19, 103, 41, 7, 1, 208, 147, 208, 176, 208, 183, 32, 209, 129, 208, 181, 208, 189, 209, 129, 208, 190, 209, 128, 209, 139, 0, 70, 60, 71, 13, 13, 16, 1, 31, 1, 70, 60, 85, 13, 13, 16, 3, 31, 3, 70, 60, 99, 13, 13, 16, 12, 31, 2, 1, 12, 118, 23, 23, 0, 31, 12, 49, 0, 1, 42, 118, 23, 23, 0, 31, 12, 50, 0, 1, 72, 118, 23, 23, 0, 31, 12, 51, 0, 4, 22, 149, 66, 11, 128, 6, 31, 10, 11, 165, 23, 23, 48, 6, 31, 31, 79, 78, 0, 12, 79, 70, 70, 0, 10, 42, 165, 23, 23, 48, 6, 31, 31, 79, 78, 0, 12, 79, 70, 70, 0, 10, 73, 165, 23, 23, 48, 6, 31, 31, 79, 78, 0, 12, 79, 70, 70, 0, 69, 79, 82, 20, 20, 0, 28};
struct 
{
    unsigned char K1;
    unsigned char K2;
    unsigned char K3;
    signed char Gromkost;
    unsigned char L1;
    unsigned char L2;
    unsigned char L3;
    char T1[11];
    char H2[11];
    unsigned char R1;
    unsigned char Y2;
    unsigned char G3;
    int16_t sound;
    unsigned char connect_flag;
}
 RemoteXY;
#pragma pack(pop)
bool StartTrack_246847042_5;
bool _dfstart1_246847042_5= 0;
bool _dfstart1I_246847042_5= 0;
bool StartTrack_246847042_6;
bool _dfstart1_246847042_6= 0;
bool _dfstart1I_246847042_6= 0;
bool StartTrack_246847042_4;
bool _dfstart1_246847042_4= 0;
bool _dfstart1I_246847042_4= 0;
SoftwareSerial mySerial(10 ,  11); // RX, TX
int _volsetup= 20;
int _eqsetup= 0;
DFPlayerMega dfPlayerMega= DFPlayerMega ();
int _gtv2;
int _gtv1;
int _gtv3;
int _gtv4;
int _inputNumber2_Out = 0;
int _inputNumber4_Out = 0;
int _disp1oldLength = 0;
int _disp2oldLength = 0;
int _inputNumber1_Out = 0;
bool _trgrt5 = 0;
bool _trgrt5I = 0;
int _inputNumber3_Out = 0;
byte _RTC1_GetTime1_HourOut = 0;
byte _RTC1_GetTime1_MinOut = 0;
byte _RTC1_GetTime1_SecOut = 0;
bool _trgrt6 = 0;
bool _trgrt6I = 0;
unsigned long _dht2LRT = 0UL;
unsigned long _dht2Tti = 0UL;
bool _trgrt4 = 0;
bool _trgrt4I = 0;
void setup()
{
    pinMode(33, OUTPUT);
    digitalWrite(33, 0);
    pinMode(35, OUTPUT);
    digitalWrite(35, 0);
    pinMode(37, OUTPUT);
    digitalWrite(37, 0);
    Wire.begin();
    delay(10);
    RemoteXY_Init ();
    _RTC1.begin();
    _RTC1.period(1);
    _SM3.attach(4);
    _SM2.attach(3);
    _SM6.attach(7);
    _SM5.attach(6);
    _SM4.attach(5);
    _SM1.attach(2);
    _SM7.attach(8);
    _lcd1.init();
    _lcd1.backlight();
    _dht2.setup(28);
    _dht2LRT = millis();
    _dht2Tti = millis();
    Serial.begin (9600);
    mySerial.begin (9600);
    dfPlayerMega.set_serial (mySerial);
    delay(500);
    dfPlayerMega.normal_mode();
    delay(500);
    dfPlayerMega.set_volume(_volsetup);
    delay(500);
    dfPlayerMega.set_EQ(_eqsetup);
    delay(500);
}
void loop()
{
    if (_isNeedClearDisp1) 
    {
        _lcd1.clear();
        _isNeedClearDisp1= 0;
    }
    RemoteXY_Handler  ();
    //Плата:1
    if(flprog::isTimer(_dht2Tti, 1000)) 
    {
        if(flprog::isTimer(_dht2LRT,(_dht2.getMinimumSamplingPeriod()))) 
        {
            _dht2.readSensor();
            _dht2LRT = millis();
            _dht2Tti = millis();
        }
    }
    if (!(0)) 
    {
        _dispTempLength1 = ((((String("Temp~")) + ((_floatToStringWitRaz(_dht2.temperature,0))) + (String(" ")) + (String("Hum~")) + ((_floatToStringWitRaz(_dht2.humidity,0)))))).length();
        if (_disp2oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp2oldLength = _dispTempLength1;
        _lcd1.setCursor(int((16 - _dispTempLength1)/2), 1);
        _lcd1.print((((String("Temp~")) + ((_floatToStringWitRaz(_dht2.temperature,0))) + (String(" ")) + (String("Hum~")) + ((_floatToStringWitRaz(_dht2.humidity,0))))));
    }
     else 
    {
        if (_disp2oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp2oldLength = 0;
        }
    }
    ((_floatToStringWitRaz(_dht2.temperature,0))).toCharArray((RemoteXY.T1), 11);
    ((_floatToStringWitRaz(_dht2.humidity,0))).toCharArray((RemoteXY.H2), 11);
    RemoteXY.R1 = (map((_gtv2), (0), (1), (0), (255)));
    RemoteXY.Y2 = (map((_gtv1), (0), (1), (0), (255)));
    RemoteXY.G3 = (map((_gtv3), (0), (1), (0), (255)));
    RemoteXY.sound = (map((_gtv4), (0), (1), (0), (255)));
    digitalWrite(37, (RemoteXY.L3));
    digitalWrite(35, (RemoteXY.L2));
    digitalWrite(33, (RemoteXY.L1));
    if ((RemoteXY.K3)) 
    {
         if (_trgrt4I) 
        {
             _trgrt4 = 0;
        }
         else 
        {
            _trgrt4 = 1;
            _trgrt4I = 1;
        }
    }
     else 
    {
        _trgrt4 = 0;
        _trgrt4I = 0;
    }
    ;
    StartTrack_246847042_4 = _trgrt4;
    if (StartTrack_246847042_4) 
    {
         if (_dfstart1I_246847042_4) 
        {
             _dfstart1_246847042_4 = 0;
        }
         else 
        {
            _dfstart1_246847042_4 = 1;
            _dfstart1I_246847042_4 = 1;
        }
    }
     else 
    {
        _dfstart1_246847042_4 = 0;
        _dfstart1I_246847042_4 = 0;
    }
    ;
    if(_dfstart1_246847042_4 == true) 
    {
        dfPlayerMega.start_track (1, 3);
    }
    ;
    if ((RemoteXY.K2)) 
    {
         if (_trgrt6I) 
        {
             _trgrt6 = 0;
        }
         else 
        {
            _trgrt6 = 1;
            _trgrt6I = 1;
        }
    }
     else 
    {
        _trgrt6 = 0;
        _trgrt6I = 0;
    }
    ;
    StartTrack_246847042_6 = _trgrt6;
    if (StartTrack_246847042_6) 
    {
         if (_dfstart1I_246847042_6) 
        {
             _dfstart1_246847042_6 = 0;
        }
         else 
        {
            _dfstart1_246847042_6 = 1;
            _dfstart1I_246847042_6 = 1;
        }
    }
     else 
    {
        _dfstart1_246847042_6 = 0;
        _dfstart1I_246847042_6 = 0;
    }
    ;
    if(_dfstart1_246847042_6 == true) 
    {
        dfPlayerMega.start_track (1, 2);
    }
    ;
    if ((RemoteXY.K1)) 
    {
         if (_trgrt5I) 
        {
             _trgrt5 = 0;
        }
         else 
        {
            _trgrt5 = 1;
            _trgrt5I = 1;
        }
    }
     else 
    {
        _trgrt5 = 0;
        _trgrt5I = 0;
    }
    ;
    StartTrack_246847042_5 = _trgrt5;
    if (StartTrack_246847042_5) 
    {
         if (_dfstart1I_246847042_5) 
        {
             _dfstart1_246847042_5 = 0;
        }
         else 
        {
            _dfstart1_246847042_5 = 1;
            _dfstart1I_246847042_5 = 1;
        }
    }
     else 
    {
        _dfstart1_246847042_5 = 0;
        _dfstart1I_246847042_5 = 0;
    }
    ;
    if(_dfstart1_246847042_5 == true) 
    {
        dfPlayerMega.start_track (1, 1);
    }
    ;
    _RTC1.gettime();
    _RTC1_GetTime1_HourOut = _RTC1.Hours;
    _RTC1_GetTime1_MinOut = _RTC1.minutes;
    _RTC1_GetTime1_SecOut = _RTC1.seconds;
    if (!(0)) 
    {
        _dispTempLength1 = ((((String("Time~")) + ((_convertNumbeToTime(_RTC1_GetTime1_HourOut))) + (String(":")) + ((_convertNumbeToTime(_RTC1_GetTime1_MinOut))) + (String(":")) + ((_convertNumbeToTime(_RTC1_GetTime1_SecOut)))))).length();
        if (_disp1oldLength > _dispTempLength1) 
        {
            _isNeedClearDisp1 = 1;
        }
        _disp1oldLength = _dispTempLength1;
        _lcd1.setCursor(int((16 - _dispTempLength1)/2), 0);
        _lcd1.print((((String("Time~")) + ((_convertNumbeToTime(_RTC1_GetTime1_HourOut))) + (String(":")) + ((_convertNumbeToTime(_RTC1_GetTime1_MinOut))) + (String(":")) + ((_convertNumbeToTime(_RTC1_GetTime1_SecOut))))));
    }
     else 
    {
        if (_disp1oldLength > 0) 
        {
            _isNeedClearDisp1 = 1;
            _disp1oldLength = 0;
        }
    }
    _inputNumber2_Out = 0;
    if (0) 
    {
        _inputNumber2_Out = 1;
    }
    _gtv2 = _inputNumber2_Out;
    _inputNumber1_Out = 0;
    if (0) 
    {
        _inputNumber1_Out = 1;
    }
    _gtv1 = _inputNumber1_Out;
    _inputNumber3_Out = 0;
    if (((0) || (0) || (0))) 
    {
        _inputNumber3_Out = 1;
    }
    _gtv4 = _inputNumber3_Out;
    _inputNumber4_Out = 0;
    if (0) 
    {
        _inputNumber4_Out = 1;
    }
    _gtv3 = _inputNumber4_Out;
    if (!(0)) 
    {
        _SM1.write ((map(((analogRead (0))), (0), (1023), (0), (180))));
    }
    if (!(0)) 
    {
        _SM2.write ((map(((analogRead (1))), (0), (1023), (0), (180))));
    }
    if (!(0)) 
    {
        _SM3.write ((map(((analogRead (2))), (0), (1023), (0), (180))));
    }
    if (!(0)) 
    {
        _SM4.write ((map(((analogRead (3))), (0), (1023), (0), (180))));
    }
    if (!(0)) 
    {
        _SM5.write ((map(((analogRead (4))), (0), (1023), (0), (180))));
    }
    if (!(0)) 
    {
        _SM6.write ((map(((analogRead (5))), (0), (1023), (0), (180))));
    }
    if (!(0)) 
    {
        _SM7.write ((map(((analogRead (6))), (0), (1023), (0), (180))));
    }
}
String  _floatToStringWitRaz(float value, int raz)
{
    return String(value,raz);
}
String _convertNumbeToTime(long value)
{
    if (value > 9) 
    {
        return String(value, DEC);
    }
    return (String("0") + String(value, DEC));
}
