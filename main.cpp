 MbedOS Error Info
Error Status: 0x80010133 Code: 307 Module: 1
Error Message: Mutex: 0x200015FC, Not allowed in ISR context
Location: 0x800934D
Error Value: 0x200015FC



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