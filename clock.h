#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>
#include <stdio.h>

typedef struct clock {
    uint8_t seconds : 6;
    uint8_t minutes : 6;
    uint8_t hours : 5;
} clock_t;

void init_clock(clock_t *cloc, uint8_t hour, uint8_t min, uint8_t sec);
void increment_time(clock_t *cloc);
void decrement_time(clock_t *cloc);
void display_time(const clock_t *cloc);

#endif // CLOCK_H