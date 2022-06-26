#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


class Operation {//���� -- ������
protected:
	double numberA;
	double numberB;
public:
	double getA() {
		return numberA;
	}
	void setA(double number) {
		this->numberA = number;
	}
	double getB() {
		return numberB;
	}
	void setB(double number) {
		this->numberB = number;
	}

	virtual double getResult() = 0;
};

class OperationAdd : public Operation {//���� -- �ӷ���
public:
	double getResult() {
		double result = 0;
		result = numberA + numberB;
		return result;
	}
};

class OperationSub : public Operation {//���� -- ������
public:
	double getResult() {
		double result = 0;
		result = numberA - numberB;
		return result;
	}
};

class OperationMul : public Operation {//���� -- �˷���
public:
	double getResult() {
		double result = 0;
		result = numberA * numberB;
		return result;
	}
};

class OperationDiv : public Operation {//���� -- ������
public:
	double getResult() {
		double result = 0;
		if (numberB != 0) {
			result = numberA / numberB;
			return result;
		}
		else {
			cout << "����������Ϊ0" << endl;
			return 0;
		}
	}
};

class OperationFactory {//���㹤����
public:
	Operation* createOperation(char type) {
		Operation* open = nullptr;
		switch (type) {
		case'+':
			open = new OperationAdd();
			break;
		case'-':
			open = new OperationSub();
			break;
		case'*':
			open = new OperationMul();
			break;
		case'/':
			open = new OperationDiv();
			break;
		}
		return open;
	}
};

//������
int main() {
	Operation* open = nullptr;
	open = OperationFactory().createOperation('*');
	open->setA(6);
	open->setB(2);
	cout << open->getResult() << endl;
	if (open != nullptr) {
		delete open;
		open = nullptr;//�����ΪҰָ��
	}

	Operation* open2 = nullptr;
	open2 = OperationFactory().createOperation('/');
	open2->setA(1);
	open2->setB(0);
	cout << open2->getResult() << endl;
	if (open2 != nullptr) {
		delete open2;
		open2 = nullptr;//�����ΪҰָ��
	}
	return 0;
 }