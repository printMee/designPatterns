#include<iostream>
using namespace std;

/**
*
*我们现在在做一个实际音频的控制，它具有以下功能：
* 1.可以打开耳机
* 2.可以关闭耳机
* 3.可以打开麦克风
* 4.可以关闭麦克风
* 5.麦克风可以选择声卡样式
* 6.电脑开机时初始化打开耳机，耳机初始化同时初始化打开麦克风和选择默认声卡
*/

/**
*分析：
* 1.麦克风可以选择声卡样式，所以麦克风mike类和声卡soundCard类有一定的耦合
* 2.电脑开机先监测耳机，耳机初始化时要初始化麦克风，因此耳机类earphone在Init时要init mike类，两者有一定耦合
* 3.mike类和soundCard类直接通信，mike类和earphone类直接通信，但是soundCard类和earphone类不应直接通信
* 4.一个类对其他类了解的越少越好，因此在soundCard类中加入一个chooseType()函数
*/

/**
* @brief 耳机类
* 可以打开耳机，关闭耳机，耳机初始化的同时初始化麦克风
*/
class earphone { 
public:
	void Init(mike* pmike) {
		openVoice();
		pmike->Init();
	}
	//声音
	void openVoice() {};
	void closeVoice() {};
};

/**
* @brief 麦克风类
* 可以打开麦克风，关闭麦克风，麦克风初始化时会选择默认声卡
*/
class mike {
private:
	soundCard* m_soundCard;
public:
	void Init() {
		openMike();
		m_soundCard = new soundCard();
		m_soundCard->chooseType(1);
	}
	//麦克风
	void openMike() {};
	void closeMike() {};
};

/**
* @brief 声卡类
* 选择声卡类型，有3种，第一种是默认声卡。
*/
class soundCard {
public:
	void chooseType(int i) {};
private:
	void soundCardType1() {};
	void soundCardType2() {};
	void soundCardType3() {};
};

