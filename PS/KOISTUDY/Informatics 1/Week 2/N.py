A = list(map(int, input().split()))

for i in A:
    if i <= 168:
        print("CRASH " + str(i))
        break
else:
    print("NO CRASH")
