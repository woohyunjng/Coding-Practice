N = int(input())
A = input().rstrip()
B = input().rstrip()

odd_A, odd_B = [], []
even_A, even_B = [], []

for i in range(N):
    if i & 1:
        odd_A.append(A[i])
        odd_B.append(B[i])
    else:
        even_A.append(A[i])
        even_B.append(B[i])

odd_A = list(sorted(odd_A))
odd_B = list(sorted(odd_B))
even_A = list(sorted(even_A))
even_B = list(sorted(even_B))

print("Yes" if odd_A == odd_B and even_A == even_B else "No")
