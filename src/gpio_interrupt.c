#include <stdio.h>
#include <pico/stdlib.h>
#include <pico/sync.h>
#include "global.h"

int toggle = 1;
void gpio_callback(uint gpio, uint32_t events) {
    gpio_put(LED_PIN, !gpio_get(LED_PIN));  // Toggle LED

    // Busy wait for jitter measurement
    for (volatile int i = 0; i < 100000; i++);
}

int main() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0);

    gpio_init(INTERRUPT_PIN);
    gpio_set_dir(INTERRUPT_PIN, GPIO_IN);
    gpio_pull_down(INTERRUPT_PIN);

    gpio_set_irq_enabled_with_callback(INTERRUPT_PIN, GPIO_IRQ_EDGE_RISE, true, &gpio_callback);

    while (1) {
        tight_loop_contents();
    }
    return 0;
}