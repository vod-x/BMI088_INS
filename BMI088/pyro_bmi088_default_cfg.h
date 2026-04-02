#ifndef PYRO_BMI088_DEFAULT_CFG_H
#define PYRO_BMI088_DEFAULT_CFG_H

#include <stdint.h>
#include "pyro_bmi088_reg.h"

namespace pyro{

enum bmi088_acc_error_code_t
{
    ACC_OK = 0,
    /* BMI088 is not enabled, it happens when write reg BMI088_ACC_PWR_CTRL */
    ACC_EN = 1,
    /* BMI088 is in suspend mode instead of active mode, it happens when write
       reg BMI088_ACC_PWR_CTRL. */
    ACC_MODE = 1  << 1,
    /* Configuration error, it happens when write reg BMI088_ACC_CONF */
    ACC_CONF = 1  << 2,
    /* Range error, it happens when write reg BMI088_ACC_RANGE */
    ACC_RANGE = 1 << 3,
    /* IO cfg error, it happens when write reg BMI088_INT1_IO_CTRL or BMI088_INT2_IO_CTRL */
    ACC_IO1 = 1   << 4,
    ACC_IO2 = 1   << 5,
    ACC_MAP = 1   << 6,
};

enum bmi088_gyro_error_code_t
{
    GYRO_OK = 0,
    /* BMI088 is not enabled, it happens when write reg BMI088_GYRO_LPM1 */
    GYRO_EN = 1,
    /* Configuration error, it happens when write reg BMI088_GYRO_BANDWIDTH */
    GYRO_BANDWIDTH = 1  << 2,
    /* Range error, it happens when write reg BMI088_GYRO_RANGE */
    GYRO_RANGE = 1 << 3,
    /* Interrupt error, it happens when write reg BMI088_GYRO_INT_CTRL */
    GYRO_INT = 1 << 4,
    /* IO configuration error, it happens when write reg BMI088_GYRO_INT3_INT4_IO_CONF */
    GYRO_IO = 1 << 5,
    /* Mapping error, it happens when write reg BMI088_GYRO_INT_MAP */
    GYRO_MAP = 1 << 6,
};
/* The configuration for BMI088 accelerometer and gyroscope. It is a nx3 array,
   where each row represents a register address, a set value, and a error code. */
#define BMI088_ACC_CFG_NUM 6
static uint8_t bmi088_acc_cfg[BMI088_ACC_CFG_NUM][3] = {
    /******** Cfgs below should not be changed *********/

    /* Turn accelerometer on.*/
    {BMI088_ACC_PWR_CTRL, BMI088_ACC_ENABLE_ACC_ON, bmi088_acc_error_code_t::ACC_EN},
    /* Set accelerometer to active mode. Defualt mode is suspend mode, under 
       suspend mode, the accelerometer does not measure acceleration. */
    {BMI088_ACC_PWR_CONF, BMI088_ACC_PWR_ACTIVE_MODE, bmi088_acc_error_code_t::ACC_MODE},
    
    /******* Cfg below can be changed in user cfg ******/  

    /* Set OSR(over sampling rate) and ODR(output data rate). OSR and ODR will 
      influence the bandwidth(3dB) of the accelerometer low pass filter in 
      the chip. Detailed correspondence can be found in "pyro_bmi088_reg.h" */
    {BMI088_ACC_CONF, BMI088_ACC_NORMAL | BMI088_ACC_800_HZ, bmi088_acc_error_code_t::ACC_CONF},
    /* Set accelerometer range. It is +- value. Larger range is, less sensitive 
        the accelerometer is. */
    {BMI088_ACC_RANGE, BMI088_ACC_RANGE_6G, bmi088_acc_error_code_t::ACC_RANGE},
    /* Configure the io of accelerometer. Include the io is input or output, 
       mode is push-pull or open-drain, and level is high or low. In this 
       project, pin 1 is linked to the main chip, so we only configure pin1.
       Because we will use pin1 as a interrupt io, so we set it is output, 
       push-pull mode. The valid level is depend on the interrupt type. Set 
       high lelvel in using rising edge, set low level in using falling edge. */
    {BMI088_INT1_IO_CTRL, BMI088_ACC_INT1_IO_OUTPUT | BMI088_ACC_INT1_GPIO_PP | BMI088_ACC_INT1_GPIO_HIGH, bmi088_acc_error_code_t::ACC_IO1},
    /* Set interrupt mapping. Configure the interrupt signal(data ready, fifo 
       watermark, fifo full) to output in IO1 or IO2. In this project, we use
       dada ready int, so map it to IO1. */
    {BMI088_INT_MAP_DATA, BMI088_ACC_INT1_DRDY_INTERRUPT, bmi088_acc_error_code_t::ACC_MAP},
};

#define BMI088_GYRO_CFG_NUM 6
static uint8_t bmi088_gyro_cfg[BMI088_GYRO_CFG_NUM][3] = {
    /******** Cfgs below should not be changed *********/

    /* Turn gyroscope on.*/
    {BMI088_GYRO_LPM1, BMI088_GYRO_NORMAL_MODE, bmi088_gyro_error_code_t::GYRO_EN},
    
    /******* Cfg below can be changed in user cfg ******/  

    /* Set ODR(output data rate). Value of ODR will influence the bandwidth(3dB)
     of the gyroscope low pass filter in the chip. Detailed correspondence can 
     be found in "pyro_bmi088_reg.h" */
    {BMI088_GYRO_BANDWIDTH, BMI088_GYRO_BANDWIDTH_MUST_Set | BMI088_GYRO_2000_532_HZ, bmi088_gyro_error_code_t::GYRO_BANDWIDTH},
    /* Set gyroscope range. It is +- value. Larger range is, less sensitive the 
       gyroscope is. */
    {BMI088_GYRO_RANGE, BMI088_GYRO_2000, bmi088_gyro_error_code_t::GYRO_RANGE},
    /* Set gyroscope interrupt is enable or disable. Type of interrupt include
     DRDY(data ready) and FIFO. In this project, we use DRDY interrupt. */
    {BMI088_GYRO_INT_CTRL, BMI088_DRDY_ON, bmi088_gyro_error_code_t::GYRO_INT},
    /* Set gyroscope IO configuration, including its mode and valid level. In
       this project, we use DRDY interrupt, and type of interrupt is rising 
       edge. So we set it is push-pull mode and high level. And only int3 is 
       conected with the main chip. */
    {BMI088_GYRO_INT3_INT4_IO_CONF, BMI088_GYRO_INT3_GPIO_PP | BMI088_GYRO_INT3_GPIO_HIGH, bmi088_gyro_error_code_t::GYRO_IO},
    /* Set gyroscope interrupt mapping. Map the DRDY interrupt to INT3 or INT4. 
       In this project, we map it to INT3. */
    {BMI088_GYRO_INT3_INT4_IO_MAP,BMI088_GYRO_DRDY_IO_INT3 , bmi088_gyro_error_code_t::GYRO_MAP},
};

}
#endif //PYRO_BMI088_DEFAULT_CFG_H 


