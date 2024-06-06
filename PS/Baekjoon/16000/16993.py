from sys import stdin


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = [arr[start], arr[start], arr[start], arr[start]]
    else:
        init(tree, arr, node * 2, start, (start + end) // 2)
        init(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end)
        tree[node] = [
            max(tree[node * 2][0], tree[node * 2][3] + tree[node * 2 + 1][0]),
            max(tree[node * 2 + 1][1], tree[node * 2][1] + tree[node * 2 + 1][3]),
            max(
                tree[node * 2][2], tree[node * 2 + 1][2], tree[node * 2][1] + tree[node * 2 + 1][0]
            ),
            tree[node * 2][3] + tree[node * 2 + 1][3],
        ]


def query(tree, node, start, end, left, right):
    if end < left or right < start:
        return [-1e12, -1e12, -1e12, 0]
    elif left <= start and end <= right:
        return tree[node]
    else:
        left_tree = query(tree, node * 2, start, (start + end) // 2, left, right)
        right_tree = query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
        return [
            max(left_tree[0], left_tree[3] + right_tree[0]),
            max(right_tree[1], left_tree[1] + right_tree[3]),
            max(left_tree[2], right_tree[2], left_tree[1] + right_tree[0]),
            left_tree[3] + right_tree[3],
        ]


N = int(stdin.readline())
tree = [[-1e12, -1e12, -1e12, 0] for i in range(N * 4)]

arr = list(map(int, stdin.readline().rstrip().split()))
init(tree, arr, 1, 0, N - 1)

M = int(stdin.readline())
for i in range(M):
    p, q = map(int, stdin.readline().rstrip().split())
    print(query(tree, 1, 0, N - 1, p - 1, q - 1)[2])
