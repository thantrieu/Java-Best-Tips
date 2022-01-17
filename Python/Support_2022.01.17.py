option = 'Nhập lựa chọn: 1. Cộng, 2. Trừ, 3. Nhân, 0. Thoát.\n' \
         'Xin mời chọn: '

while True:
    try:
        choice = int(input(option))
        break
    except ValueError:
        print('==> Giá trị không hợp lệ. Vui lòng nhập số nguyên 0-3.')

match choice:
    case 0:
        print('==> Chương trình kết thúc.')
    case 1:
        a = int(input('Nhập số a: '))
        b = int(input('Nhập số b: '))
        print(f'{a} + {b} = {a + b}')
    case 2:
        a = int(input('Nhập số a: '))
        b = int(input('Nhập số b: '))
        print(f'{a} - {b} = {a - b}')
    case 3:
        a = int(input('Nhập số a: '))
        b = int(input('Nhập số b: '))
        print(f'{a} * {b} = {a * b}')
    case _:
        print('==> Vui lòng chọn số từ 0-3.')
