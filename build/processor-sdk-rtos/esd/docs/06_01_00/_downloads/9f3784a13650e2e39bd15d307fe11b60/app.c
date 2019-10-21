/*
 * Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/**
 *
 *  \brief  Template application tasks file:
 *          This template application exercises multiple tasks and
 *          peripherals. The different task functions are run under
 *          separate Tasks in TI BIOS.
 *          The appTasksCreate function creates the different tasks.
 *          More tasks can be added in this function as required.
 */

/* Standard header files */
#include <string.h>

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>

/* Local template app header file */
#include "app.h"

/**********************************************************************
 ************************** Function prototypes ***********************
 **********************************************************************/
void biosTaskCreate(ti_sysbios_knl_Task_FuncPtr taskFunctionPtr,
                    char *taskName, int taskPriority, int stackSize);

/* Task functions */
void gpio_toggle_led_task(UArg arg0, UArg arg1);
void uart_task(UArg arg0, UArg arg1);
/* Add any additional task function prototypes here */

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
volatile uint32_t g_endTestTriggered = 0;

/* Modification: Create a Mailbox handle */
Mailbox_Handle mHandle;

/**
 *  @brief Function appTasksCreate : Creates multiple application tasks
 *
 *  @param[in]         None
 *  @retval            none
 */
void appTasksCreate(void)
{

    /* Create multiple tasks with different task priority & stack size */
    appPrint("\n ======== Starting to create application tasks ========\n");

    /* Create task to toggle led */
    biosTaskCreate(gpio_toggle_led_task,
                   "gpio_toggle_led_task",
                   8, 4096);

    /* Create task to exercise uart */
    biosTaskCreate(uart_task,
                   "uart_task",
                   9, 4096);

    appPrint("\n ======== Application tasks created successfully ========\n");

    /* Modification: Create a Mailboxes for inter-task communication */
    mHandle = Mailbox_create(sizeof(uint32_t), 1, NULL, NULL);
    if (mHandle == NULL) {
       appPrint("Mailbox_create() failed! \n");
       BIOS_exit(0);
    }
}

/**
 *  @brief Function gpio_toggle_led_task : Toggles LED through GPIO
 *
 *  @param[in]         arg0, arg1: Arguments ( Currently not used)
 *  @retval            none
 */
void gpio_toggle_led_task(UArg arg0, UArg arg1)
{
    /* Modification: This task is modified to use the delay value retrieved
       from the Mailbox instead of a constant delay value. */

    appPrint("\n gpio_toggle_led task started");
    uint32_t delay = 0;
    while(1) {
        /* Write High to test GPIO connected to LED */
        GPIO_write(TEST_LED_GPIO_INDEX, GPIO_PIN_VAL_HIGH);

        /* Check if the user has entered a new delay value */
        Mailbox_pend(mHandle, &delay, BIOS_NO_WAIT);

        /* Delay to set period of pulse */
        Task_sleep(delay);

        /* Write Low to test GPIO connected to LED */
        GPIO_write(TEST_LED_GPIO_INDEX, GPIO_PIN_VAL_LOW);

        /* Check in between blinks to reduce latency */
        Mailbox_pend(mHandle, &delay, BIOS_NO_WAIT);

        /* Delay to set period of pulse */
        /* Note: If the Clock for the platform is incorrectly
           configured, this may loop here p forever */
        /* Check if the user has entered a new delay value */
        Task_sleep(delay);

        /* If end Test is triggered, then exit
         * Note:  The end test can be triggered through commands through uart
         */
        if (g_endTestTriggered)
            break;
    };
    appPrint("\n gpio_toggle_led task ended");
    Task_exit();
}

/**
 *  @brief Function uart_task : This task scans UART port for an
 *      LED delay. "ESC" triggers end of test.
 *
 *  @param[in]         arg0, arg1: Arguments ( Currently not used)
 *  @retval            none
 */
void uart_task(UArg arg0, UArg arg1)
{
    /* Modification: this task is modified to ask the user to enter a delay
       value in ms and then post that value to the Mailbox. */

    uint32_t delay = 0;
    const char LED_delay_prompt[] = "\n uart_task: Enter a delay value in ms(0 to 5000)>";
    const char echoPrompt[] = "\n uart_task: Data received is ";

    UART_printf("\n uart_task task started\n");
    
    /* Wait for other tasks to settle */
    Task_sleep(100);

    while (1) {
        /* Print LED_delay_prompt to UART port */
        UART_printf(LED_delay_prompt);

        /* Scan LED delay from user */
        if (UART_scanFmt("%u", &delay) != S_PASS)
        {
            UART_printf("\n ERROR: UART_scanFmt failed");
            goto UART_TASK_EXIT;
        }

        /* Check the LED delay value */
        if (27 == delay) /* Exit on ESC character */
        {
            goto UART_TASK_EXIT;
        }
        else if (delay < 0 || delay > 5000)
        {
            UART_printf("\nInvalid delay value. Try again.");
            continue;
        }
        else
        {
            UART_printf(echoPrompt);
            UART_printf("%u", delay);

            /* Send LED delay value to the mailbox */
            Mailbox_post(mHandle, &delay, BIOS_NO_WAIT);
        }
        /* Sleep to yield */
        Task_sleep(10);
    }

UART_TASK_EXIT:
    appPrint("\n uart_task task ended");
    /* Trigger end test to other tasks */
    g_endTestTriggered = 1;
    /* Wait a while */
    Task_sleep(100);
    /* Now exit application */
    BIOS_exit(0);
    Task_exit();
    return;
}

/**
 *  @brief Function biosTaskCreate : Task create function
 *             This function is customized to control
 *             certain parameters of the tasks. More parameters
 *             can be controlled for each task; Refer to SYSBIOS
 *             API for other parameters that can be controlled.
 *  @retval              : 0: success ; -1: fail
 */
void biosTaskCreate(ti_sysbios_knl_Task_FuncPtr taskFunctionPtr,
                    char *taskName, int taskPriority, int stackSize)
{
    Task_Params taskParams;
    Error_Block eb;
    Task_Handle task;

    Error_init(&eb);
    Task_Params_init(&taskParams);
    taskParams.instance->name = taskName;
    taskParams.priority = taskPriority;
    taskParams.stackSize = stackSize;
    task = Task_create(taskFunctionPtr, &taskParams, &eb);
    if (task == NULL) {
       appPrint("%s: Task_create() failed! \n", taskName);
       BIOS_exit(0);
    }
    appPrint("\n %s task created.", taskName);

    return;
}
