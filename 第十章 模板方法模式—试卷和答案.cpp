#include<iostream>
using namespace std;

class testPaper { // ������ -- ʵ��һ��ģ�巽��������Ǽ�
public:
	void Q1() {
		cout << "Q1:����õ����������˹������������콣�������������������ǡ���a.��ĥ���� b.����� c.���ٺϽ�� d.̼����ά" << std::endl;
		cout << "�𰸣�" << Answer1() << endl;
	}
	void Q2()
	{
		cout << "Q2:�������Ӣ��½��˫�������黨����ɡ���a.ʹ����ֲ�ﲻ�ٺ��� b.ʹһ����ϡ������� c.�ƻ����Ǹ�����Ȧ����̬ƽ�� d.��ɸõ���ɳĮ��" << std::endl;
		cout << "�𰸣�" << Answer2() << endl;
	}
	void Q3()
	{
		cout << "Q3:�������ʹ��ɽʦͽ���ҹ�����Ż�²�ֹ��������Ǵ�򣬻�����ǿ�ʲôҩ����a.��˾ƥ�� b.ţ�ƽⶾƬ c.������ d.�����Ǻȴ���ţ��" << std::endl;
		cout << "�𰸣�" << Answer3() << endl;
	}
protected:
	virtual string Answer1() = 0;
	virtual string Answer2() = 0;
	virtual string Answer3() = 0;
};

class testPaperA :public testPaper {
public:
	virtual string Answer1() {
		return "b";
	}
	virtual string Answer2() {
		return "c";
	}
	virtual string Answer3() {
		return "a";
	}
};

class testPaperB :public testPaper {
public:
	virtual string Answer1() {
		return "c";
	}
	virtual string Answer2() {
		return "a";
	}
	virtual string Answer3() {
		return "b";
	}
};

int main() {
	cout << "paper of student A:" << endl;
	testPaper* studentA = new testPaperA();
	studentA->Q1();
	studentA->Q2();
	studentA->Q3();
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "paper of student B:" << endl;
	testPaper* studentB = new testPaperB();
	studentB->Q1();
	studentB->Q2();
	studentB->Q3();
	if(studentA!=nullptr)
		delete studentA;
	if(studentB!=nullptr)
		delete studentB;
	return 0;
}