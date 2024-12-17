#include <stdio.h>
#include <pico/stdlib.h>
#include "global.h"

int main() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (1) {
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_PIN, 0);
        sleep_ms(500);

        // Busy wait for jitter measurement
        for (volatile int i = 0; i < 100000; i++);
    }
    return 0;
}