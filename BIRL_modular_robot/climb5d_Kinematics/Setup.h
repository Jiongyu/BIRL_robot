#ifndef __SETUP_H__
#define __SETUP_H__
/*****************************************************************************
 *        Robot����������Robotϵͳ�ļ�������                                 *
 *        SCUT, 2011                                                         *
 *        Author :                                                           *
 *        Version number :  0.10                                             *
 *        Date :            2011-04-22                                       *
 *****************************************************************************/
#include "Robot.h"

//#include "TaskControl.h"
//#include "ServoControl.h"
//#include "Monitor.h"
//#include "PumpControl.h"
//#include "masterdlg.h"

#define unchar  unsigned char


#define USING_CBUTTONST  // CButtonSTʹ��
//#define USING_DAQ_FSR  // FSRʹ��

#define WM_MY_MESSAGE            WM_USER + 101  // ��Ϣ - ������
#define WM_WELCOME_HIDE_MESSAGE  WM_USER + 102  // ��Ϣ - Welcome����
#define WM_MAIN_DLG_MESSAGE      WM_USER + 103  // ��Ϣ - ������
#define WM_SETUPDLG_MESSAGE      WM_USER + 104  // ��Ϣ - ��������
#define WM_FILE_OPERATE_MESSAGE  WM_USER + 105  // ��Ϣ - �ļ�����

#define SW_WELCOME_HIDE        1   // ��Ϣ���� - Welcome������ʾ
#define SW_WELCOME_SHOW        2   // ��Ϣ���� - Welcome��������
#define SW_WELCOME_EXIT        3   // ��Ϣ���� - Welcome�����˳�

#define MY_FILE_NEW            1   // ��Ϣ���� - �½��ļ�
#define MY_FILE_OPEN           2   // ��Ϣ���� - ���ļ�
#define MY_FILE_CLOSE          3   // ��Ϣ���� - �ر��ļ�
#define MY_FILE_SAVE           4   // ��Ϣ���� - �����ļ�
#define MY_FILE_SAVEAS         5   // ��Ϣ���� - �ļ����Ϊ

#define MY_FILE_GET_STARPOINT  7   // ��Ϣ���� - ��ȡ����Ƕ���
#define MY_FILE_MOVE_SINGLE    8   // ��Ϣ���� - �����˶�
#define MY_FILE_MOVE_ALL       9   // ��Ϣ���� - ���������˶�
#define MY_FILE_MOVE_FROMHERE 10   // ��Ϣ���� - �ӵ�ǰλ�����������˶�
#define MY_FILE_MOVE_STOP     11   // ��Ϣ���� - ֹͣ�˶�

#define MY_TEST_MOVES         15


#define MY_MONITORDLG_CLOSE 1
#define MY_TOLLDLG_CLOSE    2
#define MY_OPENGLDLG_CLOSE  3
#define MY_FSRDLG_CLOSE     4 
#define MY_MASTERDLG_CLOSE  5
#define MY_WHEELDLG_CLOSE	6


#define WRITE_MODE_ROBOTLEN  1   // д�ļ����� - �˳�
#define WRITE_MODE_MOTORRAT  2   // - ���ٱ�
#define WRITE_MODE_JPOSLIM   3   // - ������
#define WRITE_MODE_JNEGLIM   4   // - ������
#define WRITE_MODE_TEACHLIM  5   // - ʾ�̲���
#define WRITE_MODE_AUTOLIM   6   // - ���ֲ���

#define ROBOT_FILE_FOLDER  "D:/Robot/"                   // ϵͳ�ļ���·��
#define ROBOT_FILE_PATH    "D:/Robot/RobotPara/"         // ϵͳ�ļ�·��
#define ROBOT_FILE_CME2    "D:/Program Files/Copley Motion/CME 2/CME2.exe" // ģ���ʽ���·��
#define ROBOT_PATH_CME2    "D:/Program Files/Copley Motion/CME 2/"         // ģ���ʽ����ļ���·��

// ȫ�־�̬����
/*class Robot
{
public:
/////////////////////////////////////////////////////////////////////////// ����
// [[ ������̬�����
	static ServoControl I_Servo; // �ŷ�������
	static Monitor      I_Monit; // �����
	static TaskControl  I_Task;  // Task����
	static PumpControl  I_Pump;  // �������ÿ�����
//	static CMasterDlg	I_Master;// ����������
// ]] ������̬�����

// [[ ������̬����
	static unchar axisNum;
	static unchar robotMode;  // ģʽ, 1����,2����,3��е��
	static unchar robotEndMode;	//ĩ��ִ��������
	static unchar actualTool; // ��ǰ��צ, #1, #2
	static unchar runMode;    // �˶�ģʽ, 1ʾ��, 2����
	static unchar teachMode;  // ʾ��ģʽ, 1�ؽ�ʾ��, 2�ѿ���ʾ��
	static bool ifMonitor;	  // �����Ƿ���
	static bool ifTool;
	static bool ifMaster;
	static bool ifWheel;
	static double robotLen[7]; // �����˸˳�
	static double motorRat[MAX_AXIS_NUM]; // ���ٱ�
	static double posLim[MAX_AXIS_NUM];   // ������
	static double negLim[MAX_AXIS_NUM];   // ������
	// ʾ�����Ʋ���, �ؽ��ٶ�|���ٶ�|�ѿ������ٶ�|�߼��ٶ�|���ٶ�|�Ǽ��ٶ�
	static double teachLim[6];
	static double autoLim[7];
// ]] ������̬����
};*/

// ϵͳ�ļ�����
class RobotFile
{
public:
///////////////////////////////////////////////////////////// ���졢��������ʼ��
	RobotFile();
	~RobotFile();	
	bool Init();  // ��ʼ��ȫ�ֱ���

public:
/////////////////////////////////////////////////////////////////////// ���÷���
// [[ ����
	bool Set_RobotMode(IN unchar cMode);   // ���û����˹���ģʽ
	bool Set_ActTool(IN unchar cTool);     // ���õ�ǰ����
	bool Set_RunMode(IN unchar cMode);     // �����˶�ģʽ
	bool Set_TeachMode(IN unchar cMode);   // ����ʾ��ģʽ
	bool Set_IfStartDlg(IN int nDlg, IN bool bIf);// �����Ƿ�򿪴���
	bool Set_RobotLen(IN double dLen[]);   // ���û����˸˳�
	bool Set_MotorRat(IN double dRat[]);   // ���ü��ٱ�
	bool Set_JPosLim(IN double dLim[]);    // ����������
	bool Set_JNegLim(IN double dLim[]);    // ���ø�����
	bool Set_TeachLim(IN double dLim[]);   // ����ʾ������
	bool Set_AutoLim(IN double dLim[]);    // ������������
	bool Set_SecZeroPos(IN double dPos[]); // ���ø�λλ��
	bool Set_ZeroVel(IN int vel);          // ���û��㸴λ�ٶȵȼ�
// ]] ����

// [[ ��ȡ
	/*
	unchar Get_RobotMode() const;
	unchar Get_ActTool() const;
	unchar Get_RunMode() const;
	unchar Get_TeachMode() const;
	bool Get_IfStartMonitor() const;	
	void Get_RobotLen(OUT double dLen[]) const;
	void Get_MotorRat(OUT double dRat[]) const;
	void Get_JPosLim(OUT double dLim[]) const;
	void Get_JNegLim(OUT double dLim[]) const;
	*/
	//bool Get_SecZeroPos(OUT double dPos[]); // ��ȡ��λλ��
	//bool Get_SecZeroPos(OUT CString str[]); // ��ȡ��λλ���ַ���
	//bool Get_ZeroVel(OUT int& vel);         // ��ȡ���㸴λ�ٶȵȼ�
// ]] ��ȡ

/*private:
	/////////////////////////////////////////////////////////////////////// ˽�з���
	CStdioFile m_file;
	bool Read_File(IN CString path, OUT CString& str);
	bool Read_File(IN CString path, OUT CString str[], IN int num, IN int mode);
	bool Write_File(IN CString path, IN CString str);
	bool Write_File(IN CString path, IN CString str[], IN int num);*/
};

#endif
