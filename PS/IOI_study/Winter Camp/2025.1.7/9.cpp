#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int val[MAX], A[MAX], B[MAX], K[MAX];

vector<pr> tree[MAX * 4];

vector<pr> mrg(vector<pr> L, vector<pr> R) {
    vector<pr> res;
    int X = 0, Y = 0;

    res.push_back({-INF, L[0].second + R[0].second});
    while (X < L.size() && Y < R.size()) {
        if (X + 1 == L.size() && Y + 1 == R.size())
            break;
        else if (X + 1 == L.size())
            res.push_back({R[Y + 1].first - L[X].second, L[X].second + R[Y + 1].second}), Y++;
        else if (Y + 1 == R.size())
            res.push_back({L[X + 1].first, L[X + 1].second + R[Y].second}), X++;
        else if (L[X + 1].first <= R[Y + 1].first - L[X].second)
            res.push_back({L[X + 1].first, L[X + 1].second + R[Y].second}), X++;
        else
            res.push_back({R[Y + 1].first - L[X].second, L[X].second + R[Y + 1].second}), Y++;
    }

    for (int i = 1; i < res.size(); i++)
        res[i].first = max(res[i].first, res[i - 1].first);

    return res;
}

void init(int n, int s, int e) {
    if (s == e) {
        tree[n].push_back({-INF, A[s]}), tree[n].push_back({K[s], B[s]});
        return;
    }

    int m = s + e >> 1;
    init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    tree[n] = mrg(tree[n << 1], tree[n << 1 | 1]);
}

vector<int> query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return vector<int>();
    if (l <= s && e <= r)
        return vector<int>{n};

    int m = s + e >> 1;
    vector<int> l_res = query(n << 1, s, m, l, r), r_res = query(n << 1 | 1, m + 1, e, l, r);

    for (int i : r_res)
        l_res.push_back(i);
    return l_res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, res, st, en, mid;
    vector<int> arr;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i] >> K[i];
    init(1, 1, N);

    for (int i = 1; i <= N; i++) {
        if (val[i - 1] >= K[i])
            val[i] = val[i - 1] + B[i];
        else
            val[i] = val[i - 1] + A[i];
    }

    for (int i = 1; i <= N; i++) {
        arr = query(1, 1, N, i + 1, N), res = val[i - 1];
        for (int j : arr) {
            st = 0, en = tree[j].size() - 1;
            while (st <= en) {
                mid = st + en >> 1;
                if (tree[j][mid].first <= res)
                    X = mid, st = mid + 1;
                else
                    en = mid - 1;
            }
            res += tree[j][X].second;
        }
        cout << res << '\n';
    }

    return 0;
}