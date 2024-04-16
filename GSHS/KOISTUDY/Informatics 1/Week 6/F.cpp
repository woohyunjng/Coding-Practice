#include <iostream>
using namespace std;

int main()
{
    int A;
    cin >> A;
    if (A <= 2 || A == 12)
        cout << "winter";
    else if (A <= 5)
        cout << "spring";
    else if (A <= 8)
        cout << "summer";
    else
        cout << "fall";
}