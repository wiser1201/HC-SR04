# HC-SR04 Driver

Cross-platform driver for the HC-SR04 ultrasonic distance sensor.
Distance range is 2 - 400 cm, accuracy is 0.3 cm;
MCU with two GPIO and frequency at least 16 MHz is required;

# HC-SR04 Integration

User must implement a couple of platform-specific functions:

extern void sr_trig_echo_config(void);

extern void sr_trig_write(const bool level);

extern bool sr_echo_read(void);

extern uint32_t ex_time_us(void);

One of the GPIO must be input (echo pin), another one is output (trigger);
sr_trig_echo_config function must implement configuration for these pins.
ex_time_us must return current time in us. It's used for delay and distance
calculations.
The folder "examples" contains the configuration example for STM.