/** @file    SRStruct.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   ��ƽ̨��Ⱦ��ṹ����ض����ͷ�ļ�
 *
 *  @author  ����Ӧ������� -- ������
 *  @date    2013/03/01
 *  @note    V1.0.0
 *
 *  @warning ��Ȩ����
 */
#ifndef __SR_STRUCT_H__
#define __SR_STRUCT_H__

// ��������֧�ֵ���ʾ�˿�����
#define SR_MAX_WND 32
#define SR_DEFAULT_FRAME_SIZE 128

// ��ʾ����ö��
typedef enum tagSRRenderEngine
{
	SR_ENGINE_DEFAULT	= 0x0,			// ��ָ����ʾ����
	SR_ENGINE_D3D		= 0x1,			// D3D��ʾ����
	SR_ENGINE_DDRAW		= 0x2,			// DDraw��ʾ����
	SR_ENGINE_OPENGL	= 0x4,			// OpenGL��ʾ����
	SR_ENGINE_OPENGLES  = 0x8,			// OpenGL ES��ʾ����
}SREngine;

// ���νṹ��
typedef struct tagSRRectF
{
	float fTop;		// [0.0 , 1.0]
	float fBottom;	// [0.0 , 1.0]
	float fLeft;	// [0.0 , 1.0]
	float fRight;	// [0.0 , 1.0]
}SRRECTF;


// ��ṹ��
typedef struct tagSRPointF
{
	float fX;
	float fY;
}SRPOINTF;

// ɫ�ʽṹ��
typedef struct tagSRColor
{
	float fR;		// [0.0 , 1.0]
	float fG;		// [0.0 , 1.0]
	float fB;		// [0.0 , 1.0]
	float fAlpha;	// [0.0 , 1.0]
}SRCOLOR;

// ��ɫ�ṹ��
typedef struct SR_COLOR
{
	float   R;		// [0.0 , 255.0]
	float   G;		// [0.0 , 255.0]
	float   B;		// [0.0 , 255.0]
	float   Y;		// [0.0 , 255.0]
	float   U;		// [0.0 , 255.0]
	float   V;		// [0.0 , 255.0]
}SR_COLOR;

#define SR_UPDATE_FLAG 0x1f

#define SR_CAPS_DRIVQUALITY  0x1

#define CFG_DISPLAYSURFACE     0x400
#define CFG_DISPLAYRESET       0x401
#define CFG_DISPLAY_START_LINE 0x410
#define CFG_SHOW_COLOR_RIBBON  0x420      // ��ʾ��ɫ����־

// �������ṹ��
typedef struct tagSRCapability
{
	unsigned int nCapType;				// ��Ҫ��ѯ�����������ͣ����룩
	unsigned int nEngineCap;			// ���ص��������������������Ҫ��ѯ��ǰ���������������ʱ����Ҫָ��һ�����棨���룩
	unsigned int nPixelFormatCap;		// ���ظ�ʽ�������� ����ָ������

	unsigned int nMaxRenderWidth;		// ������ʾ��� ����ָ������
	unsigned int nMaxRenderHeight;		// ������ʾ�߶� ����ָ������
	unsigned int nMaxPort;				// ���֧�ֵĶ˿���

	unsigned int nDrivQuality;          // ��������

}SRCAPABILITY;


// ��ͼ�ص�������
#define		SR_CALLBACK_NULL		0   // ��ʼ��ֵ
#define		SR_CALLBACK_DRAWLINE	1   // ����ֱ��  ��Ӧ�ں���
#define		SR_CALLBACK_DRAWRECT	2	// ���ƾ���  ��Ӧ�ں���
#define		SR_CALLBACK_DRAWCIRCLE	4	// ����Բ��  ��Ӧ�ں���
#define		SR_CALLBACK_DRAWPIXELS	8	// ��������  ��Ӧ�ں���
#define		SR_CALLBACK_DRAWTEXT	16	// ��������  ��Ӧ�ں���

// ��ת��Ԫ�ṹ��
typedef struct tagSRTransformElement
{
	bool  bAxisX;
	bool  bAxisY;
	bool  bAxisZ;
	float fValue;	// ��ת�ĽǶ�
	
}SRTRANSFERELEMENT;

// ��ת��ϲ���
typedef struct tagSRTransformParam
{
	SRTRANSFERELEMENT * pTransformElement;		// ��ת��������
	unsigned int		nTransformCount;		// ��ת����ϴ���
}SRTRANSFERPARAM;

typedef enum tagSRTextureFilterType
{
	SR_TEXF_NONE            = 0,    // filtering disabled (valid for mip filter only)
	SR_TEXF_POINT           = 1,    // nearest
	SR_TEXF_LINEAR          = 2,    // linear interpolation
	SR_TEXF_ANISOTROPIC     = 3,    // anisotropic
	SR_TEXF_PYRAMIDALQUAD   = 6,    // 4-sample tent
	SR_TEXF_GAUSSIANQUAD    = 7,    // 4-sample gaussian

}SRTEXTUREFILTERTYPE;

/**	@fn	     SR_CallBack
 *	@brief	 ��ͼ�ص�����
 *	@param c pUser  
 *	@param n �û�����
 *	@param c nPort  
 *	@param n ��Ӧ�Ķ˿�
 *	@param c nCBType  
 *	@param n ��ͼ�ص�����
 *	@param c hDC  
 *	@param n ����DC
 *	@param c nWidth  
 *	@param n ��ͼ����Ŀ�
 *	@param c nHeight  
 *	@param n ��ͼ����ĸ�
 *	@return	
	������ֵ����˵��
 */ 
typedef void (__stdcall * SR_CallBack )( void* pUser  , unsigned int  nPort , unsigned int nCBType , void * hDC ,   unsigned int nWidth , unsigned int nHeight); 


/**	@fn	     SR_CallBack
 *	@brief	 ��ͼ�ص�����
 *	@param c pUser  
 *	@param n �û�����
 *	@param c nPort  
 *	@param n ��Ӧ�Ķ˿�
 *	@param c nCBType  
 *	@param n ��ͼ�ص�����
 *	@param c hDC  
 *	@param n ����DC
 *	@param c nWidth  
 *	@param n ��ͼ����Ŀ�
 *	@param c nHeight  
 *	@param n ��ͼ����ĸ�
 *	@return	
	������ֵ����˵��
 */ 
typedef void (__stdcall * SR_UpdateCallBack )( void* pUser, void * pData); 
// ��Port��Ӧ�Ľṹ��
typedef struct tagRenderParam
{
	
	SR_CallBack		    cbFunc;						// ��Ӧ�Ļ�ͼ�ص�����
	
	void *			    pcbUser;					// �ص��������û�����
	
	unsigned int	    nCBType;					// �ص�����������
	
	SRRECTF *		    pRectSrc;					// ԭʼͼ�����ʾ����
	
	SRRECTF *		    pRectDst;					// Ŀ�괰�ڵ���ʾ����
	
	SRDISPLAYEFFECT	    nDisplayEffect;				// ��ʾЧ��
	
	void		*	    pShader;					// ��ʾЧ����Ӧ��shdaer

	void *			    hWnd;						// ��¼��һ����Ⱦ��hWnd

	SRTRANSFERPARAM*    pRotation;                  // ��ת��ϲ���

	SRTEXTUREFILTERTYPE	nTextureFilterType;		    // �������������

    float               fOutR1;                     // Բ����ʾ����Բ��X��뾶

    float               fOutR2;                     // Բ����ʾ����Բ��Y��뾶

    float               fInR1;                      // Բ����ʾ����Բ��X��뾶

    float               fInR2;                      // Բ����ʾ����Բ��Y��뾶

    SRCOLOR             stColor;                    // Բ����ʾʱԲ�������ɫ

    SRPOINTF            stCenter;                   // Բ����ʾʱԲ����Բ��
	
}RENDERPARAM;

#endif
