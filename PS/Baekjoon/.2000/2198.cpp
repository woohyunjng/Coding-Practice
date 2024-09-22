#include <bits/stdc++.h>
#define int long long

#define MAX 20100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, N, C, S, E, M, res = 0;
    multiset<int> st;

    cin >> K >> N >> C;
    while (K--) {
        cin >> S >> E >> M;
        if (E < S) {
            S = 2 * N - S;
            E = 2 * N - E;
        }

        while (M--)
            arr[S].push_back(E);
    }

    for (int i = 1; i < N * 2; i++) {
        while (!st.empty() && *st.begin() <= i)
            st.erase(st.begin()), res++;

        for (int j : arr[i]) {
            if (st.size() == C && *prev(st.end()) > j)
                st.erase(prev(st.end()));
            if (st.size() < C)
                st.insert(j);
        }
    }

    cout << res;

    return 0;
}