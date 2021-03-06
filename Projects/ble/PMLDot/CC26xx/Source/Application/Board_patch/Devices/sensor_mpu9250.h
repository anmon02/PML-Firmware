/*******************************************************************************
*  Filename:       sensor_mpu9250.h
*  Revised:        $Date: 2015-03-07 10:33:11 +0100 (fr, 07 mar 2015) $
*  Revision:       $Revision: 12329 $
*
*  Description:    Driver for the InvenSense MPU9250 Motion Processing Unit
*
*  Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com/
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*******************************************************************************/
#ifndef SENSOR_MPU9250_H
#define SENSOR_MPU9250_H

#ifdef __cplusplus
extern "C" {
#endif

/* -----------------------------------------------------------------------------
 *                                          Includes
 * -----------------------------------------------------------------------------
 */
#include "stdint.h"
#include "stdbool.h"

/* -----------------------------------------------------------------------------
 *                                          Constants
 * -----------------------------------------------------------------------------
 */
//Accel config 2
#define ACCEL_CONF_2_FCHOICE		  0X08
#define ACCEL_CONF_2_460HZ			  0X00
#define ACCEL_CONF_2_184HZ			  0X01
#define ACCEL_CONF_2_92HZ			  0X02
#define ACCEL_CONF_2_41HZ			  0X03
#define ACCEL_CONF_2_20HZ			  0X04
#define ACCEL_CONF_2_10HZ			  0X05
#define ACCEL_CONF_2_5HZ			  0X06

//Gyro DLPF
#define CONFIG_DLPF_CONF			  0x07
#define CONFIG_DLPF_250HZ			  0X00
#define CONFIG_DLPF_184HZ			  0X01
#define CONFIG_DLPF_92HZ 			  0X02
#define CONFIG_DLPF_41HZ			  0X03
#define CONFIG_DLPF_20HZ			  0X04
#define CONFIG_DLPF_10HZ			  0X05
#define CONFIG_DLPF_5HZ			      0X06

// Accelerometer ranges
#define ACC_RANGE_2G      0
#define ACC_RANGE_4G      1
#define ACC_RANGE_8G      2
#define ACC_RANGE_16G     3
#define ACC_RANGE_INVALID 0xFF

// Gyro ranges
#define GYRO_RANGE_250     0
#define GYRO_RANGE_500     1
#define GYRO_RANGE_1000    2
#define GYRO_RANGE_2000    3
#define GYRO_RANGE_INVALID 0xFF

// Axis bitmaps
#define MPU_AX_GYR        0x07
#define MPU_AX_ACC        0x38
#define MPU_AX_MAG        0x40
#define MPU_AX_ALL        0x7F

// Interrupt status bit
#define MPU_DATA_READY    0x01
#define MPU_MOVEMENT      0x40

// Magnetometer status
#define MAG_STATUS_OK     0x00
#define MAG_READ_ST_ERR   0x01
#define MAG_DATA_NOT_RDY  0x02
#define MAG_OVERFLOW      0x03
#define MAG_READ_DATA_ERR 0x04
#define MAG_BYPASS_FAIL   0x05
#define MAG_NO_POWER      0x06

/* ----------------------------------------------------------------------------
 *                                           Typedefs
 * -----------------------------------------------------------------------------
*/
typedef void (*MpuCallbackFn_t)(void);

/* -----------------------------------------------------------------------------
 *                                          Functions
 * -----------------------------------------------------------------------------
 */
bool sensorMpu9250Init(void);
bool sensorMpu9250Reset(void);
void sensorMpu9250RegisterCallback(MpuCallbackFn_t);
bool sensorMpu9250Test(void);

void sensorMpu9250PowerOn(void);
void sensorMpu9250PowerOff(void);
bool sensorMpu9250PowerIsOn(void);

void sensorMpu9250Enable(uint16_t config);
void sensorMpu9250Calibrate(float * dest1, float * dest2);
bool sensorMpu9250WomEnable(uint8_t threshold);

bool sensorMpu9250AccSetFilter(uint8_t bandwidth);
bool sensorMpu9250AccSetRange(uint8_t range);
uint8_t sensorMpu9250AccReadRange(void);
bool sensorMpu9250AccRead(uint16_t *rawData);
float sensorMpu9250AccConvert(int16_t *rawValue);

bool sensorMpu9250GyroSetFilter(uint8_t bandwidth);
bool sensorMpu9250GyroSetRange(uint8_t newRange);
void sensorMpu9250GyroCalSet(int16_t *data );
void sensorMpu9250GyroCal(int16_t *data );
bool sensorMpu9250GyroRead(uint16_t *rawData);
float sensorMpu9250GyroConvert(int16_t *rawValue);
uint8_t sensorMpu9250IntStatus(void);

bool sensorMpu9250MagTest(void);
void sensorMpu9250MagCal(int16_t *data);
void sensorMpu9250MagSetCal(int16_t *data);
uint8_t sensorMpu9250MagRead(int16_t *data);
uint8_t sensorMpu9250MagStatus(void);
void sensorMpu9250MagReset(void);

/*******************************************************************************
*/

#ifdef __cplusplus
};
#endif

#endif
