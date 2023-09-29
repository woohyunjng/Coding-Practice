from sys import stdin


def update(tree, node, start, end, index):
    if index < start or end < index:
        return

    tree[node][0] += index
    tree[node][1] += 1

    if start != end:
        update(tree, node * 2, start, (start + end) // 2, index)
        update(tree, node * 2 + 1, (start + end) // 2 + 1, end, index)


def query(tree, node, start, end, left, right):
    if end < left or right < start:
        return [0, 0]
    elif left <= start and end <= right:
        return tree[node]

    left_val = query(tree, node * 2, start, (start + end) // 2, left, right)
    right_val = query(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)
    return (left_val[0] + right_val[0], left_val[1] + right_val[1])


N = int(stdin.readline())
tree = [[0, 0] for i in range(200001 * 4)]

res = 1

for i in range(N):
    X = int(stdin.readline())
    update(tree, 1, 0, 200000, X)
    if not i:
        continue

    left = query(tree, 1, 0, 200000, 0, X - 1)
    right = query(tree, 1, 0, 200000, X + 1, 200000)
    res = res * ((left[1] - right[1]) * X - left[0] + right[0]) % (10**9 + 7)

print(res)
