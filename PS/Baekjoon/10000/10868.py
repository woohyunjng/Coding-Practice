from sys import stdin


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = arr[start]
        return

    init(tree, arr, node * 2, start, (start + end) // 2)
    init(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end)
    tree[node] = min(tree[node * 2], tree[node * 2 + 1])


def query(tree, node, start, end, left, right):
    if right < start or end < left:
        return 1e11
    elif left <= start and end <= right:
        return tree[node]

    left_min = query(tree, node * 2, start, (start + end) // 2, left, right)
    right_min = query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
    return min(left_min, right_min)


N, M = map(int, stdin.readline().rstrip().split())
tree = [1e11 for i in range(N * 4)]
arr = []

for i in range(N):
    arr.append(int(stdin.readline()))
init(tree, arr, 1, 0, N - 1)

for i in range(M):
    A, B = map(int, stdin.readline().rstrip().split())
    print(query(tree, 1, 0, N - 1, A - 1, B - 1))
