#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class cashSuper { //������ -- ���ࣨ�����ࣩ
public:
	virtual double acceptCash(double money) = 0;
};

class cashNormal :public cashSuper {//�����շ��� -- ����
public:
	double acceptCash(double money) {
		return money;
	}
};

class cashRebate :public cashSuper {//�����շ��� -- ����
private:
	double moneyRebate;
public:
	cashRebate(double moneyRebate) {
		this->moneyRebate = moneyRebate;
	}
	double acceptCash(double money) {
		return money * moneyRebate;
	}
};

class cashReturn :public cashSuper {//�����ֽ��� -- ����
private:
	double moneyCondition;
	double moneyReturn;
public:
	cashReturn(double moneyCondition, double moneyReturn) {
		this->moneyCondition = moneyCondition;
		this->moneyReturn = moneyReturn;
	}
	double acceptCash(double money) {
		double result = money;
		if (money > moneyCondition)
			result = money - floor(money / moneyCondition) * moneyReturn;
			//floor(x)������x���������
		return result;
	}
};

class cashContext {//cash�������� -- ��װ�������ʹ��
private:
	cashSuper* cash;
public:
	cashContext(int type) :cash(nullptr) {
		switch (type) {
		case 1:
			cash = new cashNormal();
			break;
		case 2:
			cash = new cashRebate(0.8);//�����
			break;
		case 3:
			cash = new cashReturn(300, 100);//��300��100
			break;
		}
	}
	~cashContext() {//��������
		if (cash != nullptr) {
			delete cash;
			cash = nullptr;
		}
	}
	double getResult(double money) {//getResult
		return cash->acceptCash(money);
	}
};

int main() {
	double totalPrice = 0;
	//�����շ�
	cashContext *cashNormal = new cashContext(1);
	totalPrice = cashNormal->getResult(800);
	cout << "�����շѣ�" << totalPrice << endl;
	//������շ�
	cashContext* cashRebate = new cashContext(2);
	totalPrice = cashRebate->getResult(800);
	cout << "������շѣ�" << totalPrice << endl;
	//��300��100�շ�
	cashContext* cashReturn = new cashContext(3);
	totalPrice = cashReturn->getResult(800);
	cout << "��300��100�շѣ�" << totalPrice << endl;
	return 0;
}