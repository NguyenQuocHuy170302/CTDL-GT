/*do các phần tử của mảng được lưu trữ
 liên tiếp nhau nên việc truy suất hoạc sửa là dễ và 
 hiệu quả khi chỉ cần biết địa chỉ phần tử đầu tiên
*/

#include<iostream>

using namespace std;

void insertArr(int arr[], int &n, int p, int x) {
	for (size_t i = n; i > p; i--)
	{
		arr[i] = arr[i - 1];
	}
	n++;
	arr[p] = x;
}

void deleteArr(int arr[], int &n, int p) {
	for (size_t i = p; i < n-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
}

void Cout(int arr[], int n) {
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[1000];
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	deleteArr(arr, n, 0);

	Cout(arr, n);
	return 0;
}