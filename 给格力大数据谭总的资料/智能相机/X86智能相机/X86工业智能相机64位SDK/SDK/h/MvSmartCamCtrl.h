/***************************************************************************************************
* 
* ��Ȩ��Ϣ����Ȩ���� (c) 2016, ���ݺ��������˼������޹�˾, ��������Ȩ��
* 
* �ļ����ƣ�MvSmartCamCtrl.h
* ժ    Ҫ���������SDK��C�ӿ���
*
* ��ǰ�汾��1.0.0.0
* ��    �ڣ�2016-05-02
* ��    ע���½�
***************************************************************************************************/
#ifndef _MV_SMART_CAM_CTRL_H_
#define _MV_SMART_CAM_CTRL_H_

#include "MvErrorDefine.h"
#include "MvSmartCamParams.h"


/**
*  @brief  ��̬�⵼�뵼������
*/
#ifndef MVSMARTCAMCTRL_API

    #ifdef WIN32
        #if defined(MVSMARTCAMCTRL_EXPORTS)
            #define MVSMARTCAMCTRL_API __declspec(dllexport)
        #else
            #define MVSMARTCAMCTRL_API __declspec(dllimport)
        #endif
    #else
        #ifndef __stdcall
            #define __stdcall
        #endif

        #ifndef MVSMARTCAMCTRL_API
            #define  MVSMARTCAMCTRL_API
        #endif
    #endif

#endif

#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif


#ifdef __cplusplus
extern "C" {
#endif 

/*@fn       MV_SC_GetSDKVersion
**@brief    ��ȡ��ǰ��SDK�汾
**@param    ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API unsigned int __stdcall MV_SC_GetSDKVersion();

/*@fn       MV_SC_Discovery
**@brief    ö���豸
**@param    pstDevList      �豸��Ϣ�б�ṹ��ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_Discovery(IN OUT MV_SC_DEVICE_INFO_LIST * pstDevList);

/*@fn       MV_SC_DiscoveryEx
**@brief    ö���豸����չ�ӿڣ�����ָ��ö�ٶ˿ں�
**@param    pstDevList      �豸��Ϣ�б�ṹ��ָ��
**@param    nDevPort        ָ���豸�˿ں�
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_DiscoveryEx(IN OUT MV_SC_DEVICE_INFO_LIST * pstDevList, IN const unsigned short nDevPort);

/*@fn       MV_SC_GetDeviceInfo
**@brief    ��ȡ�豸��Ϣ
**@param    nDeviceIp       �豸IP��ַ
**@param    pstDeviceInfo   �豸��Ϣ�ṹ��ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetDeviceInfo(IN unsigned int nDeviceIp, OUT MV_SC_DEVICE_INFO * pstDeviceInfo);

/*@fn       MV_SC_GetDeviceInfoEx
**@brief    ��ȡ�豸��Ϣ����չ�ӿڣ���ָ���˿ں�
**@param    nDeviceIp       �豸IP��ַ
**@param    pstDeviceInfo   �豸��Ϣ�ṹ��ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetDeviceInfoEx(IN unsigned int nDeviceIp, IN const unsigned short nDevPort, OUT MV_SC_DEVICE_INFO * pstDeviceInfo);

/*@fn       MV_SC_CreateHandle
**@brief    �����豸���
**@param    handle          �豸���
**@param    pstDevInfo      �豸��Ϣ�ṹ��ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_CreateHandle(  OUT void ** handle
                                                    , IN  MV_SC_DEVICE_INFO* pstDevInfo);

/*@fn       MV_SC_CreateHandleEx
**@brief    �����豸�������չ�ӿڣ�����ָ�������豸����Ķ˿ں�
**@param    handle          �豸���
**@param    pstDevInfo      �豸��Ϣ�ṹ��ָ��
**@param    nDevPort        ָ���豸�˿ں�
**@param    bLogEnable      �Ƿ񴴽�Log�ļ�
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_CreateHandleEx(  OUT void ** handle
                                                      , IN  MV_SC_DEVICE_INFO* pstDevInfo
                                                      , IN  const unsigned short nDevPort
                                                      , IN  const bool bLogEnable);

/*@fn       MV_SC_DestroyHandle
**@brief    �����豸���
**@param    handle          Ҫ���ٵ��豸���
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_DestroyHandle(IN void * handle);

/*@fn       MV_SC_ForceIp
**@brief    
**@param    handle          �豸���
**@param    nNewIp          
**@param    nNewSubNet      
**@param    nNewGateWay     
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_ForceIp(IN void * handle, IN unsigned int nNewIp);

/*@fn       MV_SC_GetTlProxy
**@brief    ��ȡ����������
**@param    handle          �豸���
**@param    ppcTlProxy      ���صĴ���������ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetTlProxy(IN void * handle, OUT void ** ppcTlProxy);

/* 3��״̬��Offline��Online��NotConnected
   �쳣��CvsInSightLockedException��CvsSensorAlreadyConnectedException��
         CvsInvalidLogonException��CvsNetworkException
*/

/*@fn       MV_SC_Connect
**@brief    �����豸
**@param    handle          �豸���
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_Connect(IN void * handle);

/*@fn       MV_SC_Disconnect
**@brief    �Ͽ�����
**@param    handle          �豸���
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_Disconnect(IN void * handle);

/*@fn       MV_SC_SaveJob
**@brief    ���浱ǰ�������̵���n�飨nȡֵ��Χ1-3��
**@param    handle          �豸���
**@param    nIndex          
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SaveJob(IN void * handle, IN int nIndex);

/*@fn       MV_SC_ImportJob
**@brief    ���빤�����̵���n�飨nȡֵ��Χ1-3��
**@param    handle          �豸���
**@param    pJobBuf         �������̻���ָ��
**@param    nBufLen         �������̻����С
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_ImportJob(IN void * handle, IN unsigned char* pJobBuf, IN unsigned int nBufLen);

/*@fn       MV_SC_ExportJob
**@brief    ������n�飨nȡֵ��Χ1-3����������
**@param    handle          �豸���
**@param    pJobBuf         �������̻���ָ��
**@param    nBufSize        �������̻����С
**@param    pnBufLen        ���صĻ����Сָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_ExportJob(IN void * handle, IN OUT unsigned char* pJobBuf, IN unsigned int nBufSize, IN OUT unsigned int* pnBufLen);

/*@fn       MV_SC_ExportLog
**@brief    
**@param    handle          �豸���
**@param    pJobBuf         �������̻���ָ��
**@param    nBufSize        �������̻����С
**@param    pnBufLen        ���صĻ����Сָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_ExportLog(IN void * handle, IN OUT unsigned char* pJobBuf, IN unsigned int nBufSize, IN OUT unsigned int* pnBufLen);

/*@fn       MV_SC_ImportFilterRules
**@brief    ������չ���˹���
**@param    handle          �豸���
**@param    pJobBuf         �������̻���ָ��
**@param    nBufSize        �������̻����С
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_ImportFilterRules(IN void * handle, IN unsigned char* pJobBuf, IN unsigned int nBufLen);

/*@fn       MV_SC_OutportFilterRules
**@brief    ������չ���˹���
**@param    handle          �豸���
**@param    pJobBuf         �������̻���ָ��
**@param    nBufSize        �������̻����С
**@param    pnBufLen        ���صĻ����Сָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_OutportFilterRules(IN void * handle, IN OUT unsigned char* pJobBuf, IN unsigned int nBufSize, IN OUT unsigned int* pnBufLen);

/*@fn       MV_SC_SetFilterRulesEnable
**@brief    ������չ���˹���ʹ��
**@param    handle          �豸���
**@param    bCutout         
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetFilterRulesEnable(IN void* handle, IN bool bCutout);


/*@fn       MV_SC_GetFilterRulesEnableStatus
**@brief    ��ȡ�����չ���˹���ʹ�ܵ�״̬
**@param    handle          �豸���
**@param    bCutout         
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetFilterRulesEnableStatus(IN void* handle, IN bool *pbEnbale);


/*@fn       MV_SC_BeCameraExistExFilterRules
**@brief    ��ȡ����Ƿ������չ���˹���
**@param    handle          �豸���
**@param    pbExist         
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_BeCameraExistExFilterRules(IN void* handle, IN bool *pbExist);

/*@fn       MV_SC_StartJob
**@brief    ��ʼ��������
**@param    handle          �豸���
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_StartJob(IN void * handle);

/*@fn       MV_SC_StopJob
**@brief    ֹͣ��������
**@param    handle          �豸���
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_StopJob(IN void * handle);

/*@fn       MV_SC_GetJobState
**@brief    ��ȡ�����ǰ�Ĺ���״̬��pbWorking����ֵΪ1����ʾ���ڹ���״̬��Ϊ0��ʾ�ǹ���״̬
**@param    handle          �豸���
**@param    pbWorking       ����״ָ̬��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetJobState(IN void * handle, IN OUT int* pbWorking);

/*@fn       MV_SC_SetCutoutEnable
**@brief    �����Ƿ��ͼ
**@param    handle          �豸���
**@param    bCutout         �Ƿ��ͼ��־
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetCutoutEnable(IN void* handle, IN bool bCutout);

/*@fn       MV_SC_GetOneFrame
**@brief    ��ȡһ֡ͼ������
**@param    handle          �豸���
**@param    pData           ��ȡ��ͼ������ָ��
**@param    pData           ͼ�����ݻ�������С
**@param    pstImageInfo    ͼ��֡��Ϣ�ṹ��ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetOneFrame(IN void * handle, 
                                                  IN OUT unsigned char * pData , 
                                                  IN unsigned int nDataSize, 
                                                  IN OUT MV_SC_IMAGE_OUT_INFO * pstImageInfo);

/*@fn       MV_SC_DisplayOneFrame
**@brief    ��ʾһ֡ͼ��
**@param    hWnd            ��ʾ���ھ��
**@param    pData           Ҫ��ʾ��ͼ������ָ��
**@param    pData           ͼ�����ݴ�С
**@param    nWidth          ͼ����
**@param    nHeight         ͼ��߶�
**@param    nPixelFormat    ͼ���ʽ
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_DisplayOneFrame(IN void * hWnd, IN unsigned char * pData , 
                                                   unsigned int nDataLen, IN unsigned int nWidth, IN unsigned int nHeight, IN unsigned int nPixelFormat);

/*@fn       MV_SC_Display
**@brief    ��ʾһ֡ͼ��������ȥ����MV_SC_DisplayOneFrame��������Ⱦ����ظ���ʼ�������٣��������������Ƶ�����������ĳ�ʼ����������ȥ��
**@param    handle          �豸���
**@param    hWnd            ��ʾ���ھ��
**@param    pData           Ҫ��ʾ��ͼ������ָ��
**@param    pData           ͼ�����ݴ�С
**@param    nWidth          ͼ����
**@param    nHeight         ͼ��߶�
**@param    nPixelFormat    ͼ���ʽ
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_Display(  IN void * handle
                                               , IN void * hWnd
                                               , IN unsigned char * pData
                                               , IN unsigned int nDataLen
                                               , IN unsigned int nWidth
                                               , IN unsigned int nHeight
                                               , IN MvScPixelType nPixelFormat);

/*@fn       MV_SC_RegisterOutputCallBack
**@brief    ע��ͼ�����ݻص�����
**@param    handle          �豸���
**@param    cbOutput        �ص�����ָ��
**@param    pUser           ��ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_RegisterOutputCallBack(IN void * handle, 
                                                             IN void(__stdcall * cbOutput)(unsigned char * pData, MV_SC_IMAGE_OUT_INFO* pstImageInfo, void* pUser),
                                                             IN void * pUser);

/*@fn       MV_SC_RegisterExceptionCallBack
**@brief    ע���쳣�ص�����
**@param    handle          �豸���
**@param    cbOutput        �ص�����ָ��
**@param    pUser           ��ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_RegisterExceptionCallBack(IN void * handle, 
                                                                 void(__stdcall * cbException)(unsigned int nMsgType, void * pUser), 
                                                                 void * pUser);


// �������úͻ�ȡ(�߼�����)
/*@fn       MV_SC_GetGenICamXML
**@brief    ��ȡXML����
**@param    handle          �豸���
**@param    pData           ���������ȡ��XML���ݵ����ݻ���ָ��
**@param    nDataSize       �����С
**@param    pnDataLen       ���ص�XML���ݳ���ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetGenICamXML(IN void * handle, IN OUT unsigned char * pData, IN unsigned int nDataSize, IN OUT unsigned int * pnDataLen);

/*@fn       MV_SC_CommandExecute
**@brief    ִ������
**@param    handle          �豸���
**@param    strName         �����Ӧ��XML�ڵ�����
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_CommandExecute(IN void * handle, IN const char * strName);

/*@fn       MV_SC_GetBooleanValue
**@brief    ��ȡBoolean�Ͳ���ֵ
**@param    handle          �豸���
**@param    strName         ������Ӧ��XML�ڵ�����
**@param    pbValue         ���صĲ���ֵָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetBooleanValue(IN void * handle, IN const char * strName, IN OUT bool * pbValue);

/*@fn       MV_SC_SetBooleanValue
**@brief    ����Boolean�Ͳ���ֵ
**@param    handle          �豸���
**@param    strName         ������Ӧ��XML�ڵ�����
**@param    bValue          Ҫ���õĲ���ֵ
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetBooleanValue(IN void * handle, IN const char * strName, IN bool bValue);

/*@fn       MV_SC_GetIntegerValue
**@brief    ��ȡInteger�Ͳ���ֵ
**@param    handle          �豸���
**@param    strName         ������Ӧ��XML�ڵ�����
**@param    pnValue         ���صĲ���ֵָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetIntegerValue(IN void * handle, IN const char * strName, IN OUT unsigned int * pnValue);

/*@fn       MV_SC_SetIntegerValue
**@brief    ����Integer�Ͳ���ֵ
**@param    handle          �豸���
**@param    strName         ������Ӧ��XML�ڵ�����
**@param    nValue          Ҫ���õĲ���ֵ
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetIntegerValue(IN void * handle, IN const char * strName, IN unsigned int nValue);

/*@fn       MV_SC_GetFloatValue
**@brief    ��ȡFloat�Ͳ���ֵ
**@param    handle          �豸���
**@param    strName         ������Ӧ��XML�ڵ�����
**@param    pfValue         ���صĲ���ֵָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetFloatValue(IN void * handle, IN const char * strName, IN OUT float * pfValue);

/*@fn       MV_SC_SetFloatValue
**@brief    ����Float�Ͳ���ֵ
**@param    handle          �豸���
**@param    strName         ������Ӧ��XML�ڵ�����
**@param    fValue          Ҫ���õĲ���ֵ
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetFloatValue(IN void * handle, IN const char * strName, IN float fValue);

/*@fn       MV_SC_GetStringValue
**@brief    ��ȡString�Ͳ���ֵ
**@param    handle          �豸���
**@param    strName         ������Ӧ��XML�ڵ�����
**@param    strValue        ���صĲ���ֵָ��
**@param    nSize           ����ֵָ��ָ��Ļ���������
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetStringValue(IN void * handle, IN const char * strName, IN OUT char * strValue, IN unsigned int nSize);

/*@fn       MV_SC_SetStringValue
**@brief    ����String�Ͳ���ֵ
**@param    handle          �豸���
**@param    strName         ������Ӧ��XML�ڵ�����
**@param    strValue        Ҫ���õĲ���ֵ
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetStringValue(IN void * handle, IN const char * strName, IN const char * strValue);

/*@fn       MV_SC_GetEnumerationValue
**@brief    ��ȡEnumeration�Ͳ���ֵ
**@param    handle          �豸���
**@param    strName         ������Ӧ��XML�ڵ�����
**@param    pnValue         ���صĲ���ֵָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetEnumerationValue(IN void * handle, IN const char * strName, IN OUT unsigned int * pnValue);

/*@fn       MV_SC_SetEnumerationValue
**@brief    ����Enumeration�Ͳ���ֵ
**@param    handle          �豸���
**@param    strName         ������Ӧ��XML�ڵ�����
**@param    nValue          Ҫ���õĲ���ֵ
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetEnumerationValue(IN void * handle, IN const char * strName, IN unsigned int nValue);

/*@fn       MV_SC_GetNetTransInfo
**@brief    ��ȡ���紫����Ϣ
**@param    handle          �豸���
**@param    pstNetTransInfo ���紫����Ϣ�ṹ��ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetNetTransInfo(IN void * handle, OUT MVSC_NETTRANS_INFO * pstNetTransInfo);

/*@fn       MV_SC_GetOptimalPacketSize
**@brief    ��ȡ���ŵ����ݰ���С
**@param    handle          �豸���
**@param    pstNetTransInfo ���紫����Ϣ�ṹ��ָ��
**@return   ����ֵС��0����ʾ�����룻����0����ʾ�Ƽ�ʹ�õ�packetsize
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetOptimalPacketSize(IN void * handle);


// ���½ӿ�Ϊ���ƽӿڣ������ʹ��

/*@fn       MV_SC_SaveJpg
**@brief    ����JPG��ʽͼ��
**@param    pstParam        ͼ��ת�������ṹ��ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SaveJpg(MVSC_IMG_CONVERT_PARAM* pstParam);


/************************************************************************/
/* ������չ�ͽӿ�                                                       */
/************************************************************************/

/*@fn       MV_SC_GetIntegerValueEx
**@brief    ������Ͳ���ֵ��ص�ȫ��ֵ�������ֵ�����ֵ����Сֵ���������ȵ�
**@param    handle          �豸���
**@param    strName         ���Ͳ���ֵ��Ӧ��XML�ڵ���
**@param    pstValue        ���ͽṹ��ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetIntegerValueEx(IN void * handle, IN const char * strName, IN OUT MVSC_INTVALUE * pstValue);

/*@fn       MV_SC_GetIntegerValueEx
**@brief    ��ø����Ͳ���ֵ��ص�ȫ��ֵ�������ֵ�����ֵ����Сֵ��
**@param    handle          �豸���
**@param    strName         �����Ͳ���ֵ��Ӧ��XML�ڵ���
**@param    pstValue        �����ͽṹ��ָ��
**@return   �ɹ�������MV_OK;ʧ�ܣ����ش�����
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetFloatValueEx(IN void * handle, IN const char * strName, IN OUT MVSC_FLOATVALUE * pstValue);

#ifdef __cplusplus
}
#endif 

#endif //_MV_SMART_CAM_CTRL_H_
