from collections import defaultdict

N = int(input())
tree = defaultdict(set)

top = set([])

for i in range(N):
    arr = input().split()
    K, arr = int(arr[0]), arr[1:]
    k = ""

    for j in range(K):
        k += f"{arr[j]}."
        arr[j] = k
        if not j:
            top.add(arr[j])

    for j in range(K - 1):
        tree[arr[j]].add(arr[j + 1])


def print_tree(key, K):
    print(f"{'--' * K}{key.split('.')[K]}")

    for i in sorted(list(tree[key])):
        print_tree(i, K + 1)


for key in sorted(list(top)):
    print_tree(key, 0)
