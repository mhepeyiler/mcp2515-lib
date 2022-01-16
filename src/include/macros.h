#ifndef MCP2515_LIB_SRC_INCLUDE_MCP2515_H
#define MCP2515_LIB_SRC_INCLUDE_MCP2515_H

#ifdef __cplusplus
extern "C" {
#endif

/** Transmit buffer n control register macros **/
#define IS_ABORTED(x)                       (x & (1 << 6))
#define IS_ARBITRATION_LOST(x)              (x & (1 << 5))
#define IS_TRANSMISSION_ERROR(x)            (x & (1 << 4))
#define IS_PENDING_TRANSMISSION(x)          (x & (1 << 3))
#define IS_HIGHEST_PRIORITY(x)              (((x & (1 << 1)) & (x & (1 << 0))))
#define IS_HIGH_INTERMEDIATE_PRIORITY(x)    (((x & (1 << 1) & (~(x | (0 << 0)))))
#define IS_LOW_INTERMEDIATE_PRIORITY(x)     (((~(x | (0 << 1))) & (x & (1 << 0))))
#define IS_LOWEST_INTERMEDIATE_PRIORITY(x)  (((~(x | (0 << 1))) & (~(x | (0 << 0)))))

/** TXnRTS pin control and status register macros **/
#define READ_TX2_STATE(x) (x & (1 << 5))
#define READ_TX1_STATE(x) (x & (1 << 4))
#define READ_TX0_STATE(x) (x & (1 << 3))
#define READ_TX2_MODE(x) (x & (1 << 2))
#define READ_TX1_MODE(x) (x & (1 << 1))
#define READ_TX0_MODE(x) (x & (1 << 0))



#ifdef __cplusplus
}
#endif

#endif