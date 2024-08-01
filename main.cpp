#include "mbed.h"

InterruptIn button(PA_13,PullUp);

// Flag variable
volatile bool button_flag = false;

// Interrupt function
void button_pressed() {
    button_flag = true;
}

int main() {
    
    button.fall(&button_pressed);

    // Main loop
    while (1) {
        if (button_flag) {
            printf("Button pressed\n");
            button_flag = false;
        }
    }
}
