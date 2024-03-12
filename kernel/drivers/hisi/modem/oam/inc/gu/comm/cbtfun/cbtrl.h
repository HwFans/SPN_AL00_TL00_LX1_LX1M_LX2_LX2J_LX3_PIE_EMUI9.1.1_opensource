/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __CBTRL_H__
#define __CBTRL_H__

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#if (OSA_CPU_CCPU == VOS_OSA_CPU)
#include "msp_diag_comm.h"
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif

/*****************************************************************************
  2 �궨��
*****************************************************************************/
/*OM<->APP : NON SIGALING Transparent Message.*/
#define APP_OM_NON_SIG_BT_TRAN_REQ      (0x1601)
#define OM_APP_NON_SIG_BT_TRAN_CNF      (0x1602)

/*OM<->APP : Get the WCDMA SYNC Status.*/
#define APP_OM_W_SYNC_STATUS_REQ        (0x1603)
#define OM_APP_W_SYNC_STATUS_CNF        (0x1604)

/*OM<->APP : Get the GMSK/EDGE DownLink Status.*/
#define APP_OM_GE_DL_STATUS_REQ         (0x1605)
#define OM_APP_GE_DL_STATUS_CNF         (0x1606)

/*OM<->APP : Get the EDGE BLER.*/
#define APP_OM_EDGE_BLER_REQ            (0x1607)
#define OM_APP_EDGE_BLER_CNF            (0x1608)

/*OM<->APP : Get the EDGE BLER.*/
#define APP_OM_W_BER_DATA_REQ           (0x1609)
#define OM_APP_W_BER_DATA_CNF           (0x160a)
#define OM_APP_W_BER_DATA_IND           (0x160b)

#define APP_OM_LISTMODE_BT_GETMSG_REQ   (0x1611)
#define OM_APP_LISTMODE_BT_GETMSG_CNF   (0x1612)

#define APP_OM_LISTMODE_BT_TRAN_REQ     (0x1613)
#define OM_APP_LISTMODE_BT_TRAN_CNF     (0x1614)

#define APP_OM_LISTMODE_BT_TEST_REQ     (0x1615)
#define OM_APP_LISTMODE_BT_TEST_CNF     (0x1616)
#define OM_APP_LISTMODE_BT_BER_IND      (0x1617)

#define OM_APP_LISTMODE_BT_RSSI_IND     (0x1618)

#define APP_OM_BT_W_TX_SET_POWER_REQ    (0x1619)
#define OM_APP_BT_W_TX_SET_POWER_CNF    (0x1620)

#define APP_OM_BT_WG_RSSI_REQ           (0x1621)
#define OM_APP_BT_WG_RSSI_CNF           (0x1622)

#define APP_OM_G_BER_DATA_REQ           (0x1624)
#define OM_APP_G_BER_DATA_CNF           (0x1625)
#define OM_APP_G_BER_DATA_IND           (0x1626)

#define APP_OM_NON_SIG_BT_C_SYNC_REQ    (0x1701)
#define OM_APP_NON_SIG_BT_C_SYNC_CNF    (0x1702)
#define APP_OM_NON_SIG_BT_C_FER_REQ     (0x1703)
#define OM_APP_NON_SIG_BT_C_FER_CNF     (0x1704)

#define APP_OM_BT_C_TX_SET_POWER_REQ        (0x1705)
#define OM_APP_BT_C_TX_SET_POWER_CNF        (0x1706)

#define APP_OM_SWITCH_RF_ANT_REQ         0x0068
#define OM_APP_SWITCH_RF_ANT_CNF         0x0068


#define CBT_STATE_IDLE                          0 /*IDLE̬�����������빤�߽���ͨ��*/
#define CBT_STATE_ACTIVE                        1 /*ACTIVE̬���ܹ���������*/

#define CBT_MSG_ID_COMP_LENGTH                  (4U)

#define CBT_MSG_HEADER_LENGTH                   (16U)
#define CBT_MSG_IDLEN_LENGTH                    (8U)
#define CBT_MSG_HEAD_EX_LENGTH                  ((CBT_MSG_HEADER_LENGTH) + (CBT_MSG_IDLEN_LENGTH))

#define CBT_MSG_SEGMENT_LEN                     (4U*1024U)
#define CBT_MSG_CONTEXT_MAX_LENGTH              (CBT_MSG_SEGMENT_LEN - CBT_MSG_HEADER_LENGTH)

#define CBT_CCPU_TO_ACPU_SEND_DATA_REQ          (0x030d)

#define CBT_GET_COMPMODE_COMPID(COMPMODE)       ((COMPMODE>>12)& 0xF)
#define CBT_GET_COMPMODE_MODE(COMPMODE)         ((COMPMODE>>8) & 0xF)

#define CBT_MODEM_SSID_COMBINE(modem, ssid)     (((modem) & 0x0F) | ((ssid<<4) & 0xF0))

#define CBT_POWER_10TH_UNIT                             (10)
#define CBT_RSSI_8TH_UNIT                               (8)
#define CBT_POWER_10DBM_THRESHOLD                       (100)
#define CBT_GSM_BAND_CHAN_COMPOSE(usBand, usChan)       (((usBand) << 12) | (0xFFF & (usChan)))
#define CBT_RSSI_TO_POWER(x)                            (((x) * CBT_POWER_10TH_UNIT) / CBT_RSSI_8TH_UNIT)
#define CBT_CALL_GSM_RX_LEVEL_PARA                      (316)
#define CBT_WCDMA_FREQ_MEASURE_PARA                     (65535)

#define CBT_WRITE_NV_HEAD_SIZE                  (8)
#define CBT_WRITE_NV_FLASH_HEAD_SIZE            (8)

#define OM_BER_DATA_MAX_SIZE                    (1024)
#define CBT_NV_TO_FLASH_HEAD_SIZE               (4)
#define OM_STATE_IDLE                               0 /*IDLE̬��OM���������빤�߽���ͨ��*/
#define OM_STATE_ACTIVE                             1 /*ACTIVE̬��OM�ܹ���������*/

/*OM<->APP : Just for LMT.*/
#define APP_OM_WRITE_NV_REQ                       0x8023
#define OM_APP_WRITE_NV_CNF                       0x8024

/*OM<->APP : Just for LMT.*/
#define APP_OM_HANDLE_LMT_REQ                     0x80a1
#define OM_APP_HANDLE_LMT_CNF                     0x80a2

/*OM<->APP : Just for LMT.*/
#define APP_OM_ACTIVE_PHY_REQ                     0x80a3
#define OM_APP_ACTIVE_PHY_CNF                     0x80a4

/*OM<->APP :��ѯPA������*/
#define APP_OM_PA_ATTRIBUTE_REQ                   0x80c1
#define OM_APP_PA_ATTRIBUTE_IND                   0x80c2

/*OM<->APP :ͨ������ͨ����ѯPA���¶�*/
#define APP_OM_PA_TEMP_PHY_CHAN_REQ               0x80c7
#define OM_APP_PA_TEMP_PHY_CHAN_IND               0x80c8

/*���ô��������л�����������*/
#define APP_OM_SET_FTM_REQ                        0x80e5
#define OM_APP_SET_FTM_CNF                        0x80e6

/* OM<->APP :LMT��ѯDSDA֧��״̬ */
#define APP_OM_QUERY_MODEM_NUM_REQ                0x8211
#define OM_APP_QUERY_MODEM_NUM_CNF                0x8212

#define APP_OM_AT_TMODE_REQ                       0x0065
#define OM_APP_AT_TMODE_CNF                       0x0065

#define APP_OM_AT_BANDSW_REQ                      0x0066
#define OM_APP_AT_BANDSW_CNF                      0x0066

#define APP_OM_AT_FCHAN_REQ                       0x0067
#define OM_APP_AT_FCHAN_CNF                       0x0067

/*OM<->APP : Restablish link*/
#define APP_OM_ESTABLISH_REQ                      0x80b1
#define OM_APP_ESTABLISH_CNF                      0x80b2

/*OM<->APP : Release link*/
#define APP_OM_RELEASE_REQ                        0x80b3
#define OM_APP_RELEASE_CNF                        0x80b4

#define OM_TRANS_PRIMID                           0x5001

/* OM<->APP :����C��NV�洢��Flash*/
#define APP_OM_NV_TO_FLASH_REQ                    0x802B
#define OM_APP_NV_TO_FLASH_CNF                    0x802C

/* OM<->APP :����C��һ����дNV�洢Flash*/
#define APP_OM_NV_WRITE_FLASH_REQ                 0x802D
#define OM_APP_NV_WRITE_FLASH_CNF                 0x802E

/* GUCCBT->NRNOSIG����IND��NR���ںϺ����Ϣɾ�� */
#define ID_GUCCBT_NRNOSIG_IND                     0x0F0F

/* RTTAgent TMode Defines */
#define RTTAGENT_CBT_TMODE1      1   // LTE ��ģ CT У׼TDS
#define RTTAGENT_CBT_TMODE13     13  // LTE ��ģ CT
#define RTTAGENT_CBT_TMODE14     14  // LTE ��ģ BT
#define RTTAGENT_CBT_TMODE15     15  // LTE ��ģ CT
#define RTTAGENT_CBT_TMODE16     16  // LTE ��ģ BT
#define RTTAGENT_CBT_TMODE17     17  // TDS ��ģ
#define RTTAGENT_CBT_TMODE18     18  // TDS ��ģ
#define RTTAGENT_CBT_TMODE20     20  // TDS ��ģ

/*****************************************************************************
  6 STRUCT����
*****************************************************************************/
/*Query PA attribute*/
enum
{
    OM_W_PA_TEMP = 1,
    OM_G_PA_TEMP,
    OM_W_PLL_LOCK,
    OM_G_PLL_LOCK,
    OM_W_HKADC,
    OM_G_HKADC,
    OM_W_BBP_PLL_LOCK,
    OM_G_BBP_PLL_LOCK,
    OM_DSP_PLL_LOCK,
    OM_ARM_PLL_LOCK,
    OM_SIM_TEMP,
    OM_TCM_STATUS,
    OM_SDMMC_STATUS,
    OM_BATTER_VOLT,
    OM_BATTER_TEMP,
    OM_OLED_TEMP,
    OM_DCXO_TEMP,
    OM_DCXO_TEMP_LT,
    OM_OLED_BUTT
};

typedef enum
{
    RFIC_CHANNEL_FLAG_MODEM          = 0,
    RFIC_CHANNEL_FLAG_CHANNEL_NO     = 1,
    RFIC_CHANNEL_FLAG_BUSSINESS_TYPE = 2,
    RFIC_CHANNEL_FLAG_BUTT
}OM_RFIC_CHANNEL_FLAG_ENUM;
typedef VOS_UINT8   OM_RFIC_CHANNEL_FLAG_ENUM_UINT8;

enum OM_W_SNYC_STATUS
{
    OM_W_SYNC_STATUS_SYNC = 0,
    OM_W_SYNC_STATUS_OUT_OF_SYNC,
    OM_W_SYNC_STATUS_UNKNOWN,
    OM_W_SYNC_STATUS_BUTT
};

typedef VOS_UINT16 OM_W_SNYC_STATUS_ENUM_UINT16;

enum OM_GE_SNYC_STATUS
{
    OM_GE_SYNC_STATUS_NORMAL,
    OM_GE_SYNC_STATUS_DISNORMAL,
    OM_GE_SYNC_STATUS_UNKNOWN,
    OM_GE_SYNC_STATUS_BUTT
};

enum CBT_C_SYNC_STATUS
{
    CBT_C_SYNC_STATUS_SYNC = 0,
    CBT_C_SYNC_STATUS_OUT_OF_SYNC,
    CBT_C_SYNC_STATUS_UNKNOWN,
    CBT_C_SYNC_STATUS_BUTT
};

enum LMT_RAT_MODE
{
    LMT_RAT_WCDMA = 0,
    LMT_RAT_GSM,
    LMT_RAT_CDMA,
    LMT_RAT_TDS,
    LMT_RAT_LTE,
    LMT_RAT_NR,
    LMT_RAT_BUTT
};

/* ComponentTypeʹ�� */
typedef enum
{
    CBT_MODE_LTE = 0,
    CBT_MODE_TDS,
    CBT_MODE_GSM,
    CBT_MODE_UMTS,
    CBT_MODE_CDMA,
    CBT_MODE_NR,
    CBT_MODE_LTEV2X = 7,
    CBT_MODE_COMM = 0xf,
    CBT_MODE_BUTT

} CBT_COMPONENT_MODE_ENUM;

typedef enum
{
    CBT_MT_REQ = 1,
    CBT_MT_CNF,
    CBT_MT_IND,
    CBT_MT_BUTT

} CBT_MSG_TYPE_ENUM;

typedef enum
{
    CBT_SSID_NOAPPOINT = 0,
    CBT_SSID_APP_CPU,
    CBT_SSID_MODEM_CPU,
    CBT_SSID_LTE_DSP,
    CBT_SSID_LTE_BBP,
    CBT_SSID_GU_DSP,
    CBT_SSID_HIFI,
    CBT_SSID_TDS_DSP,
    CBT_SSID_TDS_BBP,
    CBT_SSID_MCU,
    CBT_SSID_GPU,
    CBT_SSID_GU_BBP,
    CBT_SSID_IOM3,
    CBT_SSID_ISP,
    CBT_SSID_X_DSP,
    CBT_SSID_RESERVE,
    CBT_SSID_BUTT
} CBT_SSID_ENUM;

typedef enum
{
    CBT_COMP_FUNC = 1,
    CBT_COMP_NOSIG,
    CBT_COMP_PHY,
    CBT_COMP_PS,
    CBT_COMP_TRANS,
    CBT_COMP_BBIC,
    CBT_COMP_BUTT
} CBT_COMPONET_ID_ENUM;

typedef enum
{
    CBT_TEST_MODE_INVALID   = 0xFFFFFFFF,
    CBT_TEST_MODE_CT        = 0,
    CBT_TEST_MODE_BT        = 1,
    CBT_TEST_MODE_BUTT
}CBT_TEST_MODE_ENUM;

/*****************************************************************************
�ṹ��    : MODEM_SSID_STRU
�ṹ˵��  : �������modem��ssid�����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8 ucModem  : 3;  /*modem0: 0  modem1: 1*/
    VOS_UINT8 ucResv   : 1;
    VOS_UINT8 ucSsid   : 4;  /**/
} CBT_MODEM_SSID_STRU;

/*****************************************************************************
�ṹ��    : FRAGMENT_INFO_STRU
�ṹ˵��  : ���������Ϣ���ͺ���Ϣ�ֶ���Ϣ�����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8 ucMsgType    : 2; /*��Ϣ���ͣ�REQ: 1   CNF: 2   IND: 3*/
    VOS_UINT8 ucFragIndex  : 4; /*��Ϣ�ֶε�Ƭ������*/
    VOS_UINT8 ucEof        : 1; /*�ֶν�����ʶ��0�ֶ�δ������1�ֶν���*/
    VOS_UINT8 ucFragFlag   : 1; /*�Ƿ�ֶα�ʶ��0���ֶΣ�1�ֶ�*/
} CBT_FRAGMENT_INFO_STRU;

/*****************************************************************************
�ṹ��    : TIME_STAMP_STRU
�ṹ˵��  : �������ʱ��������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32 ulTimestampL;
    VOS_UINT16 usTimestampH;
    VOS_UINT16 usRsv;
} CBT_TIME_STAMP_STRU;

/*****************************************************************************
�ṹ��    : COMPONENT_MODE_STRU
�ṹ˵��  : ������������ģ�����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8 ucRsv;
    VOS_UINT8 ucMode     : 4;  /*����GUTLCģ*/
    VOS_UINT8 ucCompID   : 4;
} CBT_COMPONENT_MODE_STRU;

/*****************************************************************************
�ṹ��    : CBT_MSG_HEAD_STRU
�ṹ˵��  : ����OM��Ϣͷ�����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8               ucSid;              /* �̶�Ϊ 7*/
    CBT_MODEM_SSID_STRU     stModemSsid;
    VOS_UINT8               ucSessionID;        /*�̶�Ϊ 1*/
    CBT_FRAGMENT_INFO_STRU  stMsgSegment;
    VOS_UINT32              ulTransId;
    CBT_TIME_STAMP_STRU     stTimeStamp;        /*ʱ�����Ϣ*/
} CBT_MSG_HEAD_STRU;

/*****************************************************************************
�ṹ��    : CBT_UNIFORM_MSG_STRU
�ṹ˵��  : �����·����ݰ���չ�ṹ
*****************************************************************************/
typedef struct
{
    CBT_MSG_HEAD_STRU               stMsgHeader;
    VOS_UINT16                      usMsgId;      /* ��ϢID */
    CBT_COMPONENT_MODE_STRU         stCompMode;
    VOS_UINT32                      ulMsgLength;
    VOS_UINT8                       aucPara[4];   /* ��Ϣ���� */
} CBT_UNIFORM_MSG_STRU;

/*****************************************************************************
�ṹ��    : CBT_UNIFORM_MSG_STRU
�ṹ˵��  : �����·����ݰ���չ�ṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    CBT_UNIFORM_MSG_STRU            stPcMsgData;
} CBT_UNIFORM_MSG_WITH_HEADER_STRU;

/*****************************************************************************
�ṹ��    : CBT_TRANS_MSG_STRU
�ṹ˵��  : �����·����ݰ���չ�ṹ
*****************************************************************************/
typedef struct
{
    CBT_MSG_HEAD_STRU               stMsgHeader;
    VOS_UINT16                      usMsgId;      /* ��ϢID */
    VOS_UINT16                      usCompMode;
    VOS_UINT32                      ulMsgLength;
    VOS_UINT32                      ulReceiverPid; /* ������Ϣ��ģ��PID */
    VOS_UINT8                       aucPara[4];    /* ��Ϣ���� */
} CBT_TRANS_MSG_STRU;
/*****************************************************************************
�ṹ��    : CBT_HOOK_MSG_STRU
�ṹ˵��  : ���͸�CBTģ��ķ�͸����Ϣ���ݰ��ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usPrimId;
    VOS_UINT16                          usReserve;
    VOS_UINT8                           aucPara[4];   /* ��Ϣ���� */
} CBT_HOOK_MSG_STRU;
/*****************************************************************************
�ṹ��    : CBT_RCV_TRANS_MSG_STRU
�ṹ˵��  : ͸����CBTģ������ݰ��ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usTransPrimId;
    VOS_UINT16                          usRsv;
    VOS_UINT16                          usMsgId;     /* ָʾ��ǰ��Ϣ���� */
    VOS_UINT16                          usCompMode;
    VOS_UINT8                           aucPara[4];   /* ��Ϣ���� */
}CBT_RCV_TRANS_MSG_STRU;

/*****************************************************************************
�ṹ��    : CBT_SEND_COMM_MSG_STRU
�ṹ˵��  : PHY�����Agent�����㷢�͸�CBTģ������ݰ��ṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT16                          usMsgId;     /* ָʾ��ǰ��Ϣ���� */
    VOS_UINT16                          usCompMode;
    VOS_UINT8                           aucPara[4];   /* ��Ϣ���� */
}CBT_SEND_COMM_MSG_STRU;
/*****************************************************************************
�ṹ��    : PS_TO_CBT_MSG_STRU
�ṹ˵��  : PHY�����Agent�����㷢�͸�CBTģ������ݰ��ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usMsgId;     /* ָʾ��ǰ��Ϣ���� */
    VOS_UINT16                          usCompMode;     /* Ŀǰδʹ�� */
    VOS_UINT8                           aucPara[4];   /* ��Ϣ���� */
}PS_TO_CBT_MSG_STRU;
/*****************************************************************************
�ṹ��    : CBT_CTOA_MSG_STRU
�ṹ˵��  : �����·����ݰ���չ�ṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT16                      usPrimId;            /* ��ϢID */
    VOS_UINT16                      usLen;
    VOS_UINT8                       aucData[4];
}CBT_CTOA_MSG_STRU;

/*****************************************************************************
�ṹ��    : CBT_WRITE_NV_REQ_STRU
�ṹ˵��  : дNV����
*****************************************************************************/
typedef struct
{
    VOS_UINT32 ulCount;             /*Ҫд���NV�����*/
    VOS_UINT16 ausNvItemData[2];    /*����NVIDֵ��NVID���ݵĳ��ȡ�NVID������*/
}CBT_WRITE_NV_REQ_STRU;

/*****************************************************************************
�ṹ��    : CBT_WRITE_NV_CNF_STRU
�ṹ˵��  : дNV���
*****************************************************************************/
typedef struct
{
    CBT_MSG_HEAD_STRU           stMsgHead;
    VOS_UINT16                  usMsgId;      /* ��ϢID */
    CBT_COMPONENT_MODE_STRU     stCompMode;
    VOS_UINT32                  ulMsgLength;
    VOS_UINT32                  ulErrorCode;        /*����ִ�н��*/
    VOS_UINT32                  ulErrNvId;          /*���س��ִ����NVID*/
}CBT_WRITE_NV_CNF_STRU;

/*****************************************************************************
�ṹ��    : CBT_WRITE_NV_FLASH_REQ_STRU
�ṹ˵��  : дNVˢflash����
*****************************************************************************/
typedef struct
{
    VOS_UINT32 ulCount;             /*Ҫд���NV�����*/
    VOS_UINT16 ausNvItemData[2];    /*����NVIDֵ��NVID���ݵĳ��ȡ�NVID������*/
}CBT_WRITE_NV_FLASH_REQ_STRU;

/*****************************************************************************
�ṹ��    : CBT_WRITE_NV_FLASH_CNF_STRU
�ṹ˵��  : дNVˢflash���
*****************************************************************************/
typedef struct
{
    CBT_MSG_HEAD_STRU           stMsgHead;
    VOS_UINT16                  usMsgId;            /* ��ϢID */
    CBT_COMPONENT_MODE_STRU     stCompMode;
    VOS_UINT32                  ulMsgLength;
    VOS_UINT32                  ulErrorCode;        /*����ִ�н��*/
    VOS_UINT32                  ulErrNvId;          /*���س��ִ����NVID*/
}CBT_WRITE_NV_FLASH_CNF_STRU;

/*****************************************************************************
�ṹ��    : CBT_NV_TO_FLASH_CNF_STRU
�ṹ˵��  : �洢NV��FLASH������Ӧ���ṹ
*****************************************************************************/
typedef struct
{
    CBT_MSG_HEAD_STRU           stMsgHead;
    VOS_UINT16                  usMsgId;      /* ��ϢID */
    CBT_COMPONENT_MODE_STRU     stCompMode;
    VOS_UINT32                  ulMsgLength;
    VOS_UINT32                  ulErrorCode;        /*����ִ�н��*/
}CBT_NV_TO_FLASH_CNF_STRU;

typedef VOS_VOID (*CBT_FUN)(const CBT_UNIFORM_MSG_STRU *pstCbtMsg, VOS_UINT16 usReturnPrimId);

typedef struct
{
    CBT_FUN     pfCbtFun;           /*Reserves the pointer of function handles current msg.*/
    VOS_UINT16  primId;             /*Indicates current msg type.*/
    VOS_UINT16  returnPrimId;       /*Indicates return msg type.*/
} CBT_MSG_FUN_STRU;
/*****************************************************************************
 �ṹ��    : CBT_LISI_MODE_CTRL_STRU
 Э�����  :
 �ṹ˵��  : Listmode��ص����ݽṹ
*****************************************************************************/
typedef struct
{
    CBT_MODEM_SSID_STRU         stModemSsid;            /* Modem */
    VOS_UINT8                   ucReserve;              /* ������ */
    CBT_COMPONENT_MODE_STRU     stCompMode;             /* ���ID */

    VOS_UINT32                  ulBand;
    VOS_UINT16                  usTxChan;
    VOS_UINT16                  usRxChan;
    VOS_UINT16                  usPcl;
    VOS_UINT16                  usRsv1;

    VOS_UINT16                  usWSyncStatus;
    VOS_UINT16                  usCSyncStatus;
    VOS_UINT16                  usCReportFlag;
    VOS_UINT16                  usGeReportFlag;

    VOS_UINT16                  usRecvPrimId;
    VOS_UINT16                  usEnableReport;
    VOS_UINT16                  usListModeSegIndex;             /* list mode segment index, start by 1 */
    VOS_UINT16                  usRsv2;
    VOS_UINT32                  ulHandOverStartTime;            /* Handover ��ʼʱ��: ms */
    VOS_UINT16                  usEnableRssiReport;             /* RSSI�ϱ�ʹ�� */
    VOS_UINT16                  usOffSetFrames;                 /* Handover����ʱ����dsp�����ϱ�RSSI����λ: Frames */
    VOS_UINT16                  usRssiReportFrames;             /* RSSI�ϱ�֡�� */
    VOS_UINT16                  usTrigRssiTimer;                /* ����dsp�����ϱ�RSSI�ļ����� */
    VOS_BOOL                    bCbtCallSuc;                    /*CBT listmode call ���*/
    VOS_UINT32                  ulCbtCallSucStartTime;          /* CBT call �ѵ��źŵ���ʼʱ�� */
    VOS_UINT32                  ulCbtCallTimeOut;               /* ��������CBT call ��ʱʱ�䣬��λms ��0 ���봥��*/
    VOS_INT16                   sCbtCallRxLevel;                /* CBT call ʱ�������ź�ǿ�ȣ���λ0.1dBm */
    VOS_INT16                   sCbtCallTxPower;                /* CBT call ʱ�������ź�ǿ�ȣ���λ0.1dBm */

    VOS_UINT16                  usTotalFrameNum;        /* ��֡�� */
    VOS_UINT16                  usCurFrameNum;          /* �ϱ���BER��ǰ֡�� */
    VOS_UINT16                  usReportFrameNum;       /* �ϱ���BER��֡�� */
    VOS_UINT16                  usCurReportFrameNum;    /* �ϱ���BER��֡�� */
    VOS_UINT32                  ulFrameStatistic;       /* listmode ����֡���� */
    VOS_UINT32                  ulListmodeFrameTotal;   /* listmode �Ѳ���֡�� */

    VOS_UINT16                  usTxTotalFrameNum;      /* �ϱ���BER��֡�� */
    VOS_UINT16                  usTxCurFrameNum;        /* �ϱ���BER��ǰ֡�� */

    VOS_SEM                     ulCbtTotalFrameSem;
    VOS_SEM                     ulCbtTxSegmentFrameSem;
    VOS_SEM                     ulCbtSyncSem;
    VOS_SEM                     ulCbtGeDlQualitySem;

#if ( FEATURE_ON == FEATURE_GSM_WHOLE_SDR )
    VOS_SEM                     ulCbtEdgeBlerSem;
#endif
}CBT_LISI_MODE_CTRL_STRU;
/*****************************************************************************
 �ṹ��    : CBT_GE_DL_STATUS_STRU
 Э�����  :
 �ṹ˵��  : GSM�ϱ�����������Ϣ�ṹ
*****************************************************************************/
typedef struct
{
    CBT_MSG_HEAD_STRU      stHeader;
    VOS_UINT16             usPrimId;   /*Indicates current msg type.*/
    VOS_UINT16             usToolId;   /*Not used now.*/
    VOS_UINT32             ulMsgLength;
    VOS_UINT16             usBerValue[2];
}CBT_GE_DL_STATUS_STRU;
/*****************************************************************************
 �ṹ��    : CBT_LIST_MODE_BER_IND_STRU
 Э�����  :
 �ṹ˵��  : Ber�ϱ���Ϣ�ṹ
*****************************************************************************/
typedef struct
{
    CBT_MSG_HEAD_STRU       stHeader;
    VOS_UINT16              usPrimId;            /*Indicates current msg type.*/
    VOS_UINT16              usToolId;            /*Not used now.*/
    VOS_UINT32              ulMsgLength;

    VOS_UINT16              usTotalFrameNum;
    VOS_UINT16              usCurFrameNum;
    VOS_UINT16              usBand;
    VOS_UINT16              usRxChan;
    VOS_UINT16              usCrcData;
    VOS_UINT16              usListModeSegIndex;  /* list mode segment index, start by 1 */
    VOS_UINT32              ulDataLen;           /* ���ݳ���,��λ:�ֽ�,����ֵ����4��������,��Χ[0..WTTFPHY_MAX_PHY_DATA_REQ_LEN-1] */
    VOS_UINT8               aucData[OM_BER_DATA_MAX_SIZE]; /* �������ݿ� */
}CBT_LIST_MODE_BER_IND_STRU;
/*****************************************************************************
 �ṹ��    : CBT_C_FER_DATA_CNF_STRU
 Э�����  :
 �ṹ˵��  : Cģ Fer�ϱ���Ϣ�ṹ
*****************************************************************************/
typedef struct
{
    CBT_MSG_HEAD_STRU       stHeader;
    VOS_UINT16              usPrimId;            /*Indicates current msg type.*/
    VOS_UINT16              usToolId;            /*Not used now.*/
    VOS_UINT32              ulMsgLength;

    VOS_UINT32              ulErrorCode;
    VOS_UINT16              usTotalFrameNum;
    VOS_UINT16              usBadFrameNum;
    VOS_UINT32              ulTotalBitsNum;
    VOS_UINT32              ulErrorBitsNum;
}CBT_C_FER_DATA_CNF_STRU;

/*****************************************************************************
 �ṹ��    : CBT_G_BER_DATA_IND_STRU
 Э�����  :
 �ṹ˵��  : Gģ Ber�ϱ���Ϣ�ṹ
*****************************************************************************/
typedef struct
{
    CBT_MSG_HEAD_STRU       stHeader;
    VOS_UINT16              usPrimId;            /*Indicates current msg type.*/
    VOS_UINT16              usToolId;            /*Not used now.*/
    VOS_UINT32              ulMsgLength;

    VOS_UINT16              usTotalFrameNum;
    VOS_UINT16              usCurFrameNum;
    VOS_UINT16              usCrcData;
    VOS_UINT16              usDataLen;           /* ���ݳ���,��λ:�ֽ�,����ֵ����4��������,��Χ[0..WTTFPHY_MAX_PHY_DATA_REQ_LEN-1] */
    VOS_UINT8               aucData[OM_BER_DATA_MAX_SIZE]; /* �������ݿ� */
}CBT_G_BER_DATA_IND_STRU;

/*****************************************************************************
 �ṹ��    : CBT_LT_SWITCH_RF_ANT_STRU
 Э�����  :
 �ṹ˵��  : Ber�ϱ���Ϣ�ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16  usGpioNo;
    VOS_UINT16  usGpioLevel;
} CBT_LT_SWITCH_RF_ANT_STRU;

/*****************************************************************************
 �ṹ��    : CBT_LIST_MODE_RSSI_IND_STRU
 Э�����  :
 �ṹ˵��  : listmode Rssi�ϱ���Ϣ�ṹ
*****************************************************************************/
typedef struct
{
    CBT_MSG_HEAD_STRU       stHeader;
    VOS_UINT16              usPrimId;            /*Indicates current msg type.*/
    VOS_UINT16              usToolId;            /*Not used now.*/
    VOS_UINT32              ulMsgLength;

    VOS_UINT16              usBand;
    VOS_UINT16              usRxChan;
    VOS_UINT16              usListModeSegIndex; /* list mode segment index, start by 1 */
    VOS_UINT16              usRsv;
    VOS_INT32               lRxLevel;           /* �ϱ���RX level 0.125dBm */
    VOS_INT32               lRscp;                /* �ϱ���Rscp 0.125dBm */
}CBT_LIST_MODE_RSSI_IND_STRU;

/*****************************************************************************
 �ṹ��    : CBT_NO_SIG_BT_RSSI_IND_STRU
 Э�����  :
 �ṹ˵��  : �����۲�Rssi�ϱ���Ϣ�ṹ
*****************************************************************************/
typedef struct
{
    CBT_MSG_HEAD_STRU       stHeader;
    VOS_UINT16              usPrimId;            /*Indicates current msg type.*/
    VOS_UINT16              usToolId;            /*Not used now.*/
    VOS_UINT32              ulMsgLength;

    VOS_UINT32              ulErrorCode;
    VOS_INT32               lRxLevel;           /* �ϱ���RX level 0.125dBm */
}CBT_NO_SIG_BT_RSSI_CNF_STRU;

/*****************************************************************************
�ṹ��    : CBT_RTT_AGENT_MSG_STRU
�ṹ˵��  : CBTģ��ת����RTTģ�����Ϣ
*****************************************************************************/
typedef struct
{
    CBT_MSG_HEAD_STRU               stMsgHeader;
    VOS_UINT16                      usMsgId;      /* ��ϢID */
    CBT_COMPONENT_MODE_STRU         stCompMode;
    VOS_UINT32                      ulMsgLength;
    VOS_UINT16                      usTMode;      /* TMode */
    VOS_UINT16                      usRsv;
} CBT_RTT_AGENT_MSG_STRU;

/*****************************************************************************
�ṹ��    : CBT_LMT_MSG_INFO
�ṹ˵��  : ����LMT�Ĳ��ֲ���
*****************************************************************************/
typedef struct
{
    VOS_UINT32              enModem;
    VOS_UINT16              usSysMode;
    VOS_BOOL                bMasterMode;
    VOS_RATMODE_ENUM_UINT32 enMsgMode;
    VOS_UINT32              ulReceiverPid;
}CBT_LMT_MSG_INFO;

typedef VOS_UINT32 (* RTTAgentFunc)(VOS_VOID *pMsg);

/*****************************************************************************
�ṹ��    : GUCCBT_NRNOSIG_IND_MSG_STRU
�ṹ˵��  : NR��ģBTҵ���£�usBusiness��ʶ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT16              usMsgId;
    VOS_UINT16              usBusiness;
}GUCCBT_NRNOSIG_IND_MSG_STRU;

typedef struct
{
    VOS_UINT8               ucRsv;
    VOS_UINT8               ucComponentType    : 4;   //��ucComponentType��OM/MSP,����Ч 0x0: LTE, 0x1: TDS,0x2: GSM, 0x3: UMTS,0x4: X, 0xF: ��ģ�޹�
    VOS_UINT8               ucComponentID      : 4;   // OM/MSP:0x1, nosig:0x2, PHY:0x3
}CBT_COMPONENT_ID_STRU;

/*****************************************************************************
�ṹ��    : NRNOSIG_GUCCBT_MSG_STRU
�ṹ˵��  : NrNosig��GUCCBT�ظ���Ϣ�ݶ�
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT16              usMsgId;      /* ָʾ��ǰ��Ϣ���� */
    CBT_COMPONENT_ID_STRU   stComponentId;
    VOS_UINT32              ulResult;
}NRNOSIG_GUCCBT_MSG_STRU;

/*��ѯPA���Խṹ��*/
typedef struct
{
    VOS_UINT16        usQueryType;
    VOS_UINT16        usRsv;
    VOS_INT32         lQueryResult;
}OM_PA_ITEM_STRU;

typedef struct
{
    VOS_UINT32        ulResult;
    OM_PA_ITEM_STRU   aPaItem[1];
}OM_APP_PA_ATTRIBUTE_STRU;

typedef struct
{
    VOS_UINT16                          usSysMode;                       /* rat��ʽ��0xffff��ʾ��ʽ���䣬ֻ����ˢ��nv */
    VOS_UINT8                           ucNvEnable                  :1;
    VOS_UINT8                           ucRficChannel               :4;  /* RFICͨ�� */
    OM_RFIC_CHANNEL_FLAG_ENUM_UINT8     ucRficChannelFlag           :3;  /* RFICͨ��ʹ�ܱ�־, 0 ��ʹ��, 1 ��ʾ����ͨ��, 2 ��ʾͨ����ҵ������ */
    VOS_UINT8                           ucFtmMode                   :1;
    VOS_UINT8                           ucRsv2                      :7;
}OM_LMT_MSG_STRU;

typedef struct
{
    VOS_UINT16              usSysMode;
    VOS_UINT16              usRsv;
}OM_ACTIVE_PHY_STRU;

/*****************************************************************************
  ��������
*****************************************************************************/
#if (OSA_CPU_CCPU == VOS_OSA_CPU)

VOS_VOID CBT_SendContentChannel(CBT_MODEM_SSID_STRU stModemSsid, CBT_COMPONENT_MODE_STRU stCompMode,
                                       VOS_UINT16 usReturnPrimId, CBT_UNIFORM_MSG_STRU * pstCbtToPcMsg);

VOS_VOID CBT_SendResultChannel(CBT_MODEM_SSID_STRU stModemSsid, CBT_COMPONENT_MODE_STRU stCompMode,
                                VOS_UINT16 usReturnPrimId, VOS_UINT32 ulResult);

VOS_VOID OM_NoSigCtrlInit(VOS_UINT8 ucModemId);

VOS_VOID CBT_ListModeCtrlInit(VOS_UINT8 ucModemId);

VOS_VOID CBT_ResetMsgHead(CBT_UNIFORM_MSG_STRU * pstCbtToPcMsg);

VOS_UINT32 CBT_SendData(CBT_UNIFORM_MSG_STRU * pucMsg, VOS_UINT16 usMsgLen);

VOS_UINT32 CBT_GreenChannel(CBT_MODEM_SSID_STRU stModemSsid, CBT_COMPONENT_MODE_STRU stCompMode, VOS_UINT16 usPrimId,
                            VOS_UINT8 * pucData, VOS_UINT16 usLen);

#endif


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif