#include <stdio.h>
#include <pico/stdlib.h>
#include <FreeRTOS.h>
#include "task.h"
#include <task.h>
#include "global.h"

void task_delay_loop(void *params) {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (1) {
        gpio_put(LED_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(500));  // 500ms delay
        gpio_put(LED_PIN, 0);
        vTaskDelay(pdMS_TO_TICKS(500));

        // Busy wait for jitter measurement
        for (volatile int i = 0; i < 100000; i++); 
    }
}

int main() {
    stdio_init_all();
    xTaskCreate(task_delay_loop, "TaskDelay", 256, NULL, 1, NULL);
    vTaskStartScheduler();
    while (1);  // Safety loop
    return 0;
}