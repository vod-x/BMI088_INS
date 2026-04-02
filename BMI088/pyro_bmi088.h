#ifndef PYRO_BMI088_H
#define PYRO_BMI088_H

#include <stdint.h>

class bmi088_drv
{
public:
enum error_t
{
    OK         = 0,
    ERROR      = 1,
    INIT_ERROR = 2,
}error_code;

    bmi088_drv();
    ~bmi088_drv();
    error_t init();

// private:
    error_t read_write_byte(uint8_t tx_data, uint8_t* rx_data);

    error_t read_acc_reg(uint8_t reg_addr, uint8_t* data);
    error_t write_acc_reg(uint8_t reg_addr, uint8_t data);
    error_t read_gyro_reg(uint8_t reg_addr, uint8_t* data);
    error_t write_gyro_reg(uint8_t reg_addr, uint8_t data);

};
#endif //PYRO_BMI088_H
