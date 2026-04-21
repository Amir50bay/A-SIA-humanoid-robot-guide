# System Architecture — A-SIA Humanoid Robotic Guide

## Overview

A-SIA is built around a single Arduino Mega 2560 as the central controller. All subsystems — servo actuation, audio playback, and auxiliary sensing — connect directly to this board. There is no secondary microcontroller, no onboard compute module, and no embedded inference engine.

---

## Controller

**Arduino Mega 2560**
- 54 digital I/O pins, 16 analog inputs
- Sufficient PWM outputs for all 7 servo channels simultaneously
- Hardware Serial1 used for RemoteXY / ESP8266
- SoftwareSerial used for DFPlayer Mini

---

## Subsystems

### 1. Facial and Head Motion

Seven SG90 micro-servos drive all expressive and positional degrees of freedom in the head. Each servo is controlled by a dedicated analog input channel connected to a physical potentiometer. The mapping is direct and continuous — no buffering, no state machine.

```
A0–A6  →  map(0–1023, 0–180)  →  D2–D8 (SM1–SM7)
```

See `docs/servo-map.md` for full channel assignments.

### 2. Audio Playback

A DFPlayer Mini module handles all audio output. It communicates over SoftwareSerial on pins D10/D11 and plays prerecorded `.mp3` files stored on a microSD card. Tracks are triggered by button presses relayed through the RemoteXY interface.

```
RemoteXY K1/K2/K3  →  dfPlayerMega.start_track(1, x)  →  Speaker
```

See `docs/voice-system.md` for detail.

### 3. RemoteXY Interface

An ESP8266 module connected to Hardware Serial1 hosts a RemoteXY access point. The companion smartphone app provides three audio trigger buttons (K1/K2/K3), a volume slider, and status indicators. Servo control itself remained wired — the RemoteXY layer was an operator convenience overlay, not the primary control path.

### 4. Auxiliary Sensing and Display

Present in the archived prototype but outside the core restored scope:

| Component | Interface | Role |
|---|---|---|
| DS1302 RTC | D23/D25/D27 | Real-time clock |
| DHT sensor | D28 | Temperature and humidity |
| LCD 16×2 I²C | SDA/SCL (0x27) | Status display |

These are preserved in `archived/legacy_flprog_code.ino`.

### 5. Mobile Base

A custom oval foam enclosure on passive casters served as the rolling platform during demonstration. The electronics bay was housed inside this base. Motorized drive was a planned next stage and was not implemented in the demonstrated hardware. See `docs/mobile-base.md`.

---

## External AI Guide Layer

The guide persona was not embedded in the firmware. A conversational AI interface was operated externally and scripted separately to deliver guide narration. The embedded system was responsible solely for motion and audio — the interaction layer above it was decoupled.

```
External conversational layer
        ↓  (operator-triggered)
  Audio playback (DFPlayer)
  Facial motion  (servo potentiometers)
```

---

## Control Flow Diagram

```
┌──────────────────────────────────────────────────────┐
│                  Arduino Mega 2560                    │
│                                                       │
│   Analog inputs          Digital outputs              │
│   A0 ──────────────────► D2  (Head Yaw)              │
│   A1 ──────────────────► D3  (Head Pitch)            │
│   A2 ──────────────────► D4  (Mouth)                 │
│   A3 ──────────────────► D5  (Eyes H)                │
│   A4 ──────────────────► D6  (Eyes V)                │
│   A5 ──────────────────► D7  (Face Left)             │
│   A6 ──────────────────► D8  (Face Right)            │
│                                                       │
│   Serial1 ◄────────────── ESP8266 (RemoteXY)         │
│   D10/D11 ──────────────► DFPlayer Mini              │
│   I²C     ──────────────► LCD 16×2                   │
│   D23/25/27 ────────────► DS1302 RTC                 │
│   D28     ◄────────────── DHT sensor                 │
└──────────────────────────────────────────────────────┘
```
