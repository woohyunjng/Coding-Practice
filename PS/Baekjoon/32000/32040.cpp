#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 200001;

int P[MAX][4], D[MAX], R[MAX],
    RV[4] = {1, 0, 3, 2},
    CS[3][4] = {{0, 0, 2, 3},
                {0, 0, 3, 2},
                {0, 0, 0, 1}},
    BS[3][4] = {{0, 0, 0, 0},
                {0, 0, 1, 1},
                {0, 0, 0, 0}};
set<pr> st[3][4][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, S[4];
    char C;

    pr X, Y;

    vector<int> ans, comp[4];

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    tp K;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i][0] >> P[i][1] >> C, R[i] = -1, P[i][1] = -P[i][1];
        P[i][2] = P[i][0] + P[i][1], P[i][3] = P[i][1] - P[i][0];
        for (int j = 0; j < 4; j++)
            comp[j].push_back(P[i][j]);

        if (C == 'N')
            D[i] = 0;
        else if (C == 'S')
            D[i] = 1;
        else if (C == 'E')
            D[i] = 2;
        else if (C == 'W')
            D[i] = 3;
    }

    for (int i = 0; i < 4; i++)
        sort(comp[i].begin(), comp[i].end()), comp[i].erase(unique(comp[i].begin(), comp[i].end()), comp[i].end()), S[i] = comp[i].size();

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 4; j++)
            P[i][j] = lower_bound(comp[j].begin(), comp[j].end(), P[i][j]) - comp[j].begin() + 1;
        for (int x = 0; x < 4; x++)
            for (int y = x + 1; y < 4; y++) {
                if (D[i] != x && D[i] != y)
                    continue;
                st[x][y][P[i][CS[x][y]]].insert({comp[RV[CS[x][y]]][P[i][RV[CS[x][y]]] - 1] * (BS[x][y] ? -1 : 1), i});
            }
    }

    set<pr>::iterator iter;

    for (int x = 0; x < 4; x++)
        for (int y = x + 1; y < 4; y++)
            for (int i = 1; i <= S[CS[x][y]]; i++) {
                iter = st[x][y][i].begin();
                if (iter == st[x][y][i].end())
                    continue;
                while (next(iter) != st[x][y][i].end()) {
                    if (D[(*iter)[1]] == x && D[(*next(iter))[1]] == y)
                        pq.push({abs((*iter)[0] - (*next(iter))[0]), (*iter)[1], (*next(iter))[1]});
                    iter++;
                }
            }

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if ((R[K[1]] != -1 && R[K[1]] != K[0]) || (R[K[2]] != -1 && R[K[2]] != K[0]))
            continue;
        for (int i = 1; i <= 2; i++) {
            if (R[K[i]] == K[0])
                continue;
            A = K[i];
            if (R[A] != K[0]) {
                for (int x = 0; x < 4; x++)
                    for (int y = x + 1; y < 4; y++) {
                        if (D[A] != x && D[A] != y)
                            continue;
                        iter = st[x][y][P[A][CS[x][y]]].find({comp[RV[CS[x][y]]][P[A][RV[CS[x][y]]] - 1] * (BS[x][y] ? -1 : 1), A});
                        if (iter != st[x][y][P[A][CS[x][y]]].begin() && next(iter) != st[x][y][P[A][CS[x][y]]].end()) {
                            X = *prev(iter), Y = *next(iter);
                            if (D[X[1]] == x && D[Y[1]] == y)
                                pq.push({abs(X[0] - Y[0]), X[1], Y[1]});
                        }
                        st[x][y][P[A][CS[x][y]]].erase(iter);
                    }
            }
            R[A] = K[0];
        }
    }

    for (int i = 1; i <= N; i++)
        if (R[i] == -1)
            ans.push_back(i);

    for (int i : ans)
        cout << i << '\n';

    return 0;
}