#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
�칫��Ա��A��B��C�ڿ���Ʊ����Ӱ��
��ʱ�ϰ�����ˣ���A��B��C�ؽ��¸���ǰ̨����֪ͨ��A��B��C��A��B��C�յ�֪ͨ��Ͻ��ص��ԣ�
�ع�Ʊ���ڣ�װ���ڸɻ
*/

/**
* @brief ����۲�����
* ����۲����ṩһ���ӿ�
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
* @brief ����֪ͨ����
* ����֪ͨ���ṩһ���ӿ�
*/
class subject {
public:
	virtual void addObserver(observer* b) = 0;
	virtual void delObserver(observer* b) = 0;
	virtual void notify(string strEvent) = 0;
};

/**
* @brief ����۲���
* �۲��߸���״̬�ķ���
*/
class cObserver :public observer {
public:
	virtual void update(string strEvent) {
		cout << mNameObserver << "get" << strEvent << "call!" << endl;
	}
};
/**
* @brief ����֪ͨ��
* ֪ͨ���й۲���
*/
class boss :public subject {
private:
	vector<observer*> listObserver;
public:
	//��ӹ۲���
	void addObserver(observer* b) {
		listObserver.push_back(b);
	}
	//ɾ���۲���
	void delObserver(observer* b) {
		int i = 0;
		for (auto a : listObserver) {
			if (a->getName() == b->getName())
				listObserver.erase(listObserver.begin() + i);
			i++;
		}
	}
	//֪ͨ�۲���
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
	bs->notify("�ϰ�����");
	return 0;
}