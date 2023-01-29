/*
 * Copyright © 2011 Stéphane Raimbault <stephane.raimbault@gmail.com>
 *
 * License ISC, see LICENSE for more details.

 * This library implements the Modbus protocol.
 * http://libmodbus.org/
 *
 */

#ifndef Modbusino_h
#define Modbusino_h

#include <inttypes.h>
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif

#define MODBUS_BROADCAST_ADDRESS 0

/* Protocol exceptions */
#define MODBUS_EXCEPTION_ILLEGAL_FUNCTION     1
#define MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS 2
#define MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE   3
#define MODBUS_INFORMATIVE_NOT_FOR_US   4
#define MODBUS_INFORMATIVE_RX_TIMEOUT   5


class ModbusinoSlave {
private:
    typedef void (*forward_t)(uint8_t *msg, uint8_t msg_length);
public:
    ModbusinoSlave(uint8_t slave, forward_t forward_func = NULL);
    void setup(long baud);
    int loop(uint16_t *tab_reg, uint16_t nb_reg);
private:
    int _slave;
    forward_t _forward_func;
};

#endif
