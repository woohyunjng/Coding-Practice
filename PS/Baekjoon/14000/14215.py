A = list(sorted(map(int, input().split())))
while A[2] >= A[0] + A[1]:
    A[2] -= 1

print(sum(A))
