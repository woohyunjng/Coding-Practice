#include "advisor.h"
#include "assistant.h"

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int V[MAX], P[MAX], B[MAX];
bool chk[MAX];
vector<int> arr[MAX];

typedef array<int, 2> pr;

void Assist(unsigned char *A, int N, int K, int R) {
    int X = 0, Y, Z;
    for (int i = 0; i < K; i++)
        V[i] = P[i] = i, chk[i] = true;
    fill(chk + K, chk + N, false);

    deque<int> dq;

    for (int i = 0; i < K; i++)
        if (A[i])
            dq.push_back(i);

    for (int i = 0; i < N; i++) {
        Z = GetRequest();
        if (!chk[Z]) {
            Y = dq.front(), dq.pop_front();
            chk[V[Y]] = false, PutBack(V[Y]);
            chk[Z] = true, V[Y] = Z, P[Z] = Y;
        }
        if (A[K + i])
            dq.push_back(P[Z]);
    }
}

void ComputeAdvice(int *C, int N, int K, int M) {
    vector<bool> ans(N + K, false);

    set<pr> st;
    pr X;
    int Y;

    for (int i = 0; i < N; i++)
        chk[i] = false, arr[i].clear();
    for (int i = 0; i < K; i++)
        V[i] = P[i] = B[i] = i, chk[i] = true;

    for (int i = 0; i < N; i++)
        arr[C[i]].push_back(i);
    for (int i = 0; i < N; i++)
        arr[i].push_back(N), reverse(arr[i].begin(), arr[i].end());

    for (int i = 0; i < K; i++)
        st.insert({arr[i].back(), i});

    for (int i = 0; i < N; i++) {
        if (chk[C[i]])
            st.erase(st.find({arr[C[i]].back(), C[i]}));
        else {
            X = *st.rbegin(), st.erase(prev(st.end()));
            ans[B[P[X[1]]]] = true, V[P[X[1]]] = C[i];
            P[C[i]] = P[X[1]], chk[X[1]] = false;
        }
        arr[C[i]].pop_back(), st.insert({arr[C[i]].back(), C[i]});
        chk[C[i]] = true, B[P[C[i]]] = K + i;
    }

    for (bool i : ans)
        WriteAdvice(i);
}