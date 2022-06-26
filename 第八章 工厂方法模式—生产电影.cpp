#include<iostream>
#include<string>
using namespace std;

class Movie { // �����Ʒ�� -- ��Ӱ
public:
	virtual string getMovie() = 0;
};

class ChineseMovie : public Movie { // �����Ʒ�� -- �й���Ӱ
public:
	string getMovie() {
		return "�������";
	}
};
class JapaneseMovie : public Movie { // �����Ʒ�� -- �ձ���Ӱ
public:
	string getMovie() {
		return "ǧ��ǧѰ";
	}
};
class AmericanMovie : public Movie { // �����Ʒ�� -- ������Ӱ
public:
	string getMovie() {
		return "������";
	}
};

class Factory {	// ���󹤳��� -- ������Ӱ
public:
	virtual Movie *createMovie() = 0;

};

class ChineseProducer :public Factory { // ���幤���� -- �й�������
public:
	Movie *createMovie() {
		return new ChineseMovie();
	}
};
class JapaneseProducer :public Factory { // ���幤���� -- �ձ�������
public:
	Movie* createMovie() {
		return new JapaneseMovie();
	}
};
class AmericanProducer :public Factory { // ���幤���� -- ����������
public:
	Movie* createMovie() {
		return new AmericanMovie();
	}
};

int main() {
	Factory* factoryA = new ChineseProducer();
	Movie* movieA = factoryA->createMovie();
	cout << movieA->getMovie() << endl;

	Factory* factoryB = new JapaneseProducer();
	Movie* movieB = factoryB->createMovie();
	cout << movieB->getMovie() << endl;

	Factory* factoryC = new AmericanProducer();
	Movie* movieC = factoryC->createMovie();
	cout << movieC->getMovie() << endl;
	if (factoryA != nullptr) {
		delete factoryA;
		factoryA = nullptr;
	}
	if (factoryB != nullptr) {
		delete factoryB;
		factoryB = nullptr;
	}
	if (factoryC != nullptr) {
		delete factoryC;
		factoryC = nullptr;
	}
	/*
	* ��������ģʽʵ��ʱ���ͻ�����Ҫ����ʵ������һ��������ʵ�ֲ�Ʒ�࣬ѡ���жϵ����⻹���ڣ�
	* ���������ǰѼ򵥹���ģʽ���ڲ��ж��߼��ƶ����˿ͻ��˴��������С�
	*/
	return 0;
}
