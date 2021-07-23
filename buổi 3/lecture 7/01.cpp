#include<iostream>
#include<fstream>

using namespace std;

int main() {
	int arr[10000];
	int size = 0;
	ifstream readFile("number.txt");
	ofstream createFile("number.sorted");
	while (!readFile.eof())
	{
		int x;
		readFile >> x;
		arr[size] = x;
		size++;
	}
	for (size_t i = 0; i < size-1; i++)
	{
		for (size_t j = 0; j < size-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
	for (size_t i = 0; i < size; i++)
	{
		createFile << arr[i] << " ";
	}

	return 0;
}