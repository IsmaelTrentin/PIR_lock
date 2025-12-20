#include <p32xxxx.h>
#include "libmc/pwm.h"
#include "libmc/timer.h"
#include "libmc/audio.h"

#include "libmc_config.h"

int freq_to_pr(float freq) {
    return (LIBMC_PBCLK_HZ / (8 * freq)) - 1;
}

// initializes timer2 and pwm on oc1
// uses timer1 for delay when playing, must be set to 1ms

void audio_init() {
    timer2_init(1, LIBMC_PBCLK_HZ, 1, 0);
    // override PR2 value
    PR2 = freq_to_pr(NOTE_A4);

    // setup RB14 pin
    ANSELBbits.ANSB14 = 0;
    TRISBbits.TRISB14 = 0;
    // OC1 function - see PPS Output remaps
    RPB14R = 0b1100; 
    
    // uses timer2 and sets DC to 50%
    // generating a square wave
    pwm_oc1_init(0, PR2 / 2);
    
    audio_stop();
}

void audio_stop() {
    OC1RS = 0;
}

void audio_play_tone(float freq) {
    PR2 = freq_to_pr(freq);
    OC1RS = PR2 / 2;
}

void audio_play_note(float freq, int ms) {
    audio_play_tone(freq);
    timer1_delay_ms(ms);
    audio_stop();
}

void audio_play_success() {
    audio_play_note(NOTE_Gb4, LIBMC_AUDIO_SUCCESS_DELAY);
    audio_play_note(NOTE_B4, LIBMC_AUDIO_SUCCESS_DELAY);
}

void audio_play_error() {
    audio_play_note(NOTE_Gb4, LIBMC_AUDIO_ERROR_DELAY);
    audio_play_note(NOTE_C4, LIBMC_AUDIO_ERROR_DELAY);
}