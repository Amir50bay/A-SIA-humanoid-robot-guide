// ============================================================
// asia_main.ino — A-SIA Humanoid Robotic Guide
// Main sketch — initializes subsystems and runs control loop
//
// Controller : Arduino Mega 2560
// Servos     : 7× SG90 on D2–D8, driven by analog A0–A6
// Audio      : DFPlayer Mini on SoftwareSerial D10/D11
// ============================================================

#include "config.h"
#include "servos.h"
#include "audio.h"

// ============================================================
// setup()
// ============================================================
void setup() {
    Serial.begin(9600);

    // Initialize facial and head servo channels
    initializeServos();

    // Initialize DFPlayer Mini audio subsystem
    initAudio();

    Serial.println("A-SIA ready.");
}

// ============================================================
// loop()
// ============================================================
void loop() {
    // Continuously read wired potentiometer inputs
    // and write computed angles to all 7 servo channels.
    // This is the primary confirmed control mode.
    updateServosFromAnalog();
}
