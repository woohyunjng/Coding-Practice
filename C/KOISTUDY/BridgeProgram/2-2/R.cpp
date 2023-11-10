#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, A, res = 24;
    cin >> N;

    while (N--)
    {
        cin >> A;
        res = min(res, A);
    }

    cout << res;
}