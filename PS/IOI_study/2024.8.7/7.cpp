#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];
int sz[MAX], C[MAX];
bool checked[MAX];

int get_size(int node, int parent) {
    sz[node] = 1;
    for (int i : arr[node]) {
        if (i == parent || checked[i])
            continue;
        sz[node] += get_size(i, node);
    }
    return sz[node];
}

int get_centroid(int node, int parent, int cap) {
    for (int i : arr[node]) {
        if (i == parent || checked[i])
            continue;
        if (sz[i] * 2 > cap)
            return get_centroid(i, node, cap);
    }
    return node;
}

void divide_and_conquer(int node, int depth) {
    get_size(node, -1);
    int cent = get_centroid(node, -1, sz[node]);

    checked[cent] = true;
    C[cent] = depth;

    for (int i : arr[cent]) {
        if (checked[i])
            continue;
        divide_and_conquer(i, depth + 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, mx = 0;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    divide_and_conquer(1, 1);

    for (int i = 1; i <= N; i++)
        mx = max(mx, C[i]);

    if (mx > 17)
        cout << -1;
    else {
        for (int i = 1; i <= N; i++)
            cout << C[i] << '\n';
    }

    return 0;
}