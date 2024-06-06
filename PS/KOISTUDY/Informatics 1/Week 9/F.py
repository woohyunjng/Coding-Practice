A = input()
B = str(int("".join(reversed(A))))
K = 0

while A != B:
    A = str(int(A) + int(B))
    B = str(int("".join(reversed(A))))
    K += 1

print(K, A)
