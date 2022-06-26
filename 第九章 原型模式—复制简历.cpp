#include<iostream>
#include<string>
using namespace std;


class workExperience { // ����������
private:
	string workDate; // ��������
	string company; // ��˾
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


class prototype {	//����ԭ���� -- ����һ����¡����Ľӿڡ�
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
	//����¡���õĹ��캯��
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
		cout << "��������" << workExp->getworkDate() << " " << workExp->getcompany() << endl;
	}
	Resume* clone() { // ���
		Resume* cloneResume = new Resume(workExp); //�����ö�����������
		cloneResume->name = this->name;
		cloneResume->sex = this->sex;
		cloneResume->age = this->age;
		return cloneResume;
	}
};

int main() {
	Resume* a = new Resume("����");
	a->setPersonalInfo("��", "29");
	a->setWorkExperience("1998-2000", "XX��˾");
	Resume* b = a->clone();
	b->setWorkExperience("1998-2006", "YY��˾");
	Resume* c = b->clone();
	c->setPersonalInfo("��", "24");
	c->setWorkExperience("1998-2006", "ZZ��˾");

	a->display();
	b->display();
	c->display();
	delete a;
	delete b;
	delete c;
	a = b = c = nullptr;

	return 0;
}