#chương trình python đơn giản để triển khai ngăn xếp
# stack_python.py
import sys
sys.stdout.reconfigure(encoding='utf-8')

class Stack:
    def __init__(self):
        # Sử dụng danh sách để lưu trữ các phần tử
        self.elements = []

    def push(self, item):
        # Thêm phần tử vào cuối danh sách
        self.elements.append(item)
        print(f"Đã thêm '{item}' vào ngăn xếp.")

    def pop(self):
        # Logic bỏ phần tử cuối cùng
        if not self.is_empty():
            item = self.elements.pop()  # Lấy và xóa phần tử cuối cùng
            print(f"Đã lấy '{item}' khỏi ngăn xếp.")
            return item
       
        else:
            print("Ngăn xếp trống, không thể lấy phần tử!")
        return None

    def peek(self):
        # Truy cập phần tử cuối cùng
        if not self.is_empty():
            return self.elements[-1]
        else:
            print("Ngăn xếp trống, không có phần tử nào để xem!")
            return None

    def is_empty(self):
        # Kiểm tra ngăn xếp trống
        return len(self.elements) == 0

    def size(self):
        # Trả về kích thước ngăn xếp
        return len(self.elements)

    def display(self):
        # In ngăn xếp từ đỉnh đến đáy
        if not self.is_empty():
            print("Ngăn xếp hiện tại (từ đỉnh đến đáy):", self.elements[::-1])
        else:
            print("Ngăn xếp hiện đang trống.")

# Kiểm tra sử dụng ngăn xếp
if __name__ == "__main__":
    stack = Stack()
    stack.push("Sách A")
    stack.push("Sách B")
    stack.push("Sách C")
    stack.display()  # Ngăn xếp hiện tại (từ đỉnh đến đáy): ['Sách C', 'Sách B', 'Sách A']
    
    top_item = stack.peek()
    print("Phần tử trên đỉnh ngăn xếp:", top_item)  # Output: Sách C
    
    stack.pop()
    stack.display()  # Ngăn xếp hiện tại (từ đỉnh đến đáy): ['Sách B', 'Sách A']
    print("Ngăn xếp trống?", stack.is_empty())  # Output: False
