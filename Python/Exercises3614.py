def length(x):
    return len(x)


t = int(input())
for i in range(1, t + 1):
    string = input()
    words = string.split()
    words.sort(key=lambda x: len(x), reverse=False)  # lambda x: len(x)
    for x in words:
        print(f"{x} ", end="")
    print()

# Ctrl Alt L
