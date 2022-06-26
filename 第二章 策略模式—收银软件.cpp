#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class cashSuper { //抽象类 -- 基类（策略类）
public:
	virtual double acceptCash(double money) = 0;
};

class cashNormal :public cashSuper {//正常收费类 -- 子类
public:
	double acceptCash(double money) {
		return money;
	}
};

class cashRebate :public cashSuper {//打折收费类 -- 子类
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

class cashReturn :public cashSuper {//返回现金类 -- 子类
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
			//floor(x)不大于x的最大整数
		return result;
	}
};

class cashContext {//cash上下文类 -- 封装策略类的使用
private:
	cashSuper* cash;
public:
	cashContext(int type) :cash(nullptr) {
		switch (type) {
		case 1:
			cash = new cashNormal();
			break;
		case 2:
			cash = new cashRebate(0.8);//打八折
			break;
		case 3:
			cash = new cashReturn(300, 100);//满300减100
			break;
		}
	}
	~cashContext() {//析构函数
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
	//正常收费
	cashContext *cashNormal = new cashContext(1);
	totalPrice = cashNormal->getResult(800);
	cout << "正常收费：" << totalPrice << endl;
	//打八折收费
	cashContext* cashRebate = new cashContext(2);
	totalPrice = cashRebate->getResult(800);
	cout << "打八折收费：" << totalPrice << endl;
	//满300减100收费
	cashContext* cashReturn = new cashContext(3);
	totalPrice = cashReturn->getResult(800);
	cout << "满300减100收费：" << totalPrice << endl;
	return 0;
}