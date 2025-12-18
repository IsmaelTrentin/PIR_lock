#pragma once

#define NOTE_C4   261.625565f
#define NOTE_Db4  277.182631f
#define NOTE_D4   293.664768f
#define NOTE_Eb4  311.126984f
#define NOTE_E4   329.627557f
#define NOTE_F4   349.228231f
#define NOTE_Gb4  369.994423f
#define NOTE_G4   391.995436f
#define NOTE_Ab4  415.304698f
#define NOTE_A4   440.000000f
#define NOTE_Bb4  466.163762f
#define NOTE_B4   493.883301f

int freq_to_pr(float freq);
void audio_init();
void audio_stop();
void audio_play_tone(float freq);
void audio_play_note(float freq, int ms);
void audio_play_success();
void audio_play_error();