#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[30], dp[30][30][30], K;

int get(int X, int A, int B)
{
    if (dp[X][A][B])
        return dp[X][A][B];

    if (X == K)
        return dp[X][A][B] = min(abs(arr[X] - A), abs(arr[X] - B));
    if (arr[X] == A || arr[X] == B)
        return dp[X][A][B] = get(X + 1, A, B);

    if (B < arr[X])
        return dp[X][A][B] = get(X + 1, A, arr[X]) + abs(arr[X] - B);
    else if (A > arr[X])
        return dp[X][A][B] = get(X + 1, arr[X], B) + abs(arr[X] - A);
    else
        return dp[X][A][B] = min(
                   get(X + 1, arr[X], B) + abs(arr[X] - A),
                   get(X + 1, A, arr[X]) + abs(arr[X] - B));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, B, X, res = 0, a, b;
    cin >> K;
    cin >> A >> B;

    cin >> K;
    for (int i = 1; i <= K; i++)
        cin >> arr[i];

    cout << get(1, min(A, B), max(A, B));

    return 0;
}