#include <bits/stdc++.h>
#define int long long

#define MAX 1100
using namespace std;
typedef array<int, 4> tp;

int res[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    vector<tp> arr;
    cin >> N;

    cout << N * 2 - 1 << '\n';

    for (int i = 1; i < N; i++)
        arr.push_back({(N + 1) * (i - 1) + 1, (N + 1) * (i - 1) + N, i, 1});

    for (int i = 1; i < N; i++)
        arr.push_back({(N + 1) * i, (N + 1) * i, N, i % N + 1});
    arr.push_back({N * N, N * N, N, 1});

    for (tp i : arr)
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << ' ' << i[3] << '\n';

    return 0;
}