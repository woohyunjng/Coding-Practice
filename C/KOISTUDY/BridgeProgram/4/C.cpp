#include <iostream>
using namespace std;

int main()
{
    int a, b, A, B;
    cin >> a >> b;
    cin >> A >> B;

    int res = a * A + b * B;
    cout << (res >= 10000 ? res - 1000 : res);
}