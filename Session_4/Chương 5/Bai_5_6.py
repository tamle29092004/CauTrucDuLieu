# Chương trình chuyển đổi biểu thức trung tố sang hậu tố

# Lớp Stack tự xây dựng
class Stack:
    def __init__(self):
        self.items = []  # Danh sách để lưu các phần tử trong stack
    
    def push(self, item):
        """Thêm một phần tử vào đỉnh stack."""
        self.items.append(item)
    
    def pop(self):
        """Lấy và loại bỏ phần tử trên cùng của stack."""
        if not self.is_empty():
            return self.items.pop()
        return None
    
    def top(self):
        """Trả về phần tử trên cùng của stack mà không loại bỏ nó."""
        return self.items[-1] if not self.is_empty() else None
    
    def is_empty(self):
        """Kiểm tra xem stack có rỗng không."""
        return len(self.items) == 0

# Hàm xác định độ ưu tiên của toán tử
def precedence(op):
    """Trả về độ ưu tiên của toán tử."""
    if op in ('+', '-'):
        return 1
    if op in ('*', '/'):
        return 2
    if op == '^':
        return 3
    return 0

# Hàm chuyển đổi trung tố sang hậu tố
def infix_to_postfix(expression):
    """Chuyển đổi biểu thức trung tố thành hậu tố bằng cách sử dụng stack."""
    stack = Stack()
    output = []
    
    for ch in expression:
        if ch.isalnum():  # Nếu là toán hạng, thêm vào kết quả
            output.append(ch)
        elif ch == '(':  # Nếu là dấu ngoặc mở, đẩy vào stack
            stack.push(ch)
        elif ch == ')':  # Nếu là dấu ngoặc đóng, lấy toán tử ra khỏi stack
            while not stack.is_empty() and stack.top() != '(':
                output.append(stack.pop())
            stack.pop()  # Loại bỏ dấu ngoặc mở
        else:  # Nếu là toán tử
            while (not stack.is_empty() and precedence(stack.top()) >= precedence(ch)):
                output.append(stack.pop())
            stack.push(ch)
    
    while not stack.is_empty():  # Lấy hết toán tử còn lại trong stack
        output.append(stack.pop())
    
    return ''.join(output)

if __name__ == "__main__":
    T = int(input().strip())  # Đọc số lượng test case
    for _ in range(T):
        expression = input().strip()
        print(infix_to_postfix(expression))
