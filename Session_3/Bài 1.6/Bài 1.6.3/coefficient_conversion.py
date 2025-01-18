#đây là chương trình chuyển đổi hệ số từ hệ thập phân sang hệ nhị phân
def decimal_to_binary(n):
    stack = []
    print(f"Chuyển đổi số thập phân: {n} sang nhị phân...")

    if n == 0:
        stack.append(0)

    while n > 0:
        remainder = n % 2
        stack.append(remainder)
        n = n // 2
        print(f"Chia n = {n} ; dư = {remainder} vào ngăn xếp.")

    binary = ''
    while stack:
        binary += str(stack.pop())

    print(f"Đã lấy {binary} từ ngăn xếp thành nhị phân là (binary)!")

    return binary

# Minh họa
number = 13
binary = decimal_to_binary(number)
print(f"Số nhị phân của {number} là: {binary}")  # 1101