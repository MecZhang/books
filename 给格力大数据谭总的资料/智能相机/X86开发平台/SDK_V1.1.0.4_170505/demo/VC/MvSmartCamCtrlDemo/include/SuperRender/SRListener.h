/** @file    SRListener.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   ��ƽ̨��Ⱦ������ඨ���ͷ�ļ�
 *
 *  @author  ����Ӧ������� -- ������
 *  @date    2013/03/01
 *  @note    V1.0.0
 *
 *  @warning ��Ȩ����
 */
#ifndef __SR_LISTENER_H__
#define __SR_LISTENER_H__

// ������Ķ��壬����������չ
class CSRListener
{
public:

	CSRListener()
	{

	};

	~CSRListener()
	{

	};

	virtual int Draw()
	{
		return 1;
	};

};

#endif