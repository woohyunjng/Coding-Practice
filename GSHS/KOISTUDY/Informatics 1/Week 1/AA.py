A = list(map(int, input().split()))
B = list(map(int, input().split()))

if A[0] == A[1] or B[0] == B[1] or len(set(A + B)) != 3:
    print("NO")
else:
    if A[0] == B[0]:
        print("YES" if A[0] == A[1] + B[1] else "NO")
    elif A[0] == B[1]:
        print("YES" if A[0] == A[1] + B[0] else "NO")
    elif A[1] == B[0]:
        print("YES" if A[1] == A[0] + B[1] else "NO")
    elif A[1] == B[1]:
        print("YES" if A[1] == A[0] + B[0] else "NO")
