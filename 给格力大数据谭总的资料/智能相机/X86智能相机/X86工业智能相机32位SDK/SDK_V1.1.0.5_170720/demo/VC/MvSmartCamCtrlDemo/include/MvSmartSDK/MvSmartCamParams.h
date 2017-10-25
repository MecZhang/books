/***************************************************************************************************
* 
* ��Ȩ��Ϣ����Ȩ���� (c) 2016, ���ݺ��������˼������޹�˾, ��������Ȩ��
* 
* �ļ����ƣ�SmartCamParams.h
* ժ    Ҫ�����������������
*
* ��ǰ�汾��1.0.0.0
* ��    �ڣ�2016-05-02
* ��    ע���½�
***************************************************************************************************/
#ifndef _MV_SMTCAM_PARAMS_H_
#define _MV_SMTCAM_PARAMS_H_

#include "PixelType.h"


// ���֧�ֵ��豸����
#define MV_SC_MAX_DEVICE_NUM      16

//  �쳣��Ϣ����
#define MV_SC_EXCEPTION_DEV_DISCONNECT     0x00008001      // �豸�Ͽ�����

//�ڵ�Stringֵ��󳤶�
#define MV_SC_MAX_XML_STRVALUE_LEN 256

//�豸��Ϣ�ṹ�嶨��
typedef struct _MV_SC_DEVICE_INFO_
{
    unsigned int    nDeviceIp;                      // �豸Ip
    unsigned int    nNetAdapterIp;                  // �豸��Ӧ��������IP
    unsigned char   strUserName[16];                // ��Ҫ�û���д
    unsigned char   strPassword[32];                // ��Ҫ�û���д
    unsigned int    bForceConnect;                  // ��Ҫ�û���д

    unsigned short  nMacAddrHigh;                    // �豸Mac��ַ��2�ֽ�
    unsigned int    nMacAddrLow;                     // �豸Mac��ַ��4�ֽ�
    unsigned int    nIpCfgOption;                    // �豸Ip����ѡ��
    unsigned int    nIpCfgCurrent;                   // �豸Ip����:bit31-static bit30-dhcp bit29-lla ��������Ip����ѡ��
    unsigned int    nCurrentSubNetMask;              // �豸��������
    unsigned int    nDefultGateWay;                  // ����
    unsigned char   chManufacturerName[32];          // ����������
    unsigned char   chModelName[32];                 // �ͺ�
    unsigned char   chDeviceVersion[32];             // �豸�汾
    unsigned char   chManufacturerSpecificInfo[48];  // ��������ϸ��Ϣ
    unsigned char   chSerialNumber[16];              // ���к�
    unsigned char   chUserDefinedName[16];           // �û��Զ�������

    unsigned int    nReserved[16];
}MV_SC_DEVICE_INFO;

enum SC_PROGRAM_STATE
{
	SC_PROGRAM_UNKNOWN,
	SC_PROGRAM_RUNNING,
	SC_PROGRAM_STOP
};

typedef struct _MV_SC_UPGRADE_INFO_
{
	unsigned long		deviceIndex;
	unsigned long		hostIp;
	unsigned short		progress;
	SC_PROGRAM_STATE 	programState;
	unsigned char		deviceHostName[32];
	unsigned char		cameraName[32];
	unsigned char		cameraVersion[32];
	MV_SC_DEVICE_INFO 	oriCameraInfo;
}MV_SC_UPGRADE_INFO;

typedef struct _MV_SC_UPGRADE_INFO_LIST_
{
	unsigned int           nDeviceNum;                             // �����豸����
	MV_SC_UPGRADE_INFO     astUpgradeDeviceInfo[MV_SC_MAX_DEVICE_NUM];     // ֧�����16���豸
}MV_SC_UPGRADE_INFO_LIST;

// �豸��Ϣ�б�
typedef struct _MV_SC_DEVICE_INFO_LIST_
{
    unsigned int            nDeviceNum;                             // �����豸����
    MV_SC_DEVICE_INFO      astDeviceInfo[MV_SC_MAX_DEVICE_NUM];     // ֧�����16���豸
}MV_SC_DEVICE_INFO_LIST;


// ���紫��������Ϣ
typedef struct _MV_NETTRANS_INFO_
{
    int64_t         nReviceDataSize;    // �ѽ������ݴ�С  [ͳ��StartGrabbing��StopGrabbing֮���������]
    int             nThrowFrameCount;   // ��֡����
    unsigned int    nReserved[5];       // ����

}MV_NETTRANS_INFO;

// ȫƥ���һ����Ϣ�ṹ��
typedef struct _MV_ALL_MATCH_INFO_
{
    unsigned int    nType;          // ��Ҫ�������Ϣ���ͣ�e.g. MV_MATCH_TYPE_NET_DETECT
    void*           pInfo;          // �������Ϣ���棬�ɵ����߷���
    unsigned int    nInfoSize;      // ��Ϣ����Ĵ�С

}MV_ALL_MATCH_INFO;

//��������
enum MvScPixelType
{
    // Undefined pixel type
    PixelType_Sc_Undefined              = 0,    
    PixelType_Sc_Bmp                    = 1,
    PixelType_Sc_Jpg                    = 2,
    PixelType_Sc_Mono8                  = 3,
};

//�����Ϣ����
enum MvScResultType
{
    ScResType_NULL                      = 0,    // û�н�����
    ScResType_BCR                       = 1,    // �����ϢΪBCR  (��Ӧ�ṹ�� MV_SC_RESULT_BCR)
};


#define MV_SC_MAX_BCR_CODE_LEN 256

//������Ϣ�ṹ�嶨��
typedef struct _MV_SC_BCR_INFO_
{
    unsigned int    nID;                                // ����ID
    char            chCode[MV_SC_MAX_BCR_CODE_LEN];     // �ַ�
    unsigned int    nLen;                               // �ַ�����
    unsigned int    nBarType;                           // ��������

    // ����λ��
    struct SC_POINT
    {
        int x;                                          // x����
        int y;                                          // y����
    } pt[4];

    int             nAngle;                             // ����Ƕȣ�0~1800��
    unsigned int    nMainPackageId;                     // ����ID
    unsigned int    nSubPackageId;                      // �ΰ�ID
    unsigned int    nReserved[2];                       // ����
} MV_SC_BCR_INFO;

// һ�����������������
#define MAX_SC_BCR_COUNT    200

// ScResType_BCR ��Ӧ�Ľṹ��
typedef struct _MV_SC_RESULT_BCR_
{
    unsigned int    nCodeNum;                           // ��������
    MV_SC_BCR_INFO  stBcrInfo[MAX_SC_BCR_COUNT];        // ������Ϣ�ṹ��
    unsigned int    nReserved[4];                       // ����
}MV_SC_RESULT_BCR;

// ������ݻ��������
#define MV_SC_MAX_RESULT_SIZE       (1024*64)

// ���֡��Ϣ�ṹ�嶨��
typedef struct _MV_SC_IMAGE_OUT_INFO_
{
    unsigned short      nWidth;             // ͼ���
    unsigned short      nHeight;            // ͼ���
    MvScPixelType       enPixelType;        // ���ػ�ͼƬ��ʽ

    unsigned int        nTriggerIndex;      // ������ţ����ڵ�ƽ����ʱ��Ч��
    unsigned int        nFrameNum;          // ֡��
    unsigned int        nFrameLen;          // ��ǰ֡���ݴ�С
    unsigned int        nTimeStampHigh;     // ʱ�����32λ
    unsigned int        nTimeStampLow;      // ʱ�����32λ

    unsigned int        nResultType;        // �������Ϣ����

    unsigned char       chResult[MV_SC_MAX_RESULT_SIZE];    // ������Ϣ���Ͷ�Ӧ��ͬ�Ľṹ��

    unsigned int        nFrameLenForCutout; // ���浥���ͼƬ���ݴ�С

    unsigned int        bFlaseTrigger;       // �Ƿ��󴥷�
    unsigned int        nFocusScore;       //  �۽��÷�

    unsigned int        nReserved[5];       // ����
}MV_SC_IMAGE_OUT_INFO;

//����ģʽ��״̬
typedef enum _MV_SC_TRIGGER_MODE_
{
    SC_TRIGGER_MODE_OFF         = 0,        // �ر�
    SC_TRIGGER_MODE_ON          = 1,        // ��
}MV_SC_TRIGGER_MODE;

//����Դ
typedef enum _MV_SC_TRIGGER_SOURCE_
{
    SC_TRIGGER_SOURCE_LINE0             = 0,        // Line0 ����
    SC_TRIGGER_SOURCE_LINE1             = 2,        // Line1 ����
    SC_TRIGGER_SOURCE_LINE2             = 3,        // Line2 ����
    SC_TRIGGER_SOURCE_COUNTER0          = 5,        // Counter0 ����
    SC_TRIGGER_SOURCE_SOFTWARE          = 1,        // ����
}MV_SC_TRIGGER_SOURCE;

// �Զ��ع�ģʽ
typedef enum _MV_SC_EXPOSURE_AUTO_MODE_
{
    SC_EXPOSURE_AUTO_MODE_OFF        = 0,            // �ر�
    SC_EXPOSURE_AUTO_MODE_ONCE       = 1,            // һ��
    SC_EXPOSURE_AUTO_MODE_CONTINUOUS = 2,            // ����

}MV_SC_EXPOSURE_AUTO_MODE;

//�Զ�����
typedef enum _MV_SC_GAIN_AUTO_MODE_
{
    SC_GAIN_AUTO_MODE_OFF        = 0,            // �ر�
    SC_GAIN_AUTO_MODE_ONCE       = 1,            // һ��
    SC_GAIN_AUTO_MODE_CONTINUOUS = 2,            // ����
};


//����/�������� ģʽ  
typedef enum _MV_SC_FIELD_CORRECT_MODE_
{
    SC_DARK_FILED_CORRECT        = 0,            // ����У��
    SC_BRIGHT_FILED_CORRECT       = 1,            // ����У��
    SC_INVAILED_FILED_CORRECT     = 2,            // ��ЧУ��

}MV_SC_FIELD_CORRECT_MODE;




// GigEVision IP Configuration
#define MV_IP_CFG_STATIC        0x05000000
#define MV_IP_CFG_DHCP          0x06000000
#define MV_IP_CFG_LLA           0x04000000

// GigEVision Net Transfer Mode
#define MV_NET_TRANS_DRIVER     0x00000001
#define MV_NET_TRANS_SOCKET     0x00000002

// ��Ϣ����
#define MV_MATCH_TYPE_NET_DETECT             0x00000001      // ���������Ͷ�����Ϣ

//  ���������Ͷ�����Ϣ�����ṹ�壬��Ӧ����Ϊ MV_MATCH_TYPE_NET_DETECT
typedef struct _MV_MATCH_INFO_NET_DETECT_
{
    int64_t         nReviceDataSize;    // �ѽ������ݴ�С  [ͳ��StartGrabbing��StopGrabbing֮���������]
    int64_t         nLostPacketCount;   // ��ʧ�İ�����
    unsigned int    nLostFrameCount;    // ��֡����
    unsigned int    nReserved[5];          // ����
}MV_MATCH_INFO_NET_DETECT;

#define MV_MAX_XML_SYMBOLIC_NUM      64

//ͼ�������Ϣ�ṹ�嶨��
typedef struct _MV_IMAGE_BASIC_INFO_
{
    // width
    unsigned short      nWidthValue;        // ͼ����
    unsigned short      nWidthMin;          // ͼ������Сֵ
    unsigned int        nWidthMax;          // ͼ�������ֵ
    unsigned int        nWidthInc;          // ͼ���Ȳ���ֵ

    // height
    unsigned int        nHeightValue;       // ͼ��߶�
    unsigned int        nHeightMin;         // ͼ��߶���Сֵ
    unsigned int        nHeightMax;         // ͼ��߶����ֵ
    unsigned int        nHeightInc;         // ͼ��߶Ȳ���ֵ

    // framerate
    float               fFrameRateValue;    // ֡��ֵ
    float               fFrameRateMin;      // ֡����Сֵ
    float               fFrameRateMax;      // ֡�����ֵ

    // ���ظ�ʽ
    unsigned int        enPixelType;                // ��ǰ�����ظ�ʽ
    unsigned int        nSupportedPixelFmtNum;      // ֧�ֵ����ظ�ʽ����
    unsigned int        enPixelList[MV_MAX_XML_SYMBOLIC_NUM];
    unsigned int        nReserved[8];                           // ����

}MV_IMAGE_BASIC_INFO;

typedef struct _MVSC_CMDVALUE_T
{
    bool            bIsDone;
    unsigned int    nReserved[4];
}MVSC_CMDVALUE;

//BOOL��ֵ�ṹ�嶨��
typedef struct _MVSC_BOOLVALUE_T
{
    bool            bCurValue;      // ��ǰֵ
    unsigned int    nReserved[4];
}MVSC_BOOLVALUE;

//����ֵ�ṹ�嶨��
typedef struct _MVSC_INTVALUE_T
{
    unsigned int    nCurValue;      // ��ǰֵ
    unsigned int    nMax;           // ���ֵ
    unsigned int    nMin;           // ��Сֵ
    unsigned int    nInc;           // ����ֵ

    unsigned int    nReserved[4];   // ����
}MVSC_INTVALUE;

//������ֵ�ṹ�嶨��
typedef struct _MVSC_FLOATVALUE_T
{
    float           fCurValue;      // ��ǰֵ
    float           fMax;           // ���ֵ
    float           fMin;           // ��Сֵ

    unsigned int    nReserved[4];   // ����
}MVSC_FLOATVALUE;

//String��ֵ�ṹ�嶨��
typedef struct _MVSC_STRINGVALUE_T
{
    char   chCurValue[MV_SC_MAX_XML_STRVALUE_LEN];      // ��ǰֵ

    unsigned int    nReserved[4];                       // ����
}MVSC_STRINGVALUE;

//ö����ֵ�ṹ�嶨��
typedef struct _MVSC_ENUMVALUE_T
{
    unsigned int    nCurValue;      // ��ǰֵ
    unsigned int    nSupportedNum;  // ���ݵ���Ч���ݸ���
    unsigned int    nSupportValue[MV_MAX_XML_SYMBOLIC_NUM];     // ��ǰ֧�ֵ�ö��ֵ

    unsigned int    nReserved[4];   // ����
}MVSC_ENUMVALUE;




// ���紫��������Ϣ
typedef struct _MVSC_NETTRANS_INFO_
{
    int64_t         nGvspReceiveDataSize;           // GVSPͨ�����յ����ݴ�С
    int             nGvspThrowFrameCount;           // GVSPͨ���׳���֡��
    int64_t         nGvmpReceiveDataSize;           // GVMPͨ�����յ����ݴ�С
    int             nGvmpThrowFrameCount;           // GVMPͨ���׳���֡��
    unsigned int    nReserved[24];                  // ����

}MVSC_NETTRANS_INFO;

// ���Э��
#define CommuPtlSmartSDK 1
#define CommuPtlTcpIP    2
#define CommuPtlSerial   3



// ͼƬ��ʽת������
typedef struct _MVSC_IMG_CONVERT_PARAM_
{
    unsigned char*      pData;              // [IN]     �������ݻ���
    unsigned int        nDataLen;           // [IN]     �������ݴ�С
    unsigned short      nWidth;             // [IN]     ͼ���
    unsigned short      nHeight;            // [IN]     ͼ���

    char                strFilePath[256];   // [IN]     ���ͼƬ·��
    unsigned int        nJpgQuality;        // [IN]     ��������, (0-100]
    unsigned int        nReserved[4];

}MVSC_IMG_CONVERT_PARAM;


#endif /* _MV_SMTCAM_PARAMS_H_ */
