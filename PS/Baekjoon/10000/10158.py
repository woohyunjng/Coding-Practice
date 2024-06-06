w, h = map(int, input().split())
p, q = map(int, input().split())
t = int(input())

p = (p + t) % (2 * w)
q = (q + t) % (2 * h)

p = (2 * w - p) if p > w else p
q = (2 * h - q) if q > h else q

print(p, q)
