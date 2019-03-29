/*******************************************************************************
* File Name          : avmlib_gpu_drawline.h
* Author             : Jerry
* Revision           : 2.1
* Date               : 15/07/2016
* Description        : Library Interface 
*******************************************************************************/

#ifndef __GPU_DRAWLINE_H__
#define __GPU_DRAWLINE_H__

#include <stdio.h>
#if !defined(EGL_EGLEXT_PROTOTYPES)
#define EGL_EGLEXT_PROTOTYPES
#endif

#if !defined(GL_GLEXT_PROTOTYPES)
#define GL_GLEXT_PROTOTYPES
#endif
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include "avmlib_sdk.h"
#include "avmlib_vectors.h"
#include "avmlib_matrices.h"

/*
*************************************************************************
*************************************************************************
*                      D A T A   S T R U C T U R E S
*************************************************************************
*************************************************************************
*/

typedef struct draw_line_ //�߶�
{
    F32 sx;//���x
    F32 sy;//���y
    F32 ex;//�յ�x
    F32 ey;//�յ�y
    GLboolean r;//red(0~255)
    GLboolean g;//green(0~255)
    GLboolean b;//blue(0~255)
    GLboolean a;//alpha(����δ��)
} draw_line_t;

typedef struct point_t_ //�߶ε�����
{
    F64 x;
    F64 y;
    U8 blend;
} point_t;

typedef struct color_t_ //�߶���ɫ
{
    U8 red;
    U8 green;
    U8 blue;
} color_t;

typedef struct line_attr_ //�߶�����
{
    U32 line_w;      // �߶ο��(��λ����)
    U32 win_x;       // ���ߴ���x
    U32 win_y;       // ���ߴ���y
    U32 win_width;   // ���ߴ��ڿ��
    U32 win_height;  // ���ߴ��ڸ߶�
    U8 Blend;        // �߶�alpha(0~255��0:��ʹ��blending)
} line_attr_t;

typedef struct line_strip_attr_ //�߶�����
{
    U32 line_w;     // �߶ο��(��λ����)
    U32 win_x;      // ���ߴ���x
    U32 win_y;      // ���ߴ���y
    U32 win_width;  // ���ߴ��ڿ��
    U32 win_height; // ���ߴ��ڸ߶�
    U8 Blend;       // �߶�alpha(0~255��0:��ʹ��blending)
    U8 IsStrip;     // 1: glDrawArrays(GL_LINE_STRIP,.. 0: glDrawArrays(GL_LINES,..
    F32 scalex;     //����X����ϵ��
    F32 scaley;     //����Y����ϵ��
    color_t linecolor;
} line_strip_attr_t;

/*
*************************************************************************
*************************************************************************
*                      F U N C T I O N
*************************************************************************
*************************************************************************
*/

/*******************************************************************************************
* Function Name  : avmlib_Draw_Lines.
*
* Description    : ����
*
* Arguments      : lines_buffer      ��Ҫ�����߶�ָ��
*                  -----
*
*                  line_num          �߶���
*                  -----
*
*                  line_attr          �߶�����
*
*                  up                 �ӵ�������
*                  -----
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        : һ����໭50����
*******************************************************************************************/
AVM_EXT AVM_ERR avmlib_Draw_Lines(const draw_line_t *const lines_buffer,U32 line_num,const line_attr_t *const line_attr,Vector3 *up);

/*******************************************************************************************
* Function Name  : avmlib_Draw_Lines_Strip.
*
* Description    : �������߲μ�GL_LINE_STRIP
*
* Arguments      : points_buffer      ��Ҫ�����߶��ϵĵ�����ָ��
*                  -----
*
*                  point_num          ����
*                  -----
*
*                  line_attr          �߶�����
*                  -----
*
*                  up                 �ӵ�������
*                  -----
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        : һ����໭50����(100����)
*******************************************************************************************/
AVM_EXT AVM_ERR avmlib_Draw_Lines_Strip(const point_t *const points_buffer, U32 point_num, const line_strip_attr_t *const line_attr, Vector3 *up, GLfloat *ModelView, GLfloat *Proj);

/*******************************************************************************************
* Function Name  : avmlib_Drawline_Init.
*
* Description    : ���߳�ʼ��
*
* Arguments      : programName    ������ɫ������
*                  -----
*
*                  programName1   Ƭ����ɫ������
*                  -----
*
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        : �ڻ���֮ǰ��Ҫ����һ�γ�ʼ��.
******************************************************************************************/
AVM_EXT AVM_ERR avmlib_Drawline_Init(const C8 *programName, const C8 *programName1);

/*******************************************************************************************
* Function Name  : avmlib_DrawLine_Exit.
*
* Description    : �����˳�
*
* Arguments      : none
*
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        : none.
*******************************************************************************************/
AVM_EXT AVM_ERR avmlib_DrawLine_Exit(void);



#endif /* GPU_DRAWLINE_H_ */
