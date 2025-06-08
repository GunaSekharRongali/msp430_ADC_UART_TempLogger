#include "keypad.h"
#include <msp430.h>

const char keymap[4][4] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

void Keypad::init() {
    // P2.0 to P2.3 as output (rows), P2.4 to P2.7 as input (columns)
    P2DIR |= 0x0F;  // P2.0-P2.3 output
    P2DIR &= ~0xF0; // P2.4-P2.7 input
    P2OUT = 0x0F;   // Rows high initially
    P2REN |= 0xF0;  // Enable pull-up/down
    P2OUT |= 0xF0;  // Pull-up for columns
}

char Keypad::getKey() {
    for (int row = 0; row < 4; ++row) {
        P2OUT = ~(1 << row);  // Drive one row low at a time

        __delay_cycles(2000);  // Small delay for signal to settle

        for (int col = 0; col < 4; ++col) {
            if (!(P2IN & (1 << (col + 4)))) {  // Check if column pin is low
                while (!(P2IN & (1 << (col + 4))));  // Wait for release
                return keymap[row][col];
            }
        }
    }
    return 0;  // No key pressed
}
