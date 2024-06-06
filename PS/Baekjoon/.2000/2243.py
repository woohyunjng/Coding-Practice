from sys import stdin


def update(tree, node, start, end, index, val):
    if index < start or end < index:
        return
    tree[node] += val

    if start != end:
        update(tree, node * 2, start, (start + end) // 2, index, val)
        update(tree, node * 2 + 1, (start + end) // 2 + 1, end, index, val)


def query(tree, node, start, end, val):
    tree[node] -= 1
    if start == end:
        return start

    if val <= tree[node * 2]:
        return query(tree, node * 2, start, (start + end) // 2, val)
    else:
        return query(
            tree, node * 2 + 1, (start + end) // 2 + 1, end, val - tree[node * 2]
        )


N = int(stdin.readline())
MAX = 10**6 + 1

tree = [0 for i in range(MAX * 4)]

for i in range(N):
    line = list(map(int, stdin.readline().rstrip().split()))
    if line[0] == 1:
        print(query(tree, 1, 1, MAX - 1, line[1]))
    else:
        update(tree, 1, 1, MAX - 1, line[1], line[2])
