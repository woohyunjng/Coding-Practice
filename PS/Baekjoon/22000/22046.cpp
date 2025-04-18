#include "dna.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int S[2][MAX][3], V[3][3][MAX];

int change(char C) { return C == 'A' ? 0 : C == 'C' ? 1
                                                    : 2; }

void init(string A, string B) {
    int N = A.size();
    for (int i = 0; i < N; i++) {
        S[0][i + 1][change(A[i])]++, S[1][i + 1][change(B[i])]++;
        for (int j = 0; j < 3; j++) {
            S[0][i + 1][j] += S[0][i][j];
            S[1][i + 1][j] += S[1][i][j];
        }

        V[change(A[i])][change(B[i])][i + 1] = 1;
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                V[j][k][i + 1] += V[j][k][i];
    }
}

int get_distance(int x, int y) {
    bool flag = true;
    int ans = 0, K = 0;
    for (int i = 0; i < 3; i++)
        flag &= (S[0][y + 1][i] - S[0][x][i]) == (S[1][y + 1][i] - S[1][x][i]);

    if (!flag)
        return -1;

    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++) {
            ans += min(V[i][j][y + 1] - V[i][j][x], V[j][i][y + 1] - V[j][i][x]);
            K += max(V[i][j][y + 1] - V[i][j][x], V[j][i][y + 1] - V[j][i][x]) - min(V[i][j][y + 1] - V[i][j][x], V[j][i][y + 1] - V[j][i][x]);
        }

    ans += K / 3 * 2;
    return ans;
}
