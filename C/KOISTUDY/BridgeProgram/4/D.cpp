#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int a[N], A[N], res = 0;

    for (int i = 0; i < N; i++)
        cin >> a[i];

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
        res += a[i] * A[i];
    cout << res;
}