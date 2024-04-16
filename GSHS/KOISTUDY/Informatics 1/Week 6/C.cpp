#include <iostream>
using namespace std;

int main()
{
    int A;
    cin >> A;
    cout << (A > 0 ? "plus" : "minus") << '\n';
    cout << (A % 2 ? "odd" : "even");
}