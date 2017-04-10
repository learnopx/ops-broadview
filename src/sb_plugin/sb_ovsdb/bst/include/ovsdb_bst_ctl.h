/*****************************************************************************
 *
 * (C) Copyright Broadcom Corporation 2015
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 *
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
***************************************************************************/

#ifndef INCLUDE_OVSDB_BST_CTL_H
#define INCLUDE_OVSDB_BST_CTL_H

#ifdef __cplusplus
extern "C"
{
#endif

#define BST_OVSDB_REALM_SIZE          128
typedef struct _realm_map_
{
  char realmName[BST_OVSDB_REALM_SIZE];
  int realmId;
} BVIEW_BST_REALM_MAP_t;

/*********************************************************************
* @brief           Set default connection parameters                                 
*
* @param[in,out]   connectMode  - Connection Type 
*
* @notes
*
* @retval          none
*
*********************************************************************/

void ovsdb_set_default(char * connectMode);

/*********************************************************************
* @brief           Read OVSDB Config File 
*
* @param[in,out]   connectMode  - Connection Type 
*
* @notes       
*
* @retval          BVIEW_STATUS_SUCCESS for successful execution
*
*********************************************************************/

BVIEW_STATUS ovsdb_file_read(char * connectMode);

/*********************************************************************
* @brief       Commit column "trigger_threshold" in table "bufmon" to 
*              OVSDB database.
*
* @param[in]   asic             -  ASIC ID
* @param[in]   port             -  Port 
* @param[in]   index            -  Index 
* @param[in]   bid              -  Stat ID
* @param[in]   threshold      -   Threshold.
*
* @notes       
*          
*
*
*********************************************************************/
BVIEW_STATUS bst_ovsdb_threshold_commit (int asic , int port, int index,
                                         int bid, uint64_t threshold);

/*********************************************************************
* @brief   Commit Table "System" columns to OVSDB database.
*
* @param[in]   asic              -   ASIC ID
* @param[in]   config            -   Pointer to BST config Data.
*
* @retval      
* 
* @notes    
*          
*
*
*********************************************************************/
BVIEW_STATUS bst_ovsdb_bst_config_commit (int asic ,
                                          BVIEW_OVSDB_CONFIG_DATA_t *config);

/*********************************************************************
* @brief   BST OVSDB monitor thread
*
*
*
* @notes   Receive JSON notification from OVSDB-SERVER and Update the 
*          SB PLUGIN cache.
*
*
*********************************************************************/
void bst_ovsdb_monitor();

/*********************************************************************
* @brief   Commit Column 'enabled' in bufmon table
*
* @param[in]   asic              -   ASIC ID
* @param[in]   config            -   Pointer to BST config Data.
*
* @retval
*
* @notes
*
*
*
*********************************************************************/
BVIEW_STATUS bst_ovsdb_bst_tracking_commit (int asic ,
                                          BVIEW_OVSDB_CONFIG_DATA_t *config);

/*********************************************************************
* @brief       Commit column "trigger_threshold" in table "bufmon" to
*              Zero.
*
* @param[in]   asic             -  ASIC ID
*
* @notes
*
*
*
*********************************************************************/
BVIEW_STATUS bst_ovsdb_clear_thresholds_commit (int asic);

/*********************************************************************
* @brief       Commit Clear Stats to OVSDB.
*              .
*
* @param[in]   asic             -  ASIC ID
*
* @notes       Set all Stats to Zero
*
*
*
*********************************************************************/
BVIEW_STATUS bst_ovsdb_clear_stats_commit (int asic);


#ifdef __cplusplus
}
#endif
#endif

