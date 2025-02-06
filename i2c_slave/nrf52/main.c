#include <nrfx_example.h>
#include <nrfx_twim.h>
#include <nrfx_twis.h>

#define NRFX_LOG_MODULE                     EXAMPLE
#define NRFX_EXAMPLE_CONFIG_LOG_ENABLED     1
#define NRFX_EXAMPLE_CONFIG_LOG_LEVEL       3
#include <nrfx_log.h>

#define SLAVE_SCL_PIN LOOPBACK_PIN_1B
#define SLAVE_SDA_PIN LOOPBACK_PIN_2B
#define TWIS_INST_IDX 1
#define SLAVE_ADDR 0x4a

static nrfx_twis_t twis_inst = NRFX_TWIS_INSTANCE(TWIS_INST_IDX);
static uint8_t m_rx_buffer_slave[10];

static void twis_handler(nrfx_twis_evt_t const * p_event)
{
    nrfx_err_t status;
    (void)status;

    switch (p_event->type)
    {
        case NRFX_TWIS_EVT_WRITE_DONE:
            break;

        case NRFX_TWIS_EVT_READ_DONE:
            break;

        case NRFX_TWIS_EVT_WRITE_REQ:
            NRFX_LOG_INFO("--> Slave event: write request");
            for(int i=0;i<sizeof(m_rx_buffer_slave); i++)
            {
                NRFX_LOG_INFO("--> Slave event: %x", m_rx_buffer_slave[i]);
            }

            status = nrfx_twis_rx_prepare(&twis_inst, m_rx_buffer_slave, sizeof(m_rx_buffer_slave));
            NRFX_ASSERT(status == NRFX_SUCCESS);  
            break;

        case NRFX_TWIS_EVT_READ_REQ:
            NRFX_LOG_INFO("--> Slave event: read request");
            status = nrfx_twis_tx_prepare(&twis_inst, m_rx_buffer_slave, sizeof(m_rx_buffer_slave));
            NRFX_ASSERT(status == NRFX_SUCCESS);
            break;

        default:
    }
}

int main(void)
{
    nrfx_err_t status;
    (void)status;

    IRQ_CONNECT(NRFX_IRQ_NUMBER_GET(NRF_TWIS_INST_GET(TWIS_INST_IDX)), IRQ_PRIO_LOWEST,
                NRFX_TWIS_INST_HANDLER_GET(TWIS_INST_IDX), 0, 0);

    NRFX_EXAMPLE_LOG_INIT();

    NRFX_LOG_INFO("Starting nrfx_twim_twis non-blocking example.");
    NRFX_EXAMPLE_LOG_PROCESS();
    
    nrfx_twis_config_t twis_config = NRFX_TWIS_DEFAULT_CONFIG(SLAVE_SCL_PIN,
                                                              SLAVE_SDA_PIN,
                                                              SLAVE_ADDR);
    status = nrfx_twis_init(&twis_inst, &twis_config, twis_handler);
    NRFX_ASSERT(status == NRFX_SUCCESS);

    nrfx_twis_enable(&twis_inst);

    while (1)
    {
        NRFX_EXAMPLE_LOG_PROCESS();
    }
}
