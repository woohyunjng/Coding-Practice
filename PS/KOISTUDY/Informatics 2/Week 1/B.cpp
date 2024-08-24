#include <bits/stdc++.h>
#define int long long

#define MAX 10
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

struct Team {
    int score, goal_earned, many_goal, index;

    bool operator<(const Team &t) const {
        if (score != t.score)
            return score > t.score;
        if (goal_earned != t.goal_earned)
            return goal_earned > t.goal_earned;
        if (many_goal != t.many_goal)
            return many_goal > t.many_goal;
        return index > t.index;
    }
};

Team arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N = 4, A, B, C;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B >> C >> arr[i].goal_earned >> arr[i].many_goal;
        arr[i].score = A * 3 + B;
        arr[i].index = i;
    }
    sort(arr + 1, arr + N + 1);

    cout << arr[1].index << '\n'
         << arr[2].index;

    return 0;
}