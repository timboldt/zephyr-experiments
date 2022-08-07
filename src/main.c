/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/zephyr.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_MS   1000

#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)

static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);

void main(void)
{
	int ret;

	if (!device_is_ready(led0.port)) {
		return;
	}
	if (!device_is_ready(led1.port)) {
		return;
	}

	ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return;
	}
	ret = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return;
	}

	ret = gpio_pin_toggle_dt(&led0);
	if (ret < 0) {
		return;
	}
	while (1) {
		ret = gpio_pin_toggle_dt(&led0);
		if (ret < 0) {
			return;
		}
		ret = gpio_pin_toggle_dt(&led1);
		if (ret < 0) {
			return;
		}
		k_msleep(SLEEP_TIME_MS);
	}
}
