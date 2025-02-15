from collections import deque

# Hàm tìm số nguyên dương nhỏ nhất chỉ chứa các chữ số '9' và '0', chia hết cho N
def find_smallest_number(N):
    # Sử dụng deque làm hàng đợi, bắt đầu với số "9"
    queue = deque(['9'])
    
    # Tiến hành tìm kiếm theo chiều rộng (BFS)
    while queue:
        # Lấy số đầu tiên trong hàng đợi
        current = queue.popleft()
        
        # Kiểm tra nếu số này chia hết cho N
        if int(current) % N == 0:
            # Nếu có, trả về số đó
            return current
        
        # Thêm hai số mới vào hàng đợi: một số thêm '0' và một số thêm '9'
        queue.append(current + '0')
        queue.append(current + '9')

# Hàm chính để đọc và xử lý các test case
def main():
    T = int(input())  # Đọc số lượng test
    for _ in range(T):
        N = int(input())  # Đọc giá trị N cho mỗi test
        print(find_smallest_number(N))  # Tìm và in số nhỏ nhất chia hết cho N

if __name__ == "__main__":
    main()  # Gọi hàm chính để thực hiện
