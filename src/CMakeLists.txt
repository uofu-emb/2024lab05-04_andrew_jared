# This is the main binary. List your C files here.
add_executable(task_delay
    task_delay.c
    rtc.c
    sleep.c
    timer.c
    gpio_interrupt.c
    )
# Building Task Delay 
# Modify the below lines to enable/disable output over UART/USB.
pico_enable_stdio_uart(task_delay 0)
pico_enable_stdio_usb(task_delay 1)
target_link_libraries(task_delay PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)
pico_add_extra_outputs(task_delay)
add_custom_target(flash_delay picotool load -f $<TARGET_FILE:task_delay> DEPENDS task_delay)

#Building rtc
pico_enable_stdio_uart(rtc 0)
pico_enable_stdio_usb(rtc 1)
target_link_libraries(rtc PRIVATE
  pico_stdlib
  hardware_rtc
  pico_cyw43_arch_none
)
pico_add_extra_outputs(rtc)
add_custom_target(flash_delay picotool load -f $<TARGET_FILE:rtc> DEPENDS rtc)

#Building Sleep
pico_enable_stdio_uart(sleep 0)
pico_enable_stdio_usb(sleep 1)
target_link_libraries(sleep PRIVATE
  pico_stdlib
)
pico_add_extra_outputs(sleep)
add_custom_target(flash_delay picotool load -f $<TARGET_FILE:sleep> DEPENDS sleep)

#Building Timer
pico_enable_stdio_uart(timer 0)
pico_enable_stdio_usb(timer 1)
target_link_libraries(timer PRIVATE
  pico_stdlib
)
pico_add_extra_outputs(timer)
add_custom_target(flash_delay picotool load -f $<TARGET_FILE:timer> DEPENDS timer)

#Building gpio_interrupt
pico_enable_stdio_uart(gpio_interrupt 0)
pico_enable_stdio_usb(gpio_interrupt 1)
target_link_libraries(gpio_interrupt PRIVATE
  pico_stdlib
)
pico_add_extra_outputs(gpio_interrupt)
add_custom_target(flash_delay picotool load -f $<TARGET_FILE:gpio_interrupt> DEPENDS gpio_interrupt)


# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
# if(PICO_CYW43_SUPPORTED)
#     # For led support on pico_w
#     target_link_libraries(task_delay PRIVATE
#         pico_cyw43_arch_none
#     )
# endif()
