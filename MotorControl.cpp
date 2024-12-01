#include "MotorControl.h"

void motorOut(unsigned char lpwm, unsigned char rpwm, int arrow) {
    // arrow = 1 untuk mundur, 2 untuk maju
    if (arrow == 1) {
        // Pengaturan untuk mundur
        digitalWrite(m3, HIGH);    // Motor kiri mundur
        digitalWrite(m1, LOW);     // Motor kanan mundur
        analogWrite(m4, 255 - lpwm);
        analogWrite(m2, rpwm);
    }
    else if (arrow == 2) {
        // Pengaturan untuk maju
        digitalWrite(m3, LOW);     // Motor kiri maju
        digitalWrite(m1, HIGH);    // Motor kanan maju
        analogWrite(m4, lpwm);
        analogWrite(m2, 255 - rpwm);
    }
}
