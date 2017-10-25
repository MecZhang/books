/** @file    SuperRender.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   ��ƽ̨��Ⱦ��ӿڵ�ͷ�ļ�
 *
 *  @author  ����Ӧ������� -- ������
 *  @date    2014/05/14
 *  @note    V1.0.1
 *
 *  @warning ��Ȩ����
 */
#ifndef __SUPER_RENDER_H__
#define __SUPER_RENDER_H__

	#include "SuperRenderDefine.h"

	/**	@fn	     SR_CreateHandle
	 *	@brief	 ������ʾ���
	 *	@return	
		������ֵ����˵��
	 */ 
	SR_API void  *		 __stdcall	SR_CreateHandle();

	/**	@fn	     SR_Init
	 *	@brief	 ��ʼ��
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nPixelFormat  
	 *	@param n ���ظ�ʽ
	 *	@param c nEngineType  
	 *	@param n ��ʾ��������
	 *	@param c bThreadSafe  
	 *	@param n �Ƿ������̰߳�ȫ
	 *	@return	
		������ֵ����˵��
	 */ 
	SR_API unsigned int __stdcall	SR_Init(	void				* handle ,  
												SRPIXELFORMAT		nPixelFormat , 
												SREngine			nEngineType , 
												unsigned int		bThreadSafe);

	/**	@fn	     SR_UpdateFrameData
	 *	@brief	 �ϴ�ͼ������
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c pImageData  
	 *	@param n ͼ�������ڴ��׵�ַ
	 *	@param c nWidth  
	 *	@param n ͼ���
	 *	@param c nHeight  
	 *	@param n ͼ���
	 *	@param c pResverd  
	 *	@param n ����
	 *	@return	
		������ֵ����˵��
	 */ 
	SR_API unsigned int __stdcall	SR_UpdateFrameData(	void			* handle , 
														unsigned char	* pImageData , 
														unsigned int	nWidth , 
														unsigned int	nHeight , 
														void			*pResverd );

	/**	@fn	     SR_AddSubPort
	 *	@brief	 ����һ����ʾPort��
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nPort  
	 *	@param n ��Ӧ��port��
	 *	@param c nDisplayEffect  
	 *	@param n ��ʾЧ��
	 *	@return	
		������ֵ����˵��
	 */ 
	SR_API unsigned int __stdcall	SR_AddSubPort(	void			* handle , 
													unsigned int	nPort ,  
													SRDISPLAYEFFECT nDisplayEffect);

	/**	@fn	     SR_AddSubPortEx
	 *	@brief	 ����һ����ʾPort��
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nPort  
	 *	@param n ��Ӧ��port��
	 *	@param c nDisplayEffect  
	 *	@param n ��ʾЧ��
	 *	@param c nTextureFilterType  
	 *	@param n �������������
	 *	@return	
		������ֵ����˵��
	 */ 
	SR_API unsigned int __stdcall	SR_AddSubPortEx(void			   * handle , 
													unsigned int	    nPort ,  
													SRDISPLAYEFFECT     nDisplayEffect,
													SRTEXTUREFILTERTYPE nTextureFilterType);

	/**	@fn	     SR_DelSubPort
	 *	@brief	 ɾ��һ����ʾPort��
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nPort  
	 *	@param n ��Ӧ��port��
	 *	@return	
		������ֵ����˵��
	 */ 
	SR_API unsigned int __stdcall	SR_DelSubPort(	void * handle , unsigned int nPort);


	 /** @fn	  SR_RegisterDisplayWnd
	  *	 @brief	  ע����ʾ����
	  *	 @param c handle  
	  *	 @param n ��ʾ���
	  *	 @param c hWnd  
	  *	 @param n ��Ҫע��Ĵ��ھ��
	  *	 @return	
		 ������ֵ����˵��
	  */ 
	SR_API unsigned int __stdcall  SR_RegisterDisplayWnd(void * handle ,  void * hWnd);

	/**	@fn	     SR_Display
	 *	@brief	 ��ָ��Port�ŵ�ͼ��������ʾ��ָ���Ĵ�����
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nPort  
	 *	@param n ָ����Port��
	 *	@param c hWnd  
	 *	@param n ���ھ�� 
	 *	@return	
		������ֵ����˵��
	 */ 
	SR_API unsigned int __stdcall	SR_Display(		void			* handle ,
													unsigned int	nPort, 
													void			* hWnd );

	SR_API unsigned int __stdcall	SR_DisplaySurface(void			* handle,
		                                              unsigned int	nPort, 
		                                              void			* hWnd,
													  void          * pSurface);


	/**	@fn	     SR_SetDisplayRect
	 *	@brief	 ��ָ��Port�ŵ�ͼ��������ʾ��ָ���Ĵ��ڵ�ָ������ 
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nPort  
	 *	@param n ָ����Port��
	 *	@param c pDisplayRectSrc  
	 *	@param n ԭʼͼ��Ĵ���ʾ����
	 *	@param c pDisplayRectDst  
	 *	@param n Ŀ�괰�ڵ���ʾ����	 
	 *	@return	
		������ֵ����˵��
	 */
	SR_API unsigned int __stdcall  SR_SetDisplayRect(	void			* handle ,
														unsigned int	nPort , 
														SRRECTF			* pDisplayRectSrc , 
														SRRECTF			* pDisplayRectDst  );


	/**	@fn	     SR_GetCaptureData
	 *	@brief	 ���Դ�ץȡͼ��
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c pData  
	 *	@param n �Դ����ݵ��ڴ��ַ��IN and OUT��
	 *	@param c pDataSize  
	 *	@param n ��ȡ�����ݵĴ�С
	 *	@param c pWidth  
	 *	@param n ��ȡ���ݵĿ�
	 *	@param c pHeight  
	 *	@param n ��ȡ���ݵĸ�
	 *	@param c pBitCount  
	 *	@param n ���ص��ֽ���
	 *	@return	
		������ֵ����˵��
	 */ 
	SR_API unsigned int __stdcall  SR_GetCaptureData(	void			* handle ,
														unsigned int	nPort,
														unsigned char	* pData , 
														unsigned int	* pDataSize , 
														unsigned int	* pWidth , 
														unsigned int	* pHeight , 
														unsigned int	* pBitCount );

	/**	@fn	     SR_SetTransform
	 *	@brief	 ����ͼ�����ת�;���Ч����Ӧ���ڵ�ǰ��ʾ����������������Ӷ˿ڵ�ͼ����ʾ
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nType  
	 *	@param n ��ʾ�任����
	 *	@return	
		������ֵ����˵��;
	 */
	SR_API unsigned int __stdcall  SR_Rotate(	void			* handle , 
												unsigned int	nPort ,
												SRTRANSFERPARAM *pstRotateParam);


	/**	@fn	     SR_SetCallBack
	 *	@brief	 ����ָ��Port����ʾʱ�����ʾ�ص�
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nPort  
	 *	@param n ָ����Port��
	 *	@param c nCBType  
	 *	@param n ��ʾ�ص�����
	 *	@param c cbFunc  
	 *	@param n ��ʾ�ص�����
	 *	@param c pUser  
	 *	@param n �û�����
	 *	@return	
		������ֵ����˵��
	 */
	SR_API unsigned int __stdcall  SR_SetCallBack(	void			* handle , 
													unsigned int	nPort, 
													unsigned int	nCBType , 
													SR_CallBack		cbFunc , 
													void			* pUser);


	/**	@fn	     SR_SetUpdateCallBack
	 *	@brief	 ����ָ��Port����ʾʱ�����ʾ�ص�
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c cbFunc  
	 *	@param n ��ʾ�ص�����
	 *	@param c pUser  
	 *	@param n �û�����
	 *	@return	
		������ֵ����˵��
	 */
	SR_API unsigned int __stdcall  SR_SetUpdateCallBack(void			   * handle , 
													     SR_UpdateCallBack	cbFunc , 
													     void			   * pUser);

	/**	@fn	     SR_RegisterListener
	 *	@brief	 ע��ָ��port�ŵļ�����
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nPort  
	 *	@param n ָ����Port��
	 *	@param c nCBType  
	 *	@param n ��ʾ�ص�����
	 *	@param c cbFunc  
	 *	@param n ��ʾ�ص�����
	 *	@param c pUser  
	 *	@param n �û�����
	 *	@return	
		������ֵ����˵��
	 */
	SR_API unsigned int __stdcall  SR_RegisterListener(		void			* handle , 
															unsigned int	nPort,  
															CSRListener		* pListener );

	/**	@fn	     SR_DestroyHandle
	 *	@brief	 �ͷ���ʾ���
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@return	
		������ֵ����˵��
	 */
	 SR_API unsigned int __stdcall	SR_DestroyHandle(	void * handle);


	/**	@fn	     SR_SetVerticalSyncPeriod
	 *	@brief	 �Ƿ�򿪴�ֱͬ������
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nPort  
	 *	@param n �Ӷ˿ں�
	 *	@param c nPeriod  
	 *	@param n ����Ϊ1�򿪴�ֱͬ��������Ϊ0�رմ�ֱͬ��
	 *	@return	
		������ֵ����˵��
	 */
	SR_API unsigned int __stdcall	SR_SetVerticalSyncPeriod(	void			* handle , 
																unsigned int	nPort , 
																unsigned int	nPeriod);
	
	// �ص���ͼ����

	/**	@fn	     SR_DrawLines
	*	@brief	 �ص��л��ߺ���
	*	@param c handle  
	*	@param n ��ʾ���
	*	@param c pPoints  
	*	@param n ����������
	*	@param c nPointNum  
	*	@param n ����������
	*	@param c bLoop  
	*	@param n �Ƿ�պ�
	*	@param c pColor  
	*	@param n ��������ɫ
	*	@param c nLineWidth  
	*	@param n �����Ŀ��
	*	@return	
		������ֵ����˵��
	*/
	SR_API unsigned int __stdcall	SR_DrawLines(void * handle , SRPOINTF ** pPoints , unsigned int nPointNum , 
		unsigned int bLoop , SRCOLOR * pColor , unsigned int nLineWidth);

	/**	@fn	     SR_DrawCircle������䣩
	*	@param c handle  
	*	@param n ��ʾ���
	*	@brief	 ��ͼ�ص��л���Բ
	*	@param c pCenter   (���һ��)
	*	@param n Բ������
	*	@param c nR1       (���һ��)
	*	@param n X����뾶
	*	@param c nR2       (���һ��)
	*	@param n Y����뾶
	*	@param c pColor    (���һ��)
	*	@param n ������ɫ
	*	@param c nLineWidth  
	*	@param n �����Ŀ��
	*	@return	
	������ֵ����˵��
	*/ 
	SR_API unsigned int __stdcall	SR_DrawCircle(  void * handle , 
													SRPOINTF * pCenter , 
													float fR1 , 
													float fR2 , 
													SRCOLOR * pColor,
													unsigned int nLineWidth);

    /**	@fn	     SR_DrawCircleEx
	*	@param c handle  
	*	@param n ��ʾ���
	*	@brief	 ��ͼ�ص��л������Բ
	*	@param c pCenter   (���һ��)
	*	@param n Բ������
	*	@param c nR1       (���һ��)
	*	@param n X����뾶
	*	@param c nR2       (���һ��)
	*	@param n Y����뾶
    *	@param c bFill     
    *	@param n �Ƿ���䣨0��ʾ����䣬1��ʾ��䣩
	*	@param c pColor    (���һ��)
	*	@param n ������ɫ
	*	@param c nLineWidth  
	*	@param n �����Ŀ��
	*	@return	
	������ֵ����˵��
	*/ 
	SR_API unsigned int __stdcall	SR_DrawCircleEx(void * handle , 
													SRPOINTF * pCenter , 
													float fR1 , 
													float fR2 , 
                                                    unsigned int bFill,
													SRCOLOR * pColor,
													unsigned int nLineWidth);

	/**	@fn	     SR_DrawColorRibbon
	*	@brief	 �ص��л���ɫ��
	*	@param c handle  
	*	@param n ��ʾ���
	*	@param c pRect  
	*	@param n ���νṹ��
	*	@return	
	    ������ֵ����˵��
	*/
	SR_API unsigned int __stdcall	SR_DrawColorRibbon(void * handle,SRRECTF * pRect);
	/**	@fn	     SR_DrawRect
	 *	@brief	 �ص��о��κ���
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c pRect  
	 *	@param n ���νṹ��
	 *	@param c pColor  
	 *	@param n ��������ɫ
	 *	@param c nLineWidth  
	 *	@param n �����Ŀ��
	 *	@return	
		������ֵ����˵��
	 */
	SR_API unsigned int __stdcall	SR_DrawRect(void * handle,SRRECTF * pRect,
		SRCOLOR * pColor,unsigned int nLineWidth);

	/**	@fn	     DrawPolygon
	 *	@brief	 ��ͼ�ص��л��ƶ���μ�����
	 *	@param c pPoints  
 	 *	@param n �����б�
	 *	@param c nPointNum  
	 *	@param n ��������
	 *	@param c bFill  
	 *	@param n �Ƿ����
	 *	@param c pColor  
	 *	@param n ��ɫ
	 *	@param c nLineWidth  
	 *	@param n �����Ŀ��
	 *	@return	
		������ֵ����˵��
	 */ 
    SR_API unsigned int __stdcall SR_DrawPolygon(void * handle,
		SRPOINTF ** pPoints,
		unsigned int nPointNum,
		unsigned int bFill,
		SRCOLOR * pColor,
		unsigned int nLineWidth);
	
	/**	@fn	     SR_DrawFont
	 *	@brief	 ��ͼ�ص���д��
	 *	@param c pRect  
	 *	@param n ���ڴ����е�λ��
	 *	@param c pString  
	 *	@param n ָ�������ݵ�ָ��
	 *	@param c nWidth  
	 *	@param n �ֵĿ�
	 *	@param c nHeight  
	 *	@param n �ָ�
	 *	@param c pColor  
	 *	@param n ����ɫ
	 *	@param c Format  
	 *	@param n ����pRect��ָ�����е�λ�ã�Ϊ0ʱ�������Ͻǣ�Ϊ1�������Ͻ�
	 *	@return	
	    ������ֵ����˵��
	 */ 
	SR_API unsigned int __stdcall	SR_DrawFont(void * handle ,
											    SRRECTF * pRect,
											    wchar_t * pString,
											    unsigned int nWidth,
											    unsigned int nHeight, 
											    SRCOLOR * pColor , 
											    unsigned long Format); 
	/**	@fn	     SR_GetCapability
	 *	@brief	 ��ȡ��ʾ������
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c pCapability  
	 *	@param n �������ṹ��
	 *	@return	
		������ֵ����˵��
	 */
	SR_API unsigned int __stdcall SR_GetCapability(	void * handle ,
													SRCAPABILITY	* pCapability);

	/**	@fn	     SR_SetConfig
	 *	@brief	 ����������Ϣ
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nCfgType  
	 *	@param n ��������
	 *	@param c pValue  
	 *	@param n ��������
	 *	@return	
		������ֵ����˵��
	 */
	SR_API unsigned int __stdcall  SR_SetConfig(void * handle, int nCfgType, void *pValue, BOOL bShow = FALSE);

	
	/**	@fn	     SR_GetPonitColor
	 *	@brief	 ���ݵ������ȡ��ɫ��Ϣ
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nPointX  
	 *	@param n ���X������
	 *	@param c nPointY  
	 *	@param n ���Y������
	 *	@param c pPointColor  
	 *	@param n ָ�����ɫ��Ϣ�Ľṹ���ָ��
	 *	@return	
		������ֵ����˵��
	 */
	SR_API unsigned int __stdcall  SR_GetPonitColor(void * handle, unsigned int nPointX, unsigned int nPointY,SR_COLOR * pPointColor);

	/**	@fn	     SR_GetSDKVersion
	 *	@brief	 ��ȡ�汾����Ϣ
	 *	@param c pVersionInfo  
	 *	@param n �汾�Ŷ�Ӧ���ڴ��ַ
	 *	@return	
		������ֵ����˵��
	 */
	SR_API unsigned int __stdcall  SR_GetSDKVersion(	char ** pVersionInfo);

	/**	@fn	     SR_GetLastError
	 *	@brief	 ��ȡ���һ�δ���
	 *	@param c handle  
	 *	@param n ��ʾ���
	 *	@param c nPort  
	 *	@param n ��Ӧ��Port��
	 *	@param c nError  
	 *	@param n ������
	 *	@return	
		������ֵ����˵��
		*/
	SR_API unsigned int __stdcall  SR_GetLastError(	void * handle  , unsigned int nPort , unsigned int * nError);

	/**	@fn	     SR_SetBackgroundColor
	*	@brief	 ���ô��ڱ�����ɫ
	*	@param c handle  
	*	@param n ��ʾ���
	*	@param c hWnd  
	*	@param n ���ھ��
	*	@param c pColor  (���һ��,ȡֵ��Χ[0.0f,1.0f]��NULL��ʾ��ɫ)
	*	@param n ָ�򱳾���ɫ�Ľṹ���ָ��
	*	@return	
	������ֵ����˵��
	*/
	SR_API unsigned int __stdcall  SR_SetBackgroundColor(void * handle,void * hWnd,SRCOLOR* pColor);

    /**	@fn	     SR_SetVerticalFlip
    *	@brief	 ����ͼ�����·�ת
    *	@param c handle  
    *	@param n ��ʾ���
    *	@param c bFlag(trueΪ��ת��falseΪ����ת)
    *	@param n �Ƿ����·�ת
    *	@return	
    ������ֵ����˵��
    */
    SR_API unsigned int __stdcall  SR_SetVerticalFlip(void * handle,bool bFlag);

    /**	@fn	     SR_SetRingShow
    *	@brief	 ����Բ����ʾ
    *	@param c handle  
    *	@param n ��ʾ���
    *	@param c nPort
	*	@param n ��Ӧ��port��
    *	@param c pCenter   (���һ��)
    *	@param n Բ������
    *	@param c fOutsideR1 (���һ��,ȡֵ��Χ[0.0f,0.5f])
    *	@param n ��Բ����X��뾶;
    *	@param c fOutsideR2 (���һ��,ȡֵ��Χ[0.0f,0.5f])
    *	@param n ��Բ����Y��뾶;
    *	@param c fInsideR1  (���һ��,ȡֵ��Χ[0.0f,0.5f])
    *	@param n ��Բ����X��뾶;
    *	@param c fInsideR2  (���һ��,ȡֵ��Χ[0.0f,0.5f])
    *	@param n ��Բ����Y��뾶;
    *	@param c pColor     (���һ��)
    *	@param n ������ɫ
    *	@return	
    ������ֵ����˵��
    */
    SR_API unsigned int __stdcall  SR_SetRingShow(void * handle,
                                                  unsigned int nPort,
                                                  SRPOINTF* pCenter , 
                                                  float fOutsideR1 , 
                                                  float fOutsideR2 , 
                                                  float fInsideR1 , 
                                                  float fInsideR2 ,
                                                  SRCOLOR * pColor);


#endif

	 