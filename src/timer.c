#include <stdio.h>
#include <pico/stdlib.h>
#include "hardware/timer.h"
#include <pico/sync.h>
#include "global.h"

static volatile bool toggle_flag = false;

bool timer_callback(struct repeating_timer *t) {
    toggle_flag = !toggle_flag;
    gpio_put(LED_PIN, toggle_flag);

    // Busy wait for jitter measurement
    for (volatile int i = 0; i < 100000; i++);
    return true;
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    struct repeating_timer timer;
    add_repeating_timer_ms(500, timer_callback, NULL, &timer);

    while (1) {
        tight_loop_contents();
    }
    return 0;
}
