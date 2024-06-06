A = list(map(int, input().split()))
if len(set(A)) != 3:
    print("Impossible")
else:
    print(*sorted(A))
