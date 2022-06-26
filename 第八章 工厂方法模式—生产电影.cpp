#include<iostream>
#include<string>
using namespace std;

class Movie { // 抽象产品类 -- 电影
public:
	virtual string getMovie() = 0;
};

class ChineseMovie : public Movie { // 具体产品类 -- 中国电影
public:
	string getMovie() {
		return "警察故事";
	}
};
class JapaneseMovie : public Movie { // 具体产品类 -- 日本电影
public:
	string getMovie() {
		return "千与千寻";
	}
};
class AmericanMovie : public Movie { // 具体产品类 -- 美国电影
public:
	string getMovie() {
		return "钢铁侠";
	}
};

class Factory {	// 抽象工厂类 -- 生产电影
public:
	virtual Movie *createMovie() = 0;

};

class ChineseProducer :public Factory { // 具体工厂类 -- 中国生产者
public:
	Movie *createMovie() {
		return new ChineseMovie();
	}
};
class JapaneseProducer :public Factory { // 具体工厂类 -- 日本生产者
public:
	Movie* createMovie() {
		return new JapaneseMovie();
	}
};
class AmericanProducer :public Factory { // 具体工厂类 -- 美国生产者
public:
	Movie* createMovie() {
		return new AmericanMovie();
	}
};

int main() {
	Factory* factoryA = new ChineseProducer();
	Movie* movieA = factoryA->createMovie();
	cout << movieA->getMovie() << endl;

	Factory* factoryB = new JapaneseProducer();
	Movie* movieB = factoryB->createMovie();
	cout << movieB->getMovie() << endl;

	Factory* factoryC = new AmericanProducer();
	Movie* movieC = factoryC->createMovie();
	cout << movieC->getMovie() << endl;
	if (factoryA != nullptr) {
		delete factoryA;
		factoryA = nullptr;
	}
	if (factoryB != nullptr) {
		delete factoryB;
		factoryB = nullptr;
	}
	if (factoryC != nullptr) {
		delete factoryC;
		factoryC = nullptr;
	}
	/*
	* 工厂方法模式实现时，客户端需要决定实例化哪一个工厂来实现产品类，选择判断的问题还存在；
	* 工厂方法是把简单工厂模式的内部判断逻辑移动到了客户端代码来进行。
	*/
	return 0;
}
