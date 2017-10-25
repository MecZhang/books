// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// ("Fluent UI")����ʾ������Ϊ�ο������ṩ�� 
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ���� (C) Microsoft Corporation
// ��������Ȩ����

// MvSmartCamCtrlDemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

#include "MvSmartCamCtrl.h"


// CMvSmartCamCtrlDemoDlg �Ի���
class CMvSmartCamCtrlDemoDlg : public CDialog
{
// ����
public:
	CMvSmartCamCtrlDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MVSMARTCAMCTRLDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    void DisplayOneFrame();
public:
    MV_SC_DEVICE_INFO_LIST m_stDeviceInfoList;
    MV_SC_DEVICE_INFO m_stDeviceInfo;
    void* m_handle;
    bool m_bConnect;
    bool m_bStartJob;
    unsigned char * m_pData;
    unsigned int m_nDataSize;
    MV_SC_IMAGE_OUT_INFO m_stImageOutInfo;
    CComboBox m_ctrlComboDeviceList;
    unsigned int m_nComboDeviceList;
    afx_msg void OnBnClickedButtonEnumDevice();
    afx_msg void OnCbnSelchangeComboDeviceList();
    afx_msg void OnBnClickedButtonOpenDevice();
    afx_msg void OnBnClickedButtonCloseDevice();
    afx_msg void OnBnClickedButtonStartGrabbing();
    afx_msg void OnBnClickedButtonStopGrabbing();
    CEdit m_ctrlEditExposureTime;
    CEdit m_ctrlEditGain;
    CEdit m_ctrlEditFrameRate;
    afx_msg void OnBnClickedButtonParamGet();
    afx_msg void OnBnClickedButtonParamSet();
	BOOL PreTranslateMessage(MSG* pMsg);
 
    afx_msg void OnBnClickedRadioTriggerOff();
    afx_msg void OnBnClickedRadioTriggerOn();
    afx_msg void OnBnClickedCheckSoftware();
    CButton m_ctrlCheckSoftware;
    afx_msg void OnBnClickedButtonSoftwareOnce();
	afx_msg void OnBnClickedButtonSaveBmp();
    afx_msg void OnClose();
};
