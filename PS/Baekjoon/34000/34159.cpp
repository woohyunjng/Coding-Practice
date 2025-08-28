#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;

bool chk[MAX], tr[MAX], res[MAX];
int G[MAX];

void query(int X, int Y) { cout << "? " << X << ' ' << Y << '\n', cout.flush(); }

int answer(int X) {
    int res;
    cout << "! " << X << '\n', cout.flush();
    cin >> res;
    return res;
}

signed main() {
    int N, K, V, S, X;
    vector<int> arr;

    cin >> N, S = N;
    for (int i = 1; S > 1; i++) {
        if (chk[(i - 1) % N + 1])
            continue;

        K = -1;
        for (int j = 1; j <= N; j++)
            query(chk[j] ? 0 : (i - 1) % N + 1, !chk[j]);
        for (int j = 1; j <= N; j++)
            cin >> X, K = X == 1 && (i - 1) % N + 1 != j ? j : K;

        V = K == -1 ? (i - 1) % N + 1 : K, chk[V] = true, S--;
        if (answer(V) != 1)
            continue;
        V = K == -1 ? -1 : (i - 1) % N + 1, tr[V == -1 ? 0 : V] = true;

        for (int j = 1; j <= N; j++)
            if (!chk[j])
                arr.push_back(j);
        break;
    }

    if (S == 1) {
        for (int i = 1; i <= N; i++) {
            if (chk[i])
                query(0, 0);
            else
                query(i, 1), K = i;
        }
        for (int i = 1; i <= N; i++)
            cin >> X;
        answer(K);
    }

    while (!arr.empty()) {
        S = arr.size(), K = -1, fill(G + 1, G + N + 1, 0);
        for (int i = 0; i < S; i++)
            G[arr[i]] = arr[(i + 1) % S];

        for (int i = 1; i <= N; i++)
            query(G[i], G[i] != 0);
        for (int i = 1; i <= N; i++)
            cin >> X, res[i] = X == 1;

        if (V == -1)
            answer(arr.back()), arr.pop_back();
        else {
            for (int j = 0; j < S << 1; j++)
                tr[arr[(j + 1) % S]] |= tr[arr[j % S]] && res[arr[j % S]];
            for (int j = 0; j < S; j++)
                if (tr[arr[j]] && !tr[arr[(j + 1) % S]])
                    K = (j + 1) % S;

            if (K == -1)
                break;
            answer(arr[K]), arr.erase(arr.begin() + K);
        }
    }

    cout << "! " << 0 << '\n', cout.flush();

    return 0;
}