#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A % 2 ? "odd" : "even") << '\n';
    cout << (B % 2 ? "odd" : "even") << '\n';
    cout << (C % 2 ? "odd" : "even");
}