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

// MvSmartCamCtrlDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MvSmartCamCtrlDemo.h"
#include "MvSmartCamCtrlDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

unsigned int __stdcall WorkThread(void * pUser)
{
    
    int nRet = MV_OK;
    CString cstrInfo;
    CMvSmartCamCtrlDemoDlg * pcMvSmartCamCtrlDemoDlg = (CMvSmartCamCtrlDemoDlg *)pUser;
    if (pcMvSmartCamCtrlDemoDlg)
    {
        pcMvSmartCamCtrlDemoDlg->DisplayOneFrame();
    }

    return 0;
}


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMvSmartCamCtrlDemoDlg �Ի���




CMvSmartCamCtrlDemoDlg::CMvSmartCamCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMvSmartCamCtrlDemoDlg::IDD, pParent)
    , m_handle(0)
    , m_bConnect(0)
    , m_bStartJob(false)
    , m_pData(0)
    , m_nDataSize(0)
    , m_nComboDeviceList(0)
{
    memset(&m_stDeviceInfoList, 0, sizeof(m_stDeviceInfoList));
    memset(&m_stDeviceInfo, 0, sizeof(m_stDeviceInfo));
    memset(&m_stImageOutInfo, 0, sizeof(m_stImageOutInfo));
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMvSmartCamCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_DEVICE_LIST, m_ctrlComboDeviceList);
    DDX_Control(pDX, IDC_EDIT_EXPOSURE_TIME, m_ctrlEditExposureTime);
    DDX_Control(pDX, IDC_EDIT_GAIN, m_ctrlEditGain);
    DDX_Control(pDX, IDC_EDIT_FRAME_RATE, m_ctrlEditFrameRate);
    DDX_Control(pDX, IDC_CHECK_SOFTWARE, m_ctrlCheckSoftware);
}

BEGIN_MESSAGE_MAP(CMvSmartCamCtrlDemoDlg, CDialog)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    //}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BUTTON_ENUM_DEVICE, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonEnumDevice)
    ON_CBN_SELCHANGE(IDC_COMBO_DEVICE_LIST, &CMvSmartCamCtrlDemoDlg::OnCbnSelchangeComboDeviceList)
    ON_BN_CLICKED(IDC_BUTTON_OPEN_DEVICE, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonOpenDevice)
    ON_BN_CLICKED(IDC_BUTTON_CLOSE_DEVICE, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonCloseDevice)
    ON_BN_CLICKED(IDC_BUTTON_START_GRABBING, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonStartGrabbing)
    ON_BN_CLICKED(IDC_BUTTON_STOP_GRABBING, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonStopGrabbing)
    ON_BN_CLICKED(IDC_BUTTON_PARAM_GET, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonParamGet)
    ON_BN_CLICKED(IDC_BUTTON_PARAM_SET, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonParamSet)
    ON_BN_CLICKED(IDC_RADIO_TRIGGER_OFF, &CMvSmartCamCtrlDemoDlg::OnBnClickedRadioTriggerOff)
    ON_BN_CLICKED(IDC_RADIO_TRIGGER_ON, &CMvSmartCamCtrlDemoDlg::OnBnClickedRadioTriggerOn)
    ON_BN_CLICKED(IDC_CHECK_SOFTWARE, &CMvSmartCamCtrlDemoDlg::OnBnClickedCheckSoftware)
    ON_BN_CLICKED(IDC_BUTTON_SOFTWARE_ONCE, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonSoftwareOnce)
    ON_BN_CLICKED(IDC_BUTTON_SAVE_BMP, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonSaveBmp)
    ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMvSmartCamCtrlDemoDlg ��Ϣ�������

BOOL CMvSmartCamCtrlDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

    m_pData = (unsigned char *)malloc(1024 * 1024 * 10);
    if (0 == m_pData)
    {
        return TRUE;
    }
    m_nDataSize = 1024 * 1024 * 10;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMvSmartCamCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMvSmartCamCtrlDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMvSmartCamCtrlDemoDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CMvSmartCamCtrlDemoDlg::DisplayOneFrame()
{
    int nRet = MV_OK;

    while (m_bStartJob)
    {
        nRet = MV_SC_GetOneFrame(m_handle, m_pData, m_nDataSize, &m_stImageOutInfo);

        if (MV_OK == nRet)
        {
            MV_SC_Display(m_handle, GetDlgItem(IDC_STATIC_DISPLAY)->GetSafeHwnd(), m_pData, m_nDataSize, m_stImageOutInfo.nWidth, m_stImageOutInfo.nHeight, m_stImageOutInfo.enPixelType);
        }
        else
        {
            Sleep(10);
        }
    }
}

BOOL CMvSmartCamCtrlDemoDlg::PreTranslateMessage(MSG* pMsg)
 {
     if(pMsg->message==WM_KEYDOWN&&pMsg->wParam==VK_RETURN)    
         return TRUE; 
     if(pMsg->message==WM_KEYDOWN&&pMsg->wParam==VK_ESCAPE)    
         return TRUE; 
     return CDialog::PreTranslateMessage(pMsg);
 }

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonEnumDevice()
{
    m_ctrlComboDeviceList.ResetContent();


    // TODO: �ڴ���ӿؼ�֪ͨ����������

    int nRet = MV_OK;
    CString cstrInfo;


    nRet = MV_SC_Discovery(&m_stDeviceInfoList);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("ö���豸ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return;
    }

    for (int i = 0; i < m_stDeviceInfoList.nDeviceNum; i++)
    {
        unsigned char nIp1 = m_stDeviceInfoList.astDeviceInfo[i].nDeviceIp & 0xff;
        unsigned char nIp2 = (m_stDeviceInfoList.astDeviceInfo[i].nDeviceIp & 0xff00) >> 8;
        unsigned char nIp3 = (m_stDeviceInfoList.astDeviceInfo[i].nDeviceIp & 0xff0000) >> 16;
        unsigned char nIp4 = (m_stDeviceInfoList.astDeviceInfo[i].nDeviceIp & 0xff000000) >> 24;


        cstrInfo.Format("Device[%d]Name[%s]Ip[%d.%d.%d.%d]", i, m_stDeviceInfoList.astDeviceInfo[i].chUserDefinedName, nIp4, nIp3, nIp2, nIp1);
        m_ctrlComboDeviceList.AddString(cstrInfo);
    }

    //������豸��Ĭ����ʾ��һ���豸
    if(0 != m_stDeviceInfoList.nDeviceNum)
    {
        m_ctrlComboDeviceList.SetCurSel(0);
        memcpy_s(&m_stDeviceInfo, sizeof(m_stDeviceInfo), &m_stDeviceInfoList.astDeviceInfo[m_ctrlComboDeviceList.GetCurSel()], sizeof(m_stDeviceInfoList.astDeviceInfo[m_ctrlComboDeviceList.GetCurSel()]));
    }
}

void CMvSmartCamCtrlDemoDlg::OnCbnSelchangeComboDeviceList()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    memcpy_s(&m_stDeviceInfo, sizeof(m_stDeviceInfo), &m_stDeviceInfoList.astDeviceInfo[m_ctrlComboDeviceList.GetCurSel()], sizeof(m_stDeviceInfoList.astDeviceInfo[m_ctrlComboDeviceList.GetCurSel()]));
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonOpenDevice()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    int nRet = MV_OK;
    CString cstrInfo;

    nRet = MV_SC_CreateHandle(&m_handle, &m_stDeviceInfo);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("�������ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    nRet = MV_SC_Connect(m_handle);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("�����ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    m_bConnect = true;

}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonCloseDevice()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    int nRet = MV_OK;
    CString cstrInfo;

    nRet = MV_SC_Disconnect(m_handle);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("�ر����ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    nRet = MV_SC_DestroyHandle(m_handle);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("���پ��ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    m_bStartJob = false;
    m_bConnect  = false;
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonStartGrabbing()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    int nRet = MV_OK;
    CString cstrInfo;
    nRet = MV_SC_StartJob(m_handle);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("����ȡ��ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
    _beginthreadex(0, 0, WorkThread, this, 0, 0);

    m_bStartJob = true;
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonStopGrabbing()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    int nRet = MV_OK;
    CString cstrInfo;
    nRet = MV_SC_StopJob(m_handle);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("ֹͣȡ��ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
    m_bStartJob = false;
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonParamGet()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    
    int nRet = MV_OK;
    CString cstrInfo;

    float fExposureTime = 0.0f;
    nRet = MV_SC_GetFloatValue(m_handle, "ExposureTime", &fExposureTime);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("��ȡ�ع�ʱ��ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
    float fGain= 0.0f;
    nRet = MV_SC_GetFloatValue(m_handle, "Gain", &fGain);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("��ȡ����ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
    float fFrameRate= 0.0f;
    nRet = MV_SC_GetFloatValue(m_handle, "AcquisitionFrameRate", &fFrameRate);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("��ȡ֡��ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    cstrInfo.Format("%f", fExposureTime);
    m_ctrlEditExposureTime.SetWindowText(cstrInfo);

    cstrInfo.Format("%f", fGain);
    m_ctrlEditGain.SetWindowText(cstrInfo);

    cstrInfo.Format("%f", fFrameRate);
    m_ctrlEditFrameRate.SetWindowText(cstrInfo);
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonParamSet()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������

    int nRet = MV_OK;
    CString cstrInfo;

    float fExposureTime = 0.0f;
    float fGain= 0.0f;
    float fFrameRate= 0.0f;

    m_ctrlEditExposureTime.GetWindowText(cstrInfo);
    fExposureTime = atof(cstrInfo);

    m_ctrlEditGain.GetWindowText(cstrInfo);
    fGain = atof(cstrInfo);

    m_ctrlEditFrameRate.GetWindowText(cstrInfo);
    fFrameRate = atof(cstrInfo);

    nRet = MV_SC_SetEnumerationValue(m_handle, "ExposureAuto", 0);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("�ر��Զ��ع�ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
    nRet = MV_SC_SetFloatValue(m_handle, "ExposureTime", fExposureTime);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("�����ع�ʱ��ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    nRet = MV_SC_SetFloatValue(m_handle, "Gain", fGain);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("��������ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    nRet = MV_SC_SetEnumerationValue(m_handle, "GainAuto", 0);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("�ر��Զ�����ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
    nRet = MV_SC_SetFloatValue(m_handle, "AcquisitionFrameRate", fFrameRate);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("����֡��ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedRadioTriggerOff()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    int nRet = MV_OK;
    CString cstrInfo;
    nRet = MV_SC_SetEnumerationValue(m_handle, "TriggerMode", 0);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("���������ɼ�ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedRadioTriggerOn()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    int nRet = MV_OK;
    CString cstrInfo;
    nRet = MV_SC_SetEnumerationValue(m_handle, "TriggerMode", 1);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("���ô���ģʽʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedCheckSoftware()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    int nRet = MV_OK;
    CString cstrInfo;
    if (m_ctrlCheckSoftware.GetCheck())
    {
        nRet = MV_SC_SetEnumerationValue(m_handle, "TriggerSource", 1);   //ѡ������
        if (MV_OK != nRet)
        {
            cstrInfo.Format("��������ʧ��!nRet = [%#x]", nRet);
            MessageBox(cstrInfo);
            return ;
        }
    }
    else
    {
        nRet = MV_SC_SetEnumerationValue(m_handle, "TriggerSource", 0);
        if (MV_OK != nRet)
        {
            cstrInfo.Format("����Line0ʧ��!nRet = [%#x]", nRet);
            MessageBox(cstrInfo);
            return ;
        }
    }
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonSoftwareOnce()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    int nRet = MV_OK;
    CString cstrInfo;

    nRet = MV_SC_CommandExecute(m_handle, "TriggerSoftware");
    if (MV_OK != nRet)
    {
        cstrInfo.Format("����һ��ʧ��!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
}


void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonSaveBmp()
{
    int nRet = MV_OK;
    CString cstrInfo;

    FILE* pFile = NULL;
    pFile = fopen("Image.raw","wb");
    if(NULL == pFile)
    {
        cstrInfo.Format("���ļ�ʧ��");
        MessageBox(cstrInfo);
        return ;
    }

    unsigned char* pFrameData = (unsigned char*)malloc(2592*2048);
    MV_SC_IMAGE_OUT_INFO stImageInfo;

    //��ȡһ��ͼ��
//     for (int i = 0; i < 100000; ++i)
//     {
//         memset(&stImageInfo,0,sizeof(MV_SC_IMAGE_OUT_INFO));
//         nRet = MV_SC_GetOneFrame(m_handle, pFrameData,2592*2048, &stImageInfo);
//         if(MV_OK == nRet)
//         {
//             fwrite(pFrameData,1,stImageInfo.nWidth * stImageInfo.nHeight,pFile);
//             cstrInfo.Format("����ɹ�");
//             MessageBox(cstrInfo);
//             break;
//         }
//     }
    fwrite(m_pData, 1, m_stImageOutInfo.nWidth * m_stImageOutInfo.nHeight, pFile);
    free(pFrameData);
    fclose(pFile);

    // TODO: Add your control notification handler code here
}

void CMvSmartCamCtrlDemoDlg::OnClose()
{
    // TODO: Add your message handler code here and/or call default
    if(m_handle)
    {
        MV_SC_Disconnect(m_handle);
        MV_SC_DestroyHandle(m_handle);
    }
    CDialog::OnClose();
}
