#include "clock.h"

int main() {
    clock_t myClock;

    init_clock(&myClock, 12, 34, 56);
    printf("Inital time: ");
    display_time(&myClock);

    increment_time(&myClock);
    printf("After increment: ");
    display_time(&myClock);

    decrement_time(&myClock);
    printf("After decrement: ");
    display_time(&myClock);

    return 0;
}