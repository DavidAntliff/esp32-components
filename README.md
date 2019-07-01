# esp32-components

The top-level project for my ESP32 components.

## Design

https://github.com/DavidAntliff/esp32-components/wiki/Component-Design

## Components

### General

#### Utilities

https://github.com/DavidAntliff/esp32-utils

### Interfaces

#### 1-Wire Bus

https://github.com/DavidAntliff/esp32-owb

#### SMBus

https://github.com/DavidAntliff/esp32-smbus

### Devices

#### DS18B20 1-Wire Digital Thermometer

https://github.com/DavidAntliff/esp32-ds18b20

https://github.com/DavidAntliff/esp32-ds18b20-example

#### TSL2561 Ambient Light Sensor

https://github.com/DavidAntliff/esp32-tsl2561

https://github.com/DavidAntliff/esp32-tsl2561-example

#### HD44780-Compatible 16x2 Character LCD

https://github.com/DavidAntliff/esp32-i2c-lcd1602

https://github.com/DavidAntliff/esp32-i2c-lcd1602-example

Also works with the "2004" version - four rows of twenty characters each.

#### Incremental Rotary Encoders

https://github.com/DavidAntliff/esp32-rotary-encoder

https://github.com/DavidAntliff/esp32-rotary-encoder-example

Reliable debouncing driver for generating position change events for incremental rotary encoders such as the EC11 and LPD series (e.g. LPD3806).

### Applications

#### Digitally Controlled Oscillator

Makes use of the RMT or LED PWM peripherals to accurately construct a clock signal of the specified frequency. Supports frequency ranges from < 1 Hz up to > 10 MHz.

https://github.com/DavidAntliff/esp32-dco

#### Frequency Counter

Determine the average frequency of an incoming clock signal. Accuracy is determined by sampling duration.

https://github.com/DavidAntliff/esp32-freqcount

https://github.com/DavidAntliff/esp32-freqcount-example

#### Christmas Lights

Pretty SPI-controlled LED lights with numerous patterns and colour fades. Intended for use with APA102 or SK9822 LED strips. Remote control is provided over MQTT, and with a bit of configuration the lights can be controlled via TouchOSC on an iPhone or iPad.

https://github.com/DavidAntliff/esp32-xmas

#### Pool Control & Monitoring

An application for the monitoring of a swimming pool solar heating system, consisting of an ESP32, five DS18B20 temperature sensors, a TSL2561 light sensor, a ATtiny84 I2C slave for switch logic and pump control, a 16x2 Character LCD, and MQTT communications to a Raspberry Pi running a TICK stack with Grafana for time series visualisation.

https://github.com/DavidAntliff/esp32-poolmon

#### I2C Communication with an AVR Slave

#### AVR I2C

An application to enable sending commands and receiving status from an AVR I2C slave device. This was a precursor to the code found in Pool Control & Monitoring above.

https://github.com/DavidAntliff/esp32-avr-i2c
