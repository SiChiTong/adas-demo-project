/*******************************************************************************
* File Name          : avmlib_gpu_drawing.h
* Author             : Jerry
* Revision           : 2.1
* Date               : 15/07/2016
* Description        : Library Interface 
*******************************************************************************/
#ifndef __AVMLIB_GPU_DRAWIMG_H__
#define __AVMLIB_GPU_DRAWIMG_H__

#include <stdio.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include "avmlib_sdk.h"
#include "avmlib_loadpng.h"
/*
*************************************************************************
*************************************************************************
*                      D A T A   S T R U C T U R E S
*************************************************************************
*************************************************************************
*/


/*
*************************************************************************
*************************************************************************
*                      F U N C T I O N
*************************************************************************
*************************************************************************
*/

AVM_ERR avmlib_create_texture(const GLvoid *pbuf,GLenum format,S32 texture_w, 
								S32 texture_h, S32 size,GLuint *tex_id_output);

/*******************************************************************************************
* Function Name  : avmlib_Draw_Png.
*
* Description    : ��ʾpngͼƬ
*
* Arguments      : png_texture    png_texture_tָ��
*                  -----
*
*                  directdraw    �Ƿ�ֱ����ʾͼƬ���� AVM_NO:��png_texture���º�����ʾ
*                  -----                              AVM_YES:������png_textureֱ����ʾ
*
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        : none.
******************************************************************************************/
AVM_ERR avmlib_Draw_Png(const png_texture_t *const png_texture, GLuint tex_id_input);

/*******************************************************************************************
* Function Name  : avmlib_DrawPng_Init.
*
* Description    : ��ͼ��ʼ��
*
* Arguments      : programName    ������ɫ������
*                  -----
*
*                  programName1   Ƭ����ɫ������
*                  -----
*
*                  format         ͼƬ��ʽ
*                  -----
*
*                  size           ͼƬ�ߴ�
*                  -----
*
*                  pbuf           ͼƬ����
*                  -----
*
*                  win_w          ��ͼ���ڿ��
*                  -----
*
*                  win_h          ��ͼ���ڸ߶�
*                  -----
*
*
*                  dip_w          ��ʾ���ڿ��
*                  -----
*
*                  dip_h          ��ʾ���ڸ߶�
*                  -----
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        :  �ڻ�ͼ֮ǰ��Ҫ����һ�γ�ʼ��.
******************************************************************************************/
AVM_EXT AVM_ERR avmlib_DrawPng_Init(const C8 *programName, const C8 *programName1);



/*******************************************************************************************
* Function Name  : avmlib_DrawPng_Exit.
*
* Description    : ��ͼ�˳�
*
* Arguments      : none
*
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        : none.
******************************************************************************************/
AVM_EXT AVM_ERR avmlib_DrawPng_Exit(void);



#endif /* GPU_DRAWIMG_H_ */
