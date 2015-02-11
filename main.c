/*
__heap_base__=Image$$RW_IRAM1$$ZI$$Limit __heap_end__=Image$$RW_IRAM2$$Base
*/
#include "ch.h"
#include "hal.h"

#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */

//extern int Image$$RW_IRAM1$$ZI$$Limit;

static WORKING_AREA(waThread1, 128);
static msg_t Thread1(void *arg);

int main(void) {
	
  /* OS init */
  halInit();
  chSysInit();

  /*
   * Creating one task.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

  /* Main task (always present and have priority NORMALPRIO */
  while (TRUE) {
    //palClearPad(GPIOG, GPIOD_LED3);
    palClearPad(GPIOG, GPIOG_LED3_GREEN);
    chThdSleepMilliseconds(50);
    palSetPad(GPIOG, GPIOG_LED3_GREEN);
    chThdSleepMilliseconds(50);
  }
}

static msg_t Thread1(void *arg) {
  while (TRUE) {
    palClearPad(GPIOG, GPIOG_LED4_RED);
    chThdSleepMilliseconds(500);
    palSetPad(GPIOG, GPIOG_LED4_RED);
    chThdSleepMilliseconds(500);
  }
}
