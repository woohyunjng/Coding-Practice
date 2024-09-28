#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];
vector<pr> adj[MAX];
vector<tp> srt;
int longest[MAX], rnk[MAX], sm[MAX], in_degree[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, L, C;
    queue<int> q;
    stack<int> st;

    cin >> N >> M;

    while (M--) {
        cin >> A >> B >> L;
        adj[A].push_back({B, L});
        in_degree[B]++;
    }

    for (int i = 1; i <= N; i++) {
        if (!in_degree[i])
            q.push(i);
    }

    while (!q.empty()) {
        A = q.front(), q.pop();
        st.push(A);

        for (pr i : adj[A]) {
            if (--in_degree[i.first] == 0)
                q.push(i.first);
        }
    }

    while (!st.empty()) {
        A = st.top(), st.pop();
        longest[A] = 0;

        for (pr i : adj[A])
            longest[A] = max(longest[A], longest[i.first] + 1);

        arr[longest[A]].push_back(A);
    }

    rnk[0] = INF, sm[0] = 0;

    for (int i = 0; i <= N; i++) {
        srt.clear();

        for (int j : arr[i]) {
            A = 0, B = INF;

            for (pr k : adj[j]) {
                if (longest[k.first] != i - 1)
                    continue;
                if (k.second < B || (k.second == B && rnk[k.first] < rnk[A])) {
                    A = k.first;
                    B = k.second;
                }
            }

            if (A == 0)
                B = 0;

            sm[j] = sm[A] + B;
            srt.push_back({B, rnk[A], j});
        }

        sort(srt.begin(), srt.end());
        for (int j = 0; j < srt.size(); j++)
            rnk[srt[j][2]] = j + 1;
    }

    for (int i = 1; i <= N; i++)
        cout << longest[i] << ' ' << sm[i] << '\n';

    return 0;
}