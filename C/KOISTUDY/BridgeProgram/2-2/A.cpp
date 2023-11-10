#include <iostream>
using namespace std;

int main()
{
    int N, res = 0;
    cin >> N;

    for (int i = 2; i <= N; i += 2)
        res += i;

    cout << res;
}