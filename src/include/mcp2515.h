#ifndef MCP2515_LIB_SRC_INCLUDE_MCP2515_H
#define MCP2515_LIB_SRC_INCLUDE_MCP2515_H

#ifdef __cplusplus
#include <cstdint>
extern "C" {
#else
#include <stdint.h>
#endif

typedef int (*write_func_t)(void*, uint8_t*, uint64_t);
typedef int (*read_func_t)(void*, uint8_t*, uint64_t);

typedef enum TxBuffer {
    Buffer0,
    Buffer1,
    Buffer2,
    BuffersFull,
} TxBuffer_t;

typedef enum MsgPriority {
    Highest = 3,
    HighIntermediate = 2,
    LowIntermediate = 1,
    Lowest = 0
} MsgPriority_t;

typedef struct MCP2515 {
    void* spiDev;
    write_func_t write;
    read_func_t read;
} MCP2515_t, *pMCP2515_t;

pMCP2515_t create_device(void* spiDev, uint32_t canId, write_func_t write, read_func_t read);
void free_device(pMCP2515_t dev);

void enable_interrupts(const pMCP2515_t dev);

TxBuffer_t send_message(const pMCP2515_t dev, MsgPriority_t pri, uint32_t id, const uint8_t* data, uint64_t size);
int check_tx_condition(const pMCP2515_t dev, TxBuffer_t buffer);


#ifdef __cplusplus
}
#endif

#endif