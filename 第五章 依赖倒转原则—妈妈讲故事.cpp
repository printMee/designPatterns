#include<iostream>
using namespace std;




class mRead{ // �������� -- ����
public:
	virtual string story() = 0;
};

class book1 :public mRead { // ���μ� -- ���� (�ײ�ģ��)
public:
	string story() {
		return "�����μǡ�";
	}
};

class book2 :public mRead { // ˮ䰴� -- ���� (�ײ�ģ��)
public:
	string story() {
		return "��ˮ䰴���";
	}
};

class book3 :public mRead { // �������� -- ���� (�ײ�ģ��)
public:
	string story() {
		return "���������塷";
	}
};

class mother { // ���� -- �߲�ģ��
public:
	void tellStory(mRead* r) {
		cout << "���齲" << r->story() << "�Ĺ���" << endl;
	}
};

int main() {
	mother* mtr = new mother();
	mRead* bk1 = new book1();
	mRead* bk2 = new book2();
	mRead* bk3 = new book3();
	mtr->tellStory(bk1);
	mtr->tellStory(bk2);
	mtr->tellStory(bk3);

	//������תԭ�����֣��߲㣨mother����ײ㣨book1 book2 book3���������ڳ�����mRead
	return 0;
}
