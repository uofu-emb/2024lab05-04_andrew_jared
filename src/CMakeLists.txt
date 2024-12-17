# Define task_delay executable
add_executable(task_delay
    task_delay.c
    rtc.c
    sleep.c
    timer.c
    gpio_interrupt.c
)

pico_enable_stdio_uart(task_delay 0)
pico_enable_stdio_usb(task_delay 1)

target_link_libraries(task_delay PRIVATE
    pico_stdlib
    pico_multicore
    pico_async_context_freertos
    FreeRTOS-Kernel-Heap4
    hardware_rtc
)

pico_add_extra_outputs(task_delay)
add_custom_target(flash_task_delay ALL
    COMMAND picotool load -f $<TARGET_FILE:task_delay>
    DEPENDS task_delay)

# Define rtc executable
add_executable(rtc
    rtc.c
)

pico_enable_stdio_uart(rtc 0)
pico_enable_stdio_usb(rtc 1)

target_link_libraries(rtc PRIVATE
    pico_stdlib
    hardware_rtc
    pico_cyw43_arch_none
)

pico_add_extra_outputs(rtc)
add_custom_target(flash_rtc ALL
    COMMAND picotool load -f $<TARGET_FILE:rtc>
    DEPENDS rtc)

# Define sleep executable
add_executable(sleep
    sleep.c
)

pico_enable_stdio_uart(sleep 0)
pico_enable_stdio_usb(sleep 1)

target_link_libraries(sleep PRIVATE
    pico_stdlib
)

pico_add_extra_outputs(sleep)
add_custom_target(flash_sleep ALL
    COMMAND picotool load -f $<TARGET_FILE:sleep>
    DEPENDS sleep)

# Define timer executable
add_executable(timer
    timer.c
)

pico_enable_stdio_uart(timer 0)
pico_enable_stdio_usb(timer 1)

target_link_libraries(timer PRIVATE
    pico_stdlib
)

pico_add_extra_outputs(timer)
add_custom_target(flash_timer ALL
    COMMAND picotool load -f $<TARGET_FILE:timer>
    DEPENDS timer)

# Define gpio_interrupt executable
add_executable(gpio_interrupt
    gpio_interrupt.c
)

pico_enable_stdio_uart(gpio_interrupt 0)
pico_enable_stdio_usb(gpio_interrupt 1)

target_link_libraries(gpio_interrupt PRIVATE
    pico_stdlib
    hardware_gpio
)

pico_add_extra_outputs(gpio_interrupt)
add_custom_target(flash_gpio_interrupt ALL
    COMMAND picotool load -f $<TARGET_FILE:gpio_interrupt>
    DEPENDS gpio_interrupt)
