#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
办公室员工A、B、C在看股票看电影，
这时老板回来了，被A、B、C重金贿赂后的前台发出通知给A、B、C，A、B、C收到通知后赶紧关电脑，
关股票窗口，装作在干活。
*/

/**
* @brief 抽象观察者类
* 具体观察者提供一个接口
*/
class observer {
protected:
	string mNameObserver;
public:
	virtual void update(string strEvent) = 0;
	
	string getName() {
		return this->mNameObserver;
	}
	void setName(string str) {
		mNameObserver = str;
	}
};

/**
* @brief 抽象通知者类
* 具体通知者提供一个接口
*/
class subject {
public:
	virtual void addObserver(observer* b) = 0;
	virtual void delObserver(observer* b) = 0;
	virtual void notify(string strEvent) = 0;
};

/**
* @brief 具体观察者
* 观察者更新状态的方法
*/
class cObserver :public observer {
public:
	virtual void update(string strEvent) {
		cout << mNameObserver << "get" << strEvent << "call!" << endl;
	}
};
/**
* @brief 具体通知者
* 通知所有观察者
*/
class boss :public subject {
private:
	vector<observer*> listObserver;
public:
	//添加观察者
	void addObserver(observer* b) {
		listObserver.push_back(b);
	}
	//删除观察者
	void delObserver(observer* b) {
		int i = 0;
		for (auto a : listObserver) {
			if (a->getName() == b->getName())
				listObserver.erase(listObserver.begin() + i);
			i++;
		}
	}
	//通知观察者
	void notify(string strEvent) {
		if (!listObserver.empty()) {
			for (auto a : listObserver) {
				a->update(strEvent);
			}
		}
	}

};
int mian() {
	string str1 = "Mike";
	string str2 = "Kobe";
	cObserver* ob1=new cObserver();
	ob1->setName(str1);
	cObserver* ob2=new cObserver();
	ob1->setName(str2);
	boss* bs=new boss();
	bs->addObserver(ob1);
	bs->addObserver(ob2);
	bs->notify("老板来了");
	return 0;
}