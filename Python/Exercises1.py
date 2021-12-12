t = int(input())
for i in range(1, t + 1):
    words = [x for x in input().split()]
    m_set = set()
    print(f'Test {i}: ')
    for e in words:
        if e not in m_set:
            print(f'{e} ', end='')
            m_set.add(e)
    print()
