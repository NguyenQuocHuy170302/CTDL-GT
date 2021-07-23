#include<iostream>
#include<vector>

using namespace std;

typedef class Node* Tree;

class Node {
public:
	int data;
	bool isEmpty;
	Node* left;
	Node* right;
	Node* parent;
	Node() {
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
		this->isEmpty = true;
	}
	Node(int data) {
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
		this->data = data;
		this->isEmpty = false;
	}
};

void insert(Node* &add, int data) {
	//nodeRoot
	if (add->parent == NULL&&add->isEmpty==true) {
		add->data = data;
		add->isEmpty = false;
		return;
	}
	if (add->data < data) {
		if (add->right == NULL) {
			Node* newNode = new Node(data);
			add->right = newNode;
			newNode->parent = add;
			return;
		}
		insert(add->right, data);
	}
	else if (add->data > data) {
		if (add->left == NULL) {
			Node* newNode = new Node(data);
			add->left = newNode;
			newNode->parent = add;
			return;
		}
		insert(add->left, data);
	}
	else
		return;
}

void getData(Node* root, vector<int>&save) {
	if (root == NULL)
		return ;
	if (root->isEmpty == true)
		return;
	save.push_back(root->data);
	if (root->right != NULL)
		getData(root->right, save);
	if (root->left != NULL)
		getData(root->left, save);
	if (root->left == NULL && root->right == NULL&&root->parent!=NULL) {
		root->parent->right == root ? root->parent->right = NULL : root->parent->left = NULL;
		delete[]root;
		root = NULL;
	}
}

bool Delete(Node*& root, int key) {
	if (root == NULL)
		return false;
	if (root->isEmpty == true && root->parent == NULL)
		return false;
	if (root->parent == NULL && root->data == key) {
		Node* left = root->left;
		Node* right = root->right;

		if (left == NULL&&right==NULL) {
			root->isEmpty = true;
			return true;
		}
		else if (left == NULL && right != NULL) {
			right->parent = NULL;
			delete[]root;
			root = right;
			return true;
		}
		else if (left != NULL && right == NULL) {
			left->parent = NULL;
			delete[]root;
			root = left;
			return true;
		}
		else {
			left->parent = NULL;
			right->parent = NULL;
			right->isEmpty = false;
			left->isEmpty = false;
			vector<int>saveData;
			getData(left,saveData);
			delete[]left;
			left = NULL;
			for (size_t i = 0; i < saveData.size(); i++) 
				insert(right, saveData[i]);
			
			root = right;
			return true;
		}
		
	}

	if (root->data > key) {
		Delete(root->left, key);
	}
	else if (root->data < key) {
		Delete(root->right, key);
	}
	else {
		if (root->right == NULL && root->left == NULL) {
			root->parent->left == root ? root->parent->left = NULL : root->parent->right = NULL;
			delete []root;
			return true;
		}
		else if (root->left != NULL || root->right != NULL) {
			Node* parent = root->parent;
			Node*child=root->left == NULL ?root->right :root->left;
			bool check = root->parent->left == root ? 1 : 0;
			root->left = NULL;
			root->right = NULL;
			root->parent = NULL;
			delete[]root;
			if (check == 1) {
				parent->left = child;
				child->parent = parent;
			}
			else {
				parent->right = child;
				child->parent = parent;
			}
			return true;
		}
	
		else {
			Node* temp = root->right;
			if (temp->left == NULL) {
				root->parent->left == root ? root->parent->left = temp : root->parent->right = temp;
				root->left->parent = temp;
			}
			while (temp->left!=NULL)
				temp = temp->left;
			swap(root->data, temp->data);
			temp->parent->left = NULL;
			delete []temp;
			temp = NULL;
			return true;
		}
	}
}

bool search(Node* test, int key) {
	if (test == NULL) {
		return false;
	}
	if (test->isEmpty == true && test->parent == NULL) {
		return false;
	}
	if (test->data > key) {
		search(test->left, key);
	}
	else if (test->data < key) {
		search(test->right, key);
	}
	else
		return true;
}

int main() {
	//insert
	//search
	//Delete
	//getData

	Tree test = new Node();
	for (size_t i = 0; i < 100; i++)
	{
		insert(test, i + 1);
	}
	for (size_t i = 0; i < 50; i++)
	{
		Delete(test, i + 1);
	}
	vector<int>arr;
	getData(test, arr);
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}