from collections import deque

# Hàm kiểm tra các ước số của N và tìm max(u,v)
def get_divisors(N):
    divisors = []
    for i in range(2, int(N ** 0.5) + 1):
        if N % i == 0:
            divisors.append((i, N // i))  # Lưu lại các cặp (u, v)
    return divisors

# Hàm BFS để tìm số bước tối thiểu từ N đến 1
def min_operations(N):
    if N == 1:
        return 0  # Nếu N = 1, không cần thao tác gì
    
    queue = deque([(N, 0)])  # (giá trị hiện tại, số bước đã thực hiện)
    visited = [False] * (N + 1)  # Mảng đánh dấu các số đã thăm
    visited[N] = True
    
    while queue:
        current, steps = queue.popleft()

        # Thao tác (a): Trừ 1
        if current - 1 >= 1 and not visited[current - 1]:
            if current - 1 == 1:
                return steps + 1
            visited[current - 1] = True
            queue.append((current - 1, steps + 1))

        # Thao tác (b): Tìm các cặp ước số và chọn max(u,v)
        for u, v in get_divisors(current):
            next_value = max(u, v)
            if next_value == 1:
                return steps + 1
            if not visited[next_value]:
                visited[next_value] = True
                queue.append((next_value, steps + 1))

    return -1  # Không thể xảy ra trong bài toán này

# Đọc đầu vào và xử lý các test case
T = int(input())  # Số lượng test
for _ in range(T):
    N = int(input())  # Đọc N cho từng test
    print(min_operations(N))  # In kết quả của mỗi test
