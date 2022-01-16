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
    
    /** Receive buffer n control register **/
    RXB0CTRL = (uint8_t)0x60,
    RXB1CTRL = (uint8_t)0x70,

    /** RXnBF pin control and status register **/
    BFPCTRL = (uint8_t)0x0C,

    /** Receive buffer n standard indetifier register high **/
    RXB0SIDH = (uint8_t)0x61,
    RXB1SIDH = (uint8_t)0x61,

    /** Receive buffer n standard identifier register low **/
    RXB0SIDL = (uint8_t)0x62,
    RXB1SIDL = (uint8_t)0x72,

    /** Receive buffer n extended indentifier register high **/
    RXB0EID8 = (uint8_t)0x63,
    RXB1EID8 = (uint8_t)0x73,

    /** Receive buffer n extended identifier register low **/
    RXB0EID0 = (uint8_t)0x64,
    RXB1EID0 = (uint8_t)0x74,

    /** Receive buffer n data length code register **/
    RXB0DLC = (uint8_t)0x65,
    RXB1DLC = (uint8_t)0x75,

    /** Receive buffer n data byte m register **/
    /* Buffer 1 */
    RXB0D0 = (uint8_t)0x66,
    RXB0D1 = (uint8_t)0x67,
    RXB0D2 = (uint8_t)0x68,
    RXB0D3 = (uint8_t)0x69,
    RXB0D4 = (uint8_t)0x6A,
    RXB0D5 = (uint8_t)0x6B,
    RXB0D6 = (uint8_t)0x6C,
    RXB0D7 = (uint8_t)0x6D,

    /* Buffer 2 */
    RXB1D0 = (uint8_t)0x76,
    RXB1D1 = (uint8_t)0x77,
    RXB1D2 = (uint8_t)0x78,
    RXB1D3 = (uint8_t)0x79,
    RXB1D4 = (uint8_t)0x7A,
    RXB1D5 = (uint8_t)0x7B,
    RXB1D6 = (uint8_t)0x7C,
    RXB1D7 = (uint8_t)0x7D,
};

enum Filters {

    /** Filter n standard identifier register high **/
    RXF0SIDH = (uint8_t)0x00,
    RXF1SIDH = (uint8_t)0x04,
    RXF2SIDH = (uint8_t)0x08,
    RXF3SIDH = (uint8_t)0x10,
    RXF4SIDH = (uint8_t)0x14,
    RXF5SIDH = (uint8_t)0x18,

    /** Filter n standard identifier register low **/
    RXF0SIDL = (uint8_t)0x01,
    RXF1SIDL = (uint8_t)0x05,
    RXF2SIDL = (uint8_t)0x09,
    RXF3SIDL = (uint8_t)0x11,
    RXF4SIDL = (uint8_t)0x15,
    RXF5SIDL = (uint8_t)0x19,

    /** Filter n extended identifier register high **/
    RXF0SEID8 = (uint8_t)0x02,
    RXF1SEID8 = (uint8_t)0x06,
    RXF2SEID8 = (uint8_t)0x0A,
    RXF3SEID8 = (uint8_t)0x12,
    RXF4SEID8 = (uint8_t)0x16,
    RXF5SEID8 = (uint8_t)0x1A,

    /** Filter n extended 1 register low **/
    RXF0EID0 = (uint8_t)0x03,
    RXF1EID0 = (uint8_t)0x07,
    RXF2EID0 = (uint8_t)0x0B,
    RXF3EID0 = (uint8_t)0x13,
    RXF4EID0 = (uint8_t)0x17,
    RXF5EID0 = (uint8_t)0x1B,

    /** Mask n standard identifier register high **/
    RXM0SIDH = (uint8_t)0x20,
    RXM1SIDH = (uint8_t)0x24,

    /** Mask n standard identifier register low **/
    RXM0SIDL = (uint8_t)0x21,
    RXM1SIDL = (uint8_t)0x25,

    /** Mask n extended identifier register high **/
    RXM0EID8 = (uint8_t)0x22,
    RXM1EID8 = (uint8_t)0x26,

    /** Mask n extended identifier register low **/
    RXM0EID0 = (uint8_t)0x23,
    RXM1EID0 = (uint8_t)0x27,
};

enum Config {
    /** Configuration register 1 **/
    CNF1 = (uint8_t)0x2A,

    /** Configuration register 2 **/
    CNF2 = (uint8_t)0x29,

    /** Configuration register 3 **/
    CNF3 = (uint8_t)0x28,
};

enum Error {
    /** Transmit error counter register **/
    TEC = (uint8_t)0x1C,

    /** Receive error counter register **/
    REC = (uint8_t)0x1D,

    /** Error flag register **/
    EFLG = (uint8_t)0x2D,
};

enum Control {

};

#ifdef __cplusplus
}
#endif

#endif