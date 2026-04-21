// ============================================================
// audio.h — A-SIA Humanoid Robotic Guide
// Audio subsystem interface — DFPlayer Mini
// ============================================================

#pragma once
#include "config.h"

// Initialize SoftwareSerial and DFPlayer Mini
// Call once in setup()
void initAudio();

// Trigger individual prerecorded tracks
void playGreeting();       // Track 1 — K1
void playGuidePhrase();    // Track 2 — K2
void playDemoTrack();      // Track 3 — K3

// Play any track by number (folder 1 on microSD)
void playTrack(int trackNumber);
