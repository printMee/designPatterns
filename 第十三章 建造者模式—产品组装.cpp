#include<iostream>
#include<vector>
using namespace std;

/**
* @brief 产品类
* 实现产品部件的添加、展示功能。
*/
class product { 
private:
	vector<string> list; // 部件的数组
public:
	product() {
		list.reserve(5); // 默认先分配5个连续的内存空间
	}
	//添加部件
	void add(string part) {
		list.push_back(part);
	}
	//展示部件
	void show() {
		for (auto c : list) {
			cout << c << " ";
		}
		cout << endl;
	}
};

/**
* @brief 建造类
* 提供了一个建造复杂对象的抽象接口
*/
class builder { // 抽象建造类
public:
	virtual void builderPartA() = 0;
	virtual void builderPartB() = 0;
	virtual product* getResult() = 0;
};

/**
* @brief 建造者类1
* 提供第一种组成产品的部件：A和B
*/
class concreteBuilder1 :public builder{ // 具体建造者类1  
private:
	product *p = new product();
public:
	void builderPartA() {
		p->add("部件A");
	}
	void builderPartB() {
		p->add("部件B");
	}
	product* getResult() {
		return p;
	}
};

/**
* @brief 建造者类2
* 提供第二种组成产品的部件：X和Y
*/
class concreteBuilder2 :public builder { // 具体建造者类2
private:
	product* p = new product();
public:
	void builderPartA() {
		p->add("部件X");
	}
	void builderPartB() {
		p->add("部件Y");
	}
	product* getResult() {
		return p;
	}
};

/**
* @brief 指挥者类
* 用来指挥产品的组装过程
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
	//指挥者用concreteBuilder1提供的方法来建造产品
	builder* b1= new concreteBuilder1();
	d->construct(b1);
	product* p1 = b1->getResult();
	cout << "产品1组成：";
	p1->show();
	//指挥者用concreteBuilder2提供的方法来建造产品
	builder* b2 = new concreteBuilder2();
	d->construct(b2);
	product* p2 = b2->getResult();
	cout << "产品2组成：";
	p2->show();
	return 0;
}