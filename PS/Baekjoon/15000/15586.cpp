#include <bits/stdc++.h>
#define int long long

#define MAX 100100

using namespace std;
typedef array<int, 4> tp;

int parent[MAX], sz[MAX], res[MAX];

int find(int X) { return parent[X] == X ? X : parent[X] = find(parent[X]); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, C;
    vector<tp> arr;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        parent[i] = i, sz[i] = 1;

    for (int i = 1; i < N; i++) {
        cin >> A >> B >> C;
        arr.push_back({C, 1, A, B});
    }

    for (int i = 1; i <= Q; i++) {
        cin >> A >> B;
        arr.push_back({A, 0, B, i});
    }

    sort(arr.begin(), arr.end(), greater<tp>());

    for (tp i : arr) {
        if (i[1] == 0)
            A = find(i[2]), res[i[3]] = sz[A] - 1;
        else {
            A = find(i[2]), B = find(i[3]);
            if (A > B)
                swap(A, B);
            parent[A] = B, sz[B] += sz[A];
        }
    }

    for (int i = 1; i <= Q; i++)
        cout << res[i] << '\n';

    return 0;
}