/**
  ******************************************************************************
  * @file    stm3210c_eval_eeprom.h
  * @author  MCD Application Team
  * @version V6.1.0
  * @date    14-April-2017
  * @brief   This file contains all the functions prototypes for 
  *          the stm3210c_eval_eeprom.c firmware driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM3210C_EVAL_EEPROM_H
#define __STM3210C_EVAL_EEPROM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm3210c_eval.h"

/** @addtogroup BSP
  * @{
  */
  
/** @addtogroup STM3210C_EVAL
  * @{
  */
  
/** @addtogroup STM3210C_EVAL_EEPROM
  * @{
  */  

/** @defgroup STM3210C_EVAL_EEPROM_Exported_Types STM3210C EVAL EEPROM Exported Types
  * @{
  */ 
typedef struct
{
  uint32_t  (*Init)(void);
  uint32_t  (*ReadBuffer)(uint8_t* , uint16_t , uint32_t* );
  uint32_t  (*WritePage)(uint8_t* , uint16_t , uint32_t* );
}EEPROM_DrvTypeDef;
/**
  * @}
  */
  
/** @defgroup STM3210C_EVAL_EEPROM_Exported_Constants STM3210C EVAL EEPROM Exported Constants
  * @{
  */
/* EEPROMs hardware address and page size */ 
#define EEPROM_ADDRESS_M24C64_32      0xA0    /* Support the devices: M24C32 and M24C64 */
/* The M24C08W contains 4 blocks (128byte each) with the addresses below: E2 = 0 
   EEPROM Addresses defines */
#define EEPROM_ADDRESS_M24C08_BLOCK0      0xA0
#define EEPROM_ADDRESS_M24C08_BLOCK1      0xA2
#define EEPROM_ADDRESS_M24C08_BLOCK2      0xA4
#define EEPROM_ADDRESS_M24C08_BLOCK3      0xA6

#define EEPROM_PAGESIZE_M24C64_32         32       /* Support the devices: M24C32 and M24C64 */
#define EEPROM_PAGESIZE_M24C08            16       /* Support the device: M24C08. */
      
/* EEPROM BSP return values */
#define EEPROM_OK                       0
#define EEPROM_FAIL                     1   
#define EEPROM_TIMEOUT                  2   
 
/* EEPROM BSP devices definition list supported */
#define BSP_EEPROM_M24C64_32              1       /* RF I2C EEPROM M24C32 and M24C64 */
#define BSP_EEPROM_M24C08                 2       /* RF I2C EEPROM M24C08 */

/* Maximum number of trials for EEPROM_I2C_WaitEepromStandbyState() function */
#define EEPROM_MAX_TRIALS               300
/**
  * @}
  */ 

/** @addtogroup STM3210C_EVAL_EEPROM_Exported_Functions
  * @{
  */ 
uint32_t  BSP_EEPROM_Init(void);
void      BSP_EEPROM_SelectDevice(uint8_t DeviceID);
uint32_t  BSP_EEPROM_ReadBuffer(uint8_t* pBuffer, uint16_t ReadAddr, uint32_t* NumByteToRead);
uint32_t  BSP_EEPROM_WriteBuffer(uint8_t* pBuffer, uint16_t WriteAddr, uint32_t NumByteToWrite);

/* USER Callbacks: This function is declared as __weak in EEPROM driver and 
   should be implemented into user application.  
   BSP_EEPROM_TIMEOUT_UserCallback() function is called whenever a timeout condition 
   occur during communication (waiting on an event that doesn't occur, bus 
   errors, busy devices ...). */
void BSP_EEPROM_TIMEOUT_UserCallback(void);


/* Link functions for I2C EEPROM peripheral */
void                    EEPROM_I2C_IO_Init(void);
HAL_StatusTypeDef       EEPROM_I2C_IO_WriteData(uint16_t DevAddress, uint16_t MemAddress, uint8_t* pBuffer, uint32_t BufferSize);
HAL_StatusTypeDef       EEPROM_I2C_IO_ReadData(uint16_t DevAddress, uint16_t MemAddress, uint8_t* pBuffer, uint32_t BufferSize);
HAL_StatusTypeDef       EEPROM_I2C_IO_IsDeviceReady(uint16_t DevAddress, uint32_t Trials);

#ifdef __cplusplus
}
#endif

#endif /* __STM3210C_EVAL_EEPROM_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */ 

