#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>
#include <stdio.h>

typedef struct Clock {
    uint8_t seconds : 6;
    uint8_t minutes : 6;
    uint8_t hours : 5;
} Clock_t;

void init_clock(Clock_t *cloc);

void set_time(Clock_t *cloc, uint8_t hour, uint8_t min, uint8_t sec);
void set_binary(Clock_t *cloc, uint32_t binary_time);

void increment_time(Clock_t *cloc);
void decrement_time(Clock_t *cloc);

void display_time(const Clock_t *cloc);
void display_binary(const Clock_t *cloc);

#endif // CLOCK_H