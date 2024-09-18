#include <bits/stdc++.h>
#define int long long

#define MAX 2100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int min_prime_factor[MAX + 1];
vector<int> primes;

void linear_sieve(int N) {
    for (int i = 2; i <= N; i++) {
        if (min_prime_factor[i] == 0) {
            min_prime_factor[i] = i;
            primes.push_back(i);
        }

        for (int p : primes) {
            if (i * p > N)
                break;
            min_prime_factor[i * p] = p;
            if (i % p == 0)
                break;
        }
    }
}

class BipartiteMatching {
  private:
    int level[MAX];

    bool hop_dfs(int K) {
        for (int i : arr[K]) {
            if (level[B[i]] == level[K] + 1 && (!B[i] || hop_dfs(B[i]))) {
                A[K] = i, B[i] = K;
                return true;
            }
        }

        level[K] = INF;
        return false;
    }

  public:
    vector<int> arr[MAX], st;
    int A[MAX], B[MAX];

    BipartiteMatching(int N) {
        fill(A, A + N + 1, 0);
        fill(B, B + N + 1, 0);

        st.clear();
        for (int i = 0; i <= N; i++)
            arr[i].clear();
    }

    void add_path(int X, int Y) {
        st.push_back(X);
        arr[X].push_back(Y);
    }

    int run() {
        queue<int> q;
        int K, res = 0, flow;

        while (true) {
            level[0] = INF;
            for (int i : st) {
                if (!A[i]) {
                    level[i] = 0;
                    q.push(i);
                } else
                    level[i] = INF;
            }

            while (!q.empty()) {
                K = q.front(), q.pop();
                for (int i : arr[K]) {
                    if (level[B[i]] == INF) {
                        level[B[i]] = level[K] + 1;
                        q.push(B[i]);
                    }
                }
            }

            if (level[0] == INF)
                break;

            for (int i : st) {
                if (!A[i] && hop_dfs(i))
                    res++;
            }
        }

        return res;
    }
};

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    vector<int> ans;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    linear_sieve(2000);

    for (int i = 2; i <= N; i++) {
        if (min_prime_factor[arr[1] + arr[i]] != arr[1] + arr[i])
            continue;
        BipartiteMatching match(N);

        for (int j = 2; j <= N; j++) {
            if (j == i || arr[j] & 1)
                continue;

            for (int k = 2; k <= N; k++) {
                if (k == i || k == j || ((arr[k] & 1) == 0))
                    continue;

                if (min_prime_factor[arr[j] + arr[k]] == arr[j] + arr[k])
                    match.add_path(j, k);
            }
        }

        if (match.run() == N / 2 - 1)
            ans.push_back(arr[i]);
    }

    if (ans.empty())
        cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for (int i : ans)
            cout << i << ' ';
    }

    return 0;
}