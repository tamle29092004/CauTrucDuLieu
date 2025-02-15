#đây là chương trình về đếm số ngoặc đổi chiều
class CustomStack:
    def __init__(self):
        self.elements = []  # Khởi tạo stack rỗng
    
    def push(self, item):
        self.elements.append(item)  # Thêm phần tử vào stack
    
    def pop(self):
        if not self.is_empty():
            return self.elements.pop()  # Xóa phần tử trên cùng
        return None  
    
    def top(self):
        if not self.is_empty():
            return self.elements[-1]  # Lấy phần tử trên cùng
        return None
    
    def is_empty(self):
        return len(self.elements) == 0  # Kiểm tra stack rỗng
    
    def size(self):
        return len(self.elements)  # Lấy số phần tử trong stack

def min_swaps_to_balance(s):
    stack = CustomStack()
    swaps = 0  
    
    for ch in s:
        if ch == '(':
            stack.push(ch)  # Đưa '(' vào stack
        else:  # ch == ')'
            if not stack.is_empty() and stack.top() == '(':
                stack.pop()  # Loại bỏ cặp ngoặc hợp lệ
            else:
                swaps += 1  # Đánh dấu ngoặc sai cần đổi
                stack.push('(')  # Chuyển ')' thành '(' để cân bằng
    
    return swaps + stack.size() // 2  # Tổng số lần đổi cần thiết

if __name__ == "__main__":
    T = int(input())  # Số lượng test case
    
    for _ in range(T):
        S = input().strip()
        print(min_swaps_to_balance(S))
