#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long A, B, X, Y;
    cin >> X >> Y;
    cin >> A >> B;

    if (A * 2 <= B)
        cout << (X + Y) * A;
    else
        cout << max(X, Y) * A + min(X, Y) * (B - A);
}