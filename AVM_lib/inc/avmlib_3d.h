/*******************************************************************************
* File Name          : avmlib_3d.h
* Author             : Jerry
* Revision           : 2.1
* Date               : 15/07/2016
* Description        : Library Interface 
*******************************************************************************/
#ifndef __AVMLIB_3D_H__
#define __AVMLIB_3D_H__

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>

#include "avmlib_sdk.h"
#include "avmlib_vectors.h"
#include "avmlib_GenCaliData.h"



//libʹ�ã������޸�
#define MAX3DOBJECT       4
#define MAX3DTEXTURE      4
#define MAX3DUINFORM      9
#define MAX3DATTRIBUTE    5
#define MAX3DNAME         20

/*
*************************************************************************
*************************************************************************
*                    LOCAL  E N U M E R A T I O N S
*************************************************************************
*************************************************************************
*/
enum avm3d_type_enum/* avm 3d ���� */
{
    invalid3d_type = 0,//��Ч
    avm3dview_type,    //3D����
    car3d_type,        //3D��ģ��
    tire_type,         //3D����
    chassis_type       //3D����
};

enum blend3d_type_enum/*blending ���� */
{
    SRC_DST_ALPHA_3D = 1, //Դ��ɫ��alphaֵ����Ϊ���ӣ�Ŀ����ɫ��alphaֵ����Ϊ����
    SRC_ONE_MINUS_SRC_ALPHA_3D,//Դ��ɫ��alphaֵ����Ϊ���ӣ�1.0��ȥԴ��ɫ��alphaֵ����ΪĿ����ɫ����
};

/*
*************************************************************************
*************************************************************************
*                      D A T A   S T R U C T U R E S
*************************************************************************
*************************************************************************
*/
struct avm3d_type_;

typedef struct view_3d_parameter_
{
    Vector3 scale;    //��������(X,Y,Z)
    Vector3 eye;      //�ӵ�λ��(X,Y,Z)
    Vector3 pitchhead;      //pitch head radius
    Vector3 at;       //�ӵ��յ�λ��(X,Y,Z)
    Vector3 up;       //���Ϸ�������
    Vector4 rotate_axis;//����ת����
    GLfloat rotate_angle;//����ת�Ƕ�
    GLfloat offset_x; //Xƽ��
    GLfloat offset_y; //Yƽ��
    GLfloat offset_z; //Zƽ��
    GLfloat rotate_x; //��X����ת
    GLfloat rotate_y; //��Y����ת
    GLfloat rotate_z; //��Z����ת
    GLfloat fov ;     //�ӽǷ�Χ
    S32 screen_x;     //�ӿ�λ��x
    S32 screen_y;     //�ӿ�λ��y
    S32 screen_width; //�ӿڿ��
    S32 screen_height;//�ӿڸ߶�
    U32 reserved;     //����
} view_3d_parameter_t;

typedef struct shader3d_member_//libʹ�ã������޸�
{
    C8 name[MAX3DNAME];
    GLuint memberID;
} shader3d_member_t;

typedef struct avm3d_shader_type_
{
    GLuint shaderProgram;//libʹ�ã������޸�
    GLuint uiniformListNum;//libʹ�ã������޸�
    GLuint attributeListNum;//libʹ�ã������޸�
    shader3d_member_t uniformList [MAX3DUINFORM];//libʹ�ã������޸�
    shader3d_member_t attributeList [MAX3DATTRIBUTE];//libʹ�ã������޸�
    AVM_ERR(*avmlib_Use)(struct avm3d_type_ *avm3d_type);//������Ŀ����
    AVM_ERR(*avmlib_Unuse)(struct avm3d_type_ *avm3d_type);//ȥ������Ŀ����
    AVM_ERR(*avmlib_Shader_Init)(struct avm3d_type_ *avm3d_type, const C8 *programName, const C8 *programName1);//��ɫ����ʼ��
    AVM_ERR(*avmlib_Delete_Shader)(struct avm3d_type_ *avm3d_type);//��ɫ���˳�

}  avm3d_shader_type_t;

typedef struct objID_3d_//libʹ�ã������޸�
{
    GLuint ObjID;
    GLuint objIDPointNum;
} objID_3d_t;

typedef struct avm3d_object_type_
{
    objID_3d_t objID[MAX3DOBJECT];//libʹ�ã������޸�
    S32    objprivate[16];//libʹ�ã������޸�
    GLuint usedObjNum;//libʹ�ã������޸�
    AVM_ERR(*avmlib_Gen_ObjBuffer)(struct avm3d_type_ *avm3d_type, const C8 *file_name, U8 num,lut_parameter_t *plutpar);//���嶥�㻺��
    AVM_ERR(*avmlib_Delete_Object)(struct avm3d_type_ *avm3d_type);//ɾ�����㻺��
} avm3d_object_type_t;

typedef struct avm3d_texture_type_
{
    GLuint TextureID[2];//libʹ�ã������޸�
	GLuint TextureID_used;//libʹ�ã������޸�
    GLuint TextureW;//libʹ�ã������޸�
    GLuint TextureH;//libʹ�ã������޸�
    GLfloat sTextureCorrectParameter[3];//libʹ�ã������޸�
    AVM_ERR(*avmlib_Gen_TextrueBuffer)(struct avm3d_type_ *avm3d_type, GLuint texture_width, GLuint texture_heigh, GLenum format, void *pdata);//��������
    AVM_ERR(*avmlib_Update_TextureBuffer)(struct avm3d_type_ *avm3d_type, GLint xoffset, GLint yoffset, GLuint texture_width, GLuint texture_heigh, GLenum format, void *pdata);
    AVM_ERR(*avmlib_Delete_Texture)(struct avm3d_type_ *avm3d_type);//ɾ������
} avm3d_texture_type_t;

typedef struct avm3dviewParameter_//libʹ�ã������޸�
{
    GLfloat matMVP[16];
    GLfloat matProj[16];
    GLfloat matMview[16];
    U32 screen_x;
    U32 screen_y;
    U32 screen_width;
    U32 screen_height;
    U32 changeflg;
	F32 alpha_scale_mm;
} avm3d_view_Parameter_t;


typedef struct blend3dParameter_
{
    enum blend3d_type_enum blend_type;
    GLfloat   ctl_blend[4];//[0] Blend [1]lightness correct [2]de-interlace(�ݲ�֧��)
    GLfloat   rgb_correct[3];//[0]r [1]g [2]b
}  blend_3d_Parameter_t;

typedef struct avm3d_render_type_
{
    blend_3d_Parameter_t blendParameter;//libʹ�ã������޸�
    avm3d_view_Parameter_t viewParameter;//libʹ�ã������޸�
    AVM_ERR(*avmlib_Set_Blend)(struct avm3d_type_ *avm3d_type,blend_3d_Parameter_t *parameter);//Blending����
    AVM_ERR(*avmlib_Set_ViewParameter)(struct avm3d_type_ *avm3d_type, view_3d_parameter_t *viewParameter);//�ӵ��������
    AVM_ERR(*avmlib_Render_Topview)(struct avm3d_type_ *avm3d_type);//������ʾ
    AVM_ERR(*avmlib_Render_Car)(struct avm3d_type_ *avm3d_type);//��ģ��ʾ
} avm3d_render_type_t;

typedef struct avm3d_type_
{
    U8     IsUsed;//libʹ�ã������޸�
    enum   avm3d_type_enum  avm_type;
    avm3d_shader_type_t  *avm3d_shader_type;
    avm3d_object_type_t  *avm3d_object_type;
    avm3d_texture_type_t *avm3d_texture_type;
    avm3d_render_type_t  *avm3d_render_type;
    struct avm3d_type_ *pAttr;  //���ڳ�ģ����3D����
}  avm3d_type_t;

/*
*************************************************************************
*************************************************************************
*                      F U N C T I O N
*************************************************************************
*************************************************************************
*/
/*******************************************************************************************
* Function Name  : avmlib_3d_Init.
*
* Description    : avm 3D��ʼ��
*
* Arguments      : avm3d_type  avm3d_type_t����ָ��
*                  -----
*
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        : avm3d_type��ʹ��֮ǰ�����ʼ��
*******************************************************************************************/
AVM_EXT AVM_ERR avmlib_3d_Init(avm3d_type_t *avm3d_type);

/*******************************************************************************************
* Function Name  : avmlib_3d_Child_Init.
*
* Description    : avm 3d ��ʼ�� avm3d_child_type��avm3d_shader_type
*                  ��avm3d_base_type�и��ƣ����ڻ��ӵ�avm3d_object_type��
*                  ��avm3d_base_type�и���,��ģ��avm3d_object_type�����´�����
* Arguments      : avm3d_child_type  avm3d_type_t����ָ��
*                  -----
*
*                  avm3d_base_type   avm3d_type_t����ָ��
*                  -----
*
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        : avm3d_child_type��ʹ��֮ǰ�����ʼ��
*******************************************************************************************/
AVM_EXT AVM_ERR avmlib_3d_Child_Init(avm3d_type_t *avm3d_child_type, avm3d_type_t *avm3d_base_type);

/*******************************************************************************************
* Function Name  : avmlib_3d_Exit.
*
* Description    : avm 3d �˳�
*
* Arguments      : avm3d_type avm3d_type_t����ָ��
*                  -----
*
* Return         : AVM_ERR_NONE   successful.
*                  Other         Other AVM_ERR_xxx   fail.
*
* Note(s)        : ��avmlib_Delete_Object��avmlib_Delete_Texture���ú��ٵ��ô˺���
*******************************************************************************************/
AVM_EXT AVM_ERR avmlib_3d_Exit(avm3d_type_t *avm3d_type);





#endif /* AVM3D_H_ */
