#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include <nrfx_example.h>
#include <nrfx_twim.h>
#include <nrfx_twis.h>
#include <SEGGER_RTT.h>

/* Defines and system configuration */
#define MASTER_SCL_PIN      NRF_GPIO_PIN_MAP(1,3)
#define MASTER_SDA_PIN      NRF_GPIO_PIN_MAP(1,2)
#define TWIM_INST_IDX       1
#define SLAVE_ADDR          0x4A
#define MSG_TO_SEND         "hello"
#define RTT_BUFFER_SIZE     20

/* I2C Master transmit buffer */
static uint8_t m_tx_buffer_master[] = MSG_TO_SEND;

/* RTT Receive buffer */
static uint8_t rtt_rx_buffer[RTT_BUFFER_SIZE];

/* Log module init */
LOG_MODULE_REGISTER(i2c_master, LOG_LEVEL_INF);

void read_full_string_from_console(void) 
{
    uint32_t index = 0;
    int32_t byte_read = 0;

    // Initialize the buffer
    memset(rtt_rx_buffer, 0, sizeof(rtt_rx_buffer));

    // Read characters from RTT
    while (1) {
        byte_read = SEGGER_RTT_Read(0, &rtt_rx_buffer[index], 1); // Read one byte
        if (byte_read > 0) {
            // Check if the byte is a newline or carriage return
            if (rtt_rx_buffer[index] == '\n' || rtt_rx_buffer[index] == '\r') {
                rtt_rx_buffer[index] = '\0'; // Null-terminate the string
                break;
            }
            index++;
            if (index >= RTT_BUFFER_SIZE - 1) {
                rtt_rx_buffer[index] = '\0'; // Ensure the string is null-terminated
                break;
            }
        }
    }
    LOG_INF("Received string: %s\n", rtt_rx_buffer);
}

int main(void)
{
    nrfx_err_t status;
    (void)status;

    /* Init segger RTT */
    SEGGER_RTT_Init();

    LOG_INF("Setting up I2C master device.");

    /* Get the instance  */  
    nrfx_twim_t twim_inst = NRFX_TWIM_INSTANCE(TWIM_INST_IDX);

    /* Configure I2C descripto package to tranmit value */
    nrfx_twim_xfer_desc_t twim_xfer_desc = NRFX_TWIM_XFER_DESC_TX(SLAVE_ADDR,
                                                                  m_tx_buffer_master,
                                                                  sizeof(m_tx_buffer_master));
    /* Setting up I2C master configuration */
    nrfx_twim_config_t twim_config = NRFX_TWIM_DEFAULT_CONFIG(MASTER_SCL_PIN, MASTER_SDA_PIN);

    /* Init I2C device driver */
    status = nrfx_twim_init(&twim_inst, &twim_config, NULL, &twim_xfer_desc);
    NRFX_ASSERT(status == NRFX_SUCCESS);

    /* Enable I2C device driver */
    nrfx_twim_enable(&twim_inst);

    LOG_INF("Finish to setting up I2C master device, start to ping slave");
    while (1)
    {
        LOG_INF("I2C Master sending %s",m_tx_buffer_master);
        status = nrfx_twim_xfer(&twim_inst, &twim_xfer_desc, 0);
        NRFX_ASSERT(status == NRFX_SUCCESS);
        k_sleep(K_MSEC(5000));
        NRFX_EXAMPLE_LOG_PROCESS();
    }
}

/** @} */
