#include <Arduino.h>
#include <avr/io.h>
#include "pwm.h"
#include "adc.h"
#include "timer.h"
#include "switch.h"
#include "segment.h"
#include <avr/interrupt.h>

/*
 * Define a set of states that can be used in the state machine using an enum.
 */
typedef enum stateEnum{
    wait_press,
    debounce_press,
    wait_release,
    debounce_release
  } stateType;
