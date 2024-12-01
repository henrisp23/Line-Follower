#include <Arduino.h>
#include "MotorControl.h"

int a = 0; // Variabel untuk menyimpan arah belokan terakhir

void setup() {
    // Inisialisasi pin motor dan sensor
    pinMode(m1, OUTPUT);
    pinMode(m2, OUTPUT);
    pinMode(m3, OUTPUT);
    pinMode(m4, OUTPUT);
    pinMode(12, INPUT); // Sensor kiri
    pinMode(13, INPUT); // Sensor kanan
}

void loop() {
    // Membaca data dari sensor kiri dan kanan
    int lsensor = digitalRead(12);
    int rsensor = digitalRead(13);

    if ((lsensor == LOW) && (rsensor == HIGH)) {
        // Belok kanan: motor kiri lebih cepat dari motor kanan
        motorOut(100, 40, 2);
        a = 1; // Set arah terakhir menjadi kanan
    }
    else if ((lsensor == HIGH) && (rsensor == LOW)) {
        // Belok kiri: motor kanan lebih cepat dari motor kiri
        motorOut(40, 100, 2);
        a = 2; // Set arah terakhir menjadi kiri
    }
    else if ((lsensor == HIGH) && (rsensor == HIGH)) {
        // Kedua sensor mendeteksi garis, robot maju lurus
        motorOut(100, 100, 2);
    }
    else if ((lsensor == LOW) && (rsensor == LOW)) {
        // Kedua sensor tidak mendeteksi garis, robot mengikuti arah terakhir
        if (a == 1) {
            motorOut(40, 0, 2); // Jika terakhir belok kanan, belok kanan lebih tajam
        }
        else if (a == 2) {
            motorOut(0, 40, 2); // Jika terakhir belok kiri, belok kiri lebih tajam
        }
    }
}
