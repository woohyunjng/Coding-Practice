#include "Alicelib.h"
#include "Boblib.h"

#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 1024;

vector<int> adj[MAX];
int MT[MAX][MAX], DC[MAX];
bool chk[MAX];

void Alice(int N, int M, int A[], int B[]) {
    vector<pr> edges;

    for (int i = 0; i < M; i++)
        edges.push_back({A[i], B[i]});
    for (int i = 0; i <= 10; i++)
        edges.push_back({N + 11, N + i});
    for (int i = 0; i < 10; i++) {
        edges.push_back({N + i, N + i + 1});
        for (int j = 0; j < N; j++)
            if ((j + 1) & (1 << i))
                edges.push_back({j, N + i});
    }

    InitG(N + 12, edges.size());
    for (int i = 0; i < edges.size(); i++)
        MakeG(i, edges[i][0], edges[i][1]);
}

void Bob(int V, int U, int C[], int D[]) {
    for (int i = 0; i < V; i++) {
        adj[i].clear(), DC[i] = 0;
        for (int j = 0; j < V; j++)
            MT[i][j] = 0;
    }

    for (int i = 0; i < U; i++) {
        adj[C[i]].push_back(D[i]), adj[D[i]].push_back(C[i]);
        MT[C[i]][D[i]] = MT[D[i]][C[i]] = 1;
    }

    int N = V - 12;
    bool flag;

    vector<int> arr, st;
    vector<pr> edges;

    for (int i = 0; i < V; i++) {
        if (adj[i].size() != 11)
            continue;

        chk[i] = true;
        arr.clear(), st.clear(), flag = true;
        for (int j : adj[i])
            arr.push_back(j), chk[j] = true;
        for (int j : arr) {
            if (adj[j].size() != 2)
                continue;
            st.push_back(j), arr.erase(find(arr.begin(), arr.end(), j));
            break;
        }
        while (!arr.empty()) {
            for (int j : arr) {
                if (!MT[st.back()][j])
                    continue;
                st.push_back(j), arr.erase(find(arr.begin(), arr.end(), j));
                break;
            }
        }
        arr = st, reverse(arr.begin(), arr.end());

        for (int j = 0; j < 10; j++) {
            for (int k : adj[arr[j]]) {
                if (chk[k])
                    continue;
                DC[k] |= 1 << j;
            }
        }

        arr.clear();
        for (int j = 0; j < V; j++)
            if (!chk[j])
                arr.push_back(DC[j] - 1);
        sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());

        flag &= arr.size() == N && arr[0] == 0 && arr[N - 1] == N - 1;

        if (flag) {
            for (int j = 0; j < V; j++)
                for (int k = j + 1; k < V; k++) {
                    if (chk[j] || chk[k] || !MT[j][k])
                        continue;
                    edges.push_back({j, k});
                }
            break;
        }

        for (int j = 0; j < V; j++)
            DC[j] = 0, chk[j] = false;
    }

    InitMap(N, edges.size());
    for (pr i : edges)
        MakeMap(DC[i[0]] - 1, DC[i[1]] - 1);
}