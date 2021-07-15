#include<iostream>

using namespace std;

class nodeStudent {
public:
	int id;
	string name;
	string className;	
	nodeStudent* next;

	nodeStudent() {
		this->next = NULL;
	}
	nodeStudent(int id, string name, string className) {
		this->id = id;
		this->name = name;
		this->className = className;
	}
};

class mapStudent {
public:
	nodeStudent* head;
	nodeStudent* tail;
	int size;
	mapStudent() {
		this->head = NULL;
		this->tail = NULL;
		this->size = 0;
		
	}
	string insert(int id, string name, string className) {
		nodeStudent* newNode = new nodeStudent(id,name,className);
		if (this->size == 0) {
			this->head = newNode;
			this->tail = newNode;
			this->size++;
			return "complete";
		}
		nodeStudent* temp = this->head;
		while (temp!=NULL)
		{
			if (temp->id == id) {
				string oldData = temp->name + "," + temp->className;
				temp->name = name;
				temp->className = className;
				return oldData;
			}
			temp = temp->next;
		}
		this->tail->next = newNode;
		this->tail = newNode;
		size++;
		return "complete";
	}
	void Delete(int id) {
		nodeStudent* temp = this->head;
		if (this->head->id == id) {
			nodeStudent* temp_ = this->head->next;
			delete this->head;
			this->head = temp_;
			this->size--;
			return;
		}
		while (temp!=NULL)
		{
			if (temp->next->id == id) {
				nodeStudent* temp_ = temp->next;
				temp->next = temp->next->next;
				delete temp_;
				this->size--;
				return;
			}
		}
	}
	string infor(int id) {
		nodeStudent* temp = this->head;
		while (temp!=NULL)
		{
			if (temp->id == id) {
				string a = temp->name;
				a += ", ";
				a += temp->className;
				return a;
			}
			temp = temp->next;
		}
		return "NA,NA";
	}
};

int main() {
	//demo
	mapStudent test;
	test.insert(1, "roger", "java");
	test.insert(2, "huy", "web");
	test.Delete(2);
	cout << test.infor(1);
	cout << endl;
	cout<<test.infor(2);
	return 0;
}
