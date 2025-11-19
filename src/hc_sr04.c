#include "hc_sr04.h"
#include <stdbool.h>


#define HIGH 1
#define LOW 0

extern void sr_trig_echo_config(void);
extern void sr_trig_write(const bool level);
extern bool sr_echo_read(void);
extern uint32_t ex_time_us(void);

static void trigger(void);
static uint16_t trackEcho(void);
static uint16_t calculateDistance(const uint16_t echoTicks);

uint16_t hc_sr04_getDistance()
{
    sr_trig_echo_config();
    trigger();
    uint16_t time_us = trackEcho();
    uint16_t distance_cm = calculateDistance(time_us);
    return distance_cm;
}

void trigger(void)
{
    const uint32_t timeout = ex_time_us() + 10;
    sr_trig_write(HIGH);
    while (ex_time_us() < timeout) {}
    sr_trig_write(LOW);
}

uint16_t trackEcho(void)
{
    while (sr_echo_read() == LOW) {}
    const uint32_t start_us = ex_time_us();
    while (sr_echo_read() == HIGH) {}
    const uint32_t stop_us = ex_time_us();
    return stop_us - start_us;
}

uint16_t calculateDistance(const uint16_t time_us)
{
    const int ultrasonicSpeed = 58;
    return time_us / ultrasonicSpeed;
}