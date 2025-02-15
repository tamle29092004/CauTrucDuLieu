# chương trình python về chuổi sâu
def decode_string(s: str) -> str:
    stack = []  # Dùng stack để lưu trữ các xâu con và số lần lặp
    current_string = ""  # Dùng để lưu trữ xâu con hiện tại
    current_num = 0  # Dùng để lưu trữ số lần lặp
    
    for char in s:
        if char.isdigit():  # Nếu gặp ký tự số
            current_num = current_num * 10 + int(char)  # Xử lý số có thể nhiều chữ số
        elif char == '[':  # Nếu gặp dấu ngoặc mở
            stack.append((current_string, current_num))  # Đẩy xâu con hiện tại và số lần lặp vào stack
            current_string = ""  # Làm mới xâu con
            current_num = 0  # Làm mới số lần lặp
        elif char == ']':  # Nếu gặp dấu ngoặc đóng
            prev_string, num = stack.pop()  # Lấy phần xâu con và số lần lặp ra từ stack
            current_string = prev_string + current_string * num  # Lặp lại xâu con và nối vào xâu trước đó
        else:  # Nếu là ký tự bình thường
            current_string += char  # Thêm ký tự vào xâu con hiện tại

    return current_string

# Hàm đọc và xử lý nhiều bộ test
def solve():
    T = int(input())  # Số lượng bộ test
    for _ in range(T):
        s = input().strip()  # Đọc xâu mã hóa
        print(decode_string(s))  # Giải mã và in kết quả

# Gọi hàm solve() để chạy chương trình
solve()
