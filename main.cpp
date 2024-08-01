#include "mbed.h"

#define USER_BUTTON PC_13

InterruptIn button(USER_BUTTON);

void button_pressed() {
    printf("Button pressed\n");
}

int main() {
    
    button.fall(&button_pressed);

    while (1) {
        // Do nothing, waiting for the interrupt
    }
}
