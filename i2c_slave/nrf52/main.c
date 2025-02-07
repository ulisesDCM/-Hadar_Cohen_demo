#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>
#include <nrfx_example.h>
#include <nrfx_twim.h>
#include <nrfx_twis.h>

/* Slave instance and pins configuration */
#define SLAVE_SCL_PIN       31
#define SLAVE_SDA_PIN       30
#define TWIS_INST_IDX       0
#define SLAVE_ADDR          0x4a
#define SLAVE_BUFF_SIZE     255

static nrfx_twis_t slave_inst = NRFX_TWIS_INSTANCE(TWIS_INST_IDX);
static uint8_t m_rx_buffer_slave[SLAVE_BUFF_SIZE];

/* Init log module */
LOG_MODULE_REGISTER(i2c_slave, LOG_LEVEL_INF);

/* I2C slave event handler */
static void i2c_slave_handler(nrfx_twis_evt_t const * p_event)
{
    nrfx_err_t status;
    (void)status;

    switch (p_event->type)
    {
        case NRFX_TWIS_EVT_READ_DONE:
            break;

        case NRFX_TWIS_EVT_READ_REQ:
            break;

        case NRFX_TWIS_EVT_WRITE_REQ:
            status = nrfx_twis_rx_prepare(&slave_inst, m_rx_buffer_slave, sizeof(m_rx_buffer_slave));  
            break;

        case NRFX_TWIS_EVT_WRITE_DONE:
            LOG_INF("Slave msg received: %s", m_rx_buffer_slave);
            break;

        default:
    }
}

int main(void)
{
    nrfx_err_t status;

    IRQ_CONNECT(NRFX_IRQ_NUMBER_GET(NRF_TWIS_INST_GET(TWIS_INST_IDX)), IRQ_PRIO_LOWEST,
                NRFX_TWIS_INST_HANDLER_GET(TWIS_INST_IDX), 0, 0);

    LOG_INF("Init I2C slave device");
    nrfx_twis_config_t slave_config = NRFX_TWIS_DEFAULT_CONFIG(SLAVE_SCL_PIN,
                                                              SLAVE_SDA_PIN,
                                                              SLAVE_ADDR);

    status = nrfx_twis_init(&slave_inst, &slave_config, i2c_slave_handler);
    NRFX_ASSERT(status == NRFX_SUCCESS);

    nrfx_twis_enable(&slave_inst);

    LOG_INF("I2C slave listening...");

    while (1)
    {
        LOG_INF("Hello world");
        k_msleep(1000);
        NRFX_EXAMPLE_LOG_PROCESS();
    }
}
