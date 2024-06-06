#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int parent[4000100];

int find(int K)
{
    if (parent[K] != K)
        parent[K] = find(parent[K]);
    return parent[K];
}

void uni(int A, int B)
{
    A = find(A), B = find(B);
    if (A < B)
        swap(A, B);
    parent[B] = A;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, A, X, Y;
    cin >> N >> M >> K;

    vector<int> arr;

    for (int i = 0; i <= N; i++)
        parent[i] = i;

    for (int i = 1; i <= M; i++)
    {
        cin >> A;
        arr.push_back(A);
    }
    sort(arr.begin(), arr.end());

    while (K--)
    {
        cin >> A;
        X = find(lower_bound(arr.begin(), arr.end(), A + 1) - arr.begin());
        cout << arr[X] << '\n';

        Y = find(lower_bound(arr.begin(), arr.end(), arr[X] + 1) - arr.begin());
        uni(X, Y);
    }

    return 0;
}