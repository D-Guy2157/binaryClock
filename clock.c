#include "clock.h"


void init_clock(clock_t *cloc) {
    cloc->hours = 0;
    cloc->minutes = 0;
    cloc->seconds = 0;
}

void set_time(clock_t *cloc, uint8_t hour, uint8_t min, uint8_t sec) {
    cloc->hours = hour;
    cloc->minutes = min;
    cloc->seconds = sec;
}

void set_binary(clock_t *cloc, uint32_t binary_time) {
    cloc->seconds = binary_time & 0x3F;
    cloc->minutes = (binary_time >> 6) & 0x3F;
    cloc->hours = (binary_time >> 12) & 0x1F;
}

void increment_time(clock_t *cloc) {
    if (++cloc->seconds >= 60) {
        cloc->seconds = 0;
        if (++cloc->minutes >= 60) {
            cloc->minutes = 0;
            if (++cloc->hours >= 24) {
                cloc->hours = 0;
            }
        }
    }
}

void decrement_time(clock_t *cloc) {
    if (cloc->seconds-- == 0) {
        cloc->seconds = 59;
        if (cloc->minutes-- == 0) {
            cloc->minutes = 59;
            if (cloc->hours-- == 0) {
                cloc->hours = 23;
            }
        }
    }
}

void display_time(const clock_t *cloc) {
    printf("%02d:%02d:%02d\n", cloc->hours, cloc->minutes, cloc->seconds);
}

// Helper function to print an int in binary
void print_binary(uint32_t value, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
}

void display_binary(const clock_t *cloc) {
    print_binary(cloc->hours, 5);
    printf(" ");
    print_binary(cloc->minutes, 6);
    printf(" ");
    print_binary(cloc->seconds, 6);
    printf("\n");
}
