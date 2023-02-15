# Xóa bỏ tất cả các phần tử cho trước khỏi list
# cách 1: dùng hàm remove()
def remove_all(numbers: list[int], value: int):
    counter = numbers.count(value)
    for i in range(counter):
        numbers.remove(value)


# cách 2: tạo danh sách con
def remove_all_v2(numbers: list[int], value: int):
    result = [x for x in numbers if x != value]
    return result


if __name__ == '__main__':
    number_list = [5, 2, 3, 5, 4, 5, 2, 5, 0, 2, 3, 5]
    print("Danh sách gốc: ")
    print(number_list)

    print("Danh sách sau khi xóa: ")
    print(remove_all_v2(number_list, 5))
