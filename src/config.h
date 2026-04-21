// ============================================================
// config.h — A-SIA Humanoid Robotic Guide
// Central configuration: pins, servo limits, audio track IDs
// ============================================================

#pragma once

// ------------------------------------------------------------
// Servo output pins (D2–D8, confirmed from archived code)
// ------------------------------------------------------------
#define PIN_SERVO_HEAD_YAW        2
#define PIN_SERVO_HEAD_PITCH      3
#define PIN_SERVO_MOUTH           4
#define PIN_SERVO_EYES_H          5
#define PIN_SERVO_EYES_V          6
#define PIN_SERVO_FACE_LEFT       7
#define PIN_SERVO_FACE_RIGHT      8

// ------------------------------------------------------------
// Analog control inputs (A0–A6, wired potentiometers)
// Each potentiometer maps directly to its servo channel
// ------------------------------------------------------------
#define AIN_HEAD_YAW              A0
#define AIN_HEAD_PITCH            A1
#define AIN_MOUTH                 A2
#define AIN_EYES_H                A3
#define AIN_EYES_V                A4
#define AIN_FACE_LEFT             A5
#define AIN_FACE_RIGHT            A6

// ------------------------------------------------------------
// Servo angle limits (degrees)
// ------------------------------------------------------------
#define SERVO_MIN_ANGLE           0
#define SERVO_MAX_ANGLE           180
#define SERVO_NEUTRAL_ANGLE       90

// Named neutral positions per channel
#define NEUTRAL_HEAD_YAW          90    // Center
#define NEUTRAL_HEAD_PITCH        90    // Level
#define NEUTRAL_MOUTH             10    // Closed
#define NEUTRAL_EYES_H            90    // Center
#define NEUTRAL_EYES_V            90    // Center
#define NEUTRAL_FACE_LEFT         90
#define NEUTRAL_FACE_RIGHT        90

// ------------------------------------------------------------
// DFPlayer Mini — SoftwareSerial pins
// ------------------------------------------------------------
#define PIN_DFPLAYER_RX           10
#define PIN_DFPLAYER_TX           11

// DFPlayer settings
#define AUDIO_VOLUME              20    // 0–30
#define AUDIO_EQ                  0     // Normal

// Audio track IDs (folder 1 on microSD)
// Track assignment matches K1/K2/K3 buttons in RemoteXY
#define TRACK_GREETING            1     // K1 — greeting phrase
#define TRACK_GUIDE_PHRASE        2     // K2 — guide narration
#define TRACK_DEMO                3     // K3 — demo/presentation

// ------------------------------------------------------------
// RTC DS1302 pins (confirmed from archived code)
// ------------------------------------------------------------
#define PIN_RTC_CE                23
#define PIN_RTC_IO                25
#define PIN_RTC_CLK               27

// ------------------------------------------------------------
// LCD I2C
// ------------------------------------------------------------
#define LCD_I2C_ADDRESS           0x27
#define LCD_COLS                  16
#define LCD_ROWS                  2

// ------------------------------------------------------------
// DHT sensor (pin 28 in final code — see restoration-notes.md)
// ------------------------------------------------------------
#define PIN_DHT                   28
