#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/i2c.h>
#include <SEGGER_RTT.h>

#define MAX_BUFFER_SIZE 128
#define I2C0_NODE DT_NODELABEL(dev_slave)

/* Init log module */
LOG_MODULE_REGISTER(i2c_master, LOG_LEVEL_INF);

/* Internal RTT buffer */
static uint8_t rtt_rx_buffer[MAX_BUFFER_SIZE];

void read_full_string_from_console(void) 
{
    char buffer[MAX_BUFFER_SIZE];
    uint32_t index = 0;
    int32_t byte_read = 0;

    // Initialize the buffer
    memset(buffer, 0, sizeof(buffer));

    // Read characters from RTT
    while (1) {
        byte_read = SEGGER_RTT_Read(0, &buffer[index], 1); // Read one byte
        if (byte_read > 0) {
            // Check if the byte is a newline or carriage return
            if (buffer[index] == '\n' || buffer[index] == '\r') {
                buffer[index] = '\0'; // Null-terminate the string
                break;
            }
            index++;
            if (index >= MAX_BUFFER_SIZE - 1) {
                buffer[index] = '\0'; // Ensure the string is null-terminated
                break;
            }
        }
    }

    LOG_INF("Received string: %s\n", buffer);
}

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
        read_full_string_from_console();
        // Sleep for a short while to avoid busy looping
        k_sleep(K_MSEC(10));
    }
}