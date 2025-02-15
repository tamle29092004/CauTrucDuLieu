# Chương trình chuyển đổi biểu thức hậu tố sang trung tố

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

# Hàm chuyển đổi hậu tố sang trung tố
def postfix_to_infix(expression):
    """Chuyển đổi biểu thức hậu tố thành trung tố bằng cách sử dụng stack."""
    stack = Stack()
    
    for ch in expression:  # Duyệt xuôi biểu thức hậu tố
        if ch.isalnum():  # Nếu là toán hạng, đẩy vào stack
            stack.push(ch)
        else:  # Nếu là toán tử
            op2 = stack.pop()
            op1 = stack.pop()
            new_expr = f'({op1}{ch}{op2})'  # Ghép thành biểu thức trung tố
            stack.push(new_expr)
    
    return stack.pop()

if __name__ == "__main__":
    T = int(input().strip())  # Đọc số lượng test case
    for _ in range(T):
        expression = input().strip()
        print(postfix_to_infix(expression))
