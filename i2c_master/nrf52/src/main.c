#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/logging/log.h>
#include <SEGGER_RTT.h>

/* I2C config */
#define I2C0_NODE DT_NODELABEL(dev_slave)

/* Init log module */
LOG_MODULE_REGISTER(i2c_master, LOG_LEVEL_INF);

/* Internal RTT buffer */
static uint8_t rtt_rx_buffer[64];

int main(void)
{
    uint8_t config[2] = {rtt_rx_buffer[0]};
    int ret;

    /* Init segger RTT */
    SEGGER_RTT_Init();
    
    /* Init I2C device */
    static const struct i2c_dt_spec dev_i2c = I2C_DT_SPEC_GET(I2C0_NODE);
    if (!device_is_ready(dev_i2c.bus)) 
    {
	    LOG_ERR("I2C bus %s is not ready!\n\r",dev_i2c.bus->name);
	    return;
    }

    LOG_INF("Waiting for user input...");
    while(1)
    {
        unsigned int num_bytes = SEGGER_RTT_Read(0, rtt_rx_buffer, sizeof(rtt_rx_buffer));
        // If there is data received, process it
        if (num_bytes > 0) {
            // For demonstration, print the received data
            SEGGER_RTT_WriteString(0, "Received: ");
            LOG_INF("Send data: %c", rtt_rx_buffer[0]);
            SEGGER_RTT_WriteString(0, "\n");
            
            /* Send the data to the slave device over I2C */
            ret = i2c_write_dt(&dev_i2c, config, sizeof(config));
            if(ret != 0)
            {
                LOG_ERR("Failed to write to I2C device address %x at reg. %x \n\r", dev_i2c.addr,config[0]);
            }
        }

        // Sleep for a short while to avoid busy looping
        k_sleep(K_MSEC(10));
    }
}