#include "main.h"
#include "hc_sr04.h"
#include <stdint.h>
#include <stdbool.h>

#define TRIG_PORT GPIOA
#define TRIG_PIN GPIO_PIN_8
#define ECHO_PORT GPIOA
#define ECHO_PIN GPIO_PIN_10

void sr_trig_echo_config(void);
void sr_trig_write(const bool level);
bool sr_echo_read(void);

void sr_trig_echo_config(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef gpio = {0};
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pin = TRIG_PIN;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(TRIG_PORT, &gpio);

    gpio.Mode = GPIO_MODE_INPUT;
    gpio.Pin = ECHO_PIN;
    gpio.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(ECHO_PORT, &gpio);
}

void sr_trig_write(const bool level)
{
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, level);
}

bool sr_echo_read(void)
{
    return HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN);
}

uint32_t ex_time_us(void)
{
    return time_us();
}