#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <nrfx_example.h>
#include <nrfx_twim.h>
#include <nrfx_twis.h>
#include <zephyr/console/console.h>

/* System defines configuration */
#define MASTER_SCL_PIN                  NRF_GPIO_PIN_MAP(1,3)
#define MASTER_SDA_PIN                  NRF_GPIO_PIN_MAP(1,2)
#define TWIM_INST_IDX                   0
#define SLAVE_ADDR                      0x4A
#define CONSOLE_BUFFER_SIZE             255
#define MASTER_JSON_TIMEOUT_SEC         5
#define SLAVE_ST_REG_ADDR               0xa

static uint8_t m_tx_buffer_master[CONSOLE_BUFFER_SIZE];
static uint8_t m_rx_buffer_master[CONSOLE_BUFFER_SIZE];

static nrfx_twim_t twim_inst = NRFX_TWIM_INSTANCE(TWIM_INST_IDX);

static nrfx_twim_xfer_desc_t twim_xfer_desc = NRFX_TWIM_XFER_DESC_TX(SLAVE_ADDR,
                                                                     m_tx_buffer_master,
                                                                     sizeof(m_tx_buffer_master));
bool send_json_file(void) 
{
    bool send_success = false;
    nrfx_err_t status;
    uint32_t index = 0;
    uint8_t timeout = MASTER_JSON_TIMEOUT_SEC;

    // Initialize the m_tx_buffer_master
    twim_xfer_desc.type = NRFX_TWIM_XFER_TX;
    twim_xfer_desc.p_primary_buf = m_tx_buffer_master;
    twim_xfer_desc.primary_length = sizeof(m_tx_buffer_master);
    memset(m_tx_buffer_master, 0, sizeof(m_tx_buffer_master));
    memset(m_rx_buffer_master, 0, sizeof(m_rx_buffer_master));

    /* Get the JSON file from console */
    while (1) 
    {
		m_tx_buffer_master[index] = console_getchar();

        // Check if the byte is a newline or carriage return
        if (m_tx_buffer_master[index] == '\n' || m_tx_buffer_master[index] == '\r') 
        {
            m_tx_buffer_master[index] = '\0'; // Null-terminate the string
            break;
        }
    
        index++;

        if (index >= CONSOLE_BUFFER_SIZE - 1) 
        {
            m_tx_buffer_master[index] = '\0'; // Ensure the string is null-terminated
            break;
        }
    }
    
    /* Sending the JSON to the slave */
    printk("I2C Master sending: %s\n",m_tx_buffer_master);
    status = nrfx_twim_xfer(&twim_inst, &twim_xfer_desc, 0);
    if (status != NRFX_SUCCESS)
    {
        printk("Error sending i2c message to slave, code:%d\n", status);
    }
    
    /* TODO: the console_getchar buffer is not clear after the first message, clear manually */
    console_getchar();

    /* Preparing TWIM from master to receive response */
    twim_xfer_desc.type = NRFX_TWIM_XFER_RX;
    twim_xfer_desc.p_primary_buf = m_rx_buffer_master;
    twim_xfer_desc.primary_length = sizeof(m_rx_buffer_master);
    m_rx_buffer_master[0] = SLAVE_ST_REG_ADDR;

    /* Polling the status register until it reads the JSON status */
    while(timeout)
    {
        k_msleep(1000);
        printk("Waiting from slave response\n");
        status = nrfx_twim_xfer(&twim_inst, &twim_xfer_desc, 0);
        if (status != NRFX_SUCCESS)
        {
            printk("Error polling the status register from the slave, return error: %d \n",status);
            send_success = false;
        }
        else
        {
            if ((m_rx_buffer_master[0] == 0xde) && (m_rx_buffer_master[1] == 0xad) )
            {   
                send_success = true;
                break;
            }
            else
            {
                printk("Slave still sending JSON.\n");
            }
        }
        timeout--;
    }
    
    if(send_success)
    {
        printk("send JSON to cloud SUCCESS!!!\n");
    }
    else
    {
        printk("send JSON to cloud FAILED!!!\n");
    }

    return send_success;
}

int main(void)
{
    nrfx_err_t status;

    /* Setting up I2C master configuration */
    nrfx_twim_config_t twim_config = NRFX_TWIM_DEFAULT_CONFIG(MASTER_SCL_PIN, MASTER_SDA_PIN);

    /* Init I2C device driver */
    status = nrfx_twim_init(&twim_inst, &twim_config, NULL, &twim_xfer_desc);
    NRFX_ASSERT(status == NRFX_SUCCESS);

    /* Enable I2C device driver */
    nrfx_twim_enable(&twim_inst);

    /* Enable console API */
    console_init();

    printk("Finish to setting up I2C master device, type something to send\n");
    while (1)
    {
        send_json_file(); 
        k_sleep(K_MSEC(100));
        LOG_PROCESS();
    }
}

