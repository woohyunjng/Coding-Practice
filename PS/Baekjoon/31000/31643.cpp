#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int res[MAX], arr[MAX], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, A, B, K;
    stack<int> st;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        res += arr[i];
    }

    rotate(arr + 1, min_element(arr + 1, arr + N + 1), arr + N + 1);

    for (int i = N; i >= 1; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            A = st.top(), st.pop();
            if (!st.empty()) {
                B = st.top();

                sm[B - A] += arr[A] - arr[B];
                sm[B - i] -= arr[A] - arr[B];
            }
        }
        st.push(i);
    }

    A = N;

    for (int i = N - 1; i >= 1; i--) {
        if (arr[i] < arr[A]) {
            sm[N - A + 1] += arr[A] - arr[1];
            sm[N - i + 1] -= arr[A] - arr[1];
            A = i;
        }
    }
    sm[N - A + 1] += arr[A] - arr[1];

    for (int i = 1; i <= N; i++) {
        sm[i] += sm[i - 1];
        res -= sm[i];
        cout << res << '\n';
    }

    return 0;
}