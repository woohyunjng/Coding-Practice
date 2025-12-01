#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int V[MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S = 0, X;
    multiset<int> st;

    cin >> N;
    for (int i = 1; i <= (N << 1); i++)
        cin >> V[i], S += V[i], st.insert(V[i]);
    assert(S % (N + 1) == 0), S /= (N + 1);

    st.erase(st.find(S)), st.erase(st.find(S)), A[N] = S;
    for (int i = 1; i <= N - 1; i++) {
        X = *(st.begin()), st.erase(st.begin());
        A[i] = X, st.erase(st.find(S - X));
    }

    for (int i = 1; i <= N; i++)
        cout << A[i] - A[i - 1] << ' ';
    cout << '\n';

    return 0;
}