#include<iostream>
using namespace std;

/**
*
*������������һ��ʵ����Ƶ�Ŀ��ƣ����������¹��ܣ�
* 1.���Դ򿪶���
* 2.���Թرն���
* 3.���Դ���˷�
* 4.���Թر���˷�
* 5.��˷����ѡ��������ʽ
* 6.���Կ���ʱ��ʼ���򿪶�����������ʼ��ͬʱ��ʼ������˷��ѡ��Ĭ������
*/

/**
*������
* 1.��˷����ѡ��������ʽ��������˷�mike�������soundCard����һ�������
* 2.���Կ����ȼ�������������ʼ��ʱҪ��ʼ����˷磬��˶�����earphone��InitʱҪinit mike�࣬������һ�����
* 3.mike���soundCard��ֱ��ͨ�ţ�mike���earphone��ֱ��ͨ�ţ�����soundCard���earphone�಻Ӧֱ��ͨ��
* 4.һ������������˽��Խ��Խ�ã������soundCard���м���һ��chooseType()����
*/

/**
* @brief ������
* ���Դ򿪶������رն�����������ʼ����ͬʱ��ʼ����˷�
*/
class earphone { 
public:
	void Init(mike* pmike) {
		openVoice();
		pmike->Init();
	}
	//����
	void openVoice() {};
	void closeVoice() {};
};

/**
* @brief ��˷���
* ���Դ���˷磬�ر���˷磬��˷��ʼ��ʱ��ѡ��Ĭ������
*/
class mike {
private:
	soundCard* m_soundCard;
public:
	void Init() {
		openMike();
		m_soundCard = new soundCard();
		m_soundCard->chooseType(1);
	}
	//��˷�
	void openMike() {};
	void closeMike() {};
};

/**
* @brief ������
* ѡ���������ͣ���3�֣���һ����Ĭ��������
*/
class soundCard {
public:
	void chooseType(int i) {};
private:
	void soundCardType1() {};
	void soundCardType2() {};
	void soundCardType3() {};
};

