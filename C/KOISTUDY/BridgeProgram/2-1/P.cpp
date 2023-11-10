#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << (N > 0 ? "plus" : "minus") << '\n';
    cout << (N % 2 ? "odd" : "even");
}