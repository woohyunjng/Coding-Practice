#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, cur = 0, res = 0;
    string S;
    stack<int> st;

    cin >> N;
    cin >> M;

    while (M--) {
        cin >> S >> K;

        for (int i = 0; i < N * 2; i++) {
            if (S[i] == 'F')
                st.push(N * 2 - 1 - i);
        }

        reverse(S.begin(), S.end());
        for (int i = 0; i < N * 2; i += 2) {
            if (S[i] == 'F' && S[i + 1] == 'F') {
                female += 2;
                st.pop(), st.pop();
            } else if (S[i] == 'M' && S[i + 1] == 'M') {
                male += 2;
                if (male <= female)
                    continue;
                else {
                    if (st.empty()) {
                        cout << -1;
                        return 0;
                    }
                    K = st.top(), st.pop();

                    S[K] = 'M', S[i + 1] = 'F';
                    male--, female++;

                    res = max(res, K - i - 1);
                }
            } else {
                female++, male++;
                st.pop();
            }
        }
    }

    cout << res;

    return 0;
}