#include<stdio.h>
#include"mpu6050.h"
#include"driver/i2c.h"

static mpu6050_handle_t mpu6050 = NULL;

void i2c_bus_init(void)
{
    i2c_config_t conf={
        .mode=I2C_MODE_MASTER,
        .sda_io_num=4,
        .scl_io_num=5,
        .sda_pullup_en=1,
        .scl_pullup_en=1,
        .master.clk_speed=400000
    };
    i2c_param_config(0,&conf);
    i2c_driver_install(0,I2C_MODE_MASTER,0,0,0);
}

void i2c_sensor_mpu6050_init()
{
    i2c_bus_init();
    mpu6050 = mpu6050_create(0, MPU6050_I2C_ADDRESS);
    mpu6050_config(mpu6050, ACCE_FS_4G, GYRO_FS_500DPS);
    mpu6050_wake_up(mpu6050);
}

void app_main(void)
{
    mpu6050_acce_value_t acce;
    mpu6050_gyro_value_t gyro;

    i2c_sensor_mpu6050_init();

    while(1)
    {
        mpu6050_get_acce(mpu6050, &acce);
        printf("acce_x:%.2f, acce_y:%.2f, acce_z:%.2f\n",
         acce.acce_x, acce.acce_y, acce.acce_z);

        mpu6050_get_gyro(mpu6050, &gyro);
        printf("gyro_x:%.2f, gyro_y:%.2f, gyro_z:%.2f\n", 
        gyro.gyro_x, gyro.gyro_y, gyro.gyro_z);\

        vTaskDelay(pdMS_TO_TICKS(1000));
    };
}