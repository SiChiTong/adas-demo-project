/*******************************************************************************
* File Name          : avmlib_gpu_drawing.h
* Author             : Jerry
* Revision           : 2.1
* Date               : 15/07/2016
* Description        : Library Interface 
*******************************************************************************/


#ifndef __AVM_GENCALIDATA_H__
#define __AVM_GENCALIDATA_H__
#include "avmlib_sdk.h"

/* ����LUT���� */
typedef struct virtual_camera_avm_
{
    S32 vc_height;//��������߶�
    S32 vc_width; //����������
    S32 srcW;     //ԭʼͼ���
    S32 srcH;     //ԭʼͼ�߶�
    S32 tri_x_div;/* opengl������x��� */
    S32 tri_y_div;/* opengl������y��� */
    S32 OFRONTY;  /* ǰ���y�����ƫ�� */
    S32 OLEFTX;   /* �����x�����ƫ�� */
    S32 ORIGHTX;  /* ǰ���y�����ƫ�� */
    S32 OBACKY;   /* �����x�����ƫ�� */
    S32 BLEND_ANGLE_H;/* alpha�����Ƕ� (0-90)*/
    S32 BLEND_ANGLE_M;/* alpha���ȽǶ� (0-90)*/
    S32 BLEND_ANGLE_L;/* alpha��ʼ�Ƕ� (0-90)*/
    S32 REAR_BLEND_ANGLE_H;/* alpha�����Ƕ� (0-90)*/
    S32 REAR_BLEND_ANGLE_M;/* alpha���ȽǶ� (0-90)*/
    S32 REAR_BLEND_ANGLE_L;/* alpha��ʼ�Ƕ� (0-90)*/
    F32 scale_pixel_mm;//����ϵ��(һ�����ش���ʵ�ʵľ��� eg. 23��ʾ1�����ش���ʵ�ʾ���23mm)
} virtual_camera_avm_t;//����LUT����

/* �����������ʹ�ñ�־ */
typedef enum VCAMPARAM_FLAG
{
    VCAMPARAM_ABS  = 0,  /* ֱ�Ӹ�ֵ */
    VCAMPARAM_DEF ,      /* Ĭ��ֵ */
    VCAMPARAM_OFFSET,    /* ƫ��ֵ */
} vcamparam_flag_t;

/* ����ҰLUT���� */
typedef struct VirtualCameraParam_{
		double alpha_c;//skew coefficient
		double gammax;//general focus oin x direction.
		double gammay;//general focus oin y direction.
		double cx;//principle point in x direction
		double cy;//principle point in y direction
		double kc[5];//distortion[5]
		double xi;//
		double stretch;
		double R[3][3];////R,T are transformation matrix from virtual camera's CS to vehicle's CS: Xvt=R*Xcam+T
		double T[3];////R,T are transformation matrix from virtual camera's CS to vehicle's CS: Xvt=R*Xcam+T
		int IMG_WIDTH;
		int IMG_HEIGHT;

}VirtualCameraParam_t;

typedef struct virtual_camera_sv_
{
    S32 vc_height[4];   //��������߶�
    S32 vc_width[4];    //����������
    S32 srcW;           //ԭʼͼ���
    S32 srcH;           //ԭʼͼ�߶�
    S32 tri_x_div; /* opengl������x��� */
    S32 tri_y_div; /* opengl������y��� */
    S32 mirror[4]; /* �Ƿ����Ҿ��� 1:���� 0:������*/
    vcamparam_flag_t vmode[4];/* ����ʹ�÷�ʽ */
    F64 fovx_minus[4];/* �ӵ�ƽ��X��������Ұ�Ƕ� */
    F64 fovx_plus[4]; /* �ӵ�ƽ��X��������Ұ�Ƕ� */
    F64 fovy_minus[4];/* �ӵ�ƽ��Y��������Ұ�Ƕ� */
    F64 fovy_plus[4]; /* �ӵ�ƽ��Y��������Ұ�Ƕ� */
    F64 pose[4][6];   /* ��������ӵ����������λ��[x][0-2]������[x][3-5],����λ�ò����޸�*/
    F64 xi_ratio[4];  /* ����ϵ�� */
    F64 stretch[4];   /* ����ϵ�� */
    VirtualCameraParam_t puVC[4];/*puVC:�����û����������puVCΪԪ�ظ���Ϊ4��������Ԫ��ָ��
                              eg. VirtualCameraParam VirtualCamera[4];*/
} virtual_camera_sgv_t;//��������ͷLUT����
//3D


typedef struct virtual_camera_avm3d_
{
	S32 vc_width;
	S32 vc_height;
    S32 srcW;           //ԭʼͼ���
    S32 srcH;           //ԭʼͼ�߶�
    S32 tri_div_x;        /* ������������ */
    S32 tri_div_y;        /* ������������ */
    S32 front_angle0; //ǰ���ں���ʼ�Ƕ�
    S32 front_angle1; //ǰ���ںϽǶ�
    S32 front_angle2; //ǰ���ں���ʼ�Ƕ�
    S32 front_angle3; //ǰ���ںϽǶ�
	S32 rear_angle0;  //�����ں���ʼ�Ƕ�
    S32 rear_angle1;  //�����ںϽǶ�
    S32 rear_angle2;  //�����ں���ʼ�Ƕ�
    S32 rear_angle3;  //�����ںϽǶ�
    S32 OFRONTY;  /* ǰ���y�����ƫ�� */
    S32 OLEFTX;   /* �����x�����ƫ�� */
    S32 ORIGHTX;  /* ǰ���y�����ƫ�� */
    S32 OBACKY;   /* �����x�����ƫ�� */
    F32 r_begin;      //ģ����ʼ�뾶 x * V_width
    F32 r_bottom;     //ģ�ͽ����뾶 x * V_length
    F32 r_torus;      //����Բ�뾶
    F32 center_x;     //ģ������x  ��Ϊ0
    F32 center_y;     //ģ������y  x * V_length
    F32 res_angle;    //�Ƕȷֱ���
    F32 res_r;        //����ֱ��� x * V_width
    F32 alpha_wall;   //����
    F32 limit_wall;   //�ڸ� x * V_length
    F32 dx_dy_ellipse;//ģ�͵Ķ̰뾶/���뾶
	F32 alpha_scale_mm;//alpha��ķֱ���
    
} virtual_camera_avm3d_t;//����LUT����

//cali
typedef struct virtual_camera_
{
    virtual_camera_avm3d_t *pavm3d;//3D����lut����
    virtual_camera_avm_t *pavm;//����lut����
    virtual_camera_sgv_t *psgv;//����Ұlut����
    C8 *lut_savepath;//lut_savepathΪvbo���ݱ���·��
                     //���lut_savepathΪNULL,��vbo���ݲ�����
} lut_parameter_t;//LUT����

typedef struct
{
    /* camera ǰ */
    S32 cam0_left_sx; //���ɫ���λ������
    S32 cam0_left_sy;
    S32 cam0_left_ex;
    S32 cam0_left_ey;

    S32 cam0_right_sx;//�ұ�ɫ���λ������
    S32 cam0_right_sy;
    S32 cam0_right_ex;
    S32 cam0_right_ey;

    S32 cam0_left_area_min;//ɫ�������С�������δʹ��
    S32 cam0_left_area_max;
    S32 cam0_right_area_min;
    S32 cam0_right_area_max;

    /* camera �� */
    S32 cam1_left_sx;
    S32 cam1_left_sy;
    S32 cam1_left_ex;
    S32 cam1_left_ey;

    S32 cam1_right_sx;
    S32 cam1_right_sy;
    S32 cam1_right_ex;
    S32 cam1_right_ey;

    S32 cam1_left_area_min;
    S32 cam1_left_area_max;
    S32 cam1_right_area_min;
    S32 cam1_right_area_max;

    /* camera �� */
    S32 cam2_left_sx;
    S32 cam2_left_sy;
    S32 cam2_left_ex;
    S32 cam2_left_ey;

    S32 cam2_right_sx;
    S32 cam2_right_sy;
    S32 cam2_right_ex;
    S32 cam2_right_ey;

    S32 cam2_left_area_min;
    S32 cam2_left_area_max;
    S32 cam2_right_area_min;
    S32 cam2_right_area_max;

    /* camera �� */
    S32 cam3_left_sx;
    S32 cam3_left_sy;
    S32 cam3_left_ex;
    S32 cam3_left_ey;

    S32 cam3_right_sx;
    S32 cam3_right_sy;
    S32 cam3_right_ex;
    S32 cam3_right_ey;

    S32 cam3_left_area_min;
    S32 cam3_left_area_max;
    S32 cam3_right_area_min;
    S32 cam3_right_area_max;

    S32 cam0_left_rot_angle;   //��������ɫ����ת�Ƕ� ��ʱ��Ϊ��
    S32 cam0_right_rot_angle;  //������Ҳ�ɫ����ת�Ƕ� ˳ʱ��Ϊ��

    S32 cam1_left_rot_angle;
    S32 cam1_right_rot_angle;

    S32 cam2_left_rot_angle;
    S32 cam2_right_rot_angle;

    S32 cam3_left_rot_angle;
    S32 cam3_right_rot_angle;

} range_info_t;

typedef struct
{
    F32 flrotanglescale;//ǰ����ͷ���ɫ����ת�Ƕ�ϵ��
    F32 frrotanglescale;//ǰ����ͷ�Ҳ�ɫ����ת�Ƕ�ϵ��
    F32 rlrotanglescale;//������ͷ���ɫ����ת�Ƕ�ϵ��
    F32 rrrotanglescale;//������ͷ�Ҳ�ɫ����ת�Ƕ�ϵ��
    F32 blrotanglescale;//������ͷ���ɫ����ת�Ƕ�ϵ��
    F32 brrotanglescale;//������ͷ�Ҳ�ɫ����ת�Ƕ�ϵ��
    F32 llrotanglescale;//������ͷ���ɫ����ת�Ƕ�ϵ��
    F32 lrrotanglescale;//������ͷ�Ҳ�ɫ����ת�Ƕ�ϵ��
} rotangle_t;

typedef struct
{
    F32  l_r_luminancemin ;    //������ͷ�Ҳ�ɫ���������
    F32  l_l_luminancemin ;    //������ͷ���ɫ���������
    F32  r_r_luminancemin ;    //������ͷ�Ҳ�ɫ���������
    F32  r_l_luminancemin ;    //������ͷ���ɫ���������
    F32  l_r_luminancescale;   //������ͷ�Ҳ�ɫ��ƽ������ϵ��
    F32  l_l_luminancescale;   //������ͷ���ɫ��ƽ������ϵ��
    F32  r_r_luminancescale;   //������ͷ�Ҳ�ɫ��ƽ������ϵ��
    F32  r_l_luminancescale;   //������ͷ���ɫ��ƽ������ϵ��
    F32  l_r_luminancemin_s;   //������ͷ�Ҳ�ɫ��������ȣ��ڶ��ξ�ѡ��
    F32  l_l_luminancemin_s;   //������ͷ���ɫ��������ȣ��ڶ��ξ�ѡ��
    F32  r_r_luminancemin_s;   //������ͷ�Ҳ�ɫ��������ȣ��ڶ��ξ�ѡ��
    F32  r_l_luminancemin_s;   //������ͷ���ɫ��������ȣ��ڶ��ξ�ѡ��
    F32  l_r_luminancescale_s; //������ͷ�Ҳ�ɫ��ƽ������ϵ�����ڶ��ξ�ѡ��
    F32  l_l_luminancescale_s; //������ͷ���ɫ��ƽ������ϵ�����ڶ��ξ�ѡ��
    F32  r_r_luminancescale_s; //������ͷ�Ҳ�ɫ��ƽ������ϵ�����ڶ��ξ�ѡ��
    F32  r_l_luminancescale_s; //������ͷ���ɫ��ƽ������ϵ�����ڶ��ξ�ѡ��

    F32  f_l_luminancemin ;   //ǰ����ͷ���ɫ���������
    F32  f_r_luminancemin ;   //ǰ����ͷ�Ҳ�ɫ���������
    F32  b_l_luminancemin ;   //������ͷ���ɫ���������
    F32  b_r_luminancemin ;   //������ͷ�Ҳ�ɫ���������
    F32  f_l_luminancescale;   //ǰ����ͷ���ɫ��ƽ������ϵ��
    F32  f_r_luminancescale;   //ǰ����ͷ�Ҳ�ɫ��ƽ������ϵ��
    F32  b_l_luminancescale;   //������ͷ���ɫ��ƽ������ϵ��
    F32  b_r_luminancescale;   //������ͷ�Ҳ�ɫ��ƽ������ϵ��
    F32  f_l_luminancemin_s;   //ǰ����ͷ���ɫ��������ȣ��ڶ��ξ�ѡ��
    F32  f_r_luminancemin_s;   //ǰ����ͷ�Ҳ�ɫ��������ȣ��ڶ��ξ�ѡ��
    F32  b_l_luminancemin_s;   //������ͷ���ɫ��������ȣ��ڶ��ξ�ѡ��
    F32  b_r_luminancemin_s;   //������ͷ�Ҳ�ɫ��������ȣ��ڶ��ξ�ѡ��
    F32  f_l_luminancescale_s; //ǰ����ͷ���ɫ��ƽ������ϵ�����ڶ��ξ�ѡ��
    F32  f_r_luminancescale_s; //ǰ����ͷ�Ҳ�ɫ��ƽ������ϵ�����ڶ��ξ�ѡ��
    F32  b_l_luminancescale_s; //������ͷ���ɫ��ƽ������ϵ�����ڶ��ξ�ѡ��
    F32  b_r_luminancescale_s; //������ͷ�Ҳ�ɫ��ƽ������ϵ�����ڶ��ξ�ѡ��
} luminance_t;

typedef struct calibration_attr_cfg_
{
 int   grid_dx;        //ɫ���ȵ�һ��mm
 int   grid_dy;        //ɫ��߶ȵ�һ��mm
 int   grid_dist_v;    //���������Ҳ����궨��֮�����mm
 int   grid_dist_h;    //����ǰ����Ҳ����궨��֮�����mm
 int   isautocalib;    //�궨ģʽ(0:2D 4:3D)
 int   dist_border;    //ɫ�鵽�궨����صľ���mm
} cali_attr_cfg_t; //�궨����

typedef struct
{
    S32 video_w;//ͼ����
    S32 video_h;//ͼ��߶�
    luminance_t  luminance;  //���Ȳ���
    rotangle_t   rotangle;   //�ǶȲ���
    range_info_t range_info; //�������
    cali_attr_cfg_t cali_cfg ;//�궨����
} cali_parame_t; //�Զ��궨����

typedef struct cali_cameraParam_
{
    F64 Xw;//camera's x coordinates in the big world CS
    F64 Yw;//camera's y coordinates in the big world CS
    F64 Zw;//camera's z coordinates in the big world CS
} avm_cameraParam_t;

typedef struct vehicle_information_
{
    S32   Veh_width;//����
    S32   Veh_length;//����
    avm_cameraParam_t paramLeft;//�������Ϣ
    avm_cameraParam_t paramRight;//�������Ϣ
    avm_cameraParam_t paramFront;//ǰ�����Ϣ
    avm_cameraParam_t paramBack;//�������Ϣ
    F64 Tgw[3];//vehicle translation vector (Tgw) in world CS
} avm_vehicle_info_t;

AVM_ERR avmlib_Get_Vehicle_Info(avm_vehicle_info_t *pvehicle_info);
AVM_ERR  avmlib_init_SDASlib(const U8 *const lut_file_path, const cali_attr_cfg_t *const cali_cfg);
AVM_ERR  avmlib_getVCImageCoordFromVehicleCoord(const VirtualCameraParam_t *const pVC, const F64 *const Coord_v, S32 *Coord_vc);
AVM_ERR avmlib_getImageCoordFromVehicleCoord(const int camera_id, const F64 *const Coord_v, F64 *camera_x,F64 *camera_y);

#endif /* AUTOCALI_H_ */
