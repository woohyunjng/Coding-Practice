N = int(input())
print(*["swimming" for i in range(N)], flush=True)

A = input().split()
print(*[{"bowling": "soccer", "soccer": "bowling"}[i] for i in A], flush=True)
