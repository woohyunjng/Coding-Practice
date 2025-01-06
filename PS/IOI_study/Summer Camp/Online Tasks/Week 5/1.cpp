#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int parent[MAX];

int find(int K) {
    if (parent[K] != K)
        parent[K] = find(parent[K]);
    return parent[K];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<tp> arr;
    int N, M, A, B, C, res = 0;

    cin >> N >> M;

    while (M--) {
        cin >> A >> B >> C;
        arr.push_back({C, A, B});
    }
    sort(arr.begin(), arr.end());

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (tp i : arr) {
        A = find(i[1]), B = find(i[2]);
        if (A == B)
            res += max(0ll, i[0]);
        else {
            if (A > B)
                swap(A, B);
            parent[B] = A;
        }
    }

    cout << res;

    return 0;
}