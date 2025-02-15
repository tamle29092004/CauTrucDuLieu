#đây là chương trình tăng giảm biểu thức
class Stack:
    """Lớp ngăn xếp tự xây dựng dùng danh sách để lưu trữ phần tử"""
    def __init__(self):
        self.items = []  # Danh sách chứa phần tử trong ngăn xếp
    
    def push(self, item):
        """Thêm phần tử vào đỉnh stack"""
        self.items.append(item)
    
    def pop(self):
        """Lấy và loại bỏ phần tử trên cùng của stack"""
        return self.items.pop() if not self.is_empty() else None
    
    def is_empty(self):
        """Kiểm tra xem stack có rỗng không"""
        return len(self.items) == 0
    
    def size(self):
        """Trả về số lượng phần tử trong stack"""
        return len(self.items)

def get_smallest_number(S):
    """Hàm tìm số nhỏ nhất từ dãy I/D"""
    stack = Stack()
    result = ""
    num = 1  # Bắt đầu với số 1

    for i in range(len(S) + 1):  # Duyệt qua từng ký tự trong S + 1 ký tự cuối
        stack.push(num)  # Đẩy số hiện tại vào stack
        num += 1  # Chuẩn bị số tiếp theo

        if i == len(S) or S[i] == 'I':  # Khi gặp 'I' hoặc kết thúc chuỗi
            while not stack.is_empty():
                result += str(stack.pop())  # Lấy hết số trong stack ra
    
    return result

if __name__ == "__main__":
    T = int(input().strip())  # Số lượng test case
    for _ in range(T):
        S = input().strip()  # Nhập chuỗi S
        print(get_smallest_number(S))
