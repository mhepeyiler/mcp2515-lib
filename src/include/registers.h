#ifndef MCP2515_LIB_SRC_INCLUDE_REGISTERS_H
#define MCP2515_LIB_SRC_INCLUDE_REGISTERS_H

#ifdef __cplusplus
#include <cstdint>
extern "C" {
#else
#include <stdint.h>
#endif

enum Transmiters {

    /** TXnRTS Pin control and status register **/
    TXRTSCTRL = (uint8_t)0x0D,

    /** Transmit buffer control registers **/
    TXB0CTRL = (uint8_t)0x30,
    TXB1CTRL = (uint8_t)0x40,
    TXB2CTRL = (uint8_t)0x50,
    
    /** Transmit buffer n standard identifier register high **/
    TXB0SIDH = (uint8_t)0x31,
    TXB1SIDH = (uint8_t)0x41,
    TXB2SIDH = (uint8_t)0x51,

    /** Transmit buffer n standard identifier register low **/
    TXB0SIDL = (uint8_t)0x32,
    TXB1SIDL = (uint8_t)0x42,
    TXB2SIDL = (uint8_t)0x52,

    /** Transmit buffer n extended identifier 8 register high **/
    TXB0EID8 = (uint8_t)0x33,
    TXB1EID8 = (uint8_t)0x43,
    TXB2EID8 = (uint8_t)0x53,

    /** Transmit buffer n extended identifier 0 register low **/
    TXB0EID0 = (uint8_t)0x34,
    TXB1EID0 = (uint8_t)0x44,
    TXB2EID0 = (uint8_t)0x54,

    /** Transmit buffer n data length code register **/
    TXB0DLC = (uint8_t)0x35,
    TXB1DLC = (uint8_t)0x45,
    TXB2DLC = (uint8_t)0x55,

    /** Transmit buffer n data byte m register **/
    
    /* Buffer 0 */
    TXB0D0 = (uint8_t)0x36,
    TXB0D1 = (uint8_t)0x37,
    TXB0D2 = (uint8_t)0x38,
    TXB0D3 = (uint8_t)0x39,
    TXB0D4 = (uint8_t)0x3A,
    TXB0D5 = (uint8_t)0x3B,
    TXB0D6 = (uint8_t)0x3C,
    TXB0D7 = (uint8_t)0x3D,

    /* Buffer 1 */
    TXB1D0 = (uint8_t)0x46,
    TXB1D1 = (uint8_t)0x47,
    TXB1D2 = (uint8_t)0x48,
    TXB1D3 = (uint8_t)0x49,
    TXB1D4 = (uint8_t)0x4A,
    TXB1D5 = (uint8_t)0x4B,
    TXB1D6 = (uint8_t)0x4C,
    TXB1D7 = (uint8_t)0x4D,

    /* Buffer 2 */
    TXB2D0 = (uint8_t)0x56,
    TXB2D1 = (uint8_t)0x57,
    TXB2D2 = (uint8_t)0x58,
    TXB2D3 = (uint8_t)0x59,
    TXB2D4 = (uint8_t)0x5A,
    TXB2D5 = (uint8_t)0x5B,
    TXB2D6 = (uint8_t)0x5C,
    TXB2D7 = (uint8_t)0x5D,


};

enum Receivers {
    
};

#ifdef __cplusplus
}
#endif

#endif