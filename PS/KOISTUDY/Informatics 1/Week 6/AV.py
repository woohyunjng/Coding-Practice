A = int(input(), 16)
for i in range(1, 16):
    print(
        hex(A).upper()[2:], "*", hex(i).upper()[2:], "=", hex(A * i).upper()[2:], sep=""
    )
