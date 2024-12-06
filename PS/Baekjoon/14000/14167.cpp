#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int X[MAX], Y[MAX], parent[MAX];

int find(int K) { return parent[K] == K ? K : parent[K] = find(parent[K]); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, A, B;
    vector<tp> arr;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            arr.push_back({(X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]), i, j});

    sort(arr.begin(), arr.end());
    for (tp i : arr) {
        A = find(i[1]), B = find(i[2]);
        if (A == B)
            continue;
        if (A > B)
            swap(A, B);
        parent[B] = A;
        res = max(res, i[0]);
    }

    cout << res << '\n';

    return 0;
}