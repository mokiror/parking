#include <iostream>
#include <string>
#include <vector>

//����������� ������������

//��-�� �������� ���������� ������������ ������ �����������
class A {
public:
	A() = default; //�����������
	A(int newId, std::string newName):
	id(newId), name(newName){}
	int id;
	std::string name;
	virtual ~A() {}; //������������ ����� � ���� ������

};
class B : virtual public A{
public:
	B() = default; //�����������
	std::string model;
};
class C : virtual public A {
public:
	C() = default; //�����������
	C(int newId, std::string newName, int newPsc) :
		A(newId, newName),
		passcode(newPsc) {}

	int passcode;
};
class E :public B, public C {
public:
	E() = default;
	//������������ ������� ������ � ����������� ������������
	E(int id, int passcode, std::string name, std::string model):
		A(id, name), B(), C(){
		this->model = model;
		this->passcode = passcode;
	}

};


//�������
class Transport {
public:
	//�����
	virtual void Sound1() {
		std::cout << "\n�������� ����� ���������";
	}
	virtual void Sound2() {
		std::cout << "\n����� ��������";
	}

	//��������
	virtual void Movement1() {
		std::cout << "\n�� ������ ���� � �����";
	}
	virtual void Movement2() {
		std::cout << "\n������� ��������������";
	}

private:
};

class TypeOne : virtual public Transport {
public:
	void FirstType() {
		std::cout << "\n��������";
	}
};

class TypeTwo : virtual public Transport {
public:
	void SecondType() {
		std::cout << "\n�� �������������";
	}
};

class Parking :public TypeOne, public TypeTwo {
public:

	void ElectroSamokat() {
		TypeTwo::Sound2();
		TypeTwo::Movement1();
		TypeTwo::SecondType();
	}

	void Car() {
		TypeOne::Sound1();
		TypeOne::Movement1();
		TypeOne::FirstType();
	}

	void Samokat() {
		TypeOne::Sound2();
		TypeOne::Movement2();
		TypeOne::FirstType();
	}

	void ElectroCar() {
		TypeTwo::Sound1();
		TypeTwo::Movement1();
		TypeTwo::SecondType();
	}

private:
};

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(NULL));


	std::cout << "����-����: " << std::endl;
	Parking obj;
	std::cout << "\n��������������: ";
	obj.ElectroSamokat();
	std::cout << std::endl;
	std::cout << "\n������: ";
	obj.Car();
	std::cout << std::endl;
	std::cout << "\n�������: ";
	obj.Samokat();
	std::cout << std::endl;
	std::cout << "\n����������: ";
	obj.ElectroCar();
	std::cout << "\n\n" << std::endl;




	return 0;
}
