#include<iostream>
using namespace std;




class mRead{ // 读抽象类 -- 父类
public:
	virtual string story() = 0;
};

class book1 :public mRead { // 西游记 -- 子类 (底层模块)
public:
	string story() {
		return "《西游记》";
	}
};

class book2 :public mRead { // 水浒传 -- 子类 (底层模块)
public:
	string story() {
		return "《水浒传》";
	}
};

class book3 :public mRead { // 三国演义 -- 子类 (底层模块)
public:
	string story() {
		return "《三国演义》";
	}
};

class mother { // 麻麻 -- 高层模块
public:
	void tellStory(mRead* r) {
		cout << "麻麻讲" << r->story() << "的故事" << endl;
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

	//依赖倒转原则体现：高层（mother）与底层（book1 book2 book3）都依赖于抽象类mRead
	return 0;
}
