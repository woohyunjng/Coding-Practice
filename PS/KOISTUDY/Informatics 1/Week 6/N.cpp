#include <iostream>
using namespace std;

int main()
{
    int N, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0)
            res += i;
    }
    cout << res;
}