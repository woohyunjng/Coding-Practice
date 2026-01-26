#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 100001;
const int BUCKET = 300;

int N, A[MAX], B[MAX], C[2][MAX], NP;
vector<int> sq[2][MAX / BUCKET + 1], hull[2][MAX / BUCKET + 1];
bool chk[MAX];

void hull_update(int t, int K) {
    hull[t][K].clear();
    for (int i = K * BUCKET; i < (K + 1) * BUCKET; i++) {
        if (C[t][i] == -1)
            continue;
        while (!hull[t][K].empty() && C[t][hull[t][K].back()] > C[t][i])
            hull[t][K].pop_back();
        hull[t][K].push_back(i);
    }
}

void insert(int t, int x, int v) {
    int K = x / BUCKET;
    C[t][x] = v;
    sq[t][K].insert(lower_bound(sq[t][K].begin(), sq[t][K].end(), v), v);
    hull_update(t, K);
}

void erase(int t, int x, int v) {
    int K = x / BUCKET;
    C[t][x] = -1;
    sq[t][K].erase(lower_bound(sq[t][K].begin(), sq[t][K].end(), v));
    hull_update(t, K);
}

int query(int t, int l, int r, int ql, int qr) {
    if (l > r)
        return 0;

    int res = 0, K;
    if (l / BUCKET == r / BUCKET) {
        for (; l <= r; l++)
            res += (ql <= C[t][l] && C[t][l] <= qr);
    } else {
        for (; l % BUCKET; l++)
            res += (ql <= C[t][l] && C[t][l] <= qr);
        for (; (r + 1) % BUCKET; r--)
            res += (ql <= C[t][r] && C[t][r] <= qr);
        for (K = l / BUCKET; K * BUCKET <= r; K++)
            res += upper_bound(sq[t][K].begin(), sq[t][K].end(), qr) - lower_bound(sq[t][K].begin(), sq[t][K].end(), ql);
    }
    return res;
}

vector<int> increasing_hull(int t, int l, int r) {
    vector<int> res;

    int L = A[l], R = A[r], K;
    if (r == N + 1)
        R = MAX;
    l++, r--;

    if (l / BUCKET == r / BUCKET) {
        for (; r >= l; r--)
            if (C[t][r] != -1 && C[t][r] < R)
                res.push_back(r), R = C[t][r];
    } else {
        for (; (r + 1) % BUCKET; r--)
            if (C[t][r] != -1 && C[t][r] < R)
                res.push_back(r), R = C[t][r];
        for (; r / BUCKET > l / BUCKET; r -= BUCKET) {
            K = r / BUCKET;
            for (int i = 0; i < hull[t][K].size(); i++) {
                if (C[t][hull[t][K][i]] < R)
                    res.push_back(hull[t][K][i]);
                else
                    break;
            }
            if (!hull[t][K].empty())
                R = min(R, C[t][hull[t][K][0]]);
        }
        for (; r >= l; r--)
            if (C[t][r] != -1 && C[t][r] < R)
                res.push_back(r), R = C[t][r];
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, X, ans, L, R;
    set<int> val;
    vector<int> st;

    cin >> N >> Q, ans = N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], C[0][i] = C[1][i] = -1;
        while (!st.empty() && A[i] < A[st.back()])
            chk[st.back()] = false, st.pop_back();
        st.push_back(i), chk[i] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (chk[i]) {
            ans += query(0, 1, i - 1, A[i] + 1, N);
            insert(1, i, A[i]), val.insert(i);
        } else
            insert(0, i, A[i]);
    }

    cout << ans << ' ', st.clear();
    val.insert(0), val.insert(N + 1);

    while (Q--) {
        cin >> X, ans--;
        if (!chk[X])
            erase(0, X, A[X]), ans -= query(1, X + 1, N, 1, A[X] - 1);
        else {
            erase(1, X, A[X]), ans -= query(0, 1, X - 1, A[X] + 1, N);
            L = *prev(val.lower_bound(X)), R = *next(val.lower_bound(X)), val.erase(X);
            st = increasing_hull(0, L, R);

            for (int i : st) {
                val.insert(i), chk[i] = true;
                insert(1, i, A[i]), erase(0, i, A[i]);
                ans += query(0, 1, i - 1, A[i] + 1, N);
            }
            vector<int>().swap(st);
        }
        cout << ans << ' ';
    }
    cout << '\n';
}