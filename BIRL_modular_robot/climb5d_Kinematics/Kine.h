#ifndef __KINE_H__
#define __KINE_H__
/*****************************************************************************
 *        Robot�˶�ѧ����                                                    *
 *        SCUT, 2010                                                         *
 *        Author :                                                           *
 *        Version number :  0.10                                             *
 *        Date :            2010-12-08                                       *
 *****************************************************************************/
#include "Robot.h"
#include "Matrix.h"
#define  Len1 0.204         //����1����
#define  Len2 0.1367       //����2 ����
#define  Len3 0.29325        //����3����
#define  Len4 0.29325       //����4 ����
#define  Len5 0.1367         //����5����
#define  Len6 0.204       //����6 ����
/*****************************************************************************
 *  �˶�ѧ����
 *****************************************************************************/
class Kine
{
public:
	Kine();
	~Kine();

	/******************************************************************************
	 * ������FKine()
	 * ���ܣ�����
	 *
	 * ���룺double* gdJPos - �ؽ�ת��, 5/6�ؽ�
	 * �����double* gdCPos - ����λ��, (x,y,z,w,p,r)
	 *
	 * ���أ�int - 0�ɹ�,
	 ******************************************************************************/
	virtual int FKine(IN double gdJPos[], OUT double gdCPos[]) = 0;


	/******************************************************************************
	 * ������IKine()
	 * ���ܣ����
	 *
	 * ���룺double* gdCPos  - λ������, (x,y,z,w,p,r)
	 *       double* gdJCurr - ��ǰ�ؽ�ת��, 5/6�ؽ�
	 * �����double* id_jPos  - ���ؽ�ת��, 5/6�ؽ�
	 *
	 * ���أ�int - 0�ɹ�, ��������
	 ******************************************************************************/
	virtual int IKine(IN double gdCPos[], IN double gdJCurr[], OUT double gdJPos[]) = 0;
	
	/******************************************************************************
	 * ������Vel_FKine()
	 * ���ܣ��ٶ����, ��������ϵ�ٶ�
	 *
	 * ���룺double* gdJPos - ��ǰ�ؽ�ת��, 5/6�ؽ�, deg
	 *       double* gdJVel - ��ǰ�ؽ��ٶ�, 5/6�ؽ�, deg/s
	 * �����double* gdCVel - ĩ���ٶ�, [vx,vy,vz,wx,wy,wz], mm/s, deg/s
	 *
	 * ���أ�int - 0�ɹ�, ��������
	 ******************************************************************************/
	virtual int Vel_FKine(IN double gdJPos[], IN double gdJVel[], OUT double gdCVel[]) = 0;
	
	/******************************************************************************
	 * ������Vel_IKine()
	 * ���ܣ��ٶ����
	 *
	 * ���룺double gdJPos[] - ��ǰ�ؽ�ת��, 5/6�ؽ�, deg
	 *       double gdCVel[] - ��ǰĩ���ٶ�, [vx,vy,vz,wx,wy,wz], mm/s, deg/s
	 * �����double gdJVel[] - �ؽ��ٶ�, 5/6�ؽ�, deg/s
	 *
	 * ���أ�int - 0�ɹ�, ��������
	 ******************************************************************************/
	virtual int Vel_IKine(IN double gdJPos[], IN double gdCVel[], OUT double gdJVel[]) = 0;
protected:
	// ���Ƕȱ任Ϊ(-360,0)��(0,+360)��Χ��
	void RadInRange(double* pdRad, double* pdDeg);
};


/*****************************************************************************
 *  ��ؽ������������˶�ѧ - G1
 *****************************************************************************/
class Kine_CR_FiveDoF_G1: public Kine
{
public:
	// ��ʼ���˳� 
	void Set_Length(IN double gdLen[6]);
	// ����
	int FKine(IN double gdJPos[5], OUT double gdCPos[6]);
	// ���
	int IKine(IN double gdCPos[6], IN double gdJCurr[5], OUT double gdJPos[5]);
	// �ٶ�����
	int Vel_FKine(IN double gdJPos[5], IN double gdJVel[5], OUT double gdCVel[6]);
	// �ٶ����
	int Vel_IKine(IN double gdJPos[5], IN double gdCVel[6], OUT double gdJVel[5]);

	int FKine_Inc(IN double gdJPos[5], IN double inc[3], OUT double gdCPos[3]);
	double getl1()
	{
		return m_dL2;
	}
private:
	double m_dL1;
	double m_dL2;
	double m_dL3;
	double m_dL4;
	double m_dL5;

};

/*****************************************************************************
 *  ��ؽ������������˶�ѧ-G2
 *****************************************************************************/
class Kine_CR_FiveDoF_G2: public Kine
{
public:
	// ��ʼ���˳� 
	void Set_Length(IN double gdLen[6]);
	// ����
	int FKine(IN double gdJPos[5], OUT double gdCPos[6]);
	// ���
	int IKine(IN double gdCPos[6], IN double gdJCurr[5], OUT double gdJPos[5]);
	// �ٶ�����
	int Vel_FKine(IN double gdJPos[5], IN double gdJVel[5], OUT double gdCVel[6]);
	// �ٶ����
	int Vel_IKine(IN double gdJPos[5], IN double gdCVel[6], OUT double gdJVel[5]);

	int FKine_Inc(IN double gdJPos[5], IN double inc[3], OUT double gdCPos[3]);
	
private:
	Kine_CR_FiveDoF_G1 kine;
};

/*****************************************************************************
 *  ��ؽڴ�����е���˶�ѧ��
 *****************************************************************************/
class Kine_IR_FiveDoF: public Kine
{
public:
	// ��ʼ���˳� 
	void Set_Length(IN double gdLen[5]);
	void Set_Tool(IN double gdTool[6]);
	//��¼�任����
	//void FKineMatrix(IN double gdJPos[6]);

	// ����
	int FKine(IN double gdJPos[5], OUT double gdCPos[6]);
	// ���
	int IKine(IN double gdCPos[6], IN double gdJCurr[5], OUT double gdJPos[5]);
	// �ٶ�����
	int Vel_FKine(IN double gdJPos[5], IN double gdJVel[5], OUT double gdCVel[6]);
	// �ٶ����
	int Vel_IKine(IN double gdJPos[5], IN double gdCVel[6], OUT double gdJVel[5]);
	// š��ĸ���������
	int IKine_s(double gdCPos[], double gdJCurr[], double gdJPos[]);

	double m_dL_GetMatrix[6];

private:
	double m_dL1;
	double m_dL2;
	double m_dL3;
	double m_dL4;
	double m_dL5;
	double m_dTool[6];

	Kine_CR_FiveDoF_G1 kine;
};

/*****************************************************************************
 *  ���ؽڴ�����е���˶�ѧ��
 *****************************************************************************/
class Kine_IR_SixDoF: public Kine
{
public:
	// ��ʼ���˳� 
	void Set_Length(IN double gdLen[6]);
	void Set_Tool(IN double gdTool[6]);

	// ����
	int FKine(IN double gdJPos[6], OUT double gdgdCPos[6]);
	// ���
	int IKine(IN double gdCPos[6], IN double gdJCurr[6], OUT double gdJPos[6]);
	// �ٶ�����
	int Vel_FKine(IN double gdJPos[6], IN double gdJVel[6], OUT double gdCVel[6]);
	// �ٶ����
	int Vel_IKine(IN double gdJPos[6], IN double gdCVel[6], OUT double gdJVel[6]);

private:
	double m_dL1;
	double m_dL2;
	double m_dL3;
	double m_dL4;
	double m_dL5;
	double m_dL6;
	double m_dTool[6];
};


void Trans_PosToMtx(double* pos, MtxKine* output, int inv);
void Trans_MtxToPos(MtxKine* input, double* outpos);
void Mtx_Multiply(MtxKine* input, MtxKine* middle, MtxKine* output, int inv);
void Robot_IncreTransTool(IN double* currpos, IN double* increpos, OUT double* outpos);

#endif
