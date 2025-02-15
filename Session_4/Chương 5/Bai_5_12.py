# Chương trình tính giá trị biểu thức tiền tố

class Stack:
    def __init__(self):
        self.items = []  # Khởi tạo danh sách để lưu trữ phần tử trong ngăn xếp
    
    def push(self, item):
        """Thêm một phần tử vào đỉnh stack."""
        self.items.append(item)
    
    def pop(self):
        """Lấy và loại bỏ phần tử trên cùng của stack."""
        return self.items.pop() if not self.is_empty() else None
    
    def is_empty(self):
        """Kiểm tra xem stack có rỗng không."""
        return len(self.items) == 0

def evaluate_prefix(expression):
    """Tính giá trị biểu thức tiền tố."""
    stack = Stack()
    operators = {'+', '-', '*', '/'}
    
    # Duyệt ngược từ cuối chuỗi về đầu
    for ch in reversed(expression):
        if ch.isdigit():  # Nếu là số, đẩy vào stack
            stack.push(int(ch))
        elif ch in operators:  # Nếu là toán tử, lấy 2 toán hạng từ stack
            op1 = stack.pop()
            op2 = stack.pop()
            
            # Thực hiện phép toán tương ứng
            if ch == '+':
                result = op1 + op2
            elif ch == '-':
                result = op1 - op2
            elif ch == '*':
                result = op1 * op2
            elif ch == '/':
                result = op1 // op2  # Chia lấy phần nguyên
            
            # Đẩy kết quả vào stack
            stack.push(result)
    
    return stack.pop()  # Kết quả cuối cùng

if __name__ == "__main__":
    T = int(input().strip())  # Số lượng bộ test
    for _ in range(T):
        expression = input().strip()
        print(evaluate_prefix(expression))
