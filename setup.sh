#!/bin/bash

sudo insmod driver/Nokia5110_LCD/gpio_lcd5110.ko
sudo mknod /dev/gpio_5110 c 61 0
sudo chmod a+rw /dev/gpio_5110
sudo chmod a+rw /sys/gpio_lcd5110/gpio_lcd5110/data_mode
sudo chmod a+rw /sys/gpio_lcd5110/gpio_lcd5110/state_mode
sudo echo "i" > /sys/gpio_lcd5110/gpio_lcd5110/data_mode
sudo echo "a" > /sys/gpio_lcd5110/gpio_lcd5110/state_mode

sudo insmod driver/Button/button_ctl.ko

