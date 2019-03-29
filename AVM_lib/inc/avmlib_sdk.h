/*******************************************************************************
* File Name          : avmlib_sdk.h
* Author             : Jerry
* Revision           : 2.1
* Date               : 15/07/2016
* Description        : Library Interface 
*******************************************************************************/


#ifndef __AVMLIB_SDK_H__
#define __AVMLIB_SDK_H__

#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#include "EGL/egl.h"
#include "EGL/eglext.h"

/*
********************************************************************************
*                               STANDARD DEFINES
********************************************************************************
*/

#define  AVM_NULL                             NULL

/* ----------------- BOOLEAN DEFINES ------------------ */
#define  AVM_FALSE                            0u
#define  AVM_TRUE                             1u

#define  AVM_NO                               0u
#define  AVM_YES                              1u

#define  AVM_DISABLED                         0u
#define  AVM_ENABLED                          1u

#define  AVM_INACTIVE                         0u
#define  AVM_ACTIVE                           1u

#define  AVM_INVALID                          0u
#define  AVM_VALID                            1u

#define  AVM_OFF                              0u
#define  AVM_ON                               1u

#define  AVM_CLR                              0u
#define  AVM_SET                              1u

#define  AVM_FAIL                             0u
#define  AVM_OK                               1u

/*
********************************************************************************
********************************************************************************
*                            D A T A   T Y P E S
********************************************************************************
********************************************************************************
*/
typedef            char        C8;     /*  8-bit character          */
typedef    signed  char        S8;     /*  8-bit unsigned character */
typedef  unsigned  char        U8;     /*  8-bit unsigned integer   */
typedef  unsigned  short       U16;    /* 16-bit unsigned integer   */
typedef    signed  short       S16;    /* 16-bit   signed integer   */
typedef  unsigned  int         U32;    /* 32-bit unsigned integer   */
typedef    signed  int         S32;    /* 32-bit   signed integer   */
typedef  unsigned  long  long  U64;    /* 64-bit unsigned integer   */
typedef    signed  long  long  S64;    /* 64-bit   signed integer   */
typedef            float       F32;    /* 32-bit floating point     */
typedef            double      F64;    /* 64-bit floating point     */


#define  AVM_EXT  extern

typedef enum
{
    CAM_FRONT = 0, /* ǰ����ͷ */
    CAM_RIGHT,     /* ������ͷ */
    CAM_BACK,      /* ������ͷ */
    CAM_LEFT,      /* ������ͷ */
    CAM_MAX
} camrea_chan_t;
/*
************************************************************************************************************************
************************************************************************************************************************
*                                                E N U M E R A T I O N S
************************************************************************************************************************
************************************************************************************************************************
*/

/*
------------------------------------------------------------------------------------------------------------------------
*                                                      ERROR CODES
------------------------------------------------------------------------------------------------------------------------
*/
typedef  enum  AVM_err {
    AVM_ERR_NONE                      = 1000u,//�����ɹ�
	AVM_ERR_FALSE					  ,
    AVM_ERR_ENCRYPT                   ,       //AVM���ܴ���
    AVM_ERR_MEM_CREATE                ,       //�ڴ��������
    AVM_ERR_SYS                       ,       //ϵͳ����(eg.pthread_create)
    AVM_ERR_GL                        ,       //openGL��������
    AVM_ERR_SAVE_READ                 ,       //LUT��д����

    AVM_ERR_2D_SHADER                 = 10000u,  //shader ����ʧ��
    AVM_ERR_2D_INACTIVE               ,          //δ���г�ʼ��
    AVM_ERR_2D_MODE_INVALID           ,          //��Чģʽ
    AVM_ERR_2D_LUT_INVALID            ,          //LUT��ȡʧ��
    AVM_ERR_2D_PARAMETER_INVALID      ,          //������Ч
    AVM_ERR_2D_REINIT                 ,          //AVM�ظ���ʼ��
    AVM_ERR_2D_SHADER_GET_UNIFORM     ,          //shader ������ȡʧ��ʧ��
    AVM_ERR_2D_SHADER_GET_ATTRIB      ,          //shader ������ȡʧ��ʧ��

    AVM_ERR_3D_SHADER                 = 11000u,  //shader ����ʧ��
    AVM_ERR_3D_INACTIVE               ,          //δ���г�ʼ��
    AVM_ERR_3D_MODE_INVALID           ,          //��Чģʽ
    AVM_ERR_3D_LUT_INVALID            ,          //LUT��ȡʧ��
    AVM_ERR_3D_PARAMETER_INVALID      ,          //������Ч
    AVM_ERR_3D_REINIT                 ,          //AVM�ظ���ʼ��
    AVM_ERR_3D_SHADER_GET_UNIFORM     ,          //shader ������ȡʧ��ʧ��
    AVM_ERR_3D_SHADER_GET_ATTRIB      ,          //shader ������ȡʧ��ʧ��


} AVM_ERR;

AVM_ERR avmlib_Init(GLuint cam_width, GLuint cam_heigh, GLuint screen_width, GLuint screen_heigh, U8 islog);
AVM_ERR avmlib_Set_Stub_Textures(void (*avm_User_Stub_Textures)(GLint TexturesID, GLint *OutTexturesID));


#endif




