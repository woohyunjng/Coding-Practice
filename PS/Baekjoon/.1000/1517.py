from sys import setrecursionlimit

setrecursionlimit(10**5)


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = arr[start]
    else:
        init(tree, arr, node * 2, start, (start + end) >> 1)
        init(tree, arr, node * 2 + 1, ((start + end) >> 1) + 1, end)
        tree[node] = tree[node * 2] + tree[node * 2 + 1]


def update(tree, node, start, end, index, value):
    if index < start or end < index:
        return
    elif start == end:
        tree[node] = value
        return

    update(tree, node * 2, start, (start + end) >> 1, index, value)
    update(tree, node * 2 + 1, ((start + end) >> 1) + 1, end, index, value)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]


def query(tree, node, start, end, left, right):
    if left <= start and end <= right:
        return tree[node]
    elif right < start or end < left:
        return 0

    left_sum = query(tree, node * 2, start, (start + end) >> 1, left, right)
    right_sum = query(tree, node * 2 + 1, ((start + end) >> 1) + 1, end, left, right)
    return left_sum + right_sum


N = int(input())
A = list(map(int, input().split()))

tree = [0 for i in range(N * 4)]
arr = []

for i in range(N):
    arr.append((A[i], i))
arr = list(sorted(arr, reverse=True))

init(tree, [1 for i in range(N)], 1, 0, N - 1)

res = 0
for i, j in arr:
    res += query(tree, 1, 0, N - 1, j, N) - 1
    update(tree, 1, 0, N - 1, j, 0)
print(res)
