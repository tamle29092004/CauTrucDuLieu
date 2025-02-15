# Chương trình xóa dấu ngoặc khỏi biểu thức toán học đúng
from itertools import combinations

# Lớp Stack tự xây dựng để quản lý dấu ngoặc
class Stack:
    def __init__(self):
        self.data = []  # Danh sách lưu trữ phần tử trong ngăn xếp
    
    def push(self, item):
        self.data.append(item)  # Thêm phần tử vào ngăn xếp
    
    def pop(self):
        if not self.is_empty():
            return self.data.pop()  # Lấy phần tử trên cùng và xóa nó khỏi ngăn xếp
        return None
    
    def top(self):
        return self.data[-1] if not self.is_empty() else None  # Lấy phần tử trên cùng mà không xóa
    
    def is_empty(self):
        return len(self.data) == 0  # Kiểm tra ngăn xếp có rỗng không

# Hàm tìm tất cả các cách xóa dấu ngoặc đúng
def remove_brackets(expression):
    stack = Stack()
    pairs = []
    
    # Xác định vị trí các cặp dấu ngoặc
    bracket_positions = []  # Danh sách lưu vị trí của dấu ngoặc mở và đóng
    for i, ch in enumerate(expression):
        if ch == '(': 
            stack.push(i)  # Đưa vị trí của dấu ngoặc mở vào ngăn xếp
        elif ch == ')':
            if not stack.is_empty():
                open_index = stack.pop()  # Ghép cặp với dấu ngoặc mở tương ứng
                bracket_positions.append((open_index, i))
    
    # Tạo tất cả các cách xóa dấu ngoặc hợp lệ
    results = set()
    n = len(bracket_positions)
    for r in range(1, n + 1):  # Duyệt qua tất cả số lượng dấu ngoặc cần xóa
        for combination in combinations(bracket_positions, r):  # Chọn r cặp dấu ngoặc để xóa
            to_remove = set(idx for pair in combination for idx in pair)  # Lưu vị trí dấu ngoặc cần xóa
            new_expr = ''.join(expression[i] for i in range(len(expression)) if i not in to_remove)  # Tạo biểu thức mới
            results.add(new_expr)
    
    # Trả về danh sách kết quả sắp xếp theo thứ tự từ điển
    return sorted(results)

if __name__ == "__main__":
    expression = input().strip()
    results = remove_brackets(expression)
    for res in results:
        print(res)
