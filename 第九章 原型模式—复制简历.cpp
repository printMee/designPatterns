#include<iostream>
#include<string>
using namespace std;


class workExperience { // 工作经历类
private:
	string workDate; // 工作日期
	string company; // 公司
public:
	workExperience(){}
	~workExperience(){}
	workExperience(workExperience* work) {
		this->workDate = work->workDate;
		this->company = work->company;
	}
	string getworkDate() {
		return workDate;
	}
	string getcompany() {
		return company;
	}
	void setCompany(string company) {
		this->company = company;
	}
	void setWorkDate(string workDate) {
		this->workDate = workDate;
	}
	//clone
	workExperience* clone() {
		return new workExperience(this);
	}
};


class prototype {	//抽象原型类 -- 声明一个克隆自身的接口。
protected:
	string name;
	string sex;
	string age;
	string timearea;
	string company;
public:
	virtual void setPersonalInfo(string sex, string age) =0;
	virtual void display() = 0;
	virtual prototype* clone() = 0;
};

class Resume :public prototype {
private:
	workExperience* workExp;
public:
	Resume(string name) {
		this->name = name;
		workExp = new workExperience();
	}
	~Resume() {
		if (workExp != nullptr)
			delete workExp;
	}
	//供克隆调用的构造函数
	Resume(workExperience* workExp) {
		this->workExp = workExp->clone();
	}
	void setPersonalInfo(string sex, string age) {
		this->sex = sex;
		this->age = age;
	}
	void setWorkExperience(string company, string workDate) {
		workExp->setCompany(company);
		workExp->setWorkDate(workDate);
	}
	void display() {
		cout << name << " " << age << " " << sex << " " << endl;
		cout << "工作经历" << workExp->getworkDate() << " " << workExp->getcompany() << endl;
	}
	Resume* clone() { // 深拷贝
		Resume* cloneResume = new Resume(workExp); //对引用对象进行深拷贝。
		cloneResume->name = this->name;
		cloneResume->sex = this->sex;
		cloneResume->age = this->age;
		return cloneResume;
	}
};

int main() {
	Resume* a = new Resume("大鸟");
	a->setPersonalInfo("男", "29");
	a->setWorkExperience("1998-2000", "XX公司");
	Resume* b = a->clone();
	b->setWorkExperience("1998-2006", "YY公司");
	Resume* c = b->clone();
	c->setPersonalInfo("男", "24");
	c->setWorkExperience("1998-2006", "ZZ公司");

	a->display();
	b->display();
	c->display();
	delete a;
	delete b;
	delete c;
	a = b = c = nullptr;

	return 0;
}