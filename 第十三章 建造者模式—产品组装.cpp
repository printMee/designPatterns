#include<iostream>
#include<vector>
using namespace std;

/**
* @brief ��Ʒ��
* ʵ�ֲ�Ʒ��������ӡ�չʾ���ܡ�
*/
class product { 
private:
	vector<string> list; // ����������
public:
	product() {
		list.reserve(5); // Ĭ���ȷ���5���������ڴ�ռ�
	}
	//��Ӳ���
	void add(string part) {
		list.push_back(part);
	}
	//չʾ����
	void show() {
		for (auto c : list) {
			cout << c << " ";
		}
		cout << endl;
	}
};

/**
* @brief ������
* �ṩ��һ�����츴�Ӷ���ĳ���ӿ�
*/
class builder { // ��������
public:
	virtual void builderPartA() = 0;
	virtual void builderPartB() = 0;
	virtual product* getResult() = 0;
};

/**
* @brief ��������1
* �ṩ��һ����ɲ�Ʒ�Ĳ�����A��B
*/
class concreteBuilder1 :public builder{ // ���彨������1  
private:
	product *p = new product();
public:
	void builderPartA() {
		p->add("����A");
	}
	void builderPartB() {
		p->add("����B");
	}
	product* getResult() {
		return p;
	}
};

/**
* @brief ��������2
* �ṩ�ڶ�����ɲ�Ʒ�Ĳ�����X��Y
*/
class concreteBuilder2 :public builder { // ���彨������2
private:
	product* p = new product();
public:
	void builderPartA() {
		p->add("����X");
	}
	void builderPartB() {
		p->add("����Y");
	}
	product* getResult() {
		return p;
	}
};

/**
* @brief ָ������
* ����ָ�Ӳ�Ʒ����װ����
*/
class director {
public:
	void construct(builder* b){
		b->builderPartA();
		b->builderPartB();
	}
};


int main() {
	director* d = new director();
	//ָ������concreteBuilder1�ṩ�ķ����������Ʒ
	builder* b1= new concreteBuilder1();
	d->construct(b1);
	product* p1 = b1->getResult();
	cout << "��Ʒ1��ɣ�";
	p1->show();
	//ָ������concreteBuilder2�ṩ�ķ����������Ʒ
	builder* b2 = new concreteBuilder2();
	d->construct(b2);
	product* p2 = b2->getResult();
	cout << "��Ʒ2��ɣ�";
	p2->show();
	return 0;
}