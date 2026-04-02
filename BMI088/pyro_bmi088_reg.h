#ifndef BMI088_REG_H
#define BMI088_REG_H


#define BMI_SPI_RD_MASK 0x80
#define BMI_SPI_WR_MASK 0x7F

/******************************** ACC_CHIP_ID *********************************/
/* Address of accelerometer chip ID registers and values. This reg is read-only and 
   contains the chip ID of the accelerometer. Its value should be checked whether it 
   matches the expected value during initialization to ensure proper communication 
   with the sensor. */
#define BMI088_ACC_CHIP_ID 0x00 
#define BMI088_ACC_CHIP_ID_VALUE 0x1E
/******************************** ACC_CHIP_ID *********************************/

#define BMI088_ACC_ERR_REG 0x02
#define BMI088_ACCEL_CONGIF_ERROR_SHFITS 0x2
#define BMI088_ACCEL_CONGIF_ERROR (1 << BMI088_ACCEL_CONGIF_ERROR_SHFITS)
#define BMI088_FATAL_ERROR_SHFITS 0x0
#define BMI088_FATAL_ERROR (1 << BMI088_FATAL_ERROR_SHFITS)

#define BMI088_ACC_STATUS 0x03
#define BMI088_ACCEL_DRDY_SHFITS 0x7
#define BMI088_ACCEL_DRDY (1 << BMI088_ACCEL_DRDY_SHFITS)

#define BMI088_ACCEL_XOUT_L 0x12
#define BMI088_ACCEL_XOUT_M 0x13
#define BMI088_ACCEL_YOUT_L 0x14
#define BMI088_ACCEL_YOUT_M 0x15
#define BMI088_ACCEL_ZOUT_L 0x16
#define BMI088_ACCEL_ZOUT_M 0x17

#define BMI088_SENSORTIME_DATA_L 0x18
#define BMI088_SENSORTIME_DATA_M 0x19
#define BMI088_SENSORTIME_DATA_H 0x1A

#define BMI088_ACC_INT_STAT_1 0x1D
#define BMI088_ACCEL_DRDY_INTERRUPT_SHFITS 0x7
#define BMI088_ACCEL_DRDY_INTERRUPT (1 << BMI088_ACCEL_DRDY_INTERRUPT_SHFITS)

#define BMI088_TEMP_M 0x22
#define BMI088_TEMP_L 0x23

/********************************  ACC_CONF ***********************************/
/* Addrees of accelerometer configuration(OSR and ODR) register and 
   corresponding values. The value of OSR and ODR will influence the 
   bandwidth(3dB) of the accelerometer low pass filter in the chip.
 * =============================================================================
 * | ODR [Hz] | Normal (acc_bwp=0xA) | OSR2 (acc_bwp=0x9) | OSR4 (acc_bwp=0x8) |
 * |----------|----------------------|--------------------|--------------------|
 * | 12.5     | 5 Hz                  | 2 Hz                  | 1 Hz           |
 * | 25       | 10 Hz                 | 5 Hz                  | 3 Hz           |
 * | 50       | 20 Hz                 | 9 Hz                  | 5 Hz           |
 * | 100      | 40 Hz                 | 19 Hz                 | 10 Hz          |
 * | 200      | 80 Hz                 | 38 Hz                 | 20 Hz          |
 * | 400      | 145 Hz                | 75 Hz                 | 40 Hz          |
 * | 800      | 230 Hz (200 Hz for z) | 140 Hz                | 80 Hz          |
 * | 1600     | 280 Hz (245 Hz for z) | 234 Hz (215 Hz for z) | 145 Hz         |
 * =============================================================================
 */
#define BMI088_ACC_CONF 0x40

/* OSR(over sampling rate) and ODR(output data rate) */
#define BMI088_ACC_CONF_MUST_Set 0x80
#define BMI088_ACC_BWP_SHFITS 0x4
#define BMI088_ACC_OSR4 (0x0 << BMI088_ACC_BWP_SHFITS)
#define BMI088_ACC_OSR2 (0x1 << BMI088_ACC_BWP_SHFITS)
#define BMI088_ACC_NORMAL (0x2 << BMI088_ACC_BWP_SHFITS)

#define BMI088_ACC_ODR_SHFITS 0x0
#define BMI088_ACC_12_5_HZ (0x5 << BMI088_ACC_ODR_SHFITS)
#define BMI088_ACC_25_HZ (0x6 << BMI088_ACC_ODR_SHFITS)
#define BMI088_ACC_50_HZ (0x7 << BMI088_ACC_ODR_SHFITS)
#define BMI088_ACC_100_HZ (0x8 << BMI088_ACC_ODR_SHFITS)
#define BMI088_ACC_200_HZ (0x9 << BMI088_ACC_ODR_SHFITS)
#define BMI088_ACC_400_HZ (0xA << BMI088_ACC_ODR_SHFITS)
#define BMI088_ACC_800_HZ (0xB << BMI088_ACC_ODR_SHFITS)
#define BMI088_ACC_1600_HZ (0xC << BMI088_ACC_ODR_SHFITS)
/********************************  ACC_CONF ***********************************/


/*******************************  ACC_RANGE ***********************************/
/* Address of accelerometer range register and corresponding values */
#define BMI088_ACC_RANGE 0x41
/* Range values, 1 G = 10 m/s^2 */
#define BMI088_ACC_RANGE_SHFITS 0x0
#define BMI088_ACC_RANGE_3G (0x0 << BMI088_ACC_RANGE_SHFITS)
#define BMI088_ACC_RANGE_6G (0x1 << BMI088_ACC_RANGE_SHFITS)
#define BMI088_ACC_RANGE_12G (0x2 << BMI088_ACC_RANGE_SHFITS)
#define BMI088_ACC_RANGE_24G (0x3 << BMI088_ACC_RANGE_SHFITS)
/*******************************  ACC_RANGE ***********************************/

/*******************************  ACC_IO_CFG **********************************/
/* Address of accelerometer IO control registers and values. */
#define BMI088_INT1_IO_CTRL 0x53
/* Set the IO is input or output */
#define BMI088_ACC_INT1_IO_OUTPUT_SHFITS 0x4
#define BMI088_ACC_INT1_IO_OUTPUT (0x1 << BMI088_ACC_INT1_IO_OUTPUT_SHFITS)
#define BMI088_ACC_INT1_IO_INPUT_SHFITS 0x3
#define BMI088_ACC_INT1_IO_INPUT (0x1 << BMI088_ACC_INT1_IO_INPUT_SHFITS)
/* Set the IO mode is push-pull(PP) or open-drain(OD) */
#define BMI088_ACC_INT1_GPIO_MODE_SHFITS 0x2
#define BMI088_ACC_INT1_GPIO_PP (0x0 << BMI088_ACC_INT1_GPIO_MODE_SHFITS)
#define BMI088_ACC_INT1_GPIO_OD (0x1 << BMI088_ACC_INT1_GPIO_MODE_SHFITS)
/* Set the IO valid level is high or low */
#define BMI088_ACC_INT1_GPIO_LVL_SHFITS 0x1
#define BMI088_ACC_INT1_GPIO_LOW (0x0 << BMI088_ACC_INT1_GPIO_LVL_SHFITS)
#define BMI088_ACC_INT1_GPIO_HIGH (0x1 << BMI088_ACC_INT1_GPIO_LVL_SHFITS)
/* Same as INT1 */
#define BMI088_INT2_IO_CTRL 0x54
#define BMI088_ACC_INT2_IO_OUTPUT_SHFITS 0x4
#define BMI088_ACC_INT2_IO_OUTPUT (0x1 << BMI088_ACC_INT2_IO_OUTPUT_SHFITS)
#define BMI088_ACC_INT2_IO_INPUT_SHFITS 0x3
#define BMI088_ACC_INT2_IO_INPUT (0x1 << BMI088_ACC_INT2_IO_INPUT_SHFITS)
#define BMI088_ACC_INT2_GPIO_MODE_SHFITS 0x2
#define BMI088_ACC_INT2_GPIO_PP (0x0 << BMI088_ACC_INT2_GPIO_MODE_SHFITS)
#define BMI088_ACC_INT2_GPIO_OD (0x1 << BMI088_ACC_INT2_GPIO_MODE_SHFITS)
#define BMI088_ACC_INT2_GPIO_LVL_SHFITS 0x1
#define BMI088_ACC_INT2_GPIO_LOW (0x0 << BMI088_ACC_INT2_GPIO_LVL_SHFITS)
#define BMI088_ACC_INT2_GPIO_HIGH (0x1 << BMI088_ACC_INT2_GPIO_LVL_SHFITS)
/*******************************  ACC_IO_CFG **********************************/

/******************************* ACC_INT_MAP **********************************/
/* Address of accelerometer interrupt mapping registers and values. */
#define BMI088_INT_MAP_DATA 0x58
/* Mapping data ready intrruppt to IO2 */
#define BMI088_ACC_INT2_DRDY_INTERRUPT_SHFITS 0x6
#define BMI088_ACC_INT2_DRDY_INTERRUPT (0x1 << BMI088_ACC_INT2_DRDY_INTERRUPT_SHFITS)
/* Mapping FIFO watermark interrupt to IO2 */
#define BMI088_ACC_INT2_FWM_INTERRUPT_SHFITS 0x5
#define BMI088_ACC_INT2_FWM_INTERRUPT (0x1 << BMI088_ACC_INT2_FWM_INTERRUPT_SHFITS) 
/* Mapping FIFO full interrupt to IO2 */
#define BMI088_ACC_INT2_FIFO_FULL_INTERRUPT_SHFITS 0x4
#define BMI088_ACC_INT2_FIFO_FULL_INTERRUPT (0x1 << BMI088_ACC_INT2_FIFO_FULL_INTERRUPT_SHFITS)
/* Same as INT2 */
#define BMI088_ACC_INT1_DRDY_INTERRUPT_SHFITS 0x2
#define BMI088_ACC_INT1_DRDY_INTERRUPT (0x1 << BMI088_ACC_INT1_DRDY_INTERRUPT_SHFITS)
#define BMI088_ACC_INT1_FWM_INTERRUPT_SHFITS 0x1
#define BMI088_ACC_INT1_FWM_INTERRUPT (0x1 << BMI088_ACC_INT1_FWM_INTERRUPT_SHFITS)
#define BMI088_ACC_INT1_FIFO_FULL_INTERRUPT_SHFITS 0x0      
#define BMI088_ACC_INT1_FIFO_FULL_INTERRUPT (0x1 << BMI088_ACC_INT1_FIFO_FULL_INTERRUPT_SHFITS)
/******************************* ACC_INT_MAP **********************************/

#define BMI088_ACC_SELF_TEST 0x6D
#define BMI088_ACC_SELF_TEST_OFF 0x00
#define BMI088_ACC_SELF_TEST_POSITIVE_SIGNAL 0x0D
#define BMI088_ACC_SELF_TEST_NEGATIVE_SIGNAL 0x09

/******************************* ACC_PWR_CONF *********************************/
/* Address of accelerometer power configuration registers and values. Determine 
   the power mode of the accelerometer. */
#define BMI088_ACC_PWR_CONF 0x7C
#define BMI088_ACC_PWR_SUSPEND_MODE 0x03
#define BMI088_ACC_PWR_ACTIVE_MODE 0x00
/******************************* ACC_PWR_CONF *********************************/

/******************************* ACC_PWR_CTRL *********************************/
/* Address of accelerometer power control registers and values. Determine 
   whether the accelerometer is enabled or disabled. */
#define BMI088_ACC_PWR_CTRL 0x7D
#define BMI088_ACC_ENABLE_ACC_OFF 0x00
#define BMI088_ACC_ENABLE_ACC_ON 0x04
/******************************* ACC_PWR_CTRL *********************************/

#define BMI088_ACC_SOFTRESET 0x7E
#define BMI088_ACC_SOFTRESET_VALUE 0xB6

/******************************* GYRO_CHIP_ID *********************************/
/* Address of gyroscope chip ID registers and values. This reg is read-only and 
   contains the chip ID of the gyroscope. Its value should be checked whether it 
   matches the expected value during initialization to ensure proper 
   communication with the sensor. */
#define BMI088_GYRO_CHIP_ID 0x00
#define BMI088_GYRO_CHIP_ID_VALUE 0x0F
/******************************* GYRO_CHIP_ID *********************************/

#define BMI088_GYRO_X_L 0x02
#define BMI088_GYRO_X_H 0x03
#define BMI088_GYRO_Y_L 0x04
#define BMI088_GYRO_Y_H 0x05
#define BMI088_GYRO_Z_L 0x06
#define BMI088_GYRO_Z_H 0x07

#define BMI088_GYRO_INT_STAT_1 0x0A
#define BMI088_GYRO_DYDR_SHFITS 0x7
#define BMI088_GYRO_DYDR (0x1 << BMI088_GYRO_DYDR_SHFITS)

/****************************** GYRO_RANGE ************************************/
/* Address of gyroscope range registers and values. The range is +- value. 
   Larger range is, less sensitive the gyroscope is. 
   Unit: dps (degrees per second) */
#define BMI088_GYRO_RANGE 0x0F
#define BMI088_GYRO_RANGE_SHFITS 0x0
#define BMI088_GYRO_2000 (0x0 << BMI088_GYRO_RANGE_SHFITS)
#define BMI088_GYRO_1000 (0x1 << BMI088_GYRO_RANGE_SHFITS)
#define BMI088_GYRO_500 (0x2 << BMI088_GYRO_RANGE_SHFITS)
#define BMI088_GYRO_250 (0x3 << BMI088_GYRO_RANGE_SHFITS)
#define BMI088_GYRO_125 (0x4 << BMI088_GYRO_RANGE_SHFITS)
/****************************** GYRO_RANGE ************************************/

/**************************** GYRO_BANDWIDTH **********************************/
/* Address of gyroscope bandwidth registers and values.*/
#define BMI088_GYRO_BANDWIDTH 0x10
/* The high bit must be set. Should |0x80 to set this bit when writing */
#define BMI088_GYRO_BANDWIDTH_MUST_Set 0x80
/* The first num means ODR(output data rate), the second num means bandwidth */
#define BMI088_GYRO_2000_532_HZ 0x00
#define BMI088_GYRO_2000_230_HZ 0x01
#define BMI088_GYRO_1000_116_HZ 0x02
#define BMI088_GYRO_400_47_HZ 0x03
#define BMI088_GYRO_200_23_HZ 0x04
#define BMI088_GYRO_100_12_HZ 0x05
#define BMI088_GYRO_200_64_HZ 0x06
#define BMI088_GYRO_100_32_HZ 0x07
/**************************** GYRO_BANDWIDTH **********************************/

/******************************* GYRO_LPM *************************************/
/* Address of gyroscope power modes and its values. Note that only swtiching 
   bwtween normal mode and suspend mode is allowed, it is not possible to 
   switch between suspend mode and deep suspend mode. */
#define BMI088_GYRO_LPM1 0x11

#define BMI088_GYRO_NORMAL_MODE 0x00
#define BMI088_GYRO_SUSPEND_MODE 0x80
#define BMI088_GYRO_DEEP_SUSPEND_MODE 0x20
/******************************* GYRO_LPM *************************************/

#define BMI088_GYRO_SOFTRESET 0x14
#define BMI088_GYRO_SOFTRESET_VALUE 0xB6

/***************************** GYRO_INT_CTRL **********************************/
/* Address of gyroscope interrupt control registers and values. Type of 
   interrupt include DRDY(data ready) and FIFO*/
#define BMI088_GYRO_INT_CTRL 0x15
#define BMI088_GYRO_INT_DRDY_SHFITS 0x7
#define BMI088_DRDY_OFF (0x0 << BMI088_GYRO_INT_DRDY_SHFITS)
#define BMI088_DRDY_ON (0x1 << BMI088_GYRO_INT_DRDY_SHFITS)
#define BMI088_GYRO_INT_FIFO_SHFITS 0x6
#define BMI088_FIOF_OFF (0x0 << BMI088_GYRO_INT_FIFO_SHFITS)
#define BMI088_FIOF_ON (0x1 << BMI088_GYRO_INT_FIFO_SHFITS)
/***************************** GYRO_INT_CTRL **********************************/

/*********************** GYRO_INT3_INT4_IO_CONF *******************************/
/* Address of gyroscope interrupt 3 and 4 IO configuration registers and values.
   Include the mode is PP(push-pull) or OD(open-drain), the valid level is high 
   or low. */
#define BMI088_GYRO_INT3_INT4_IO_CONF 0x16
#define BMI088_GYRO_INT4_GPIO_MODE_SHFITS 0x3
#define BMI088_GYRO_INT4_GPIO_PP (0x0 << BMI088_GYRO_INT4_GPIO_MODE_SHFITS)
#define BMI088_GYRO_INT4_GPIO_OD (0x1 << BMI088_GYRO_INT4_GPIO_MODE_SHFITS)
#define BMI088_GYRO_INT4_GPIO_LVL_SHFITS 0x2
#define BMI088_GYRO_INT4_GPIO_LOW (0x0 << BMI088_GYRO_INT4_GPIO_LVL_SHFITS)
#define BMI088_GYRO_INT4_GPIO_HIGH (0x1 << BMI088_GYRO_INT4_GPIO_LVL_SHFITS)
#define BMI088_GYRO_INT3_GPIO_MODE_SHFITS 0x1
#define BMI088_GYRO_INT3_GPIO_PP (0x0 << BMI088_GYRO_INT3_GPIO_MODE_SHFITS)
#define BMI088_GYRO_INT3_GPIO_OD (0x1 << BMI088_GYRO_INT3_GPIO_MODE_SHFITS)
#define BMI088_GYRO_INT3_GPIO_LVL_SHFITS 0x0
#define BMI088_GYRO_INT3_GPIO_LOW (0x0 << BMI088_GYRO_INT3_GPIO_LVL_SHFITS)
#define BMI088_GYRO_INT3_GPIO_HIGH (0x1 << BMI088_GYRO_INT3_GPIO_LVL_SHFITS)
/*********************** GYRO_INT3_INT4_IO_CONF *******************************/

/*********************** GYRO_INT3_INT4_IO_MAP *******************************/
/* Address of gyroscope interrupt 3 and 4 IO mapping registers and values. 
   Determine the mapping of interrupt to INT3 or INT4. */
#define BMI088_GYRO_INT3_INT4_IO_MAP 0x18
#define BMI088_GYRO_DRDY_IO_INT3_SHFITS 0x0
#define BMI088_GYRO_DRDY_IO_INT3 (0x0 << BMI088_GYRO_DRDY_IO_INT3_SHFITS)
#define BMI088_GYRO_FIFO_IO_INT3_SHFITS 0x2
#define BMI088_GYRO_FIFO_IO_INT3 (0x1 << BMI088_GYRO_FIFO_IO_INT3_SHFITS)
#define BMI088_GYRO_FIFO_IO_INT4_SHFITS 0x5
#define BMI088_GYRO_FIFO_IO_INT4 (0x0 << BMI088_GYRO_FIFO_IO_INT4_SHFITS)
#define BMI088_GYRO_DRDY_IO_INT4_SHFITS 0x7
#define BMI088_GYRO_DRDY_IO_INT4 (0x1 << BMI088_GYRO_DRDY_IO_INT4_SHFITS)
/*********************** GYRO_INT3_INT4_IO_MAP *******************************/

#define BMI088_GYRO_SELF_TEST 0x3C
#define BMI088_GYRO_RATE_OK_SHFITS 0x4
#define BMI088_GYRO_RATE_OK (0x1 << BMI088_GYRO_RATE_OK_SHFITS)
#define BMI088_GYRO_BIST_FAIL_SHFITS 0x2
#define BMI088_GYRO_BIST_FAIL (0x1 << BMI088_GYRO_BIST_FAIL_SHFITS)
#define BMI088_GYRO_BIST_RDY_SHFITS 0x1
#define BMI088_GYRO_BIST_RDY (0x1 << BMI088_GYRO_BIST_RDY_SHFITS)
#define BMI088_GYRO_TRIG_BIST_SHFITS 0x0
#define BMI088_GYRO_TRIG_BIST (0x1 << BMI088_GYRO_TRIG_BIST_SHFITS)

#endif
