#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    if (x == 0)
        return x;
    if (y == 0)
        return y;

    if (x == y)
        return x;

    if (x > y)
        return gcd(x - y, y);
    return gcd(x, y - x);
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y);
    return 0;
}