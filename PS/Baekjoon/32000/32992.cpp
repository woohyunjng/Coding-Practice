#include <bits/stdc++.h>
#define int long long

#define MAX 500100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 4> tp;

int res[MAX], tree[MAX], tree_arr[MAX], N;
vector<tp> arr[MAX];
set<pr> st[MAX];
pr cur[MAX];

void update(int n, int val) {
    tree_arr[n] += val;
    while (n <= N) {
        tree[n] += val;
        n += n & -n;
    }
}

int query(int n) {
    int res = 0;
    while (n) {
        res += tree[n];
        n -= n & -n;
    }
    return res;
}

int query(int l, int r) { return query(r) - query(l - 1); };

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, K, C, Q, D, P, L, R, st_b, en, mid, bochu;
    cin >> N >> M >> K >> C >> Q;

    for (int i = 1; i <= Q; i++) {
        cin >> D >> P >> L >> R;
        arr[L].push_back({1, P, D, i});
        arr[R + 1].push_back({-1, P, D, i});
    }

    for (int i = 1; i <= M; i++) {
        sort(arr[i].begin(), arr[i].end());
        for (tp j : arr[i]) {
            if (j[0] == 1) {
                if (cur[j[1]].first == 0 || cur[j[1]].first > j[2]) {
                    if (cur[j[1]].first != 0)
                        update(cur[j[1]].first, -1);
                    cur[j[1]] = {j[2], j[3]}, update(j[2], 1);
                }
                st[j[1]].insert({j[2], j[3]});
            } else {
                st[j[1]].erase({j[2], j[3]});
                if (cur[j[1]].second == j[3]) {
                    update(cur[j[1]].first, -1);
                    if (!st[j[1]].empty())
                        cur[j[1]] = *st[j[1]].begin(), update(cur[j[1]].first, 1);
                    else
                        cur[j[1]] = {0, 0};
                }
            }
        }

        st_b = 0, en = N, bochu = -1;
        while (st_b <= en) {
            mid = st_b + en >> 1;
            if (query(1, mid) >= C)
                bochu = mid, en = mid - 1;
            else
                st_b = mid + 1;
        }
        if (bochu != -1)
            res[bochu]++;
    }

    for (int i = 1; i <= N; i++) {
        res[i] += res[i - 1];
        cout << res[i] << '\n';
    }

    return 0;
}
