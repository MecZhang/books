/** @file    SRFormat.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   ��ƽ̨��Ⱦ�����ظ�ʽ��ض����ͷ�ļ�
 *
 *  @author  ����Ӧ������� -- ������
 *  @date    2013/03/01
 *  @note    V1.0.0
 *
 *  @warning ��Ȩ����
 */
#ifndef __SR_FORMAT_H__
#define __SR_FORMAT_H__

// ���ظ�ʽö��
typedef enum tagSRPixelFormat
{
		SR_PF_NULL			  = 0x0,		// �û��Զ���ShaderData,
		SR_PF_YV12			  = 0x1,		// YV12
		SR_PF_NV12			  = 0x2,		// NV12
		SR_PF_I420		  	  = 0x4,		// 
		SR_PF_UYVY			  = 0x8,
		SR_PF_YV16			  = 0x10,
		SR_PF_RGB565		  = 0x20,
		SR_PF_RGB555		  = 0x40,
		SR_PF_NV16			  = 0x80,
		SR_PF_IYUV			  = 0x100,
		SR_PF_IYU2		   	  = 0x200,
		SR_PF_IUYV			  = 0x400,
		SR_PF_YUY2			  = 0x800,
		SR_PF_RGBA32		  = 0x1000,
		SR_PF_RGB24			  = 0x2000,      // RGB
		SR_PF_BGR24			  = 0x2002,      // BGR
		SR_PF_R8G8_B8G8		  = 0x4000,
		SR_PF_G8R8_G8B8		  = 0x8000,
		SR_PF_YUV9			  = 0x10000,
		SR_PF_YVYU		      = 0x20000,
        SR_PF_YUYV            = 0x22000,

		SR_PF_RGB8_PLANAR     = 0x86008, //RGB8 Planar
		SR_PF_RGB8_PACKED     = 0x86010, //RGB8 Packed
		SR_PF_Y16             = 0x86020, //Y16
		SR_PF_PSEUDO_COLOR    = 0x86022, //α��ɫ��ʾ
		SR_PF_POINT_CLOUD     = 0x86024, //Y16������ʾ
		
		SR_PF_BAYEGR16        = 0x80000, //BayerGR16 
		SR_PF_BAYEGR12        = 0x80002, //BayerGR12
		SR_PF_BAYEGR8         = 0x80004, //BayerGR8
        SR_PF_BAYEGR10        = 0x80006, //BayerGR10
		SR_PF_BAYEGR10_PACKED = 0x80008, //BayerGR10_Packed 
        SR_PF_BAYEGR12_PACKED = 0x80010, //BayerGR12_Packed 

		SR_PF_BAYEGB8         = 0x81000, //BayerGB8
		SR_PF_BAYEGB12        = 0x81002, //BayerGB12
		SR_PF_BAYEGB12_PACKED = 0x81004, //BayerGB12_Packed 
		SR_PF_BAYEGB10        = 0x81006, //BayerGB10
		SR_PF_BAYEGB10_PACKED = 0x81008, //BayerGB10_Packed 

        SR_PF_BAYEBG8         = 0x82000, //BayerBG8
		SR_PF_BAYEBG12        = 0x82002, //BayerBG12
		SR_PF_BAYEBG12_PACKED = 0x82004, //BayerBG12_Packed
		SR_PF_BAYEBG10        = 0x82006, //BayerBG10
		SR_PF_BAYEBG10_PACKED = 0x82008, //BayerBG10_Packed 

		SR_PF_BAYERG8         = 0x83000, //BayerRG8
		SR_PF_BAYERG12        = 0x83002, //BayerRG12
		SR_PF_BAYERG12_PACKED = 0x83004, //BayerRG12_Packed
		SR_PF_BAYERG10        = 0x83006, //BayerRG10
		SR_PF_BAYERG10_PACKED = 0x83008, //BayerRG10_Packed 

		SR_PF_MONO8           = 0x40000,
		SR_PF_MONO10          = 0x40002,
		SR_PF_MONO12          = 0x40004,
		SR_PF_MONO10_PACKED   = 0x40006,
		SR_PF_MONO12_PACKED   = 0x40008,


}SRPIXELFORMAT;

// ��ʾЧ��ö��
typedef enum tagSRDisplayEffect
{
	SR_ET_NULL,
		
		SR_ET_FISH_PTZ_CEILING ,			// Ӧ���ڶ�װ����
		
		SR_ET_FISH_PTZ_FLOOR ,				// Ӧ���ڵ��氲װ����
		
		SR_ET_FISH_PTZ_WALL ,				// Ӧ���ڱ�װ����
		
		SR_ET_FISH_PANORAMA_CEILING1,		// Ӧ���ڶ�װ���� 1P
		SR_ET_FISH_PANORAMA_CEILING2,		// Ӧ���ڶ�װ���� 2P
		
		SR_ET_FISH_PANORAMA_FLOOR1,			// Ӧ���ڵ��氲װ���� 1P
		SR_ET_FISH_PANORAMA_FLOOR2,			// Ӧ���ڵ��氲װ���� 2P
		
		SR_ET_FISH_PANORAMA_WALL,			// Ӧ���ڱ�װ���� 1P
		
		SR_ET_REDBLUE_3D,                   // ����3DЧ��
		
}SRDISPLAYEFFECT;


// ץͼ����ö��
typedef enum tagSRCaptureFormat
{
		SR_CP_JPEG,
		SR_CP_BMP,
		
	}SRCPATUREFORMAT;
#endif