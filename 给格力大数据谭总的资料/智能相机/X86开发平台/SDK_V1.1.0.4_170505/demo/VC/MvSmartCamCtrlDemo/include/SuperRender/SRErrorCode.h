/** @file    SRFormat.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   ��ƽ̨��Ⱦ������붨���ͷ�ļ�
 *
 *  @author  ����Ӧ������� -- ������
 *  @date    2013/03/01
 *  @note    V1.0.0
 *
 *  @warning ��Ȩ����
 */
#ifndef __SR_RENDER_ERROR_CODE_H__
#define __SR_RENDER_ERROR_CODE_H__


	// ������
	#define SR_RETURN_OK				1 // ���سɹ�
	#define SR_RETURN_FAIL				0 // ����ʧ��

	#define SR_ERR_ENGINE_NOT_SUPPORT		0x00000001	//	��֧�ֵ���Ⱦ����
	#define SR_ERR_PORT_INVALID				0x00000002	//	�Ƿ��Ķ˿ں�
	#define SR_ERR_PORT_USING				0x00000003	//	�˿ں��Ѿ���ռ��
	#define SR_ERR_PORT_UNKNOW				0x00000004	//	δ֪����
	#define SR_ERR_EFFECT_NOT_SUPPORT		0x00000005	//	��ȾЧ����֧��
	#define SR_ERR_HANDLE_NOT_INIT			0x00000006	//	��Ⱦ����û�д���
	#define SR_ERR_PF_ENGINE_NOT_INIT		0x00000007	//	���غ���Ⱦ���滹û��ָ��
	#define SR_ERR_PF_NOTSUPPORT			0x00000008	//	��֧�ֵ����ظ�ʽ
	#define SR_ERR_SRRECT_INVALID			0x00000009	//	�Ƿ��ľ��νṹ��

#endif



