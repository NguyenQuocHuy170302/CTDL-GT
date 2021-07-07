#include<iostream>

using namespace std;

class QueueArr {
public:
	const int maxSize = 10000;
	int currentSize;
	int* arr = NULL;
	QueueArr() {
		this->currentSize = 0;
		this->arr = new int[this->maxSize];
	}
	bool isFull() {
		return this->currentSize == this->maxSize;
	}
	
	bool addHead(int data) {
		if (this->isFull())
			return false;
		for (int i = currentSize; i > 0; i--) {
			this->arr[i] = this->arr[i - 1];
		}
		this->currentSize ++ ;
		this->arr[0] = data;
		return true;
	}

	int deleteTail() {
		int data = this->arr[this->currentSize - 1];
		this->currentSize--;
		return data;
	}
};

class Node {
public:
	int data;
	Node* next;
	Node(int data = 0) {
		this->data = data;
		this->next = NULL;
	}
};

typedef class Node* queueLL;

void addHead(queueLL node, queueLL head) {
	head->next = node;
}

int deledeTailLL(queueLL &node) {
	if (node == NULL) {
		cout << "node empty!";
		return 0;
	}
	if (node->next == NULL) {
		int data = node->data;
		delete node;
		node = NULL;
		return data;
	}
	queueLL temp = node;
	while (temp->next->next!=NULL)
	{
		int data = temp->next->data;
		delete temp->next;
		temp->next = NULL;
		return data;
	}
}

int main() {

	return 0;
}