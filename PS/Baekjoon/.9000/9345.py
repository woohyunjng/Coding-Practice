from sys import stdin


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = [arr[start], arr[start]]
    else:
        init(tree, arr, node * 2, start, (start + end) // 2)
        init(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end)
        tree[node] = [
            min(tree[node * 2][0], tree[node * 2 + 1][0]),
            max(tree[node * 2][1], tree[node * 2 + 1][1]),
        ]


def query(tree, node, start, end, left, right):
    if right < start or end < left:
        return True
    elif left <= start and end <= right:
        return left <= tree[node][0] and tree[node][1] <= right
    else:
        left_val = query(tree, node * 2, start, (start + end) // 2, left, right)
        right_val = query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
        return left_val * right_val


def update(tree, node, start, end, index, value):
    if index < start or end < index:
        return
    elif start == end == index:
        tree[node] = [value, value]
    else:
        update(tree, node * 2, start, (start + end) // 2, index, value)
        update(tree, node * 2 + 1, (start + end) // 2 + 1, end, index, value)
        tree[node] = [
            min(tree[node * 2][0], tree[node * 2 + 1][0]),
            max(tree[node * 2][1], tree[node * 2 + 1][1]),
        ]


T = int(stdin.readline())
for i in range(T):
    N, K = map(int, stdin.readline().rstrip().split())
    arr = list(range(N))

    tree = [[1e9, -1] for j in range(N * 4)]
    init(tree, arr, 1, 0, N - 1)

    for j in range(K):
        Q, A, B = map(int, stdin.readline().rstrip().split())
        if Q == 0:
            update(tree, 1, 0, N - 1, A, arr[B])
            update(tree, 1, 0, N - 1, B, arr[A])
            arr[A], arr[B] = arr[B], arr[A]
        else:
            print("YES" if query(tree, 1, 0, N - 1, A, B) else "NO")
