#include "clock.h"


void init_clock(clock_t *cloc, uint8_t hour, uint8_t min, uint8_t sec) {
    cloc->hours = hour;
    cloc->minutes = min;
    cloc->seconds = sec;
}

void increment_time(clock_t *cloc) {
    cloc->seconds++;
}

void decrement_time(clock_t *cloc) {
    cloc->seconds--;
}

void display_time(const clock_t *cloc) {
    printf("%02d:%02d:%02d\n", cloc->hours, cloc->minutes, cloc->seconds);
}
