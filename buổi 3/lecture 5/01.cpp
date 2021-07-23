#include<iostream>
#include<vector>

using namespace std;

vector<int>queue;

int foundRoot(int** arr, int m) {
	for (size_t i = 0; i < m; i++)
	{
		bool check = true;
		for (size_t j = 0; j < m; j++)
		{
			if (arr[i][0] == arr[j][1]) {
				check = false;
				break;
			}
		}
		if (check)
			return arr[i][0];
	}
	return -1;
}

int calculateHeight(int**arr,int m,bool checkStar=true) {
	if (checkStar == true) {
		queue.push_back(foundRoot(arr, m));
		checkStar = false;
	}
	vector<int>temp = queue;
	queue.erase(queue.begin(), queue.end());
	for (size_t i = 0; i < temp.size(); i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (arr[j][0] == temp[i]) {
				queue.push_back(arr[j][1]);
			}
		}
	}
	temp.clear();
	if (queue.size() > 0) {
		return 1 + calculateHeight(arr, m, checkStar);
	}
	else
		return 0;
	
}
void preorderTraversal(int** arr, int m, int current) {
	cout << current << " ";
	for (size_t i = 0; i < m; i++)
	{
		if (arr[i][0] == current) {
			preorderTraversal(arr, m, arr[i][1]);
		}
	}
}
void postorderTraversal( int** arr, int m, int current) {
	for (size_t i = 0; i < m; i++)
	{
		if (arr[i][0] == current) {
			postorderTraversal(arr, m, arr[i][1]);
		}
	}
	cout << current << " ";
}
bool checkBianryTree( int** arr, int m) {
	int* temp = new int[m];
	for (size_t i = 0; i < m; i++)
	{
		temp[i] = arr[i][0];
	}
	
	for (size_t i = 0; i < m-1; i++)
	{
		for (size_t j = 0; j < m-i-1; j++)
		{
			if (temp[i] > temp[i + 1])
				swap(temp[i], temp[i + 1]);
		}
	}

	for (size_t i = 0; i < m-2; i++)
	{
		if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2]) {
			delete[]temp;
			temp = NULL;
			return false;
		}
			
	}
	delete[]temp;
	temp = NULL;
	return true;
}
void inorder( int** arr,int m,int current,bool checkBinaryTree=true) {
	if (checkBinaryTree == false)
		return;
	int pos = m;
	for (size_t i = 0; i < m; i++)
	{
		if (arr[i][0] == current) {
			pos = i + 1;
			inorder(arr, m, arr[i][1]);
			break;
		}
	}
	cout << current << " ";
	for (size_t i = pos; i < m; i++)
	{
		if (arr[i][0] == current) {
			inorder(arr, m, arr[i][1]);
			break;
		}
	}
}
int main() {
	//demo
	int n, m;
	cin >> n >> m;
	int** arr = new int* [m];
	for (size_t i = 0; i < m; i++)	arr[i] = new int[2];
	
	for (size_t i = 0; i < m; i++) cin>>arr[i][0]>>arr[i][1];
		
	preorderTraversal(arr, m, foundRoot(arr, m));
	cout << endl;
	postorderTraversal(arr, m, foundRoot(arr, m));
	cout << endl;
	inorder(arr, m, foundRoot(arr, m), checkBianryTree(arr, m));
	cout << endl;
	cout << calculateHeight(arr, m);

	return 0;
}