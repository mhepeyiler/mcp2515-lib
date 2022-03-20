#ifndef MCP2515_LIB_SRC_INCLUDE_MCP2515_H
#define MCP2515_LIB_SRC_INCLUDE_MCP2515_H

#ifdef __cplusplus
extern "C" {
#include <cstdint>
#else 
#include <stdint.h>
#endif

/* Transmit Structs */

typedef struct TXBnCTRL{
    uint8_t TXP             : 2;
    uint8_t Unimplemented0  : 1;
    uint8_t TXREQ           : 1;
    uint8_t TXERR           : 1;
    uint8_t MLOA            : 1;
    uint8_t ABTF            : 1;
    uint8_t Unimplemented1  : 1;
} TXBnCTRL_t, *pTXBnCTRL_t;

typedef struct TXRTSCTRL {
    uint8_t B0RTSM          : 1;
    uint8_t B1RTSM          : 1;
    uint8_t B2RTSM          : 1;
    uint8_t B0RTS           : 1;
    uint8_t B1RTS           : 1;
    uint8_t B2RTS           : 1;
    uint8_t Unimplemented0  : 1;
} TXRTSCTRL_t, *pTXRTSCTRL_t;

typedef struct TXBnSIDH {
    uint8_t SID_10_3;
} TXBnSIDH_t, *pTXBnSIDH_t;

typedef struct TXBnSIDL {
    uint8_t EID_17_16       : 2;
    uint8_t Unimplemented0  : 1;
    uint8_t EXIDE           : 1;
    uint8_t Unimplemented1  : 1;
    uint8_t SID_2_0         : 3;
} TXBnSIDL_t, *pTXBnSIDL_t;

typedef struct TXBnEID8 {
    uint8_t EID_15_8;
} TXBnEID8_t, *pTXBnEID8_t;

typedef struct TXBnEID0 {
    uint8_t EID_7_0;
} TXBnEID0_t, *pTXBnEID0_t;

typedef struct TXBnDLC {
    uint8_t DLC_3_0         : 4;
    uint8_t Unimplemented0  : 2;
    uint8_t RTR             : 1;
    uint8_t Unimplemented1  : 1;
} TXBnDLC_t, *pTXBnDLC_t;

typedef struct TXBnDm {
    uint8_t data;
} TXBnDm_t, *pTXBnDm_t;

/* Receive Structs */

typedef struct RXB0CTRL {
    uint8_t FILHIT0         : 1;
    uint8_t BULKT1          : 1;
    uint8_t BUKT            : 1;
    uint8_t RXRTR           : 1;
    uint8_t Unimplemented0  : 1;
    uint8_t RXM             : 2;
    uint8_t Unimplemented1  : 1;
} RXB0CTRL_t, *pRXB0CTRL_t;

typedef struct RXB1CTRL {
    uint8_t FILHIT          : 3;
    uint8_t RXRTR           : 2;
    uint8_t Unimplemented0  : 1;
    uint8_t RXM             : 2;
    uint8_t Unimplemented1  : 1;
} RXB1CTRL_t, *pRXB1CTRL_t;

typedef struct BFPCTRL {
    uint8_t B0BFM           : 1;
    uint8_t B1BFM           : 1;
    uint8_t B0BFE           : 1;
    uint8_t B1BFE           : 1;
    uint8_t B0BFS           : 1;
    uint8_t B1BFS           : 1;
    uint8_t Unimplemented0  : 1;
} BFPCTRL_t, *pBFPCTRL_t;

typedef struct RXBnSIDH {
    uint8_t SID;
} RXBnSIDH_t, *pRXBnSIDH_t;

typedef struct RXBnSIDL {
    uint8_t EID_16_17       : 2;
    uint8_t Unimplemented0  : 1;
    uint8_t IDE             : 1;
    uint8_t SRR             : 1;
    uint8_t SID_2_0         : 2;
} RXBnSIDL_t, *pRXBnSIDL_t;

typedef struct RXBnEID8 {
    uint8_t EID_15_8;
} RXBnEID8_t, *pRXBnEID8_t;

typedef struct RXBnEID0 {
    uint8_t EID_7_0;
} RXBnEID0_t, *pRXBnEID0_t;

typedef struct RXBnDLC {
    uint8_t DLC             : 4;
    uint8_t RB0             : 1;
    uint8_t RB1             : 1;
    uint8_t Unimplemented0  : 1;
} RXBnDLC_t, *pRXBnDLC_t;

typedef struct RXBnDm {
    uint8_t RBnD;
} RXBnDm_t, *pRXBnDm_t;

/* Filter Structs */ 

typedef struct RXFnSIDH {
    uint8_t SID_10_3;
} RXFnSIDH_t, *pRXFnSIDH_t;

typedef struct RXFnSIDL {
    uint8_t EID_17_16       : 2;
    uint8_t Umimplemented0  : 1;
    uint8_t EXIDE           : 1;
    uint8_t Umimplemented1  : 1;
    uint8_t SID_2_0         : 2;
} RXFnSIDL_t, *pRXFnSIDL_t;

typedef struct RXFnEID8 {
    uint8_t EID_15_8;
} RXFnEID8_t, *pRXFnEID8_t;

typedef struct RXFnEID0 {
    uint8_t EID_7_0;
} RXFnEID0_t, *pRXFnEID0_t;

typedef struct RXMnSIDH {
    uint8_t SID_10_3;
} RXMnSIDH_t, *pRXMnSIDH_t;

typedef struct RXMnSIDL {
    uint8_t EID_17_16       : 2;
    uint8_t Unimplemented   : 3;
    uint8_t SID_2_0         : 3;
} RXMnSIDL_t, *pRXMnSIDL_t;

typedef struct RXMnEID8 {
    uint8_t EID_15_8;
} RXMnEID8_t, *pRXMnEID8_t;

typedef struct RXMnEID0 {
    uint8_t EID_7_0;
} RXMnEID0_t, *pRXMnEID0_t;

/* Configuration */

typedef struct CNF1 {
    uint8_t SJW             : 2;
    uint8_t BRP             : 6;
} CNF1_t, *pCNF1_t;

typedef struct CNF2 {
    uint8_t PRSEG           : 2;
    uint8_t PHSEG           : 2;
    uint8_t SAM             : 1;
    uint8_t BTLMODE         : 1;
} CNF2_t, *pCNF2_t;

typedef struct CNF3 {
    uint8_t PHSEG           : 2;
    uint8_t Unimplemented0  : 1;
    uint8_t WAKFIL          : 1;
    uint8_t SOF             : 1;
} CNF3_t, *pCNF3_t;

/* Error */

typedef struct TEC {
    uint8_t TEC;
} TEC_t, *pTEC_t;

typedef struct REC {
    uint8_t REC;
} REC_t, *pREC_t;

typedef struct EFLG {
    uint8_t EWARN           : 1;
    uint8_t RXWAR           : 1;
    uint8_t TXWAR           : 1;
    uint8_t RXEP            : 1;
    uint8_t TXEP            : 1;
    uint8_t TXBO            : 1;
    uint8_t RX0OVR          : 1;
    uint8_t RX1OVR          : 1;
} EFLG_t, *pEFLG_t;

/* Interrupts */

typedef struct CANINTE {
    uint8_t RX0IE           : 1;
    uint8_t RX1IE           : 1;
    uint8_t TX0IE           : 1;
    uint8_t TX1IE           : 1;
    uint8_t TX2IE           : 1;
    uint8_t ERRIE           : 1;
    uint8_t WAKIE           : 1;
    uint8_t MERRE           : 1;
} CANINTE_t, *pCANINTE_t;

typedef struct CANINTF {
    uint8_t RX0IF           : 1;
    uint8_t RX1IF           : 1;
    uint8_t TX0IF           : 1;
    uint8_t TX1IF           : 1;
    uint8_t TX2IF           : 1;
    uint8_t ERRIF           : 1;
    uint8_t WAKIF           : 1;
    uint8_t MERRF           : 1;
} CANINTF_t, *pCANINTF_t;

/* Control */

typedef struct CANCTRL {
    uint8_t CLKPRE          : 2;
    uint8_t CLKEN           : 1;
    uint8_t OSM             : 1;
    uint8_t ABAT            : 1;
    uint8_t REQOP           : 3;
} CANCTRL_t, *pCANCTRL_t;

typedef struct CANSTAT {
    uint8_t Unimplemneted0  : 1;
    uint8_t ICOD            : 3;
    uint8_t Unimplemneted1  : 1;
    uint8_t OPMOD           : 3; 
} CANSTAT_t, *pCANSTAT_t;



#ifdef __cplusplus
}
#endif

#endif