#include<iostream>
using namespace std;

class testPaper { // 抽象类 -- 实现一个模板方法，定义骨架
public:
	void Q1() {
		cout << "Q1:杨过得到，后来给了郭靖，练成倚天剑、屠龙刀的玄铁可能是【】a.球磨铸铁 b.马口铁 c.高速合金钢 d.碳素纤维" << std::endl;
		cout << "答案：" << Answer1() << endl;
	}
	void Q2()
	{
		cout << "Q2:杨过、程英、陆无双铲除了情花，造成【】a.使这种植物不再害人 b.使一种珍稀物种灭绝 c.破坏了那个生物圈的生态平衡 d.造成该地区沙漠化" << std::endl;
		cout << "答案：" << Answer2() << endl;
	}
	void Q3()
	{
		cout << "Q3:蓝凤凰致使华山师徒、桃谷六仙呕吐不止，如果你是大夫，会给他们开什么药【】a.阿司匹林 b.牛黄解毒片 c.氟哌酸 d.让他们喝大量牛奶" << std::endl;
		cout << "答案：" << Answer3() << endl;
	}
protected:
	virtual string Answer1() = 0;
	virtual string Answer2() = 0;
	virtual string Answer3() = 0;
};

class testPaperA :public testPaper {
public:
	virtual string Answer1() {
		return "b";
	}
	virtual string Answer2() {
		return "c";
	}
	virtual string Answer3() {
		return "a";
	}
};

class testPaperB :public testPaper {
public:
	virtual string Answer1() {
		return "c";
	}
	virtual string Answer2() {
		return "a";
	}
	virtual string Answer3() {
		return "b";
	}
};

int main() {
	cout << "paper of student A:" << endl;
	testPaper* studentA = new testPaperA();
	studentA->Q1();
	studentA->Q2();
	studentA->Q3();
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "paper of student B:" << endl;
	testPaper* studentB = new testPaperB();
	studentB->Q1();
	studentB->Q2();
	studentB->Q3();
	if(studentA!=nullptr)
		delete studentA;
	if(studentB!=nullptr)
		delete studentB;
	return 0;
}