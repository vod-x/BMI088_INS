#include "pyro_bmi088.h"
#include "pyro_bmi088_transplant.h"
#include "pyro_bmi088_reg.h"

#include "stm32h7xx_hal.h"
#include "spi.h"

/* If user configuration file exists, include it. Else, include the default 
   configuration. */
#if __has_include("pyro_bmi088_user_cfg.h")
#include "pyro_bmi088_user_cfg.h"
#else
#include "pyro_bmi088_default_cfg.h"
#endif

using namespace pyro;
#define CHECK_RET(expr) do { \
    if ((expr) != bmi088_drv::OK) { \
        return bmi088_drv::ERROR; \
    } \
} while(0)

extern "C" {

uint8_t test_buf[32];
void main_tread(void)
{
    bmi088_drv bmi088;
    bmi088.init();
    while (1)
    {
        /* do nothing */
    }
}
}


bmi088_drv::bmi088_drv()
{
    /* do nothing */
}

bmi088_drv::~bmi088_drv()
{
    /* do nothing */
}

bmi088_drv::error_t bmi088_drv::init()
{
    error_t ret;
    uint8_t chip_id;
    uint8_t temp;
    uint16_t acc_ret = 0;
    uint16_t gyro_ret = 0;
    /* 1. wait a moment to ensure power up the sensor */
    BARE_DELAY(1);

    /* 2. give a up edge to the cs port of the accelerometer, make it work on
       spi mode. */
    BMI088_CS_ACC_L();
    BMI088_CS_ACC_H();

    /* 3. Soft-reset to clear any previous state and configuration */
    ret = reset();
    CHECK_RET(ret);

    /* 4. Self-test to check whether the sensor is functioning correctly */
    /* 4.1 Make sure the communication with the accelerometer is working */
    ret = read_acc_reg(BMI088_ACC_CHIP_ID, &chip_id);
    CHECK_RET(ret);
    if (chip_id != BMI088_ACC_CHIP_ID_VALUE)
    {
        return INIT_ERROR;
    }
    ret = read_gyro_reg(BMI088_GYRO_CHIP_ID, &chip_id);
    CHECK_RET(ret);
    if (chip_id != BMI088_GYRO_CHIP_ID_VALUE)
    {
        return INIT_ERROR;
    }
    ret = read_acc_reg(BMI088_ACC_ERR_REG, &chip_id);
    CHECK_RET(ret);
    /* 5. Init accelerometer */

    /* 5.1 Write cfg of accelerometer */
    for(uint8_t i = 0; i < BMI088_ACC_CFG_NUM; i++)
    {
        ret = write_acc_reg(bmi088_acc_cfg[i][0], bmi088_acc_cfg[i][1]);
        CHECK_RET(ret);
        /* Add a delay between writes and read, make sure the sensor has enough
         * time to process the configuration */
        BARE_DELAY(1);
        /* Read back the configuration to verify, if it is not equal expected
         * value, set error code */
        ret = read_acc_reg(bmi088_acc_cfg[i][0], &temp);
        CHECK_RET(ret);
        if(temp != bmi088_acc_cfg[i][1])
        {
            acc_ret |= bmi088_acc_cfg[i][2];
        }
    }
    if (acc_ret != bmi088_acc_error_code_t::ACC_OK)
    {
        return ERROR;
    }
    /* 5.2 Write cfg of gyroscope */
    for(uint8_t i = 0; i < BMI088_GYRO_CFG_NUM; i++)
    {
        ret = write_gyro_reg(bmi088_gyro_cfg[i][0], bmi088_gyro_cfg[i][1]);
        CHECK_RET(ret);
        /* Add a delay between writes and read, make sure the sensor has enough
         * time to process the configuration */
        BARE_DELAY(1);
        /* Read back the configuration to verify, if it is not equal expected
         * value, set error code */
        ret = read_gyro_reg(bmi088_gyro_cfg[i][0], &temp);
        CHECK_RET(ret);
        if(temp != bmi088_gyro_cfg[i][1])
        {
            gyro_ret |= bmi088_gyro_cfg[i][2];
        }
    }
    if (gyro_ret != bmi088_gyro_error_code_t::GYRO_OK)
    {
        return ERROR;
    }
    return OK;
}

bmi088_drv::error_t bmi088_drv::reset()
{
    error_t ret;
    ret = write_acc_reg(BMI088_ACC_SOFTRESET, BMI088_ACC_SOFTRESET_VALUE);
    CHECK_RET(ret);
    ret = write_gyro_reg(BMI088_GYRO_SOFTRESET, BMI088_GYRO_SOFTRESET_VALUE);
    CHECK_RET(ret);
    BARE_DELAY(1);
    BMI088_CS_ACC_L();
    BMI088_CS_ACC_H();
    return OK;
}

bmi088_drv::error_t bmi088_drv::read_write_byte(uint8_t tx_data, uint8_t* rx_data)
{
    HAL_StatusTypeDef ret;
    ret = HAL_SPI_TransmitReceive(&BMI088_SPI, &tx_data, 
                                        rx_data, 1, 1000);
    if (ret != HAL_OK)
    {
        return ERROR;
    }
    return OK;
}

bmi088_drv::error_t bmi088_drv::read_acc_reg(uint8_t reg_addr, uint8_t* data)
{
    error_t ret;
    uint8_t dummy_data;
    BMI088_CS_ACC_L();
    ret = read_write_byte(reg_addr | BMI_SPI_RD_MASK, &dummy_data);
    CHECK_RET(ret);
    ret = read_write_byte(0x00, &dummy_data);
    CHECK_RET(ret);
    ret = read_write_byte(0x00, data);
    CHECK_RET(ret);
    BMI088_CS_ACC_H();
    return ret;
}


bmi088_drv::error_t bmi088_drv::write_acc_reg(uint8_t reg_addr, uint8_t data)
{
    error_t ret;
    uint8_t temp;
    BMI088_CS_ACC_L();
    ret = read_write_byte(reg_addr & BMI_SPI_WR_MASK, &temp);
    CHECK_RET(ret);
    ret = read_write_byte(data, &temp);
    CHECK_RET(ret);
    BMI088_CS_ACC_H();
    return ret;
}

bmi088_drv::error_t bmi088_drv::read_gyro_reg(uint8_t reg_addr, uint8_t* data)
{
    error_t ret;
    uint8_t dummy_data;
    BMI088_CS_GYRO_L();
    ret = read_write_byte(reg_addr | BMI_SPI_RD_MASK, &dummy_data);
    CHECK_RET(ret);
    ret = read_write_byte(0x00, data);
    CHECK_RET(ret);
    BMI088_CS_GYRO_H();
    return ret;
}

bmi088_drv::error_t bmi088_drv::write_gyro_reg(uint8_t reg_addr, uint8_t data)
{
    error_t ret;
    uint8_t temp;
    BMI088_CS_GYRO_L();
    ret = read_write_byte(reg_addr & BMI_SPI_WR_MASK, &temp);
    CHECK_RET(ret);
    ret = read_write_byte(data, &temp);
    CHECK_RET(ret);
    BMI088_CS_GYRO_H();
    return ret;
}