#ifdef __cplusplus
#include <cstdarg>
#include <cstdlib>
#include <cstring>
#else
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#endif

#include "mcp2515.h"
#include "structs.h"
#include "registers.h"

#define RESET                   0b1100000
#define READ                    0b0000011
#define READ_RX_BUFFER(n, m)    ((0b10010000 | n<<2) | m<<1)
#define WRITE                   0b0000010
#define LOAD_TX_BUFFER(a, b, c) (((0b01000000 | a<<2) | b<<1) | c)
#define RTS(n1, n2, n3)         (((0b10000000 | n1<<2) | n2 << 1) | n3)
#define READ_STATUS             0b10100000
#define RX_STATUS               0b10110000
#define BIT_MODIFT              0b00000101

static TxBuffer_t find_first_empty_tx_buffer(pMCP2515_t dev);

static int set_can_id(pMCP2515_t dev, TxBuffer_t buff, uint32_t id);
static int set_canfd_id(pMCP2515_t dev, TxBuffer_t buff, uint32_t id);
static int set_dlc(pMCP2515_t dev, TxBuffer_t buff, uint8_t dlc);

pMCP2515_t create_device(void* spiDev, uint32_t canId, write_func_t write, read_func_t read) {
    pMCP2515_t dev = malloc(sizeof(MCP2515_t));
    dev->spiDev = spiDev;
    dev->write = write;
    dev->read = write;

    return dev;
}

void free_device(const pMCP2515_t dev) {
    free(dev);
}

TxBuffer_t send_message(const pMCP2515_t dev, MsgPriority_t pri, uint32_t id, const uint8_t* data, uint64_t size) {
    if (dev == NULL) {
        return -1;
    }

    TxBuffer_t buff = find_first_empty_tx_buffer(dev);
    if (id < 2048) {
        set_can_id(dev, buff, id);
    } else {
        set_canfd_id(dev, buff, id);
    }

    static uint8_t txBufferReg[] = {TXB0D0, TXB1D0, TXB2D0};
    uint8_t arr[10] = {0};
    arr[0] = WRITE;
    arr[1] = txBufferReg[buff];
    memcpy(&arr[2], data, size);
    
    static uint8_t txCtrlReg[] = {TXB0CTRL, TXB1CTRL, TXB2CTRL};
    
    arr[0] = READ;
    arr[1] = txCtrlReg[buff];

    int res = dev->write(dev->spiDev, arr, 2);
    if (res == -1) {
        return -1;
    }

    uint8_t readData = 0;
    res = dev->read(dev->spiDev, &readData, 1);
    if (res == -1) {
        return -1;
    }

    readData |= 0x08;
    return dev->write(dev->spiDev, &readData, 1);
}

TxBuffer_t find_first_empty_tx_buffer(pMCP2515_t dev) {
    static uint8_t txBufferReg[] = {TXB0CTRL, TXB1CTRL, TXB2CTRL};
    static arr[2] = {0};
    arr[0] = READ;
    for (uint8_t idx = 0; idx < sizeof(txBufferReg)/sizeof(uint8_t); ++idx) {
        arr[1] = txBufferReg[idx];
        int res = dev->write(dev->spiDev, arr, 2);
        if (res == -1) {
            return -1;
        }
        uint8_t readData = 0;
        res = dev->read(dev->spiDev, &readData, 1);
        if (res == -1) {
            return -1;
        }
        if ((readData & 0x08) == 1) {
            return idx;
        }
    }
    return BuffersFull;
}

int set_can_id(pMCP2515_t dev, TxBuffer_t buff, uint32_t id) {
    static uint8_t txIdArr[] = {TXB0SIDH,
                                TXB1SIDH,
                                TXB2SIDH};
    static uint8_t arr[4] = {0};
    arr[0] = WRITE;
    arr[1] = txIdArr[buff];
    arr[2] = id >> 3;
    arr[3] = ((id & 0x3) << 5);
    return dev->write(dev->spiDev, arr, 4);
}

int set_canfd_id(pMCP2515_t dev, TxBuffer_t buff, uint32_t id) {
    static uint8_t txIdArr[] = {TXB0SIDL,
                                TXB1SIDL,
                                TXB2SIDL};
    
    static uint8_t arr[5] = {0};
    arr[0] = WRITE;
    arr[1] = txIdArr[buff];
    arr[2] = (0x08 | id >> 16);
    arr[3] = (id & (0xff << 8)) >> 8;
    arr[4] = (id & 0xff);
    return dev->write(dev->spiDev, arr, 5);
}

int set_dlc(pMCP2515_t dev, TxBuffer_t buff, uint8_t dlc) {
    static uint8_t txIdArr[] = {TXB0DLC,
                              TXB1DLC,
                              TXB2DLC};
    static uint8_t arr[3] = {0};
    arr[0] = WRITE;
    arr[1] = txIdArr[buff];
    arr[2] = dlc;

    return dev->write(dev->spiDev, arr, 3);
}

