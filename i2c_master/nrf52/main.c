#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include <nrfx_example.h>
#include <nrfx_twim.h>
#include <nrfx_twis.h>

#define MASTER_SCL_PIN      NRF_GPIO_PIN_MAP(1,3)
#define MASTER_SDA_PIN      NRF_GPIO_PIN_MAP(1,2)
#define TWIM_INST_IDX       0
#define SLAVE_ADDR          0x4A
#define MSG_TO_SEND         "hello"

static uint8_t m_tx_buffer_master[] = MSG_TO_SEND;

/* Init log module */
LOG_MODULE_REGISTER(i2c_master, LOG_LEVEL_INF);

int main(void)
{
    nrfx_err_t status;
    (void)status;

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
    }
}