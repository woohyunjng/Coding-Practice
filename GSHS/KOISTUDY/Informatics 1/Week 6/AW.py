N = int(input())
print(
    *map(
        lambda x: "X" if ("3" in str(x) or "6" in str(x) or "9" in str(x)) else x,
        range(1, N + 1),
    )
)
