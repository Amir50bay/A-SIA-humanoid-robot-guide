# Voice System - A-SIA Humanoid Robotic Guide

## Overview

Audio playback is handled by a DFPlayer Mini module. It operates independently from the main controller once triggered - the Arduino sends a track command over serial and the DFPlayer handles decoding, volume, and output to a connected speaker.

---

## Hardware

| Component | Detail |
|---|---|
| Module | DFPlayer Mini |
| Interface | SoftwareSerial - RX on D10, TX on D11 |
| Storage | microSD card inserted into DFPlayer |
| Audio format | MP3 |
| Volume | Set to 20/30 at init |
| EQ | Normal (0) |

---

## Initialization Sequence

Confirmed from archived code. Each `delay()` is intentional - the DFPlayer requires settling time between commands.

```cpp
dfPlayerMega.normal_mode();   delay(500);
dfPlayerMega.set_volume(20);  delay(500);
dfPlayerMega.set_EQ(0);       delay(500);
```

---

## Track Triggers

Three tracks were implemented in the archived prototype, each mapped to a RemoteXY button:

| Button | Track | Function |
|---|---|---|
| K1 | Track 1 | Greeting phrase |
| K2 | Track 2 | Guide narration |
| K3 | Track 3 | Demo / presentation phrase |

Trigger call:
```cpp
dfPlayerMega.start_track(1, trackNumber);
```

The first argument is the folder number on the microSD card. All tracks resided in folder 1.

---

## Audio Content

The original audio files were stored on a microSD card physically inserted into the DFPlayer Mini module. They are not preserved in this repository - this is standard for this class of hardware, as the firmware only stores track indices, not audio data.

The prerecorded content consisted of guide phrases appropriate for a tourist/exhibition guide context, consistent with the project's role as a humanoid guide prototype.

---

## External AI Guide Concept

The broader guide interaction concept involved an externally operated conversational layer. This was not embedded in the Arduino firmware - no LLM API, no GPT integration, and no onboard inference was present in the hardware.

The embedded system's role was to deliver prerecorded audio on trigger. The conversational guide persona was demonstrated separately and used to script the interaction scenario during presentation. The two layers were decoupled by design: the hardware handled expression and sound, the external layer handled dialogue.

---

## File Structure on microSD

```
microSD/
└── 01/
    ├── 001.mp3    ← Track 1 (K1 - greeting)
    ├── 002.mp3    ← Track 2 (K2 - guide phrase)
    └── 003.mp3    ← Track 3 (K3 - demo)
```

DFPlayer Mini expects zero-padded folder and file names in this format.
