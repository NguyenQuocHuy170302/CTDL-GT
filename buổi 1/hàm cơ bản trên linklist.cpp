#include<iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data = 0) {
		this->data = data;
		this->next = NULL;
	}
};

int maxOfLinkList(Node* head) {
	int max = head->data;
	Node* temp = head;
	while (temp!=NULL)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}

	return max;
}

int sumOfLinkList(Node* head) {
	int sum = 0;
	Node* temp = head;
	while (temp != NULL)
	{
		sum += temp->data;
		temp = temp->next;
	}

	return sum;
}

int main() {
	

	return 0;
}