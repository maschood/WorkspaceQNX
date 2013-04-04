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
/*                               C M A D E F . H                            */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/* PROJECT:            CANopen Master API                                   */
/*                                                                          */
/* MODULE:             CMADEF.H                                             */
/*                                                                          */
/* AUTHOR:             Softing GmbH                                         */
/*                                                                          */
/* MODULE_DESCRIPTION: macro definitions, struktures and prototypes for     */
/*                     CANopen Master API functions                         */
/*                                                                          */
/* USAGE: Macro        Description                                          */                         
/*                                                                          */
/*        WIN32        define for building 32-bit applications              */   
/*                     (WIN-NT 4.0 and WIN 95)                              */
/*                                                                          */
/*        __cplusplus  define for C++ applications (normally defined        */
/*                     automatically by the compiler)                       */
/*                                                                          */
/* DATE                25.08.1999                                           */
/*                                                                          */
/****************************************************************************/
#ifndef _CMADEF_H
#define _CMADEF_H


/* compatibility with borland */
#ifdef __WIN32__
  #ifndef WIN32
    #define  WIN32
  #endif //WIN32
#endif //__WIN32__

/* set the switch WIN32, if a Windows 95 or a Windows NT application is built */
#ifdef WIN32

#ifdef __cplusplus
#define PRAEDEF  extern "C" __declspec(dllexport)
#define PRAEDECL extern "C" __declspec(dllexport)
#else
#define PRAEDEF  __declspec(dllexport)
#define PRAEDECL __declspec(dllexport)
#endif

#define MIDDECL  __stdcall
#define MIDDEF   __stdcall

#ifndef FAR /* for use in Win 3.1 */
#define FAR
#endif

#else
#define PRAEDEF  
#define PRAEDECL 
#define MIDDECL  
#define MIDDEF  
#endif /* WIN32 */

/**** defines for API applications ******************************************/

#define ID11BIT    0x00
#define ID29BIT    0x01
#define DATA_FRAME 0x00
#define RTR_FRAME  0x02

/**** structure declarations ************************************************/
#ifndef PACK1
#define PACK1  __attribute__((packed)) 
#endif

/* ---- event structure for function CMA_ReadEvent ------------------------ */
struct _CMA_EventStruct
  {
  unsigned char	ucEventType;
  unsigned long	ulTimeStamp;
  unsigned char	ucaEventData[20];
  } PACK1;
typedef struct _CMA_EventStruct CMA_EventStruct;

/* ---- configuration structure for function CMA_AddNode ------------------ */
struct _CMA_NodeConfig
  {
  unsigned char  ucNodeID;
  unsigned short usGuardTime;
  unsigned char  ucRetryFactor;
  unsigned char  ucErrAction;
  } PACK1;
typedef struct _CMA_NodeConfig CMA_NodeConfig;

/* ---- configuration structure for function CMA_ConfigCANChannel --------- */
struct _CMA_CAN_CONFIG
  {
  unsigned char ucBaudRate;
  unsigned char ucPresc;
  unsigned char ucSjw;
  unsigned char ucTSeg1;
  unsigned char ucTSeg2;
  unsigned char ucAccCode;
  unsigned char ucAccMask;
  } PACK1;
typedef struct _CMA_CAN_CONFIG CMA_CAN_CONFIG;

/* ---- configuration structure for function CMA_ConfigSyncMan ------------ */
struct _CMA_SyncManConfig
  {
  unsigned char ucSendMode;
  unsigned char ucConsumeMode;
  unsigned long ulSyncID;
  unsigned long ulSyncCycle;
  }PACK1;

typedef struct _CMA_SyncManConfig CMA_SyncManConfig;

/* ---- SDO segment structure for function CMA_ReadNextSegment ------------ */
struct _CMA_SDOSeg
  {
  unsigned char  ucNodeID;
  unsigned short usIndex;
  unsigned char  ucSubIndex;
  unsigned long  ulTotalDataSize;
  unsigned long  ulSegNum;
  unsigned char  ucValidDataBytes;
  unsigned char  ucaData[7];
  } PACK1;
typedef struct _CMA_SDOSeg CMA_SDOSeg;

/* ---- configuration structure for function CMA_InstallPDO --------------- */
struct _CMA_PDOConfig
  {
  unsigned char  ucPDOType;
  unsigned long  ulCOBID;
  unsigned char  ucTransType;
  unsigned char  ucAccType;
  unsigned char  ucEventNotif;
  unsigned char  ucaDefVal[8];
  unsigned short usEventTimer;
  } PACK1;
typedef struct _CMA_PDOConfig CMA_PDOConfig;

/* ---- output data structure for function CMA_GetVersion ------------------ */
struct _CMA_VersionStruct
  {
  unsigned long  ulHWSerialNumber;    //hardware serial number
  unsigned char  ucHWMainRevision;    //hardware main revision
  unsigned char  ucHWSubRevision;     //hardware sub revision
  unsigned char  ucHWIdentString[18]; //hardware identification string

  unsigned char  ucSWMajorVersion;    //major version number of DLL & FW
  unsigned char  ucSWMinorVersion;    //minor version number of DLL & FW
  unsigned char  ucSWBuild;           //build number of DLL & FW
  } PACK1;
typedef struct _CMA_VersionStruct CMA_VersionStruct;


/**** prototypes of CANopen Master API functions ************************** */

unsigned long  GetTickCount( void);

short CMA_InitializeCard( char * device_name, unsigned char * ucChannelHandle, unsigned char board);
short CMA_SetIntEvent(unsigned char ucChannelHandle, struct sigevent * hEvent);


short CMA_ConfigCANChannel (unsigned char ucChannelHandle,
                                           CMA_CAN_CONFIG stCANConfig);

short CMA_InitSDOMan (unsigned char ucChannelHandle, 
                                     unsigned short usSDOTimeout, 
                                     unsigned short usApplTimeoutFactor);

short CMA_InitNodeMan (unsigned char ucChannelHandle, 
                                      unsigned char ucNodeID);

short CMA_Startup (unsigned char ucChannelHandle);

short CMA_Shutdown (unsigned char ucChannelHandle);

short CMA_ConfigSyncMan (unsigned char ucChannelHandle, 
                                        CMA_SyncManConfig stSyncManConfig);

short CMA_SendSyncObject (unsigned char ucChannelHandle, 
                                         CMA_SyncManConfig stSyncManConfig);

short CMA_AddNode (unsigned char ucChannelHandle,
						          CMA_NodeConfig stNodeConfig);

short CMA_RemoveNode (unsigned char ucChannelHandle,
								     unsigned char ucNodeID,
						             unsigned char ucState); 

short CMA_ChangeState (unsigned char ucChannelHandle,
						              unsigned char ucNodeID,
									  unsigned char ucState);

short CMA_RequestGuarding (unsigned char ucChannelHandle,
					                      unsigned char ucNodeID,
						                  unsigned char ucReqGuard);

short CMA_AbortSDOTransmission (unsigned char ucChannelHandle, 
                                               unsigned char ucNodeID);

short CMA_InitDownload (unsigned char  ucChannelHandle, 
                                       unsigned char  ucNodeID,
                                       unsigned short usIndex,
                                       unsigned char  ucSubIndex,
                                       unsigned long  ulTotalDataSize,
                                       unsigned char  *ucpData);

short CMA_WriteNextSegment (unsigned char  ucChannelHandle, 
                                           unsigned char  ucNodeID,
                                           unsigned short usIndex,
                                           unsigned char  ucSubIndex,
                                           unsigned char  ucDataSize,
                                           unsigned char  *ucpData);

short CMA_InitUpload (unsigned char  ucChannelHandle, 
                                     unsigned char  ucNodeID,
                                     unsigned short usIndex,
                                     unsigned char  ucSubIndex);

short CMA_ReadNextSegment (unsigned char  ucChannelHandle, 
                                          CMA_SDOSeg     *stpSDOSeg);

short CMA_InstallPDO (unsigned char  ucChannelHandle,
                                     CMA_PDOConfig  stPDOConfig, 
                                     unsigned short *uspPDOHandle);

short CMA_RemovePDO  (unsigned char  ucChannelHandle, 
                                     unsigned short usPDOHandle);

short CMA_WritePDO  (unsigned char  ucChannelHandle, 
                                    unsigned short usPDOHandle,
                                    unsigned char  ucDataOffset, 
                                    unsigned char  ucDataLength, 
                                    unsigned char  *ucpData);

short CMA_WritePDOBit  (unsigned char  ucChannelHandle, 
                                       unsigned short usPDOHandle,
                                       unsigned char  ucBitPosition, 
                                       unsigned char  ucBitValue);

short CMA_ReadPDO (unsigned char  ucChannelHandle, 
                                  unsigned short usPDOHandle,
                                  unsigned char  *ucpData);

short CMA_SendRemotePDO (unsigned char  ucChannelHandle, 
                                        unsigned short usPDOHandle);

short CMA_CloseCard ( unsigned char  ucChannelHandle);

short CMA_ReadEvent (unsigned char ucChannelHandle,
                                    CMA_EventStruct *stpEvent);

short CMA_SendL2Message  (unsigned char  ucChannelHandle, 
                                         unsigned long  ulCanID,
                                         unsigned char  ucConfig,
                                         unsigned char  ucDLC,
                                         unsigned char  *ucpData); 

short CMA_GetVersion (unsigned char     ucChannelHandle,
                                     CMA_VersionStruct *stpVersion);

#endif // _CMADEF_H
