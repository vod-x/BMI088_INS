/*
 * @Author: vod vod_x@outlook.com
 * @Date: 2026-03-31 20:42:15
 * @LastEditors: vod vod_x@outlook.com
 * @LastEditTime: 2026-03-31 21:44:53
 * @Description: Transplant inteface for BMI088, including GPIO and SPI operations. 
 * 
 * Copyright (c) 2026 by PeiYangRobot, All Rights Reserved. 
 */
#ifndef PYRO_BMI088_TRANSPLANT_H
#define PYRO_BMI088_TRANSPLANT_H

/* define which spi is used */
#ifndef BMI088_SPI
#define BMI088_SPI hspi2
#endif
/* define which GPIO pins are used for the accelerometer */
#ifndef BMI088_ACC_CS_PIN 
#define BMI088_ACC_CS_PIN GPIO_PIN_0
#endif
#ifndef BMI088_ACC_CS_PORT
#define BMI088_ACC_CS_PORT GPIOC
#endif
/* define which GPIO pins are used for the gyroscope */
#ifndef BMI088_GYRO_CS_PIN
#define BMI088_GYRO_CS_PIN GPIO_PIN_3
#endif
#ifndef BMI088_GYRO_CS_PORT
#define BMI088_GYRO_CS_PORT GPIOC
#endif

/* define delay functions(units ms), include function used in bare computer and in rtos,
    function BARE_DELAY will be used in bmi088 init. During init, it should wait
    for some time to ensure proper initialization. Init should be called before
    enter rtos to avoid conflicts, because of long delay. */
#ifndef BARE_DELAY
#define BARE_DELAY(x) HAL_Delay(x)
#endif
#ifndef RTOS_DELAY
#define RTOS_DELAY(x) vTaskDelay(x)
#endif

/* define macros for chip select operations */
#define BMI088_CS_ACC_L() HAL_GPIO_WritePin(BMI088_ACC_CS_PORT, BMI088_ACC_CS_PIN, GPIO_PIN_RESET)
#define BMI088_CS_ACC_H() HAL_GPIO_WritePin(BMI088_ACC_CS_PORT, BMI088_ACC_CS_PIN, GPIO_PIN_SET)
#define BMI088_CS_GYRO_L() HAL_GPIO_WritePin(BMI088_GYRO_CS_PORT, BMI088_GYRO_CS_PIN, GPIO_PIN_RESET)
#define BMI088_CS_GYRO_H() HAL_GPIO_WritePin(BMI088_GYRO_CS_PORT, BMI088_GYRO_CS_PIN, GPIO_PIN_SET)

/* define macros for read single reg */


#endif //PYRO_BMI088_TRANSPLANT_H