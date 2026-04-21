# Mobile Base — A-SIA Humanoid Robotic Guide

## Overview

The mobile base is a custom-fabricated rolling platform designed to carry the full humanoid upper body assembly. It provides a stable, maneuverable foundation for the prototype during demonstration and presentation contexts.

---

## Physical Design

The base has an oval profile constructed from foam board sheet material, giving it a clean and intentional aesthetic consistent with the humanoid form above it. The enclosure is hollow, providing an internal bay used to house cabling and power distribution components during the demonstration.

**Dimensions and form:** Oval footprint, approximately 60–70 cm along the long axis. Height sufficient to conceal the lower structure of the robot body and provide a grounded visual silhouette.

**Mobility:** Four passive swivel casters mounted at the underside perimeter. This configuration allows smooth omnidirectional repositioning by an operator, with low rolling resistance on flat surfaces.

**Finish:** Wrapped in white material consistent with the upper body shell, giving the full robot a unified visual appearance.

---

## Electronics Bay

The internal cavity of the base was used to house the main electronics enclosure — a 3D-printed black box containing the Arduino Mega 2560, ESP8266 module, DFPlayer Mini, and associated wiring. This arrangement kept all sensitive electronics protected and out of view during the presentation.

---

## Demonstrated Role

During the NIS Turkistan Hackathon demonstration, the base allowed the robot to be positioned and repositioned manually between interaction scenarios. The passive caster design was appropriate for the presentation environment — a flat indoor floor — and required no motor control integration.

---

## Motorized Drive — Planned Extension

Motorized mobility was identified as the next development stage following the hackathon prototype. The intended implementation would add:

- DC motors with a motor driver (L298N or equivalent)
- Forward / reverse control via PWM
- Potential integration with the RemoteXY interface for wireless drive commands

This was not implemented in the demonstrated hardware. No motor driver is present in the archived firmware.

---

## Photo Reference

See `media/mobile-station-side.jpg` for a photograph of the physical base platform.
