#include <iostream>
using namespace std;

int main()
{
    int A;
    cin >> A;
    if (A >= 90)
        cout << "A";
    else if (A >= 70)
        cout << "B";
    else if (A >= 40)
        cout << "C";
    else
        cout << "D";
}