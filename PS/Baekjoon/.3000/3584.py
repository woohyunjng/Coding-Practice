T = int(input())
for i in range(T):
    N = int(input())
    parent = [0 for i in range(N + 1)]

    for i in range(N - 1):
        A, B = map(int, input().split())
        parent[B] = A

    A, B = map(int, input().split())
    depth_A, depth_B = 0, 0

    X = A
    while parent[X]:
        X = parent[X]
        depth_A += 1

    X = B
    while parent[X]:
        X = parent[X]
        depth_B += 1

    if depth_B > depth_A:
        depth_A, depth_B = depth_B, depth_A
        A, B = B, A

    for i in range(depth_A - depth_B):
        A = parent[A]

    while A != B:
        A, B = parent[A], parent[B]

    print(A)
