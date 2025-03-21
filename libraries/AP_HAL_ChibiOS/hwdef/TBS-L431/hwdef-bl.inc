# hw definition file Matek L431 CAN node

# MCU class and specific type
MCU STM32L431 STM32L431xx

# use LSE clock source
OSCILLATOR_HZ 32768

# board ID. See Tools/AP_Bootloader/board_types.txt
APJ_BOARD_ID AP_HW_TBS_L431_PERIPH

# setup build for a peripheral firmware
env AP_PERIPH 1

FLASH_RESERVE_START_KB 0
FLASH_BOOTLOADER_LOAD_KB 36
FLASH_SIZE_KB 256

# reserve some space for params
APP_START_OFFSET_KB 4

# ---------------------------------------------
PA15 LED_BOOTLOADER OUTPUT LOW  # blue
define HAL_LED_ON 0

# enable CAN support
#PB8 CAN1_RX CAN1
#PB9 CAN1_TX CAN1
PA11 CAN1_RX CAN1
PA12 CAN1_TX CAN1
# PC13 GPIO_CAN1_SILENT OUTPUT PUSHPULL SPEED_LOW LOW

PB1 GPIO_CAN1_TERM OUTPUT PUSHPULL SPEED_LOW LOW
PB3 GPIO_CAN1_TERM_LED OUTPUT PUSHPULL SPEED_LOW LOW
PB0 GPIO_CAN1_TERM_SWITCH INPUT FLOAT

CAN_ORDER 1

# ---------------------------------------------

# make bl baudrate match debug baudrate for easier debugging
define BOOTLOADER_BAUDRATE 57600

# use a small bootloader timeout
define HAL_BOOTLOADER_TIMEOUT 1000

define HAL_USE_SERIAL FALSE

define HAL_NO_GPIO_IRQ
define SERIAL_BUFFERS_SIZE 32
define HAL_USE_EMPTY_IO TRUE
define PORT_INT_REQUIRED_STACK 64
define DMA_RESERVE_SIZE 0

MAIN_STACK 0x800
PROCESS_STACK 0x800

# Add CS pins to ensure they are high in bootloader
PA4 MAG_CS CS
PB2 SPARE_CS CS

# debugger support
PA13 JTMS-SWDIO SWD
PA14 JTCK-SWCLK SWD

