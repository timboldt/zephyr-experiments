# Find Zephyr. This also loads Zephyr's build system.
cmake_minimum_required(VERSION 3.13.1)

# set(BOARD nrf52840dk_nrf52840)
set(BOARD adafruit_feather_nrf52840)

find_package(Zephyr)
project(zephyr-experiment)

# Add your source file to the "app" target. This must come after
# find_package(Zephyr) which defines the target.
target_sources(app PRIVATE src/main.c)