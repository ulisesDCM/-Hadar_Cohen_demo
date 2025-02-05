#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <SEGGER_RTT.h>

/* Init log module */
LOG_MODULE_REGISTER(i2c_slave, LOG_LEVEL_INF);

int main(void)
{
    /* Init segger RTT */
    SEGGER_RTT_Init();

    // Buffer to store received data
    uint8_t rtt_buffer[64];

    // Send message via RTT
    const char message[] = "Hello via RTT\n";
    SEGGER_RTT_WriteString(0, message);

    while(1)
    {
        // Read data from RTT
        unsigned int num_bytes = SEGGER_RTT_Read(0, rtt_buffer, sizeof(rtt_buffer));

        // If there is data received, process it
        if (num_bytes > 0) {
            // For demonstration, print the received data
            SEGGER_RTT_WriteString(0, "Received: ");
            SEGGER_RTT_Write(0, rtt_buffer, num_bytes);
            SEGGER_RTT_WriteString(0, "\n");
        }

        // Your application code
        k_sleep(K_MSEC(1000));
    }
}