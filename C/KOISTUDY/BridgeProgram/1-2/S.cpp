#include <iostream>
using namespace std;

int main()
{
    long long int A, B;
    cin >> A >> B;
    cout.precision(2);
    cout << A + B << '\n'
         << A - B << '\n'
         << A * B << '\n'
         << A / B << '\n'
         << A % B << '\n'
         << fixed << (double)A / B;
}