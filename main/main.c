/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN = 5;
const int BTN_PIN = 4;

// Definir os pinos do motor de passo
const int IN1_PIN = 15;
const int IN2_PIN = 14;
const int IN3_PIN = 16;
const int IN4_PIN = 17;

int main() {
    int isOn = 0;
    int isOn1 = 0;
    int isOn2 = 0;
    int isOn3 = 0;
    int isOn4 = 0;

    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    // Inicialização dos pinos do motor de passo
    gpio_init(IN1_PIN);
    gpio_set_dir(IN1_PIN, GPIO_OUT);
    gpio_init(IN2_PIN);
    gpio_set_dir(IN2_PIN, GPIO_OUT);
    gpio_init(IN3_PIN);
    gpio_set_dir(IN3_PIN, GPIO_OUT);
    gpio_init(IN4_PIN);
    gpio_set_dir(IN4_PIN, GPIO_OUT);

    while (true) {
    if (!gpio_get(BTN_PIN)) {
        isOn = !isOn;
        gpio_put(LED_PIN, isOn);
        sleep_ms(300);
        
      while (!gpio_get(BTN_PIN)) {
        // Aguarda até que o botão seja solto
      };
    }
    
    if (isOn) {
      for (int i = 0; i < 512; i++) {
        if (isOn1 == 0) {
          isOn1 = !isOn1;
          gpio_put(IN1_PIN, isOn1);
          sleep_ms(10);
        
          if (isOn2 == 0) {
            isOn1 = !isOn1;
            isOn2 = !isOn2;

            gpio_put(IN1_PIN, isOn1);
            gpio_put(IN2_PIN, isOn2);

            sleep_ms(10);

            if (isOn3 == 0) {
              isOn2 = !isOn2;
              isOn3 = !isOn3;

              gpio_put(IN2_PIN, isOn2);
              gpio_put(IN3_PIN, isOn3);

              sleep_ms(10);

              if (isOn4 == 0) {
                isOn3 = !isOn3;
                isOn4 = !isOn4;

                gpio_put(IN3_PIN, isOn3);
                gpio_put(IN4_PIN, isOn4);

                sleep_ms(10);

                isOn4 = 0;
                gpio_put(IN4_PIN, isOn4);
                sleep_ms(10);
              }
            }
          }
        }
      }

    isOn = !isOn;
    sleep_ms(300);
    }
  }
}
