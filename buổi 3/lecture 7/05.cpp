#include <iostream>

using namespace std;

int n;
int* arr;
bool* check;
void permutations(int k = 0) {
    for (size_t i = 0; i < n; i++)
    {
        if (check[i] == true) {
            arr[k] = i + 1;
            check[i] = false;
            if (k == n - 1) {
                for (size_t j = 0; j < n; j++)
                    cout << arr[j] << " ";
                cout << endl;
            }
            permutations(k + 1);
            check[i] = true;
        }
    }
}

int main()
{
    cin >> n;
    arr = new int[n];
    check = new bool[n];
    for (size_t i = 0; i < n; i++)
    {
        check[i] = true;
    }
    permutations();

    return 0;
}