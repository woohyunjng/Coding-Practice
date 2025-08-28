#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2'000'000;

int S[MAX], E[MAX];
vector<int> in[MAX], out[MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C, ans = 0;
    bool flag;

    vector<int> comp, arr;
    multiset<int> st;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> E[i], S[i]++, E[i]--;
        comp.push_back(S[i]), comp.push_back(E[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), C = comp.size();

    for (int i = 0; i < N; i++) {
        S[i] = lower_bound(comp.begin(), comp.end(), S[i]) - comp.begin();
        E[i] = lower_bound(comp.begin(), comp.end(), E[i]) - comp.begin();
        in[S[i]].push_back(i), out[E[i]].push_back(i);
    }

    for (int i = 0; i < C; i++) {
        sort(in[i].begin(), in[i].end(), [&](int x, int y) { return E[x] > E[y]; });
        for (int j : in[i]) {
            if (!st.empty() && (*st.rbegin()) >= E[j]) {
                E[j] = -1;
                continue;
            }
            st.insert(E[j]), arr.push_back(j);
        }

        flag = false;
        for (int j : out[i]) {
            if (E[j] == -1)
                continue;
            st.erase(st.find(E[j]));
            if (chk[j])
                continue;
            flag = true;
        }

        if (flag) {
            ans++;
            for (int j : arr)
                chk[j] = true;
            arr.clear();
        }
    }

    cout << ans << '\n';

    return 0;
}