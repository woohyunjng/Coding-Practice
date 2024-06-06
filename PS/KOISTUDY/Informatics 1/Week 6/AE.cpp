#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, A, mn = 24;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A;
        mn = min(mn, A);
    }

    cout << mn;
}