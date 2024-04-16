#include <iostream>
using namespace std;

int main()
{
    char A;
    while (true)
    {
        cin >> A;
        cout << A << '\n';
        if (A == 'q')
            break;
    }
}