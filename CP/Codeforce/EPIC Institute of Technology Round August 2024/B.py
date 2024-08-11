from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    res = True
    l, r = 0, N - 1

    while l + 1 < r:
        if (A[l] == B[l] and A[r] == B[r]) or (A[l] == B[r] and A[r] == B[l]):
            if A[l] == B[l] and A[r] == B[r]:
                if A[l + 1] != B[l + 1]:
                    res = False
                    break
                if A[r - 1] != B[r - 1]:
                    res = False
                    break
            elif A[l] == B[r] and A[r] == B[l]:
                if A[l + 1] != B[r - 1]:
                    res = False
                    break
                if A[r - 1] != B[l + 1]:
                    res = False
                    break
            l += 1
            r -= 1
            continue
        res = False
        break

    print("Bob" if res else "Alice")
