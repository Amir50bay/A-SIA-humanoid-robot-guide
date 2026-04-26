// ============================================================
// audio.cpp - A-SIA Humanoid Robotic Guide
// Audio subsystem implementation - DFPlayer Mini
// SoftwareSerial on pins 10 (RX) and 11 (TX)
// ============================================================

#include "audio.h"
#include <SoftwareSerial.h>
#include <DFPlayerMega.h>

static SoftwareSerial _audioSerial(PIN_DFPLAYER_RX, PIN_DFPLAYER_TX);
static DFPlayerMega   _dfPlayer;

// ------------------------------------------------------------
// Initialize DFPlayer - confirmed sequence from archived code
// ------------------------------------------------------------
void initAudio() {
    _audioSerial.begin(9600);
    _dfPlayer.set_serial(_audioSerial);
    delay(500);
    _dfPlayer.normal_mode();
    delay(500);
    _dfPlayer.set_volume(AUDIO_VOLUME);
    delay(500);
    _dfPlayer.set_EQ(AUDIO_EQ);
    delay(500);
}

// ------------------------------------------------------------
// Named track triggers
// Folder 1 on microSD, tracks 1–3
// Confirmed from K1/K2/K3 RemoteXY button logic in archived code
// ------------------------------------------------------------
void playGreeting()    { _dfPlayer.start_track(1, TRACK_GREETING); }
void playGuidePhrase() { _dfPlayer.start_track(1, TRACK_GUIDE_PHRASE); }
void playDemoTrack()   { _dfPlayer.start_track(1, TRACK_DEMO); }

void playTrack(int trackNumber) {
    _dfPlayer.start_track(1, trackNumber);
}
