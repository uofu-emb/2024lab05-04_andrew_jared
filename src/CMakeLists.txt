# Define Task Delay executable
add_executable(task_delay
    task_delay.c
)

target_link_libraries(task_delay PRIVATE
    pico_stdlib
    pico_multicore
    FreeRTOS-Kernel-Heap4
)

pico_enable_stdio_uart(task_delay 0)
pico_enable_stdio_usb(task_delay 1)
pico_add_extra_outputs(task_delay)

# Define RTC executable with conditional CYW43 support
add_executable(rtc
    rtc.c
)

target_link_libraries(rtc PRIVATE
    pico_stdlib
    hardware_rtc
)

# Conditional CYW43 library inclusion
if (PICO_CYW43_SUPPORTED)
    target_link_libraries(rtc PRIVATE pico_cyw43_arch_none)
endif()

pico_enable_stdio_uart(rtc 0)
pico_enable_stdio_usb(rtc 1)
pico_add_extra_outputs(rtc)

# Define Sleep executable
add_executable(sleep
    sleep.c
)

target_link_libraries(sleep PRIVATE
    pico_stdlib
)

pico_enable_stdio_uart(sleep 0)
pico_enable_stdio_usb(sleep 1)
pico_add_extra_outputs(sleep)

# Define Timer executable
add_executable(timer
    timer.c
)

target_link_libraries(timer PRIVATE
    pico_stdlib
)

pico_enable_stdio_uart(timer 0)
pico_enable_stdio_usb(timer 1)
pico_add_extra_outputs(timer)

# Define GPIO Interrupt executable
add_executable(gpio_interrupt
    gpio_interrupt.c
)

target_link_libraries(gpio_interrupt PRIVATE
    pico_stdlib
    hardware_gpio
)

pico_enable_stdio_uart(gpio_interrupt 0)
pico_enable_stdio_usb(gpio_interrupt 1)
pico_add_extra_outputs(gpio_interrupt)
