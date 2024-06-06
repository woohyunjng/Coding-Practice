#include <iostream>
using namespace std;

int main()
{
    long long a, r, n;
    cin >> a >> r >> n;
    for (int i = 0; i < n - 1; i++)
        a *= r;
    cout << a;
}