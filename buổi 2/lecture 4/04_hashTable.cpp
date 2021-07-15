#include<iostream>

using namespace std;

class nodeStudent {
public:
	int id;
	string name;
	string className;
	nodeStudent* next;
	nodeStudent() {
		this->id = -1;
		this->next = NULL;
		this->className = "";
		this->name = "";
	}
};

class hashTableStudent {
public:
	const int MAXSIZE = 10;
	nodeStudent** listStudent;
	int currentNumberStudent;
	hashTableStudent() {
		this->listStudent = new nodeStudent * [this->MAXSIZE];
		for (int i = 0; i < this->MAXSIZE; i++) 
			this->listStudent[i] = new nodeStudent;
		
		this->currentNumberStudent = 0;
	}

	int hashFunction(int id) {
		return id % this->MAXSIZE;
	}

	string insert(int id, string name, string className) {
		if (name == "" && className == "")
			return "name and className empty";
		if (id < 0)
			return "ID negative number";
		nodeStudent* temp = this->listStudent[hashFunction(id)];
		if (temp->id == id) {
			string oldData = temp->name + ", " + temp->className;
			temp->className = className;
			temp->name =name;
			this->currentNumberStudent++;
			return oldData;
		}
		while (temp->next != NULL) {
			if (temp->id == id) {
				string oldData = temp->name + ", " + temp->className;
				temp->className = className;
				temp->name = name;
				this->currentNumberStudent++;
				return oldData;
			}
			temp = temp->next;
		}
		nodeStudent* newStudent = new nodeStudent;
		newStudent->className = className;
		newStudent->id = id;
		newStudent->name = name;
		if (temp->className == "" && temp->name == "") {
			this->listStudent[hashFunction(id)] = newStudent;
			this->currentNumberStudent++;
			return "complete";
		}
		temp->next = newStudent;
		this->currentNumberStudent++;
		return "complete";
	}

	string Delete(int id) {
		nodeStudent* temp = this->listStudent[this->hashFunction(id)];
		if (temp->className == "" && temp->name == "") {
			return "ID not already";
		}
		if (temp->id == id) {
			string oldData = temp->name + ", " + temp->className;
			temp->className = "";
			temp->name = "";
			temp->id = -1;
			this->currentNumberStudent--;
			return oldData;
		}
		while (temp->next!=NULL){
			if (temp->next->id == id) {
				nodeStudent* temp_ = temp->next;
				temp->next = temp_->next;
				string oldData = temp_->name + ", " + temp_->className;
				delete temp_;
				this->currentNumberStudent--;
				return oldData;
			}
			temp = temp->next;
		}
		return "ID not already";
	}
	
	string infor(int id) {
		nodeStudent* temp = this->listStudent[this->hashFunction(id)];
		while (temp!=NULL)
		{
			if (temp->id == id) {
				string data = temp->name + ", " + temp->className;
				return data;
			}
			temp = temp->next;
		}
		return "ID not already";
	}
};

int main() {
	//demo
	hashTableStudent test;
	test.insert(1, "huy", "web");
	test.insert(11, "roger", "c++");
	test.insert(112, "abc", "java");
	//cout<<test.Delete(1);
	//cout << test.infor(11);
	//cout<<test.Delete(111);
	//cout << test.infor(112);
	return 0;
}
