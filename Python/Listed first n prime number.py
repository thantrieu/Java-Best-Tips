# Liệt kê n số nguyên tố đầu tiên, n > 0 nhập vào từ bàn phím.
# Số nguyên tố là số nguyên dương chỉ chia hết cho 1 và chính nó.
# Số 2, 3, 5, 7... là một số ví dụ
import math


# Hàm kiểm tra n có phải số nguyên tố không
def is_prime(n):
    if n < 2:
        return False
    bound = int(math.sqrt(n))
    i = 2
    while i <= bound:
        if n % i == 0:
            return False
        i += 1
    return True


# Hàm liệt kê n số nguyên tố đầu tiên
def listed_prime_numbers(n):
    i = 2
    count = 0
    while count < n:
        if is_prime(i):
            print(f"{i} ", end="")
            count += 1
        i += 1


value = int(input("Nhập số nguyên dương n: "))
listed_prime_numbers(value)
