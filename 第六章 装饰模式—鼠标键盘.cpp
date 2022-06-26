#include<iostream>
#include<vector>

using namespace std;


class Component {
public:
	virtual ~Component() {};
	virtual void decorate() = 0;
};

class ConcreteComponent : public Component {
public:
	void decorate() {
		cout << "���ŵ�";
	}
};

class Decorator : public Component {
private://�����˽�г�Ա�������ǲ��ɼ���
	Component* mComponent; //ֻ������ָ���Ա,û��new����ռ䲻��Ҫ����
public:
	Decorator():mComponent(nullptr) {};
	void decorate() {
		if (this->mComponent)
			this->mComponent->decorate();
	}
	void setComponent(Component* c) {
		this->mComponent = c;
	}
};

class ConcreteDecoratorA :public Decorator {
public:
	void run() {
		decorate(); //װ�λ�е���̣�ͨ�������decorate()�������ø���˽�г�ԱmComponent�ķ���
		cout << "��е����!" << endl;
	}
};

class ConcreteDecoratorB :public Decorator {
public:
	void run() {
		decorate();//װ�����
		cout << "���!" << endl;
	}
};

//�ͻ���
int main() {
	ConcreteComponent* pc = new ConcreteComponent;
	ConcreteDecoratorA* A = new ConcreteDecoratorA();
	ConcreteDecoratorB* B = new ConcreteDecoratorB();
	A->setComponent(pc);//ʹ��A��װ��pc
	A->run();
	B->setComponent(A);//ʹ��B��װ��A
	B->run();
	if (pc) delete pc;
	if (A) delete A;
	if (B) delete B;
	getchar();
	return 0;
}