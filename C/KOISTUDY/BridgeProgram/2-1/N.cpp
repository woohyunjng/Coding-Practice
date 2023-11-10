#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (!(A % 2))
        cout << A << '\n';
    if (!(B % 2))
        cout << B << '\n';
    if (!(C % 2))
        cout << C;
}