#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 60'000;

int A[MAX], B[MAX], T[MAX], V[MAX];
vector<int> in[MAX], out[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int C, N, S, ans = 0;
    vector<int> comp;
    set<pr> st;

    cin >> C >> N;
    for (int i = 1; i <= C; i++)
        cin >> T[i], comp.push_back(T[i]);
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i], comp.push_back(A[i]), comp.push_back(B[i]);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();

    for (int i = 1; i <= C; i++)
        T[i] = lower_bound(comp.begin(), comp.end(), T[i]) - comp.begin() + 1, V[T[i]]++;

    for (int i = 1; i <= N; i++) {
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;
        B[i] = lower_bound(comp.begin(), comp.end(), B[i]) - comp.begin() + 1;
        in[A[i]].push_back(i), out[B[i]].push_back(i);
    }

    for (int i = 1; i <= S; i++) {
        for (int j : in[i])
            st.insert({B[j], j});

        for (int j = 0; j < V[i] && !st.empty(); j++)
            st.erase(st.begin()), ans++;

        for (int j : out[i]) {
            if (st.find({B[j], j}) != st.end())
                st.erase({B[j], j});
        }
    }

    cout << ans << '\n';

    return 0;
}