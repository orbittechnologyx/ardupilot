# ORBITF405 Flight Controller

The ORBITF405 is a flight controller produced by [ORBIT Technology](http://www.orbitteknoloji.com.tr/).

## Features

 - STM32F405 microcontroller
 - ICM42688 IMU
 - DPS310 or SPL06 barometer
 - SDCard
 - On board 128Mbit FRAM
 - AT7456E OSD
 - 6 UARTs
 - 9 PWM outputs

## Pinout
TODO

## UART Mapping

The UARTs are marked Rn and Tn in the above pinouts. The Rn pin is the
receive pin for UARTn. The Tn pin is the transmit pin for UARTn.

 - SERIAL0 -> USB
 - SERIAL1 -> UART1 (DJI VTX, DMA-enabled)
 - SERIAL2 -> UART2 (RC input, DMA-enabled) 
 - SERIAL3 -> UART3 (Telemetry - FPV CAM)
 - SERIAL4 -> UART4 (Telemetry)
 - SERIAL5 -> UART5 (ESC Telemetry)
 - SERIAL6 -> UART6 (GPS, DMA-enabled)

## RC Input

The default RC input is configured on the UART2. The SBUS pin is inverted and connected to R2 (UART2_RX). Non SBUS, single wire serial inputs can be directly tied to R2 if SBUS pin is left unconnected. RC could be applied instead at a different UART port such as UART1, UART3, UART4 or UART6, and set the protocol to receive RC data: `SERIALn_PROTOCOL=23` and change SERIAL2 _Protocol to something other than '23'
 
## FrSky Telemetry
 
FrSky Telemetry is supported using the Tx pin of any UART including SERIAL2/UART2. You need to set the following parameters to enable support for FrSky S.PORT (example shows SERIAL3).
 
  - SERIAL3_PROTOCOL 10
  - SERIAL3_OPTIONS 7
  
## OSD Support

The ORBITF405 supports OSD using OSD_TYPE 1 (MAX7456 driver).

## VTX Support

The JST-GH-6P connector supports a standard DJI HD VTX connection. Pin 1 of the connector is 9v so be careful not to connect this to a peripheral requiring 5V.

## PWM Output

The ORBITF405 supports up to 9 PWM outputs. The pads for motor output M1 to M4 on the motor connector, and M5 to M8 for a second motor connector, plus M9 for LED strip or another PWM output.

The PWM is in 5 groups:

 - PWM 1-2: Group 1
 - PWM 3,6: Group 2
 - PWM 4-5: Group 3
 - PWM 7-8: Group 4
 - PWM 9: Group 5

Channels within the same group need to use the same output rate. If
any channel in a group uses DShot then all channels in the group need
to use DShot. Channels 1-4 support bi-directional DShot.

## Battery Monitoring

The board has a internal voltage sensor and connections on the ESC connector for an external current sensor input.
The voltage sensor can handle up to 6S LiPo batteries.

The default battery parameters are:

 - BATT_MONITOR 4
 - BATT_VOLT_PIN 10
 - BATT_CURR_PIN 11
 - BATT_VOLT_MULT 10.2
 - BATT_AMP_PERVLT 52.7 (will need to be adjusted for whichever current sensor is attached)

## Compass

The ORBITF405 does not have a builtin compass, but you can attach an external compass using I2C on the SDA and SCL pads.

## Loading Firmware

Initial firmware load can be done with DFU by plugging in USB with the bootloader button pressed. Then you should load the "with_bl.hex" firmware, using your favourite DFU loading tool.

Once the initial firmware is loaded you can update the firmware using any ArduPilot ground station software. Updates should be done with the *.apj firmware files.
