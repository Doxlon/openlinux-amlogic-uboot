#include <config.h>
#include <asm/arch/firm/reg_addr.h>
#include <asm/arch/firm/uart.h>
#include <asm/arch/firm/io.h>
#ifndef FIRMWARE_IN_ONE_FILE
#define STATIC_PREFIX
#else
#define STATIC_PREFIX static
#endif
//#define BOARD_UART_PORT UART_PORT_0
#ifndef BOARD_UART_PORT
#define BOARD_UART_PORT CONFIG_AML_DEF_UART
#endif
STATIC_PREFIX void serial_hw_init(void)
{
    if(BOARD_UART_PORT==UART_A)
            SET_CBUS_REG_MASK(PERIPHS_PIN_MUX_7,((1 << 11) | (1 << 8)));
    if(BOARD_UART_PORT==UART_B)
            SET_CBUS_REG_MASK(PERIPHS_PIN_MUX_3,((1 << 30) | (1 << 27)));
    
}
