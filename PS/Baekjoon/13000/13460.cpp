#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<pr, pr, int> tp;

int N, M;
bool arr[11][11], checked[11][11][11][11];
pr go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, goal;

pr get(int A, int B, int type) {
    int res_A, res_B;
    while (true) {
        res_A = A, res_B = B;
        A += go[type].first, B += go[type].second;
        if (A <= 0 || B <= 0 || A > N || B > M || arr[A][B])
            break;
        if (goal.first == A && goal.second == B)
            return {-1, -1};
    }
    return {res_A, res_B};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int res = -1, cnt;
    pr red, blue, red_first, blue_first;
    tp A;
    string S;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= M; j++) {
            if (S[j - 1] == '#')
                arr[i][j] = true;
            else
                arr[i][j] = false;

            if (S[j - 1] == 'B')
                blue = {i, j};
            else if (S[j - 1] == 'R')
                red = {i, j};
            else if (S[j - 1] == 'O')
                goal = {i, j};
        }
    }

    queue<tp> q;
    q.push({blue, red, 0});
    checked[blue.first][blue.second][red.first][red.second] = true;

    while (!q.empty()) {
        A = q.front();
        q.pop();

        blue_first = get<0>(A), red_first = get<1>(A), cnt = get<2>(A);
        cnt++;

        for (int i = 0; i < 4; i++) {
            if (i == 0)  // 위로
            {
                if (blue_first.first < red_first.first) {
                    blue = get(blue_first.first, blue_first.second, i);
                    if (blue.first == -1)
                        continue;

                    arr[blue.first][blue.second] = true;
                    red = get(red_first.first, red_first.second, i);
                    arr[blue.first][blue.second] = false;

                    if (red.first == -1) {
                        res = cnt;
                        break;
                    }
                } else {
                    red = get(red_first.first, red_first.second, i);
                    if (red.first == -1) {
                        blue = get(blue_first.first, blue_first.second, i);
                        if (blue.first == -1)
                            continue;
                        res = cnt;
                    } else {
                        arr[red.first][red.second] = true;
                        blue = get(blue_first.first, blue_first.second, i);
                        arr[red.first][red.second] = false;

                        if (blue.first == -1)
                            continue;
                    }
                }
            } else if (i == 1)  // 아래로
            {
                if (blue_first.first > red_first.first) {
                    blue = get(blue_first.first, blue_first.second, i);
                    if (blue.first == -1)
                        continue;

                    arr[blue.first][blue.second] = true;
                    red = get(red_first.first, red_first.second, i);
                    arr[blue.first][blue.second] = false;

                    if (red.first == -1) {
                        res = cnt;
                        break;
                    }
                } else {
                    red = get(red_first.first, red_first.second, i);
                    if (red.first == -1) {
                        blue = get(blue_first.first, blue_first.second, i);
                        if (blue.first == -1)
                            continue;
                        res = cnt;
                    } else {
                        arr[red.first][red.second] = true;
                        blue = get(blue_first.first, blue_first.second, i);
                        arr[red.first][red.second] = false;

                        if (blue.first == -1)
                            continue;
                    }
                }
            } else if (i == 2)  // 왼쪽
            {
                if (blue_first.second < red_first.second) {
                    blue = get(blue_first.first, blue_first.second, i);
                    if (blue.first == -1)
                        continue;

                    arr[blue.first][blue.second] = true;
                    red = get(red_first.first, red_first.second, i);
                    arr[blue.first][blue.second] = false;

                    if (red.first == -1) {
                        res = cnt;
                        break;
                    }
                } else {
                    red = get(red_first.first, red_first.second, i);
                    if (red.first == -1) {
                        blue = get(blue_first.first, blue_first.second, i);
                        if (blue.first == -1)
                            continue;
                        res = cnt;
                    } else {
                        arr[red.first][red.second] = true;
                        blue = get(blue_first.first, blue_first.second, i);
                        arr[red.first][red.second] = false;

                        if (blue.first == -1)
                            continue;
                    }
                }
            } else  // 오른쪽
            {
                if (blue_first.second > red_first.second) {
                    blue = get(blue_first.first, blue_first.second, i);
                    if (blue.first == -1)
                        continue;

                    arr[blue.first][blue.second] = true;
                    red = get(red_first.first, red_first.second, i);
                    arr[blue.first][blue.second] = false;

                    if (red.first == -1) {
                        res = cnt;
                        break;
                    }
                } else {
                    red = get(red_first.first, red_first.second, i);
                    if (red.first == -1) {
                        blue = get(blue_first.first, blue_first.second, i);
                        if (blue.first == -1)
                            continue;
                        res = cnt;
                    } else {
                        arr[red.first][red.second] = true;
                        blue = get(blue_first.first, blue_first.second, i);
                        arr[red.first][red.second] = false;

                        if (blue.first == -1)
                            continue;
                    }
                }
            }

            if (checked[blue.first][blue.second][red.first][red.second])
                continue;
            checked[blue.first][blue.second][red.first][red.second] = true;
            q.push({blue, red, cnt});
        }

        if (res != -1)
            break;
        if (cnt >= 11)
            break;
    }

    cout << (res < 1000 ? res : -1);
    return 0;
}