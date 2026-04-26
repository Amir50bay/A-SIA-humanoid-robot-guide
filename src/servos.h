// ============================================================
// servos.h - A-SIA Humanoid Robotic Guide
// Servo subsystem interface
// ============================================================

#pragma once
#include <Servo.h>
#include "config.h"

// Attach all 7 servos and move to neutral positions
void initializeServos();

// Move all channels to their defined neutral angles
void moveToNeutralPose();

// Read analog inputs and update all servo positions
// Call continuously in loop() for live wired control
void updateServosFromAnalog();

// Named per-channel setters (angle in degrees, 0–180)
void setHeadYaw(int angle);
void setHeadPitch(int angle);
void setMouth(int angle);
void setEyesHorizontal(int angle);
void setEyesVertical(int angle);
void setLeftFacialAxis(int angle);
void setRightFacialAxis(int angle);
