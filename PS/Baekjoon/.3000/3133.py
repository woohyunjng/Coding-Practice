from sys import stdin

MOD = 10**9 + 7


def add_lis(A, B):
    if A[0] > B[0]:
        return A
    elif A[0] < B[0]:
        return B
    return (A[0], (A[1] + B[1]) % MOD)


def query(tree, node, start, end, left, right):
    if end < left or right < start:
        return (0, 0)
    elif left <= start and end <= right:
        return tree[node]

    return add_lis(
        query(tree, node * 2, start, (start + end) // 2, left, right),
        query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right),
    )


def update(tree, node, start, end, index, value):
    if index < start or end < index:
        return
    elif start == end:
        tree[node] = add_lis(tree[node], value)
        return

    update(tree, node * 2, start, (start + end) // 2, index, value)
    update(tree, node * 2 + 1, (start + end) // 2 + 1, end, index, value)
    tree[node] = add_lis(tree[node * 2], tree[node * 2 + 1])


N = int(stdin.readline())
tree = [(0, 0) for i in range(N * 4)]
arr = []

for i in range(N):
    arr.append(tuple(map(int, stdin.readline().rstrip().split())))
arr = list(sorted(arr, key=lambda x: x[0] * 10**10 - x[1]))

arr = [(arr[i][1], i) for i in range(N)]
arr = list(sorted(arr, key=lambda x: x[0] * 10**10 - x[1]))

for i in range(N):
    if arr[i][1]:
        mx = query(tree, 1, 0, N - 1, 0, arr[i][1] - 1)
    else:
        mx = (0, 0)
    update(tree, 1, 0, N - 1, arr[i][1], (mx[0] + 1, max(mx[1], 1)))

print(tree[1][0])
print(tree[1][1])
