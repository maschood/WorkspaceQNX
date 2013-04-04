/****************************************************************************/
/*                                                                          */
/*   Softing GmbH          Richard-Reitzner-Allee 6       85540 Haar        */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*   Copyright (C) by Softing GmbH, 1997,1998,1999   All rights reserved.   */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*                               C M A R E T . H                            */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/* PROJECT:            CANopen Master API                                   */
/*                                                                          */
/* MODULE:             CMARET.H                                             */
/*                                                                          */
/* AUTHOR:             Softing GmbH                                         */
/*                                                                          */
/* MODULE_DESCRIPTION  Return codes of CANopen Master API functions         */
/*                                                                          */
/* DATE                25.08.1999                                           */
/*                                                                          */
/****************************************************************************/
#ifndef _CMARET_H
#define _CMARET_H

/* ---- return code for successful execution of a CANopen Master API  ----- */
/* ---- function                                                      ----- */
#define  CANPC_OK                                     0

/* ---- error return codes for CANopen Master API functions --------------- */
         /* can't open IniFile                                              */
#define  CANPC_RB_INI_FILE                           -1 /* (0xFFFF)         */
         /* format error in INI-file                                        */    
#define  CANPC_RB_ERR_FMT_INI                        -2 /* (0xFFFE)         */
         /* error opening binary-file                                       */
#define  CANPC_RB_ERR_OP_BIN                         -3 /* (0xFFFD)         */
         /* error reading binary-file                                       */
#define  CANPC_RB_ERR_RD_BIN                         -4 /* (0xFFFC)         */
         /* binary-file too long                                            */
#define  CANPC_RB_BIN_TOO_LONG                       -5 /* (0xFFFB)         */
         /* binary-data format error                                        */
#define  CANPC_RB_ERR_BIN_FMT                        -6 /* (0xFFFA)         */
         /* binary-data checksum error                                      */
#define  CANPC_RB_ERR_BIN_CS                         -7 /* (0xFFF9)         */
         /* no interface present                                            */    
#define  CANPC_RB_NO_CARD                           -16 /* (0xFFF0)         */
         /* no physical memory                                              */
#define  CANPC_RB_NO_PHYS_MEM                       -17 /* (0xFFEF)         */
         /* invalid IRQ-number                                              */
#define  CANPC_RB_INVLD_IRQ                         -18 /* (0xFFEE)         */
         /* error accessing dpram                                           */
#define  CANPC_RB_ERR_DPRAM_ACCESS                  -19 /* (0xFFED)         */
         /* bad response from interface                                     */
#define  CANPC_RB_ERR_CRD_RESP                      -20 /* (0xFFEC)         */
         /* sram seems to be damaged                                        */
#define  CANPC_RB_ERR_SRAM                          -21 /* (0xFFEB)         */
         /* invalid program start address                                   */    
#define  CANPC_RB_ERR_PRG                           -22 /* (0xFFEA)         */
         /* invalid record type                                             */
#define  CANPC_RB_ERR_REC                           -23 /* (0xFFE9)         */
         /* no response after program start                                 */
#define  CANPC_RB_ERR_NORESP                        -24 /* (0xFFE8)         */
         /* bad response after program start                                */    
#define  CANPC_RB_ERR_BADRESP                       -25 /* (0xFFE7)         */
         /* pcmcia chip not supported                                       */    
#define  CANPC_RB_PCMCIA_NSUPP                      -26 /* (0xFFE6)         */
         /* error reading pcmcia parameters                                 */
#define  CANPC_RB_ERR_RD_PCMCIA                     -27 /* (0xFFE5)         */
         /* error initializing chip                                         */
#define  CANPC_RB_INIT_CHIP                         -38 /* (0xFFDA)         */
         /* no CANcard plugged in                                           */    
#define  CANPC_RB_ERR_NO_CANCARD                    -39 /* (0xFFD9)         */
         /* bad response from interface                                     */
#define  CANPC_RB_ERR_CRD_NORESP                    -40 /* (0xFFD8)         */
         /* interface not properly loaded                                   */    
#define  CANPC_RB_ERR_DEV_LD                        -41 /* (0xFFD7)         */

         /* param: ucLicence invalid                                        */
#define  CMA_ERR_PAR_LICENCE                       -100 /* (0xFF9C)         */
         /* demo applications expired                                       */
#define  CMA_ERR_DEMOS_EXPIRED                     -101 /* (0xFF9B)         */
         /* licence access impossible                                       */
#define  CMA_ERR_LICENCE_ACCESS                    -102 /* (0xFF9A)         */
         /* function timeout occurred                                       */
#define  CMA_ERR_FUNCTION_TIMEOUT                  -103 /* (0xFF99)         */
         /* param: ucCANxFunctionality undefined                            */
#define  CMA_ERR_PAR_FUNCTIONALITY                 -104 /* (0xFF98)         */
         /* param: ucChannelHandle undefined                                */
#define  CMA_ERR_PAR_CHAN_HANDLE                   -105 /* (0xFF97)         */
         /* struct: ucBaudRate invalid                                      */
#define  CMA_ERR_SCT_BAUD_RATE                     -106 /* (0xFF96)         */
         /* param: timeout too big                                          */
#define  CMA_ERR_PAR_TIMEOUT_MAX                   -107 /* (0xFF95)         */
         /* param: timeout too small                                        */
#define  CMA_ERR_PAR_TIMEOUT_MIN                   -108 /* (0xFF94)         */
         /* param: ucNodeID is invalid                                      */
#define  CMA_ERR_PAR_NODE_ID                       -109 /* (0xFF93)         */
         /* struct: COB-ID invalid or used                                  */
#define  CMA_ERR_SCT_COB_ID                        -110 /* (0xFF92)         */
         /* struct: ulSyncCycle is too big                                  */
#define  CMA_ERR_SCT_COMM_CYC_MAX                  -111 /* (0xFF91)         */
         /* struct: ucNodeID invalid                                        */
#define  CMA_ERR_SCT_NODE_ID                       -112 /* (0xFF90)         */
         /* improper state of the master                                    */
#define  CMA_ERR_MASTER_STATE                      -113 /* (0xFF8F)         */
         /* param: ucState invalid                                          */
#define  CMA_ERR_PAR_STATE                         -114 /* (0xFF8E)         */
         /* internal transmit fifo is full                                  */
#define  CMA_ERR_INT_TX_FIFO_FULL                  -115 /* (0xFF8D)         */
         /* master cannot guard itself                                      */
#define  CMA_ERR_MASTER_GUARDING                   -116 /* (0xFF8C)         */
         /* DPRAM command fifo is full                                      */
#define  CMA_ERR_COMMAND_FIFO_FULL                 -117 /* (0xFF8B)         */
         /* SDO transmit fifo is full                                       */
#define  CMA_ERR_SDO_TX_FIFO_FULL                  -118 /* (0xFF8A)         */
         /* param: ucDataSize is invalid                                    */
#define  CMA_ERR_PAR_DATA_SIZE                     -119 /* (0xFF89)         */
         /* param: usIndex is incorrect                                     */
#define  CMA_ERR_PAR_INDEX                         -120 /* (0xFF88)         */
         /* param: ucSubIndex is incorrect                                  */
#define  CMA_ERR_PAR_SUBINDEX                      -121 /* (0xFF87)         */
         /* ulTotalDataSize exceeded                                        */
#define  CMA_ERR_TOTAL_DATA_SIZE                   -122 /* (0xFF86)         */
         /* no normal transfer active                                       */
#define  CMA_ERR_NO_TRANSF_ACTIVE                  -123 /* (0xFF85)         */
         /* SDO receive fifo is empty                                       */
#define  CMA_ERR_SDO_RX_FIFO_EMPTY                 -124 /* (0xFF84)         */
         /* struct: ucAccType is invalid                                    */
#define  CMA_ERR_SCT_PDO_ACC_TYPE                  -125 /* (0xFF83)         */
         /* param: usPDOHandle is undefined                                 */
#define  CMA_ERR_PAR_PDO_HANDLE                    -126 /* (0xFF82)         */
         /* param: ucDataOffset is invalid                                  */
#define  CMA_ERR_PAR_BYTEPOS                       -127 /* (0xFF81)         */
         /* param: DataOffset+Datalength>8                                  */
#define  CMA_ERR_PAR_PDO_TOO_LONG                  -128 /* (0xFF80)         */
         /* access to PDO in DPRAM failed                                   */
#define  CMA_ERR_PDO_ACCESS                        -129 /* (0xFF7F)         */
         /* param: ucBitPosition is invalid                                 */
#define  CMA_ERR_PAR_BITPOS                        -130 /* (0xFF7E)         */
         /* unknown event in event fifo                                     */
#define  CMA_ERR_UNKNOWN_EVENT                     -131 /* (0xFF7D)         */
         /* wrong firmware version                                          */
#define  CMA_ERR_WRONG_FW_VERSION                  -132 /* (0xFF7C)         */
         /* struct: ucTransType invalid                                     */
#define  CMA_ERR_SCT_TRANS_TYPE                    -133 /* (0xFF7B)         */
         /* number of DPRAM-TX-PDOs exceeded                                */
#define  CMA_ERR_DPRAM_TX_PDO_MAX                  -134 /* (0xFF7A)         */
         /* number of DPRAM-RX-PDOs exceeded                                */
#define  CMA_ERR_DPRAM_RX_PDO_MAX                  -135 /* (0xFF79)         */
         /* last request still pending                                      */
#define  CMA_ERR_LAST_REQ_PENDING                  -136 /* (0xFF78)         */
         /* sync object TX request still pending                            */
#define  CMA_ERR_SYNC_REQ_PENDING                  -137 /* (0xFF77)         */
         /* sync cycle must be zero                                         */
#define  CMA_ERR_SYNC_CYCLE_IMPROPER               -138 /* (0xFF76)         */
         /* sync object TX not enabled                                      */
#define  CMA_ERR_SYNC_TX_DISABLED                  -139 /* (0xFF75)         */
         /* IRQ number invalid                                              */
#define  CMA_ERR_INVALID_INTERRUPT_CONFIGURATION   -140 /* (0xFF74)         */

         /* max. number of device exceeded                                  */
#define  INIPC_IB_ERR_VC_TOOMANYDEVICES            -500 /* (0xFE0C)         */
         /* not enough memory space to register a device                    */
#define  INIPC_IB_ERR_VC_NOTENOUGHMEMORY           -501 /* (0xFE0B)         */
         /* driver not found                                                */
#define  INIPC_IB_ERR_VC_DRIVERNOTFOUND            -502 /* (0xFE0A)         */
         /* wrong driver version                                            */
#define  INIPC_IB_ERR_VC_DRIVERVERSIONERROR        -503 /* (0xFE09)         */
         /* wrong driver-dll version                                        */
#define  INIPC_IB_ERR_VC_VERSIONERROR              -504 /* (0xFE08)         */
         /* internal error: requested functionality not supported           */
#define  INIPC_IB_ERR_VC_NOTSUPPORTED              -505 /* (0xFE07)         */
         /* internal error: illegal driver call                             */
#define  INIPC_IB_ERR_VC_ILLEGALCALL               -506 /* (0xFE06)         */
         /* internal error: driver call cancelled                           */
#define  INIPC_IB_ERR_VC_IOCANCELLED               -507 /* (0xFE05)         */
         /* internal error: driver call pending                             */
#define  INIPC_IB_ERR_VC_IOPENDING                 -508 /* (0xFE04)         */
         /* internal error: timeout during driver access                    */
#define  INIPC_IB_ERR_VC_TIMEOUT                   -509 /* (0xFE03)         */ 
         /* internal error: general error in accessing the driver           */
#define  INIPC_IB_ERR_VC_GENERALERROR              -510 /* (0xFE02)         */
         /* internal driver error                                           */
#define  INIPC_IB_ERR_VC_INTERNALERROR             -511 /* (0xFE01)         */ 
         /* no CAN device found                                             */
#define  INIPC_IB_PNP_NO_DEVICE_FOUND              -512 /* (0xFE00)         */
         /* access to an unknown device requested                           */
#define  INIPC_IB_ERR_VC_UNKNOWNDEVICE             -513 /* (0xFDFF)         */
         /* device is already registered by the driver                      */
#define  INIPC_IB_ERR_VC_DEVICEALREADYEXISTS       -514 /* (0xFDFE)         */ 
         /* device is already open                                          */
#define  INIPC_IB_ERR_VC_DEVICEACCESSERROR         -515 /* (0xFDFD)         */
         /* a requested resource is already in use by an other device       */
         /* (DPRAM, IRQ, I/O port)                                          */
#define  INIPC_IB_ERR_VC_RESOURCEALREADYREGISTERED -516 /* (0xFDFC)         */
         /* resource conflict with an other driver                          */
#define  INIPC_IB_ERR_VC_RESOURCECONFLICT          -517 /* (0xFDFB)         */
         /* resource access error                                           */
#define  INIPC_IB_ERR_VC_RESOURCEACCESSERROR       -518 /* (0xFDFA)         */
         /* internal error: invalid phys.mem-access                         */
#define  INIPC_IB_ERR_VC_PHYSMEMORYOVERRUN         -519 /* (0xFDF9)         */
         /* internal error: too many I/O ports requested                    */
#define  INIPC_IB_ERR_VC_TOOMANYPORTS              -520 /* (0xFDF8)         */
         /* internal error: unknown resource access requested               */
#define  INIPC_IB_ERR_VC_UNKNOWNRESOURCE           -521 /* (0xFDF7)         */
         /* driver DLL not found                                            */
#define  INIPC_IB_ERR_LOADDDLL_DEV                 -522 /* (0xFDF6)         */
         /* cannot register device                                          */
#define  INIPC_IB_ERR_CANT_DEVREGISTER             -523 /* (0xFDF5)         */
         /* interrupt number invalid or device cannot be assigned an        */
         /* interrupt                                                       */
#define  INIPC_IB_ERR_IRQ                          -524 /* (0xFDF4)         */

         /* internal error: wrong device handle specified                   */
#define  DDC_ERR_WRONG_DEVICEHANDLE                -550 /* (0xFDDA)         */


/* ---- Tag values for VCQEntry & VEQEntry --------------------------------- */

#define kQEEmpty              0 /* Invalid / empty */

#define kQEStartup            1 /*
		ucData[0] = Nr of DIG In / 8
		ucData[1] = Nr of DIG Out / 8
		ucData[2] = Nr of ANA In
		ucData[3] = Nr of ANA Out
		ucData[4,5] = Baudrate CAN1(10, 20, 50, 125, 250,
				500, 800, 1000)
		ucData[6,7] = Baudrate CAN2(10, 20, 50, 125, 250,
				500, 800, 1000)
		ucData[8] = Layer7-Flag on CAN1: 0=L2, 1=CANopen
		ucData[9] = Layer7-Flag on CAN2: 0=L2, 1=CANopen
		ucData[10,11] = Nr of configured Entries in Acc-List DPRAM.mL2RxDat
		ucData[12,13] = relais control 0
		ucData[14,15] = relais control 1
		ucData[16,17,18,19] = relais data
	*/
#define kQESDOWriteRq         2 /* SDO Write Request
					ucData[0] = Device ID
					ucData[1] = Sub-Index
					ucData[2,3]= Index (low, high)
					ucData[4,5]= DataSize (low,high)
					ucData[7..]= Data (low first)
					*/

#define kQESDOWriteCon        3 /* SDO Write Request Response
					ucData[0] = Device ID
					ucData[1] = Sub-Index
					ucData[2,3]= Index (low, high)
					*/

#define kQESDOReadRq          4 /* SDO Read Request
					ucData[0] = Device ID
					ucData[1] = Sub-Index
					ucData[2,3]= Index (low, high)
					*/

#define kQESDOReadCon         5 /* SDO Read Request Response
					ucData[0] = Device ID
					ucData[1] = Sub-Index 
					ucData[2,3]= Index (low, high)
					ucData[4,5]= DataSize (low,high)
					ucData[7..]= Data (low first)
					*/

#define kQESDOWriteInd        6 /* SDO Write Indication
					ucData[0] = Device ID
					ucData[1] = Sub-Index 
					ucData[2,3]= Index (low, high)
					ucData[4,5]= DataSize (low,high)
					ucData[7..]= Data (low first)
					*/

#define kQESDOWriteIndRsp     7 /* SDO Write Ind Response
					ucData[0] = Device ID
					ucData[1] = Sub-Index
					ucData[2,3]= Index (low, high)
					*/

/* #define kQESDOReadInd      8    NO MORE!  */
                            /* SDO Read Indication
					ucData[0] = Device ID
					ucData[1] = Sub-Index
					ucData[2,3]= Index (low, high)
					*/

/* #define kQESDOReadIndRsp	  9    NO MORE!  */
                            /* SDO Read Ind Response
					ucData[0] = Device ID
					ucData[1] = Sub-Index 
					ucData[2,3]= Index (low, high)
					ucData[4,5]= DataSize (low,high)
					ucData[7..]= Data (low first)
					*/

#define kQESendEMCY	         10 /* transmit Emergency Request
					ucData[0..7] = structure as
						defined in DS-301 Rev.3.0
						Section 7.3.2
					*/

#define kQEEMCYInd	         11 /* Received EMCY Indication
					ucData[0] = slave's Node ID
					ucData[1..8] = data bytes of EMCY CAN message
					*/

#define kQESendL2		     12 /* Send Layer2 Message            */
                                /* ucData[0..3]=CAN-Id (LSB first) */
                                /* ucData[4] = RTR                 */
                                /* ucData[5] = DLC                 */
                                /* ucData[6-13] = Data             */

#define kQEForceRelais	     14 /* Force relais */

#define kQEError	         15 /* Error Entry
          ucData[0] = Error Class
              Error Class =
                   1    API Error
                   2    CAN Error
                   3    SDO Error (remote and own OD access)
                   4    Guard Error
          The following fields depend on Error class

          API Error:
            ucData[1]   reserved
            ucData[2,3] 2 Byte code (low,high) conforrming to Header COERRDEF.H
            ucData[4,5] Additional info dependent on the error
          CAN Error
            ucData[1]   reserved
            ucData[2,3] 2 Byte code (low,high)  values TBD
          Remote SDO Error (see DS-301, DS-405)
            ucData[1] = Device ID
            ucData[2] = Error Class
            ucData[3] = Error Code
            ucData[4,5] = Additional Code
          Guard Error
            ucData[1] = Device ID (if 0, LifeGuaring failed)
            ucData[2] =
                  0  guarding is not activated yet
                  1  guarding is activated
                  2  one response is missed
                  3  no response and life time elapsed
                  4  toggle error
                  5  state changed
          */

#define kQEFatalError        16 /* Fatal Error:                        */
                                /* no more error information available */

#define kQEPing              17 /* Ping from PLC */

#define kQEPingRsp           18 /* Answer from the Communuication Process */

#define kQESDOAbort          19 /* Abort SDO            */
                                /* ucData[0] = Device ID */

#define kQEShutdown          20 /* Shutdown */

#define NextDownloadSegment  30 /* next download segment block should be */
                                /* written into the SDO-TX-Fifo          */

#define NextUploadSegment    31 /* next upload segment should be   */
                                /* read from the SDO-RX-Fifo       */

#define PDOReceived          32 /* ucData[0,1] = PDOHandle (low, high)    */
                                /* ucData[2]   = number of received bytes */
                                /* ucData[3..] = data                     */

#define ShutdownCompleted    33 /* Shutdown completed */

#define StartupCompleted     34 /* Startup completed */


/* --- function CMA_ReadEvent                                           --- */
#define  NoEvent             0
#define  DownloadCompleted   3
#define  UploadCompleted     5
#define  EMCYReceived        11
#define  ErrorEvent          15
#define  NextDownloadSegment 30
#define  NextUploadSegment   31
#define  PDOReceived         32
#define  ShutdownCompleted   33
#define  StartupCompleted    34


/* --- error event types returned in event structure parameter          --- */
/* --- ucaEventData[0] of function CMA_ReadEvent                        --- */
#define  APIError             1
#define  CANError             2
#define  SDOError             3
#define  GuardError           4


#endif // _CMARET_H
