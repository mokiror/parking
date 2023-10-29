#include <iostream>
#include <string>
#include <vector>

//ромбовидное наследование

//из-за виртуала становится неотъемлемой частью наследников
class A {
public:
	A() = default; //обязательно
	A(int newId, std::string newName):
	id(newId), name(newName){}
	int id;
	std::string name;
	virtual ~A() {}; //обязательная штука в этом случае

};
class B : virtual public A{
public:
	B() = default; //обязательно
	std::string model;
};
class C : virtual public A {
public:
	C() = default; //обязательно
	C(int newId, std::string newName, int newPsc) :
		A(newId, newName),
		passcode(newPsc) {}

	int passcode;
};
class E :public B, public C {
public:
	E() = default;
	//обязательный порядок вывода в ромбовидном наследовании
	E(int id, int passcode, std::string name, std::string model):
		A(id, name), B(), C(){
		this->model = model;
		this->passcode = passcode;
	}

};


//задание
class Transport {
public:
	//звуки
	virtual void Sound1() {
		std::cout << "\nтипичные звуки двигателя";
	}
	virtual void Sound2() {
		std::cout << "\nзвуки самоката";
	}

	//движение
	virtual void Movement1() {
		std::cout << "\nна педаль жмёшь и едешь";
	}
	virtual void Movement2() {
		std::cout << "\nножками отталкиваешься";
	}

private:
};

class TypeOne : virtual public Transport {
public:
	void FirstType() {
		std::cout << "\nмеханика";
	}
};

class TypeTwo : virtual public Transport {
public:
	void SecondType() {
		std::cout << "\nна электричестве";
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


	std::cout << "Авто-парк: " << std::endl;
	Parking obj;
	std::cout << "\nЭлектросамокат: ";
	obj.ElectroSamokat();
	std::cout << std::endl;
	std::cout << "\nМашина: ";
	obj.Car();
	std::cout << std::endl;
	std::cout << "\nСамокат: ";
	obj.Samokat();
	std::cout << std::endl;
	std::cout << "\nЭлектрокар: ";
	obj.ElectroCar();
	std::cout << "\n\n" << std::endl;




	return 0;
}
