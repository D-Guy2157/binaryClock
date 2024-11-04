#include "clock.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Helper function to display the menu
void display_menu() {
    printf("\n--- Binary Clock Menu ---\n");
    printf("1. Set time (hours, minutes, seconds)\n");
    printf("2. Set time using binary (H:5, M:6, S:6)\n");
    printf("3. Increment time by one second\n");
    printf("4. Decrement time by one second\n");
    printf("5. Display time (standard and binary)\n");
    printf("6. Exit\n");
    printf("7. Start the automatic clock\n");
    printf("Enter your choice: ");
}

// Function to read binary input as binary not just ints.
uint32_t get_binary_input() {
    char binary_str[20];
    uint32_t binary_value = 0;

    printf("Enter a 17-bit binary number (HHHHHMMMMMMSSSSSS or HHHHH MMMMMM SSSSSS): ");
    scanf(" %19[^\n]", binary_str);

    // Check if input contains spaces
    if (strchr(binary_str, ' ') != NULL) {
        int hours, minutes, seconds;
        char hour_str[6], minute_str[7], second_str[7];

        if (sscanf(binary_str, "%5s %6s %6s", hour_str, minute_str, second_str) == 3) {
            hours = strtol(hour_str, NULL, 2);
            minutes = strtol(minute_str, NULL, 2);
            seconds = strtol(second_str, NULL, 2);
            
            binary_value = (hours << 12) | (minutes << 6) | seconds;
        } else {
            printf("Invalid input format. Please use either HHHHHMMMMMMSSSSSS or HHHHH MMMMMM SSSSSS.\n");
            return 0;
        }
    } else {
        for (int i = 0; i < 17; i++) {
            if (binary_str[i] != '0' && binary_str[i] != '1') {
                printf("Invalid binary input.\n");
                return 0;
            }
            binary_value = (binary_value << 1) | (binary_str[i] - '0');
        }
    }

    return binary_value;
}

void automatic_clock(clock_t *cloc) {
    while (1) {
        clear_screen();
        display_time(cloc);
        display_binary(cloc);

        increment_time(cloc);

        sleep(1);
    }
}

int main() {
    clock_t myClock;
    int choice;
    uint8_t hours, minutes, seconds;
    uint32_t binary_time;

    init_clock(&myClock);

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter hours (0-23): ");
                scanf("%hhu", &hours);
                printf("Enter minutes (0-59): ");
                scanf("%hhu", &minutes);
                printf("Enter seconds (0-59): ");
                scanf("%hhu", &seconds);
                set_time(&myClock, hours, minutes, seconds);
                clear_screen();
                
                printf("Time set to: ");
                display_time(&myClock);
                break;

            case 2:
                binary_time = get_binary_input();
                set_binary(&myClock, binary_time);
                clear_screen();

                printf("Time set using binary input: ");
                display_time(&myClock);
                break;
            
            case 3:
                increment_time(&myClock);
                clear_screen();

                printf("Time after incrementing: ");
                display_time(&myClock);
                display_binary(&myClock);
                break;

            case 4:
                decrement_time(&myClock);
                clear_screen();

                printf("Time after decrementing: ");
                display_time(&myClock);
                display_binary(&myClock);
                break;

            case 5:
                clear_screen();

                printf("Current time: ");
                display_time(&myClock);
                printf("Binary representation: ");
                display_binary(&myClock);
                break;

            case 6:
                clear_screen();

                printf("Exiting program.\n");
                exit(0);
                break;

            case 7:
                automatic_clock(&myClock);
                break;

            default:
                clear_screen();
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}