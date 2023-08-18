#include <iostream>
#include <queue>
using namespace std;

long long int find(long long int *parent, long long int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A, B, K;
    cin >> N;

    vector<int> arr[N + 1];
    int parent[N + 1];
    for (int i = 0 ; i < N - 1 ; i ++) {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    queue<pair<int, int>> q;
    for (int i : arr[1]) {
        q.push(make_pair(i, 1));
    }
    parent[1] = -1;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        parent[p.first] = p.second;

        for (int i : arr[p.first]) {
            if (i != p.second) {
                q.push(make_pair(i, p.first));
            }
        }
    }

    long long int new_parent[N + 1] = {}, rank[N + 1] = {}, S[N + 1];
    cin >> Q;

    for (int i = 0 ; i < Q ; i ++) {
        cin >> K;

        int K_arr[K];
        long long int res = 0;

        for (int j = 0 ; j < K ; j ++) {
            cin >> K_arr[j];
            rank[K_arr[j]] = 1;
            S[K_arr[j]] = i + 1;
            new_parent[K_arr[j]] = K_arr[j];
        }

        for (int j : K_arr) {
            if (parent[j] != -1 && S[parent[j]] == i + 1) {
                new_parent[j] = find(new_parent, parent[j]);
                res -= (long long int)(rank[new_parent[j]] * (rank[new_parent[j]] - 1) / 2) + (long long int)(rank[j] * (rank[j] - 1) / 2);
                rank[new_parent[j]] += rank[j];
                res += (long long int)(rank[new_parent[j]] * (rank[new_parent[j]] - 1) / 2);
            }
        }

        cout << res << '\n';
    }
}
