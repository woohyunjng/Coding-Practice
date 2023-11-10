#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N >= 90)
        cout << "A";
    else if (N >= 70)
        cout << "B";
    else if (N >= 40)
        cout << "C";
    else
        cout << "D";
}