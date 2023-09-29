from sys import stdin


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = arr[start]
    else:
        init(tree, arr, node * 2, start, (start + end) // 2)
        init(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end)
        tree[node] = tree[node * 2] + tree[node * 2 + 1]


def update(tree, node, start, end, index, val):
    if index < start or end < index:
        return
    tree[node] += val

    if start != end:
        update(tree, node * 2, start, (start + end) // 2, index, val)
        update(tree, node * 2 + 1, (start + end) // 2 + 1, end, index, val)


def query(tree, node, start, end, left, right):
    if end < left or right < start:
        return 0
    elif left <= start and end <= right:
        return tree[node]

    return query(tree, node * 2, start, (start + end) // 2, left, right) + query(
        tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right
    )


T = int(stdin.readline())
for i in range(T):
    N, M = map(int, stdin.readline().rstrip().split())
    tree = [0 for i in range((N + M + 1) * 4)]
    init(tree, [1] * N + [0] * M, 1, 0, N + M - 1)

    last = N
    arr = list(map(int, stdin.readline().rstrip().split()))

    place = list(reversed(range(N)))

    for i in range(M):
        print(query(tree, 1, 0, N + M - 1, place[arr[i] - 1] + 1, N + M - 1), end=" ")
        update(tree, 1, 0, N + M - 1, last, 1)
        update(tree, 1, 0, N + M - 1, place[arr[i] - 1], -1)
        place[arr[i] - 1] = last
        last += 1

    print()
