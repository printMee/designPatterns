#include<iostream>
#include<string>
#include<vector>
using namespace std;



class schoolGirl {//��׷������
private:
	string name;//����
	string birthday;//����
public:
	schoolGirl(string name=nullptr) :name(name) {}
	string getName() {
		return name;
	}
	string getBirthday() {
		return birthday;
	};
};

class giveGift {//�������� -- ������
public:
	virtual void giveDolls() = 0;
	virtual void giveFlowers() = 0;
	virtual void giveChocolate() = 0;
};

class pursue:public giveGift{//׷������ -- ����
private:
	schoolGirl *mm=nullptr;
public:
	pursue(schoolGirl *girl) {
		mm = girl; //ָ��girl���ڴ�ռ�
	}
	void giveDolls() {
		cout << "��" <<mm->getName()<<"������"<<endl;
	}
	void giveFlowers() {
		cout << "��" << mm->getName()<< "����" << endl;
	}
	void giveChocolate() {
		cout << "��" << mm->getName()<< "�ɿ���" << endl;
	}
};

class proxy :public giveGift {//������ -- ����
private:
	pursue *gg=nullptr;
public:
	proxy(schoolGirl *girl) {
		gg = new pursue(girl);//�ڶ�������һ��pursue���͵Ķ��󣬷��ص��Ǹö����ָ��
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
	schoolGirl *mm = new schoolGirl("����");
	//������ֻ��ʶ��������Ķ���
	proxy *daiLi = new proxy(mm); //int a=1; int *p = &a
								  //��Ҫע����ǣ� int* ��ָ����������ͣ�������� p ���Ǳ������������洢��ַ��
								  //��˵�ַ &a �Ǹ�ֵ�� p ������ *p �ġ�
	//�ɴ�����ִ�У��ͻ��˲���ʶ׷����
	daiLi->giveDolls();
	daiLi->giveFlowers();
	daiLi->giveChocolate();
	return 0;
}