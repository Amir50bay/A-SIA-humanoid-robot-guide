# Servo Map - A-SIA Humanoid Robotic Guide

## Overview

Seven SG90 micro-servos drive all facial and head motion. Pin assignments are confirmed from the archived FLProg-generated sketch, where servos are attached in the `setup()` function as `_SM1.attach(2)` through `_SM7.attach(8)`.

Control inputs are seven analog potentiometers wired to A0–A6. Each potentiometer value (0-1023) is mapped continuously to a servo angle (0°-180°).

---

## Channel Reference

| Channel | Arduino Pin | Analog Input | Role | Neutral |
|---|---|---|---|---|
| SM1 | D2 | A0 | Head Yaw | 90° |
| SM2 | D3 | A1 | Head Pitch | 90° |
| SM3 | D4 | A2 | Mouth | 10° (closed) |
| SM4 | D5 | A3 | Eyes Horizontal | 90° |
| SM5 | D6 | A4 | Eyes Vertical | 90° |
| SM6 | D7 | A5 | Left Facial Axis | 90° |
| SM7 | D8 | A6 | Right Facial Axis | 90° |

---

## Angle Mapping

```cpp
servo.write(map(analogRead(Ax), 0, 1023, 0, 180));
```

Full potentiometer range covers full servo travel. No dead zones or scaling were applied in the archived implementation.

---

## Channel Notes

**Head Yaw (SM1)** - left/right head rotation. Center at 90°.

**Head Pitch (SM2)** - forward/backward head tilt. Level at 90°.

**Mouth (SM3)** - jaw open/close. Neutral is closed (10°). Full open toward 60–90° depending on mechanism geometry.

**Eyes Horizontal (SM4)** - lateral eye movement. Both eyes linked to single channel via mechanical coupling.

**Eyes Vertical (SM5)** - vertical eye movement.

**Left Facial Axis (SM6) / Right Facial Axis (SM7)** - bilateral facial surface actuators. These drive cheek or brow movement depending on the physical linkage in the head assembly.

---

## Physical Evidence

The internal head photograph confirms a multi-servo array mounted in a white foam/3D-printed bracket inside the mannequin head shell. At least five servo bodies are visible along with signal wiring routed through the neck.

---

## Source Confirmation

Attachment order in `setup()` from `archived/legacy_flprog_code.ino`:

```cpp
_SM3.attach(4);
_SM2.attach(3);
_SM6.attach(7);
_SM5.attach(6);
_SM4.attach(5);
_SM1.attach(2);
_SM7.attach(8);
```

Order of attachment in the FLProg output is non-sequential due to visual layout of the block diagram. The pin-to-servo mapping is consistent regardless of declaration order.
