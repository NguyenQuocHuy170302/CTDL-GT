#include<iostream>
#include<string>

using namespace std;

class Teacher {
private:
	int age;
	string name;
	string subject;
	string className;
public:
	Teacher() {
		this->age = 20;
		this->name = "!";
		this->subject = "!";
		this->className = "!";
	}
};

class Computer {
private:
	string name;
	string id;
	int age;
	int cost;

public:
	Computer() {
		this->name = "!";
		this->id = "!";
		this->age = 0;
		this->cost = 0;
	}
};

class point {
	double x;
	double y;
public:
	point() {
		this->x = 0;
		this->y = 0;
	}
};

class Rectangle {
	point a;
	point b;
	point c;
	
};

int main() {

	return 0;
}