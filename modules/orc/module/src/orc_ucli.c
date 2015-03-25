/************************************************************
 * <bsn.cl fy=2013 v=epl>
 * 
 *        Copyright 2013, 2014 Big Switch Networks, Inc.       
 * 
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 * 
 *        http://www.eclipse.org/legal/epl-v10.html
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the
 * License.
 * 
 * </bsn.cl>
 ************************************************************
 *
 *
 *
 ***********************************************************/

#include <orc/orc_config.h>
#include "orc/options.h"

#if ORC_CONFIG_INCLUDE_UCLI == 1

#include <uCli/ucli.h>
#include <uCli/ucli_argparse.h>
#include <uCli/ucli_handler_macros.h>

static ucli_status_t
orc_ucli_ucli__config__(ucli_context_t* uc)
{
    UCLI_HANDLER_MACRO_MODULE_CONFIG(orc)
}

static ucli_status_t
orc_ucli_ucli__hello__(ucli_context_t* uc)
{
    UCLI_COMMAND_INFO(uc,
            "hello", 0,
            "$summary#test command.");
    ucli_printf(uc, "hello world\n");
    return UCLI_STATUS_OK;
}

/* <auto.ucli.handlers.start> */
/******************************************************************************
 *
 * These handler table(s) were autogenerated from the symbols in this
 * source file.
 *
 *****************************************************************************/
static ucli_command_handler_f orc_ucli_ucli_handlers__[] =
{
    orc_ucli_ucli__config__,
    orc_ucli_ucli__hello__,
    NULL
};
/******************************************************************************/
/* <auto.ucli.handlers.end> */

static ucli_module_t
orc_ucli_module__ =
    {
        "orc_ucli",
        NULL,
        orc_ucli_ucli_handlers__,
        NULL,
        NULL,
    };

ucli_node_t*
orc_ucli_node_create(orc_options_t *options)
{
    ucli_node_t* n;
    ucli_module_init(&orc_ucli_module__);
    n = ucli_node_create("orc", NULL, &orc_ucli_module__);
    ucli_node_subnode_add(n, ucli_module_log_node_create("orc"));
    return n;
}

#else
void*
orc_ucli_node_create(void)
{
    return NULL;
}
#endif

