#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, mx = 0;
    cin >> N;

    int A[N], B[N];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    for (int i = 0; i < N; i++)
    {
        A[i] = B[i] + mx;
        mx = max(mx, A[i]);
    }

    for (int i = 0; i < N; i++)
        cout << A[i] << ' ';
}