#!/bin/bash

rm hat_zero_brick.eep spi.dtb

dtc -@ -I dts -O dtb -o spi.dtb spi.dts
eepmake eeprom_settings.txt hat_zero_brick.eep spi.dtb
