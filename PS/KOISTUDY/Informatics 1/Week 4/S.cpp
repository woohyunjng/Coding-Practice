#include <iostream>
using namespace std;

int main()
{
    long long A, B, C;
    cin >> A >> B >> C;
    cout.precision(1);
    cout << A + B + C << '\n'
         << fixed << (double)(A + B + C) / 3;
}