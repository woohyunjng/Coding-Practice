#include <bits/stdc++.h>
using namespace std;

const int MAX = 22;

int A[MAX][MAX], V[MAX][MAX][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, X, Y;
    string _S;

    vector<int> arr;

    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        cin >> _S;
        for (int j = 1; j <= W; j++)
            A[i][j] = (_S[j - 1] == 'X' ? 1 : 0);
    }

    for (int k = 1; k <= H; k++)
        for (int l = 1; l <= W; l++)
            for (int i = 1; i + k - 1 <= H; i++)
                for (int j = 1; j + l - 1 <= W; j++) {
                    arr.clear(), X = i + k - 1, Y = j + l - 1;

                    for (int x = i; x <= X; x++)
                        for (int y = j; y <= Y; y++) {
                            if (A[x][y])
                                continue;
                            arr.push_back(V[i][j][x - 1][y - 1] ^ V[i][y + 1][x - 1][Y] ^ V[x + 1][j][X][y - 1] ^ V[x + 1][y + 1][X][Y]);
                        }

                    sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());

                    V[i][j][X][Y] = arr.size();
                    for (int x = 0; x < arr.size(); x++)
                        if (arr[x] != x)
                            V[i][j][X][Y] = min(V[i][j][X][Y], x);
                }

    if (V[1][1][H][W])
        cout << "First" << '\n';
    else
        cout << "Second" << '\n';

    return 0;
}