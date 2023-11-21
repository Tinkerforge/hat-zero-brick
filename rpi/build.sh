#!/bin/bash

rm hat_zero_brick.eep spi.dtb
rm ../software/src/eeprom_data.c

dtc -@ -I dts -O dtb -o spi.dtb spi.dts
eepmake eeprom_settings.txt hat_zero_brick.eep spi.dtb

python3 create_eeprom_data_c.py
