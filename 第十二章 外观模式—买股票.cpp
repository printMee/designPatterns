#include<iostream>
using namespace std;


class stock1 { // 股票1
public:
	void buy() {};
	void sell() {};
};

class stock2 { // 股票2
public:
	void buy() {};
	void sell() {};
};

class nationalDebt { // 国债
public:
	void buy() {};
	void sell() {};
};

class realty { // 房地产
public:
	void buy() {};
	void sell() {};
};

class fund { // 基金：它将投资者分散的资金集中起来，交由专业的经理人进行管理，投资于股票、债券、外汇等领域，
								//而基金投资的收益归持有投资者所有，管理机构收取一定比例的托管管理费用。
public:
	void buyFund() {
		gu1->buy();
		gu2->buy();
		d1->buy();
		r1->buy();
	};
	void sellFund() {
		gu1->sell();
		gu2->sell();
		d1->sell();
		r1->sell();
	};
	fund() {
		gu1 = new stock1();
		gu2 = new stock2();
		d1 = new nationalDebt();
		r1 = new realty();
	}
private:
	stock1 *gu1;
	stock2 *gu2;
	nationalDebt *d1;
	realty *r1;
};

int main() {
	fund *jijin = new fund();
	jijin->buyFund();
	jijin->sellFund();
	return 0;
}