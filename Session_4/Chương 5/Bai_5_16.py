#đây là chương trình python về việc tìm diện tích lớn nhất của hình chữ nhật
class MyStack:
    def __init__(self):
        # Khởi tạo stack là một danh sách rỗng
        self.stack = []

    def push(self, value):
        # Thêm phần tử vào cuối stack
        self.stack.append(value)

    def pop(self):
        # Loại bỏ và trả về phần tử trên đỉnh stack
        if self.is_empty():
            return None
        return self.stack.pop()

    def top(self):
        # Trả về phần tử trên đỉnh stack mà không loại bỏ nó
        if self.is_empty():
            return None
        return self.stack[-1]

    def is_empty(self):
        # Kiểm tra stack có trống không
        return len(self.stack) == 0

    def size(self):
        # Trả về số lượng phần tử trong stack
        return len(self.stack)


def largestRectangleArea(heights):
    stack = MyStack()  # Sử dụng stack tùy chỉnh để lưu trữ các chỉ số
    max_area = 0  # Khởi tạo diện tích lớn nhất
    n = len(heights)  # Số cột (chiều dài mảng heights)

    for i in range(n):
        # Duyệt qua từng cột từ trái sang phải
        while not stack.is_empty() and heights[stack.top()] > heights[i]:
            # Nếu chiều cao của cột hiện tại nhỏ hơn chiều cao của cột ở đỉnh stack,
            # tính diện tích hình chữ nhật có chiều cao bằng chiều cao cột ở đỉnh stack
            h = heights[stack.pop()]  # Lấy chiều cao cột ở đỉnh stack
            # Tính chiều rộng: nếu stack trống thì chiều rộng là i, ngược lại là khoảng cách giữa
            # chỉ số cột hiện tại và cột phía trước cùng chiều cao
            width = i if stack.is_empty() else i - stack.top() - 1
            # Cập nhật diện tích lớn nhất
            max_area = max(max_area, h * width)
        # Đưa chỉ số cột hiện tại vào stack
        stack.push(i)

    # Xử lý các cột còn lại trong stack
    while not stack.is_empty():
        h = heights[stack.pop()]  # Lấy chiều cao của cột ở đỉnh stack
        width = n if stack.is_empty() else n - stack.top() - 1  # Tính chiều rộng của hình chữ nhật
        max_area = max(max_area, h * width)  # Cập nhật diện tích lớn nhất

    return max_area  # Trả về diện tích lớn nhất

# Nhập số lượng bộ test
T = int(input())
for _ in range(T):
    # Nhập số cột
    N = int(input())
    # Nhập chiều cao của các cột
    H = list(map(int, input().split()))

    # In diện tích lớn nhất của hình chữ nhật có thể được tạo ra
    print(largestRectangleArea(H))
