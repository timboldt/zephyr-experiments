/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
// #define LED2_NODE DT_ALIAS(led2)
// #define LED3_NODE DT_ALIAS(led3)

#define LED0	DT_GPIO_LABEL(LED0_NODE, gpios)
#define LED1	DT_GPIO_LABEL(LED1_NODE, gpios)
// #define LED2	DT_GPIO_LABEL(LED2_NODE, gpios)
// #define LED3	DT_GPIO_LABEL(LED3_NODE, gpios)

#define PIN0	DT_GPIO_PIN(LED0_NODE, gpios)
#define PIN1	DT_GPIO_PIN(LED1_NODE, gpios)
// #define PIN2	DT_GPIO_PIN(LED2_NODE, gpios)
// #define PIN3	DT_GPIO_PIN(LED3_NODE, gpios)

#define FLAGS0	DT_GPIO_FLAGS(LED0_NODE, gpios)
#define FLAGS1	DT_GPIO_FLAGS(LED1_NODE, gpios)
// #define FLAGS2	DT_GPIO_FLAGS(LED2_NODE, gpios)
// #define FLAGS3	DT_GPIO_FLAGS(LED3_NODE, gpios)

void main(void)
{
	const struct device *dev;
	bool led_is_on = true;
	int ret;

	dev = device_get_binding(LED0);
	if (dev == NULL) {
		return;
	}

	ret = gpio_pin_configure(dev, PIN0, GPIO_OUTPUT_ACTIVE | FLAGS0);
	if (ret < 0) {
		return;
	}
	ret = gpio_pin_configure(dev, PIN1, GPIO_OUTPUT_ACTIVE | FLAGS1);
	if (ret < 0) {
		return;
	}
	// ret = gpio_pin_configure(dev, PIN2, GPIO_OUTPUT_ACTIVE | FLAGS2);
	// if (ret < 0) {
	// 	return;
	// }
	// ret = gpio_pin_configure(dev, PIN3, GPIO_OUTPUT_ACTIVE | FLAGS3);
	// if (ret < 0) {
	// 	return;
	// }

	while (1) {
		gpio_pin_set(dev, PIN0, (int)led_is_on);
		k_msleep(SLEEP_TIME_MS);
		gpio_pin_set(dev, PIN1, (int)led_is_on);
		k_msleep(SLEEP_TIME_MS);
		// gpio_pin_set(dev, PIN2, (int)led_is_on);
		// k_msleep(SLEEP_TIME_MS);
		// gpio_pin_set(dev, PIN3, (int)led_is_on);
		// k_msleep(SLEEP_TIME_MS);
		led_is_on = !led_is_on;
	}
}