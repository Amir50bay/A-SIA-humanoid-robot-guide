# Restoration Notes — A-SIA Humanoid Robotic Guide

## Purpose

This document records the methodology, source materials, confirmed facts, and known discrepancies behind this repository. A-SIA is a restored project — the `src/` code is a structured reconstruction derived from preserved materials, not a verbatim recovery of a single original file.

---

## Source Materials

The following materials were available during restoration:

| Material | Content |
|---|---|
| `legacy_flprog_code.ino` | FLProg-generated Arduino sketch — primary code source |
| Hand-drawn wiring diagram | Block-level schematic of all connections |
| FLProg screenshot | Visual block diagram confirming subsystem layout |
| Prototype photographs | Front, rear, head interior, base, electronics bay |
| Project documentation | Original description and presentation context |

---

## Confirmed Facts

The following are directly verifiable from the source materials:

- Arduino Mega 2560 as the main controller
- 7 servos attached on D2–D8 (`_SM1.attach(2)` through `_SM7.attach(8)`)
- Analog inputs A0–A6 mapped to servo angles via `map(analogRead(Ax), 0, 1023, 0, 180)`
- SoftwareSerial on pins D10/D11 for DFPlayer Mini communication
- DFPlayer init sequence: `normal_mode()`, `set_volume(20)`, `set_EQ(0)` with 500 ms delays
- Three audio tracks triggered by RemoteXY buttons K1/K2/K3 via `start_track(1, x)`
- ESP8266 on Hardware Serial1 for RemoteXY access point
- DS1302 RTC on pins 23/25/27
- LCD I²C at address 0x27, 16×2
- Physical servo array visible inside mannequin head (photo confirmed)
- Custom oval foam rolling base on passive casters (photo confirmed)
- NIS Turkistan Hackathon as demonstration context (photo confirmed)

---

## Known Discrepancies

### DHT sensor pin mismatch

The hand-drawn wiring diagram shows the DHT sensor connected to **D9**. The archived code shows `_dht2.setup(28)` — **pin 28**. This suggests the wiring diagram was drawn at an earlier stage of the build and the pin was changed before final assembly. The code value (pin 28) is treated as authoritative.

### RemoteXY and wired control coexistence

The archived code contains both wired analog servo control (A0–A6) and RemoteXY wireless interface (ESP8266 on Serial1). The servo control path is unconditional — it runs every loop regardless of RemoteXY state. The RemoteXY layer provided audio triggers and status display only. The primary servo control mode was wired.

### FLProg attachment order

In the archived sketch, servos are attached in non-sequential order (`_SM3`, `_SM2`, `_SM6`, `_SM5`, `_SM4`, `_SM1`, `_SM7`). This reflects the visual layout of the FLProg block diagram, not functional priority. The pin assignments themselves are consistent and correct.

---

## Restoration Decisions

### Modular code structure

The original codebase was a single monolithic FLProg-generated `.ino` file with auto-generated variable names (`_SM1`, `_gtv2`, `_trgrt5I`, etc.). The restored `src/` directory refactors this into named modules with documented interfaces. All logic is derived from the original — no new behavior was introduced.

### Scope narrowing

The archived code also contains DHT sensing, RTC timekeeping, and LCD display logic. These are preserved in `archived/` but excluded from the core `src/` modules. This decision keeps the repository focused on the most visually and mechanically distinctive subsystems: facial motion and audio.

### Mobile base

The physical base is documented in `docs/mobile-base.md`. No `mobility.cpp` module was created because no motor control code exists in any preserved source. The base used passive casters in the demonstrated prototype.

### Audio files

The original `.mp3` files are not preserved. They resided on a microSD card and were never part of the firmware or project files. Their absence is expected and does not represent a gap in the code restoration.

---

## What This Repository Is Not

- It is not a claim that every listed feature was fully operational at all times
- It is not a fabrication of unconfirmed capabilities
- It is not a representation that onboard AI inference was present in the firmware

It is an honest, structured reconstruction of a physical prototype based on the best available evidence.
