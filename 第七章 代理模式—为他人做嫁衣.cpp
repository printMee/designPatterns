#include<iostream>
#include<string>
#include<vector>
using namespace std;



class schoolGirl {//被追求者类
private:
	string name;//姓名
	string birthday;//生日
public:
	schoolGirl(string name=nullptr) :name(name) {}
	string getName() {
		return name;
	}
	string getBirthday() {
		return birthday;
	};
};

class giveGift {//送礼物类 -- 抽象类
public:
	virtual void giveDolls() = 0;
	virtual void giveFlowers() = 0;
	virtual void giveChocolate() = 0;
};

class pursue:public giveGift{//追求者类 -- 子类
private:
	schoolGirl *mm=nullptr;
public:
	pursue(schoolGirl *girl) {
		mm = girl; //指向girl的内存空间
	}
	void giveDolls() {
		cout << "送" <<mm->getName()<<"洋娃娃"<<endl;
	}
	void giveFlowers() {
		cout << "送" << mm->getName()<< "花花" << endl;
	}
	void giveChocolate() {
		cout << "送" << mm->getName()<< "巧克力" << endl;
	}
};

class proxy :public giveGift {//代理类 -- 子类
private:
	pursue *gg=nullptr;
public:
	proxy(schoolGirl *girl) {
		gg = new pursue(girl);//在堆区创建一个pursue类型的对象，返回的是该对象的指针
	}
	void giveDolls() {
		gg->giveDolls();
	}
	void giveFlowers() {
		gg->giveFlowers();
	}
	void giveChocolate() {
		gg->giveChocolate();
	}
	~proxy() {
		if (gg != nullptr)
			delete gg;
	}
};
int main() {
	schoolGirl *mm = new schoolGirl("娇娇");
	//主函数只认识代理者类的对象
	proxy *daiLi = new proxy(mm); //int a=1; int *p = &a
								  //需要注意的是， int* 是指针变量的类型，而后面的 p 才是变量名，用来存储地址，
								  //因此地址 &a 是赋值给 p 而不是 *p 的。
	//由代理者执行，客户端不认识追求者
	daiLi->giveDolls();
	daiLi->giveFlowers();
	daiLi->giveChocolate();
	return 0;
}