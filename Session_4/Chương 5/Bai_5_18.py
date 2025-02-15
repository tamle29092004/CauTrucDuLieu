class MyStack:
    def __init__(self):
        self.stack = []

    # Thêm phần tử vào stack
    def push(self, value):
        self.stack.append(value)

    # Lấy phần tử ra khỏi stack
    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        return None  # Nếu stack rỗng thì không pop được

    # Xem phần tử ở đỉnh stack
    def top(self):
        if not self.is_empty():
            return self.stack[-1]
        return None  # Nếu stack rỗng thì không có phần tử top

    # Kiểm tra xem stack có rỗng không
    def is_empty(self):
        return len(self.stack) == 0

# Hàm giải quyết bài toán
def find_next_greater_frequency(arr):
    # Bước 1: Tính số lần xuất hiện của mỗi phần tử trong mảng
    freq = {}
    for num in arr:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1
    
    # Bước 2: Sử dụng stack để tìm phần tử có số lần xuất hiện lớn hơn phía bên phải
    result = [-1] * len(arr)  # Khởi tạo kết quả mặc định là -1
    stack = MyStack()  # Khởi tạo stack tùy chỉnh

    # Duyệt mảng từ phải sang trái
    for i in range(len(arr) - 1, -1, -1):
        # Xóa các phần tử trong stack mà số lần xuất hiện của chúng <= số lần xuất hiện của phần tử hiện tại
        while not stack.is_empty() and freq[arr[stack.top()]] <= freq[arr[i]]:
            stack.pop()

        # Nếu stack còn phần tử, nghĩa là có phần tử có số lần xuất hiện lớn hơn phần tử hiện tại
        if not stack.is_empty():
            result[i] = arr[stack.top()]

        # Thêm phần tử hiện tại vào stack
        stack.push(i)

    return result

# Đọc số lượng bộ test
T = int(input())

for _ in range(T):
    # Đọc số phần tử của mảng
    n = int(input())
    if n == 0:
        print('')
        continue
    
    # Đọc mảng A[]
    arr = list(map(int, input().split()))
    
    # Tính toán kết quả cho mỗi bộ test
    result = find_next_greater_frequency(arr)
    
    # In ra kết quả cho bộ test này
    print(' '.join(map(str, result)))
