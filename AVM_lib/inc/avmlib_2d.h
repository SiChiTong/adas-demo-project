/*******************************************************************************
* File Name          : avmlib_2d.h
* Author             : Jerry
* Revision           : 2.1
* Date               : 15/07/2016
* Description        : Library Interface 
*******************************************************************************/

#ifndef __AVMLIB_2D_H__
#define __AVMLIB_2D_H__

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>

#include "avmlib_sdk.h"
#include "avmlib_vectors.h"
#include "avmlib_GenCaliData.h"

//libʹ�ã������޸�
#define MAX2DOBJECT       4
#define MAX2DTEXTURE      4
#define MAX2DUINFORM      8
#define MAX2DATTRIBUTE    5
#define MAX2DNAME         20

/*
*************************************************************************
*************************************************************************
*                    LOCAL  E N U M E R A T I O N S
*************************************************************************
*************************************************************************
*/
enum avm2d_type_enum/* avm 2d ���� */
{
    invalid2d_type = 0,//��Ч
    avm2dview_type,    //����
    avmldwview_type,   //ldw
    singleview_type,   //����ͼ
    periscopeview_type,
    car2d_type         //��ģ
};

enum blend2d_type_enum/*blending ���� */
{
    SRC_DST_ALPHA_2D = 1,//Դ��ɫ��alphaֵ����Ϊ���ӣ�Ŀ����ɫ��alphaֵ����Ϊ����
    SRC_ONE_MINUS_SRC_ALPHA_2D,//Դ��ɫ��alphaֵ����Ϊ���ӣ�1.0��ȥԴ��ɫ��alphaֵ����ΪĿ����ɫ����
    ONE_ZERO_ALPHA_2D,//ʹ��1.0��ΪԴ��ɫ�����ӣ�0.0��ΪĿ����ɫ�����ӣ�
    //�൱����ȫ��ʹ����Դ��ɫ�����϶���ʹ��Ŀ����ɫ
};

/*
*************************************************************************
*************************************************************************
*                      D A T A   S T R U C T U R E S
*************************************************************************
*************************************************************************
*/
struct avm2d_type_;

typedef struct view_2d_parameter_//2d�ӵ����
{
    Vector3 scale;   //��������(X,Y,Z;Z��Ч���̶�Ϊ1.0)
    Vector3 eye;     //�ӵ�λ��(X,Y,Z)
    Vector3 at;      //�ӵ��յ�λ��(X,Y,Z)
    Vector3 up;      //���Ϸ�������
    GLfloat offset_x;//Xƽ��
    GLfloat offset_y;//Yƽ��
    GLfloat offset_z;//Zƽ����Ч,�̶�Ϊ0.0
    GLfloat rotate_x;//��X����ת
    GLfloat rotate_y;//��Y����ת
    GLfloat rotate_z;//��Z����ת
    GLfloat left;    //�Ӿ���left
    GLfloat right;   //�Ӿ���right
    GLfloat top;     //�Ӿ���top
    GLfloat bottom;  //�Ӿ���bottom
    S32 screen_x;    //�ӿ�λ��x
    S32 screen_y;    //�ӿ�λ��y
    S32 screen_width;//�ӿڿ��
    S32 screen_height;//�ӿڸ߶�
    U32 reserved;     //����
} view_2d_parameter_t;

typedef struct shader2d_member_//libʹ�ã������޸�
{
    C8 name[MAX2DNAME];
    GLuint memberID;
} shader2d_member_t;

typedef struct avm2d_shader_type_
{
    GLuint shaderProgram;//libʹ�ã������޸�
    GLuint uiniformListNum;//libʹ�ã������޸�
    GLuint attributeListNum;//libʹ�ã������޸�
    shader2d_member_t uniformList [MAX2DUINFORM];//libʹ�ã������޸�
    shader2d_member_t attributeList [MAX2DATTRIBUTE];//libʹ�ã������޸�
    AVM_ERR(*avmlib_Use)(struct avm2d_type_ *avm2d_type);//������Ŀ����
    AVM_ERR(*avmlib_Unuse)(struct avm2d_type_ *avm2d_type);//ȥ������Ŀ����
    AVM_ERR(*avmlib_Shader_Init)(struct avm2d_type_ *avm2d_type, const C8 *programName, const C8 *programName1);//��ɫ����ʼ��
    AVM_ERR(*avmlib_Delete_Shader)(struct avm2d_type_ *avm2d_type);//��ɫ���˳�
} avm2d_shader_type_t;
typedef struct objID_2d_//libʹ�ã������޸�
{
    GLuint ObjID;
    GLuint objIDPointNum;
} objID_2d_t;

typedef struct avm2d_object_type_
{
    objID_2d_t objID[MAX2DOBJECT];//libʹ�ã������޸�
    S32    objprivate[20];//libʹ�ã������޸�
    U8     usedObjNum;//libʹ�ã������޸�
    AVM_ERR(*avmlib_Gen_ObjBuffer)(struct avm2d_type_ *avm2d_type, const C8 *file_name, U8 num,lut_parameter_t* plutpar);//���嶥�㻺��
    AVM_ERR(*avmlib_Delete_Object)(struct avm2d_type_ *avm2d_type);//ɾ�����㻺��
} avm2d_object_type_t;

typedef struct avm2d_texture_type_
{
    GLuint TextureID[2];//libʹ�ã������޸�
	GLuint TextureID_used;//libʹ�ã������޸�
    GLuint TextureW;//libʹ�ã������޸�
    GLuint TextureH;//libʹ�ã������޸�
    GLfloat sTextureCorrectParameter[3];//libʹ�ã������޸�
    AVM_ERR(*avmlib_Gen_TextrueBuffer)(struct avm2d_type_ *avm2d_type, GLuint texture_width, GLuint texture_heigh, GLenum format, void *pdata);//��������
    AVM_ERR(*avmlib_Update_TextureBuffer)(struct avm2d_type_ *avm2d_type, GLint xoffset, GLint yoffset, GLuint texture_width, GLuint texture_heigh, GLenum format, void *pdata);
    AVM_ERR(*avmlib_Delete_Texture)(struct avm2d_type_ *avm2d_type);//ɾ������
} avm2d_texture_type_t;


typedef struct blend2dParameter_
{
    enum blend2d_type_enum blend_type;
    GLfloat   ctl_blend[4];  //[0] Blend [1]lightness correct [2]de-interlace
    GLfloat   rgb_correct[3];//[0]r [1]g [2]b
} blend_2d_Parameter_t;

typedef struct avm2dviewParameter_//libʹ�ã������޸�
{
    GLfloat matMVP[16];
    U32 screen_x;
    U32 screen_y;
    U32 screen_width;
    U32 screen_height;
    U32 changeflg;
} avm2d_view_Parameter_t;

typedef struct avm2d_render_type_
{
    blend_2d_Parameter_t blendParameter;//libʹ�ã������޸�
    avm2d_view_Parameter_t viewParameter[MAX2DOBJECT];//libʹ�ã������޸�
    AVM_ERR(*avmlib_Set_Blend)(struct avm2d_type_ *avm2d_type,blend_2d_Parameter_t *parameter);//Blending����
    AVM_ERR(*avmlib_Set_ViewParameter)(struct avm2d_type_ *avm2d_type, view_2d_parameter_t *viewParameter, U8 Index);//�ӵ��������
    AVM_ERR(*avmlib_Render_Singleview)(struct avm2d_type_ *avm2d_type, U8 obj_Index, U8 c_Index);//����ͼ��ʾ
    AVM_ERR(*avmlib_Render_Topview)(struct avm2d_type_ *avm2d_type);//������ʾ
    AVM_ERR(*avmlib_Render_Car)(struct avm2d_type_ *avm2d_type);//��ģ��ʾ
} avm2d_render_type_t;

typedef struct avm2d_type_
{
    U8  IsUsed;//libʹ�ã������޸�
    enum avm2d_type_enum  avm_type; //2D ����
    avm2d_shader_type_t  *avm2d_shader_type; //shader���� libʹ�ã������޸�
    avm2d_object_type_t  *avm2d_object_type; //vbo����  libʹ�ã������޸�
    avm2d_texture_type_t *avm2d_texture_type;//������� libʹ�ã������޸�
    avm2d_render_type_t  *avm2d_render_type; //��Ⱦ���� libʹ�ã������޸�
    struct avm2d_type_ *pAttr;//��ģ�����Ļ��ӣ���������Ұ��Ч
}  avm2d_type_t;

/*
*************************************************************************
*************************************************************************
*                      F U N C T I O N
*************************************************************************
*************************************************************************
*/

/*******************************************************************************************
* Function Name  : avmlib_2d_Init.
*
* Description    : avm 2D��ʼ��
*
* Arguments      : avm2d_type  avm2d_type_t����ָ��
*                  -----
*
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        : avm2d_type��ʹ��֮ǰ�����ʼ��
*******************************************************************************************/
AVM_EXT AVM_ERR avmlib_2d_Init(avm2d_type_t *avm2d_type);

/*******************************************************************************************
* Function Name  : avmlib_2d_Child_Init.
*
* Description    : avm 2d ��ģʽ��ʼ�� avm2d_child_type��avm2d_shader_type��avm2d_texture_type
*                  ��avm2d_base_type�и��ƣ����ڻ��Ӻ͵���ͼ��avm2d_object_type��
*                  ��avm2d_base_type�и���,��ģ��avm2d_object_type�����´�����
* Arguments      : avm2d_child_type  avm2d_type_t����ָ��
*                  -----
*
*                  avm2d_base_type   avm2d_type_t����ָ��
*                  -----
*
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        : avm2d_child_type��ʹ��֮ǰ�����ʼ��
*******************************************************************************************/
AVM_EXT AVM_ERR avmlib_2d_Child_Init(avm2d_type_t *avm2d_child_type, avm2d_type_t *avm2d_base_type);

/*******************************************************************************************
* Function Name  : avmlib_2d_Exit.
*
* Description    : avm 2d �˳�
*
* Arguments      : avm2d_type avm2d_type_t����ָ��
*                  -----
*
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        : ��avmlib_Delete_Object��avmlib_Delete_Texture���ú��ٵ��ô˺���
*******************************************************************************************/
AVM_EXT AVM_ERR avmlib_2d_Exit(avm2d_type_t *avm2d_type);




#endif /* AVM2D_H_ */
