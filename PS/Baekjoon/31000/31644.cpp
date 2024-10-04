#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX], S[MAX], res[MAX];

int val(pr X) {
    int A = X.first, B = X.second, K;
    K = ceil((double)(P[B] - P[A]) / (S[A] + S[B]));
    if (A & 1)
        return K * 2 - 1;
    return K * 2;
}

struct compare {
    bool operator()(const pr &A, const pr &B) { return val(A) > val(B); }
};

void solve() {
    int N;
    pr K;
    cin >> N;

    priority_queue<pr, vector<pr>, compare> pq;
    set<int> st;
    set<int>::iterator it1, it2;

    for (int i = 1; i <= N; i++)
        cin >> P[i];
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
        st.insert(i);
    }

    for (int i = 1; i < N; i++)
        pq.push({i, i + 1});

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        it1 = st.find(K.first), it2 = st.find(K.second);
        if (it1 == st.end() || *it1 != K.first || it2 == st.end() || *it2 != K.second)
            continue;

        res[K.first] = res[K.second] = val(K);

        if (it1 != st.begin() && it2 != --st.end())
            pq.push({*prev(it1), *next(it2)});
        st.erase(it1), st.erase(it2);
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}