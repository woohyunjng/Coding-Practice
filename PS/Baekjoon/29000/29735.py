inp = input().split()
H1, M1 = map(int, inp[0].split(":"))
H2, M2 = map(int, inp[1].split(":"))
N, T = map(int, input().split())

time = 0

if M2 < M1:
    time = M2 + 60 - M1 + (H2 - H1 - 1) * 60
else:
    time = M2 - M1 + (H2 - H1) * 60

day = (time - 1) // T
print(N // day)

after = (N % day + 1) * T
M1 += after
H1 += M1 // 60
M1 = M1 % 60

print(f"{str(H1).zfill(2)}:{str(M1).zfill(2)}")
