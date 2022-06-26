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
		cout << "酷炫的";
	}
};

class Decorator : public Component {
private://父类的私有成员在子类是不可见的
	Component* mComponent; //只是声明指针成员,没有new分配空间不需要析构
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
		decorate(); //装饰机械键盘：通过父类的decorate()函数调用父类私有成员mComponent的方法
		cout << "机械键盘!" << endl;
	}
};

class ConcreteDecoratorB :public Decorator {
public:
	void run() {
		decorate();//装饰鼠标
		cout << "鼠标!" << endl;
	}
};

//客户端
int main() {
	ConcreteComponent* pc = new ConcreteComponent;
	ConcreteDecoratorA* A = new ConcreteDecoratorA();
	ConcreteDecoratorB* B = new ConcreteDecoratorB();
	A->setComponent(pc);//使用A来装饰pc
	A->run();
	B->setComponent(A);//使用B来装饰A
	B->run();
	if (pc) delete pc;
	if (A) delete A;
	if (B) delete B;
	getchar();
	return 0;
}