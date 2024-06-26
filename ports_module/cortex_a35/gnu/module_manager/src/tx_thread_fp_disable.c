/***************************************************************************
 * Copyright (c) 2024 Microsoft Corporation 
 * 
 * This program and the accompanying materials are made available under the
 * terms of the MIT License which is available at
 * https://opensource.org/licenses/MIT.
 * 
 * SPDX-License-Identifier: MIT
 **************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** ThreadX Component                                                     */
/**                                                                       */
/**   Thread                                                              */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#define TX_SOURCE_CODE


/* Include necessary system files.  */

#include "tx_api.h"
#include "tx_thread.h"


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _tx_thread_fp_disable                             Cortex-A35/GNU    */
/*                                                           6.1.3        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Andres Mlinar, Microsoft Corporation                                */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function disables the FP for the currently executing thread.   */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Application Code                                                    */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  12-31-2020     Andres Mlinar            Initial Version 6.1.3         */
/*                                                                        */
/**************************************************************************/
VOID  _tx_thread_fp_disable(VOID)
{

TX_THREAD   *thread_ptr;
ULONG       system_state;


    /* Pickup the current thread pointer.  */
    TX_THREAD_GET_CURRENT(thread_ptr);

    /* Get the system state.  */
    system_state =  TX_THREAD_GET_SYSTEM_STATE();

    /* Make sure it is not NULL. */
    if (thread_ptr != TX_NULL)
    {
        
        /* Thread is running... make sure the call is from the thread context.  */
        if (system_state == 0)
        {
        
            /* Yes, now set the FP enable flag to false in the TX_THREAD structure.  */
            thread_ptr -> tx_thread_fp_enable =  TX_FALSE;
        }
    }
}
