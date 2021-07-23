#include <iostream>

using namespace std;

int n;
int* arr;

void binary(int k=0) {
    for (size_t i = 0; i <= 1; i++)
    {
        arr[k] = i;
        if (k == n - 1) {
            for (size_t j = 0; j < n; j++)
                cout << arr[j] << " ";
            cout << endl;
        }
        else
            binary(k + 1);
    }
}

int main()
{
    cin >> n;
    arr = new int[n];
    binary();
     
    return 0;
}