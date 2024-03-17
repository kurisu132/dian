#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "sdkconfig.h"

void UART_Init(void);

void app_main(void)
{
    UART_Init();

    static char *test = "Hello World!";

    while(1)
    {
        uart_write_bytes(UART_NUM_0, test, 12);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void UART_Init(void)
{
    uart_config_t uart_sturct= 
    {
    .baud_rate = 9600,
    .data_bits = UART_DATA_8_BITS,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    .parity = UART_PARITY_DISABLE,
    .source_clk = UART_SCLK_APB,
    .stop_bits = UART_STOP_BITS_1,
    };
    uart_param_config(UART_NUM_0, &uart_sturct);
    uart_driver_install(UART_NUM_0, 2048, 0, 0, NULL, 0);
    uart_set_pin(UART_NUM_0, GPIO_NUM_4, GPIO_NUM_5, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}
