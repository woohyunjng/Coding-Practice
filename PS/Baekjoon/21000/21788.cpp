#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500002;

int N, K, X[MAX], Y[MAX], SX, SY,
    XL[MAX], XR[MAX], YL[MAX], YR[MAX],
    E[MAX],
    fenwick[MAX];
vector<int> compX, compY, arr[MAX], val[MAX];
set<int> cur[MAX];

void update(int x, int v) {
    for (; x <= SY; x += x & (-x))
        fenwick[x] += v;
}
int query(int x) {
    int res = 0;
    for (; x > 0; x -= x & (-x))
        res += fenwick[x];
    return res;
}
int query(int l, int r) { return query(r) - query(l - 1); }

int calc(int V) {
    for (int i = 0; i <= SX + 1; i++)
        arr[i].clear();
    fill(fenwick, fenwick + SY + 1, 0);

    for (int i = 1; i <= N; i++) {
        XL[i] = lower_bound(compX.begin(), compX.end(), compX[X[i] - 1] - V) - compX.begin() + 1;
        XR[i] = lower_bound(compX.begin(), compX.end(), compX[X[i] - 1] + V + 1) - compX.begin();
        YL[i] = lower_bound(compY.begin(), compY.end(), compY[Y[i] - 1] - V) - compY.begin() + 1;
        YR[i] = lower_bound(compY.begin(), compY.end(), compY[Y[i] - 1] + V + 1) - compY.begin();

        arr[XL[i] - 1].push_back(-i), arr[XR[i]].push_back(i);
    }

    int res = 0;

    for (int i = 1; i <= SX; i++) {
        for (int j : val[i])
            update(Y[j], 1);
        for (int j : arr[i]) {
            if (j < 0)
                res -= query(YL[-j], YR[-j]);
            else
                res += query(YL[j], YR[j]) - 1;
        }
    }

    return res;
}

int dis(int A, int B) { return max(abs(compX[X[A] - 1] - compX[X[B] - 1]), abs(compY[Y[A] - 1] - compY[Y[B] - 1])); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int TX, TY, V;
    vector<int> ans;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> TX >> TY, X[i] = TY - TX, Y[i] = TY + TX;
        compX.push_back(X[i]), compY.push_back(Y[i]);
    }

    sort(compX.begin(), compX.end()), compX.erase(unique(compX.begin(), compX.end()), compX.end()), SX = compX.size();
    sort(compY.begin(), compY.end()), compY.erase(unique(compY.begin(), compY.end()), compY.end()), SY = compY.size();

    for (int i = 1; i <= N; i++) {
        X[i] = lower_bound(compX.begin(), compX.end(), X[i]) - compX.begin() + 1;
        Y[i] = lower_bound(compY.begin(), compY.end(), Y[i]) - compY.begin() + 1;
        val[X[i]].push_back(i);
    }

    for (int i = 1; i <= SX; i++)
        sort(val[i].begin(), val[i].end(), [&](int x, int y) { return Y[x] > Y[y]; });

    for (int st = 1, en = 4'000'000'000, md; st <= en;) {
        md = st + en >> 1, TX = calc(md);
        if (TX / 2 >= K)
            en = md - 1, V = md;
        else
            st = md + 1;
    }

    TX = calc(V - 1) / 2;
    for (int i = 0; i < K - TX; i++)
        ans.push_back(V);
    V--;

    for (int i = 0; i <= SX; i++)
        arr[i].clear();
    for (int i = 1; i <= N; i++) {
        E[i] = lower_bound(compX.begin(), compX.end(), compX[X[i] - 1] + V + 1) - compX.begin() + 1;
        arr[E[i]].push_back(i);
    }

    set<int> st;
    set<int>::iterator iter;

    for (int i = 1; i <= SX; i++) {
        for (int j : arr[i]) {
            cur[Y[j]].erase(cur[Y[j]].find(j));
            if (cur[Y[j]].size() == 0)
                st.erase(st.find(Y[j]));
        }

        for (int j : val[i]) {
            cur[Y[j]].insert(j);
            if (cur[Y[j]].size() == 1)
                st.insert(Y[j]);

            iter = st.lower_bound(YL[j]);
            while (iter != st.end() && (*iter) <= YR[j]) {
                TY = *iter, iter++;
                for (int k : cur[TY])
                    if (k != j)
                        ans.push_back(dis(k, j));
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << '\n';
}
