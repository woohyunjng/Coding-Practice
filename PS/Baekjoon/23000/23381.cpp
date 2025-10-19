#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 4001;
const int MAX_LEN = 16;
const int MOD = 1'000'000'007;

int N, S[MAX], ans[MAX];
vector<int> val[MAX_LEN];
map<int, int> mp[MAX_LEN];

int query() {
    cout << "? ";
    for (int i = 0; i <= N; i++)
        cout << S[i] << ' ';
    cout << '\n', cout.flush();

    int ret;
    cin >> ret;
    return ret;
}

signed main() {
    random_device rd;
    mt19937 gen(rd());

    vector<int> arr;
    set<int> st;

    int V, P, R;

    for (int i = 1; i <= 15; i++) {
        while (true) {
            arr.clear(), st.clear();
            for (int j = 0; j < i; j++)
                arr.push_back(gen() % MOD);

            for (int j = 0; j < (1 << i); j++) {
                V = 0;
                for (int k = 0; k < i; k++) {
                    if (j & (1 << k))
                        V *= arr[k], V %= MOD;
                    else
                        V += arr[k], V %= MOD;
                }
                st.insert(V);
            }

            if (st.size() != (1 << i))
                continue;
            break;
        }

        for (int j : arr)
            val[i].push_back(j);
        for (int j = 0; j < (1 << i); j++) {
            V = 0;
            for (int k = 0; k < i; k++) {
                if (j & (1 << k))
                    V *= arr[k], V %= MOD;
                else
                    V += arr[k], V %= MOD;
            }
            mp[i][V] = j;
        }
    }

    cin >> N, P = N;
    while (P) {
        V = min(P, 15ll);
        for (int i = 0; i < V; i++)
            S[P - V + i + 1] = val[V][i];

        R = query();
        for (int i = 0; i < V; i++)
            ans[P - V + i] = (mp[V][R] >> i) & 1;

        for (int i = 0; i < V; i++)
            S[P - i] = ans[P - i - 1];
        P -= V;
    }

    cout << "! ";
    for (int i = 0; i < N; i++)
        cout << (ans[i] ? 'x' : '+');
    cout << '\n', cout.flush();

    return 0;
}