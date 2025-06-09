#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;
typedef array<int, 2> pr;

int A[MAX][MAX], V[MAX][MAX];
pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // 상하좌우 이동을 위한 배열

int main() {
    int H, W, ans = 0, DX, DY;
    pr X;

    string S;

    cin >> H >> W; // 높이와 너비 입력

    for (int i = 0; i < H; i++) {
        cin >> S;
        for (int j = 0; j < W; j++) {
            if (S[j] == '.')
                A[i][j] = 0;
            else if (S[j] == 'F')
                A[i][j] = 1;
            else
                A[i][j] = 2;
        }

        // 입력받은 H개의 문자열을 처리가 쉽도록 2차원 배열에 저장장
    }

    /*
        마지막 상태에서부터 보자. (0, 0)에서 시작해서 자신과 동일한 종류의 동물의 발자국이 남은 길로 이동할 수 있다.

        이것들을 모두 제거했을때 위 과정을 동일시 반복할 수 있으나 위에서 지워진 길들은 어떤 동물이 방문했어도 상관이 없기 때문에 이득이 되는 방향으로 설정할 수 있다.

        따라서 정답은 매번 (0, 0)을 포함시키는 컴포넌트를 최대한 제거할 때, 최소 제거 횟수라고 할 수 있다.

        이는 0-1 BFS를 이용해서 가능하다.

        각 칸에서 인접한 동물의 발자국이 남은 길로 간선을 잇는데 동일한 발자국을 가졌으면 하나의 컴포넌트이므로 0의 가중치 간선을 추가하고 다르면 다른 컴포넌트이므로 1의 가중치 간선을 추가한다.

        0-1 BFS란? 큐(Queue) 대신 덱(Deque)을 사용하여 0과 1의 가중치를 가진 그래프를 탐색하는 방법이다.

        0-1 BFS는 일반 BFS와 비슷하지만, 가중치가 0인 간선은 덱의 앞에 추가하고, 가중치가 1인 간선은 덱의 뒤에 추가한다. 이로 인해 최단 경로를 찾을 수 있다.
     */

    deque<pr> dq;
    dq.push_back({0, 0}), V[0][0] = 1; // 시작점 초기화

    while (!dq.empty()) {
        X = dq.front(), dq.pop_front(); // 덱에서 꺼내기
        ans = max(ans, V[X[0]][X[1]]);  // 정답 갱신

        for (pr i : go) {
            DX = X[0] + i[0], DY = X[1] + i[1];                                        // 상하좌우 이동
            if (DX < 0 || DX >= H || DY < 0 || DY >= W || A[DX][DY] == 0 || V[DX][DY]) // 범위 + 방문 체크
                continue;

            if (A[DX][DY] != A[X[0]][X[1]])
                dq.push_back({DX, DY}), V[DX][DY] = V[X[0]][X[1]] + 1; // 두 정점의 값이 다를때 (비용 + 1)
            else
                dq.push_front({DX, DY}), V[DX][DY] = V[X[0]][X[1]]; // 두 정점의 값이 같을때 (비용 + 0)
        }
    }

    cout << ans << '\n'; // 결과 출력

    return 0;
}