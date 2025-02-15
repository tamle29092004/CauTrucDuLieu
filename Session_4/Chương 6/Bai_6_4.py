from collections import deque

# Hàm kiểm tra xem một số có phải là số BDN không
def is_bdn(x):
    return all(d == '0' or d == '1' for d in str(x))

# Hàm tìm số BDN nhỏ nhất của N
def find_bdn(N):
    # Dùng hàng đợi để tìm số BDN
    queue = deque(['1'])
    
    while queue:
        current = queue.popleft()
        # Nếu nhân số này với N cho ra số BDN thì trả về kết quả
        if is_bdn(int(current) * N):
            return int(current) * N
        # Thêm các số tiếp theo vào hàng đợi
        queue.append(current + '0')
        queue.append(current + '1')

# Hàm chính để giải quyết bài toán
def main():
    T = int(input())  # Số lượng test
    for _ in range(T):
        N = int(input())  # Mỗi số N trong các test
        print(find_bdn(N))

# Gọi hàm chính
if __name__ == "__main__":
    main()
