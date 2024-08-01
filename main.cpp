#include "mbed.h"

// Define the button pin with pull-up mode
InterruptIn button(PA_13,PullUp);

// Flag variable
volatile bool button_flag = false;

// Interrupt function
void button_pressed() {
    button_flag = true;
}

int main() {
    // Attach the interrupt handler to the button press event
    button.fall(&button_pressed);

    // Main loop
    while (1) {
        if (button_flag) {
            printf("Button pressed\n");
            button_flag = false;
        }
    }
}
