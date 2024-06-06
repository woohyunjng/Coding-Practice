N_A, N_B = map(int, input().split())
A = set(map(int, input().split()))
B = set(map(int, input().split()))

print(N_A + N_B - len(A & B) * 2)
