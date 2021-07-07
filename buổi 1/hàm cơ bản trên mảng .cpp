#include<iostream>
#include<vector>
using namespace std;

int sum(int arr[], int n) {
	int Return = 0;
	for (int i = 0; i < n; i++) {
		Return += arr[i];
	}
	return Return;
}

int smallest(int arr[], int n) {
	int min = arr[0];
	for (size_t i = 0; i < n; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}

int greatest(int arr[], int n) {
	int max = arr[0];
	for (size_t i = 0; i < n; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

void deleteOdd(int arr[], int &n) {
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0) {
			for (size_t j = i; j < n - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			i--;
			n--;
		}
	}
}
vector<int>rowPositive(int **arr, int height, int width) {
	vector<int>Return;
	for (size_t i = 0; i < height; i++)
	{
		int sum = 0;
		for (size_t j = 0; j < width; j++)
			sum += arr[i][j];
		if (sum > 0)
			Return.push_back(i);
	}
	return Return;
}

vector<int>colNegative(int** arr, int height, int width) {
	vector<int>Return;
	for (size_t i = 0; i < width; i++)
	{
		int sum = 0;
		for (size_t j = 0; j < height; j++)
		{
			sum += arr[j][i];
		}
		if (sum < 0)
			Return.push_back(i);
	}
	return Return;
}

int main() {
	
	return 0;
}