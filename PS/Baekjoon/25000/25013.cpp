#include "onetwothree.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX = 15001;

void maximize(vector<int> S) {
    vector<int> V, D[3];
    int N = S.size(), A = N / 3, ansX = 0, ansY = 0, X, Y;
    queue<int> q[2];

    bool flag;

    for (int i = 0; i < N; i++)
        V.push_back((int)D[S[i] - 1].size()), D[S[i] - 1].push_back(i);

    for (int i = 0; i <= N / 3; i++) {
        A = min(A, (int)min(D[0].size(), D[2].size()) - i);
        while (A >= 0) {
            flag = true, X = 0;

            for (int j = 0; j < N; j++) {
                if (S[j] == 1 && V[j] < i)
                    q[0].push(D[2][D[2].size() - i + V[j]]);
                else if (S[j] == 3 && V[j] < A)
                    q[1].push(D[0][D[0].size() - A + V[j]]);
                else if (S[j] == 2) {
                    for (int k = 0; k < 2; k++)
                        while (!q[k].empty() && q[k].front() < j)
                            q[k].pop();

                    if (q[0].empty() && q[1].empty())
                        continue;
                    else if (q[0].empty() || (!q[1].empty() && q[0].front() > q[1].front()))
                        q[1].pop(), X++;
                    else
                        q[0].pop(), X++;
                }
            }

            for (int j = 0; j < 2; j++)
                while (!q[j].empty())
                    q[j].pop();

            if (X == i + A) {
                if (i + A > ansX + ansY)
                    ansX = i, ansY = A;
                break;
            }
            A--;
        }
    }

    for (int i = 0; i < N; i++) {
        if (S[i] == 1 && V[i] < ansX)
            q[0].push(D[2][D[2].size() - ansX + V[i]]);
        else if (S[i] == 3 && V[i] < ansY)
            q[1].push(D[0][D[0].size() - ansY + V[i]]);
        else if (S[i] == 2) {
            for (int k = 0; k < 2; k++)
                while (!q[k].empty() && q[k].front() < i)
                    q[k].pop();

            if (q[0].empty() && q[1].empty())
                continue;
            else if (q[0].empty() || (!q[1].empty() && q[0].front() > q[1].front())) {
                Y = q[1].front(), q[1].pop();
                X = D[2][V[Y] + ansY - D[0].size()];
                answer(X, i, Y);
            } else {
                Y = q[0].front(), q[0].pop();
                X = D[0][V[Y] + ansX - D[2].size()];
                answer(X, i, Y);
            }
        }
    }
}