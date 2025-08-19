#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 3> tp;

const int MAX = 200001;

int A[MAX], ans[MAX], R[MAX], S[MAX], E[MAX], C[MAX];
vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, T, K, SZ;
    tp V;

    vector<int> comp;

    set<tp> st;
    set<tp>::iterator iter;

    cin >> N >> M >> T >> K;

    for (int i = 1; i <= M; i++) {
        cin >> A[i], st.insert({i, i, A[i]});
        ans[A[i]] += N;
    }

    for (int i = 1; i <= K; i++) {
        cin >> R[i] >> S[i] >> E[i] >> C[i];
        comp.push_back(R[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    SZ = comp.size();

    for (int i = 1; i <= K; i++) {
        R[i] = lower_bound(comp.begin(), comp.end(), R[i]) - comp.begin();
        arr[R[i]].push_back(i);
    }

    for (int i = 0; i < SZ; i++) {
        for (int j : arr[i]) {
            iter = st.lower_bound({S[j], 0, 0});
            if (iter != st.begin() && (*prev(iter))[1] >= S[j]) {
                V = (*prev(iter)), st.erase(prev(iter));
                ans[V[2]] -= (min(E[j], V[1]) - S[j] + 1) * (N - comp[i] + 1);

                st.insert({V[0], S[j] - 1, V[2]});
                if (V[1] > E[j])
                    st.insert({E[j] + 1, V[1], V[2]});
                iter = st.lower_bound({S[j], 0, 0});
            }

            while (iter != st.end() && (*iter)[0] <= E[j]) {
                V = *iter, st.erase(iter);
                ans[V[2]] -= (min(E[j], V[1]) - V[0] + 1) * (N - comp[i] + 1);

                if (V[1] > E[j])
                    st.insert({E[j] + 1, V[1], V[2]});
                iter = st.lower_bound({S[j], 0, 0});
            }

            ans[C[j]] += (E[j] - S[j] + 1) * (N - comp[i] + 1);
            st.insert({S[j], E[j], C[j]});
        }
    }

    for (int i = 1; i <= T; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}