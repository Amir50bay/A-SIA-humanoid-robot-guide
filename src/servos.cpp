// ============================================================
// servos.cpp - A-SIA Humanoid Robotic Guide
// Servo subsystem implementation
// ============================================================

#include "servos.h"

// Private servo objects - one per channel
static Servo _headYaw;
static Servo _headPitch;
static Servo _mouth;
static Servo _eyesH;
static Servo _eyesV;
static Servo _faceLeft;
static Servo _faceRight;

// ------------------------------------------------------------
// Attach all servos and go to neutral
// ------------------------------------------------------------
void initializeServos() {
    _headYaw.attach(PIN_SERVO_HEAD_YAW);
    _headPitch.attach(PIN_SERVO_HEAD_PITCH);
    _mouth.attach(PIN_SERVO_MOUTH);
    _eyesH.attach(PIN_SERVO_EYES_H);
    _eyesV.attach(PIN_SERVO_EYES_V);
    _faceLeft.attach(PIN_SERVO_FACE_LEFT);
    _faceRight.attach(PIN_SERVO_FACE_RIGHT);

    moveToNeutralPose();
}

// ------------------------------------------------------------
// Move all channels to neutral
// ------------------------------------------------------------
void moveToNeutralPose() {
    _headYaw.write(NEUTRAL_HEAD_YAW);
    _headPitch.write(NEUTRAL_HEAD_PITCH);
    _mouth.write(NEUTRAL_MOUTH);
    _eyesH.write(NEUTRAL_EYES_H);
    _eyesV.write(NEUTRAL_EYES_V);
    _faceLeft.write(NEUTRAL_FACE_LEFT);
    _faceRight.write(NEUTRAL_FACE_RIGHT);
}

// ------------------------------------------------------------
// Live wired control - reads A0-A6, writes to servos
// Confirmed behavior from archived FLProg sketch
// ------------------------------------------------------------
void updateServosFromAnalog() {
    _headYaw.write(map(analogRead(AIN_HEAD_YAW),   0, 1023, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    _headPitch.write(map(analogRead(AIN_HEAD_PITCH), 0, 1023, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    _mouth.write(map(analogRead(AIN_MOUTH),        0, 1023, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    _eyesH.write(map(analogRead(AIN_EYES_H),       0, 1023, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    _eyesV.write(map(analogRead(AIN_EYES_V),       0, 1023, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    _faceLeft.write(map(analogRead(AIN_FACE_LEFT),  0, 1023, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
    _faceRight.write(map(analogRead(AIN_FACE_RIGHT), 0, 1023, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE));
}

// ------------------------------------------------------------
// Named setters - for scripted sequences or future automation
// ------------------------------------------------------------
void setHeadYaw(int angle)         { _headYaw.write(constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE)); }
void setHeadPitch(int angle)       { _headPitch.write(constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE)); }
void setMouth(int angle)           { _mouth.write(constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE)); }
void setEyesHorizontal(int angle)  { _eyesH.write(constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE)); }
void setEyesVertical(int angle)    { _eyesV.write(constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE)); }
void setLeftFacialAxis(int angle)  { _faceLeft.write(constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE)); }
void setRightFacialAxis(int angle) { _faceRight.write(constrain(angle, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE)); }
