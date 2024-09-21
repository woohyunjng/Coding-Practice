#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int parent[MAX];
ordered_set arr[MAX];

int find(int K) {
    if (parent[K] != K)
        parent[K] = find(parent[K]);
    return parent[K];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, A, B, K;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        arr[i].insert(i);
    }

    while (Q--) {
        cin >> T >> A >> B;
        if (T == 1) {
            A = find(A), B = find(B);
            if (A == B)
                continue;

            if (A > B)
                swap(A, B);
            parent[B] = A;

            if (arr[A].size() < arr[B].size())
                swap(arr[A], arr[B]);
            for (int i : arr[B])
                arr[A].insert(i);
            arr[B].clear();
        } else {
            A = find(A);
            if (arr[A].size() < B)
                cout << -1 << '\n';
            else
                cout << *arr[A].find_by_order(arr[A].size() - B) << '\n';
        }
    }

    return 0;
}