#include <iostream>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, od = 0, res = 0;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
    {
        arr[i] %= 2;
        if (arr[i])
            od++;
        if (arr[i] != i % 2)
            res++;
    }

    if ((int)(N / 2) != od)
    {
        cout << -1;
        return 0;
    }

    cout << (int)(res / 2);
}