#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream readFile("matrix.txt");
	ofstream writeFile("matrix.out");
	int row, col;
	readFile >> row >> col;
	int** arr = new int*[row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			int x;
			readFile >> x;
			arr[i][j] = x;
		}
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	int sum;
	if (row > 0 && col > 0)
		sum = arr[0][0];
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			for (size_t h = i; h <row ; h++)
			{
				for (size_t k = j; k < col; k++)
				{
					int sumCureent = 0;
					for (size_t u = i; u <=h; u++)
					{
						for (size_t v = j; v <= k; v++)
						{
							sumCureent += arr[u][v];
						}
					}

					if (sum < sumCureent)
						sum = sumCureent;
				}
			}
		}
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			for (size_t h = i; h < row; h++)
			{
				for (size_t k = j; k < col; k++)
				{
					int sumCureent = 0;
					for (size_t u = i; u <= h; u++)
					{
						for (size_t v = j; v <= k; v++)
						{
							sumCureent += arr[u][v];
						}
					}
					if (sum == sumCureent) {
						writeFile << i + 1 << " " << j + 1 << " " << h + 1 << " " << k + 1 << " " << sum;
						return 0;
					}
						
				}
			}
		}
	}


	return 0;
}