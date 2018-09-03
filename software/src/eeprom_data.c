/* hat-bricklet
 * Copyright (C) 2018 Olaf Lüke <olaf@tinkerforge.com>
 *
 * eeprom_data.c: Data for EEPROM Emulation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <stdint.h>

// We use the following .dts file to create the overlay for the HAT:

/*******************************************************************************

/dts-v1/;
/plugin/;

/ {
	compatible = "brcm,bcm2835", "brcm,bcm2836", "brcm,bcm2708", "brcm,bcm2709";

    fragment@0
    {
        target = <&spi0>;
        __overlay__
        {
            status = "okay";
            pinctrl-0 = <&spi0_pins>;

            spidev@0
            {
                status = "okay";
                compatible = "spidev";
                spi-max-frequency = <1400000>;
            };

            spidev@1
            {
                status = "disabled";
            };
        };
	};
};

*******************************************************************************/

// The overlay is compiled with
//   #!/bin/bash
//   dtc -@ -I dts -O dtb -o spi.dtb spi.dts
//   eepmake eeprom_settings.txt hat_bricklet.eep spi.dtb

// and the eepom_data array is created with:
//   #!/usr/bin/env python
//   print('const uint8_t eeprom_data[] = ' + str(map(ord, open('hat_bricklet.eep').read())).replace('[', '{').replace(']', '}') + ';')

const uint8_t eeprom_data[] = {82, 45, 80, 105, 1, 0, 3, 0, 130, 2, 0, 0, 1, 0, 0, 0, 52, 0, 0, 0, 193, 47, 209, 112, 1, 230, 210, 164, 239, 71, 47, 65, 101, 51, 96, 183, 78, 8, 1, 0, 16, 12, 84, 105, 110, 107, 101, 114, 102, 111, 114, 103, 101, 32, 71, 109, 98, 72, 72, 65, 84, 32, 66, 114, 105, 99, 107, 108, 101, 116, 34, 236, 2, 0, 1, 0, 32, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 161, 161, 161, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 161, 161, 161, 161, 161, 161, 174, 215, 3, 0, 2, 0, 10, 2, 0, 0, 208, 13, 254, 237, 0, 0, 2, 8, 0, 0, 0, 56, 0, 0, 1, 196, 0, 0, 0, 40, 0, 0, 0, 17, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0, 1, 140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 52, 0, 0, 0, 0, 98, 114, 99, 109, 44, 98, 99, 109, 50, 56, 51, 53, 0, 98, 114, 99, 109, 44, 98, 99, 109, 50, 56, 51, 54, 0, 98, 114, 99, 109, 44, 98, 99, 109, 50, 55, 48, 56, 0, 98, 114, 99, 109, 44, 98, 99, 109, 50, 55, 48, 57, 0, 0, 0, 0, 1, 102, 114, 97, 103, 109, 101, 110, 116, 64, 48, 0, 0, 0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0, 11, 222, 173, 190, 239, 0, 0, 0, 1, 95, 95, 111, 118, 101, 114, 108, 97, 121, 95, 95, 0, 0, 0, 0, 3, 0, 0, 0, 5, 0, 0, 0, 18, 111, 107, 97, 121, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0, 25, 222, 173, 190, 239, 0, 0, 0, 1, 115, 112, 105, 100, 101, 118, 64, 48, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 5, 0, 0, 0, 18, 111, 107, 97, 121, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 7, 0, 0, 0, 0, 115, 112, 105, 100, 101, 118, 0, 0, 0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0, 35, 0, 21, 92, 192, 0, 0, 0, 2, 0, 0, 0, 1, 115, 112, 105, 100, 101, 118, 64, 49, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 9, 0, 0, 0, 18, 100, 105, 115, 97, 98, 108, 101, 100, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1, 95, 95, 102, 105, 120, 117, 112, 115, 95, 95, 0, 0, 0, 0, 0, 3, 0, 0, 0, 21, 0, 0, 0, 53, 47, 102, 114, 97, 103, 109, 101, 110, 116, 64, 48, 58, 116, 97, 114, 103, 101, 116, 58, 48, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 36, 0, 0, 0, 58, 47, 102, 114, 97, 103, 109, 101, 110, 116, 64, 48, 47, 95, 95, 111, 118, 101, 114, 108, 97, 121, 95, 95, 58, 112, 105, 110, 99, 116, 114, 108, 45, 48, 58, 48, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 9, 99, 111, 109, 112, 97, 116, 105, 98, 108, 101, 0, 116, 97, 114, 103, 101, 116, 0, 115, 116, 97, 116, 117, 115, 0, 112, 105, 110, 99, 116, 114, 108, 45, 48, 0, 115, 112, 105, 45, 109, 97, 120, 45, 102, 114, 101, 113, 117, 101, 110, 99, 121, 0, 115, 112, 105, 48, 0, 115, 112, 105, 48, 95, 112, 105, 110, 115, 0, 195, 69};