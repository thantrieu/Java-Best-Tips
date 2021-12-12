import matplotlib.pyplot as pp
import numpy as np

months = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])
incomes = [15.6, 14.2, 25.4, 36.6, 45.7, 56.3, 54.8, 60.1, 72.5, 60.4, 34.6, 38.5]
pp.bar(months, incomes, color=['red', 'green'])
# Đặt tên trục x:
pp.xlabel('Tháng')
pp.ylabel('Thu nhập')
pp.title('Thu nhập năm 2025 của tôi')
pp.show()
