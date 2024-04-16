#include <iostream>
using namespace std;

int main()
{
    long long a, m, d, n;
    cin >> a >> m >> d >> n;
    for (int i = 0; i < n - 1; i++)
        a = m * a + d;
    cout << a;
}