#include<iostream>
using namespace std;


class stock1 { // ��Ʊ1
public:
	void buy() {};
	void sell() {};
};

class stock2 { // ��Ʊ2
public:
	void buy() {};
	void sell() {};
};

class nationalDebt { // ��ծ
public:
	void buy() {};
	void sell() {};
};

class realty { // ���ز�
public:
	void buy() {};
	void sell() {};
};

class fund { // ��������Ͷ���߷�ɢ���ʽ�������������רҵ�ľ����˽��й���Ͷ���ڹ�Ʊ��ծȯ����������
								//������Ͷ�ʵ���������Ͷ�������У����������ȡһ���������йܹ�����á�
public:
	void buyFund() {
		gu1->buy();
		gu2->buy();
		d1->buy();
		r1->buy();
	};
	void sellFund() {
		gu1->sell();
		gu2->sell();
		d1->sell();
		r1->sell();
	};
	fund() {
		gu1 = new stock1();
		gu2 = new stock2();
		d1 = new nationalDebt();
		r1 = new realty();
	}
private:
	stock1 *gu1;
	stock2 *gu2;
	nationalDebt *d1;
	realty *r1;
};

int main() {
	fund *jijin = new fund();
	jijin->buyFund();
	jijin->sellFund();
	return 0;
}