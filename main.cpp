#include "mbed.h"

#define USER_BUTTON PC_13

InterruptIn button(USER_BUTTON);

EventQueue queue;

void handle_button_press() {
    printf("Button pressed\n");
}

// Interrupt handler function
void button_pressed() {
    queue.call(handle_button_press);
}

int main() {
    // Attach the interrupt handler to the button press event
    button.fall(&button_pressed);

    // Dispatch events in the queue forever in the main thread
    queue.dispatch_forever();

    while (1) {
        
    }
}
