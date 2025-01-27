from sys import stdin
from collections import defaultdict


def init(tree, arr, node, start, end):
    if start == end:
        tree[node] = arr[start]
    else:
        init(tree, arr, node * 2, start, (start + end) // 2)
        init(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end)
        tree[node] = tree[node * 2] + tree[node * 2 + 1]


def query(tree, node, start, end, left, right):
    if left > end or right < start:
        return 0
    if left <= start and end <= right:
        return tree[node]

    left_sum = query(tree, node * 2, start, (start + end) // 2, left, right)
    right_sum = query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
    return left_sum + right_sum


def update(tree, arr, node, start, end, index, val):
    if index < start or index > end:
        return
    if start == end:
        arr[index] = val
        tree[node] = val
        return

    update(tree, arr, node * 2, start, (start + end) // 2, index, val)
    update(tree, arr, node * 2 + 1, (start + end) // 2 + 1, end, index, val)
    tree[node] = tree[node * 2] + tree[node * 2 + 1]


N = int(stdin.readline())
tree = [0 for i in range(N * 4)]

arr = list(map(int, stdin.readline().rstrip().split()))
init(tree, arr, 1, 0, N - 1)

M = int(stdin.readline())
query_list = []
sum_list = defaultdict(list)

j = 0

for i in range(M):
    q = list(map(int, stdin.readline().rstrip().split()))
    if q[0] == 1:
        query_list.append(q[1:])
    else:
        sum_list[q[1]].append((q[2] - 1, q[3] - 1, j))
        j += 1

res = [0 for i in range(j)]

for i in range(len(query_list) + 1):
    if i:
        a, b = query_list[i - 1]
        update(tree, arr, 1, 0, N - 1, a - 1, b)

    for x, y, z in sum_list[i]:
        res[z] = query(tree, 1, 0, N - 1, x, y)

for i in res:
    print(i)
