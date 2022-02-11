import re

if __name__ == '__main__':
    email = input('Nhập email: ')
    pattern = '^[a-z_]+[a-z]+[-._0-9]*@[a-z0-9]+.[a-z]{2,4}$'
    matcher = re.search(pattern, email)
    if matcher:
        print('Email hợp lệ!')
    else:
        print('Email không hợp lệ!')