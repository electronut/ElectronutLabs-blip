/*
 * Copyright (c) 2019 Tavish Naruka <tavishnaruka@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <gpio.h>

struct led_s
{
	char *controller;
	int pin;
	struct device *dev;
};

static struct led_s blip_leds[] = {
	{LED0_GPIO_CONTROLLER, LED0_GPIO_PIN, NULL},
	{LED1_GPIO_CONTROLLER, LED1_GPIO_PIN, NULL},
	{LED2_GPIO_CONTROLLER, LED2_GPIO_PIN, NULL},
};

void blink()
{
	while(1) {
		for(int i=0; i<ARRAY_SIZE(blip_leds); i++) {
			gpio_pin_write(blip_leds[i].dev, blip_leds[i].pin, 0);
			k_sleep(5);
			gpio_pin_write(blip_leds[i].dev, blip_leds[i].pin, 1);
			k_sleep(2000);
		}
	}
}

void main(void)
{
	/* set LEDs to output */
	for(int i=0; i<ARRAY_SIZE(blip_leds); i++)
	{
		blip_leds[i].dev = device_get_binding(blip_leds[i].controller);
		gpio_pin_configure(blip_leds[i].dev, blip_leds[i].pin, 
			GPIO_DIR_OUT);
		gpio_pin_write(blip_leds[i].dev, blip_leds[i].pin, 1);
	}

	while (1) {
		k_sleep(K_FOREVER);
	}
}

K_THREAD_DEFINE(blink_id, 512, blink, NULL, NULL, NULL, 7, 0, K_NO_WAIT);