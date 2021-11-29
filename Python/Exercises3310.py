import sys

sys.setrecursionlimit(6500)


def sum(n):
    if n == 1:
        return n
    else:
        return 1 / n + sum(n - 1)


t = int(input("Nhập số lượng bộ test: "))
for x in range(1, t + 1, 1):
    n = int(input("Nhập n: "))
    result = sum(n)
    print(f"Test {x}: {round(result, 3)}")
