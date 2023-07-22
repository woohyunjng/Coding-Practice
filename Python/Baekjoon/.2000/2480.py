A = list(map(int, input().split()))

if A[0] == A[1] and A[1] == A[2]:
    print(10000 + A[0] * 1000)
elif A[0] == A[1]:
    print(1000 + A[0] * 100)
elif A[0] == A[2]:
    print(1000 + A[0] * 100)
elif A[1] == A[2]:
    print(1000 + A[1] * 100)
else:
    print(max(A) * 100)
