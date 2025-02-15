#chương trình python về biển đổi s-t
from collections import deque

# Hàm tìm số bước tối thiểu từ S đến T
def min_operations(S, T):
    if S >= T:
        return S - T  # Nếu S >= T, chỉ cần trừ 1 cho đến khi S = T
    
    # BFS để tìm số bước
    queue = deque([(S, 0)])  # Lưu trữ (giá trị hiện tại, số bước đã thực hiện)
    visited = [False] * (T * 2 + 1)  # Mảng để đánh dấu các giá trị đã thăm
    visited[S] = True
    
    while queue:
        current, steps = queue.popleft()
        
        # Nếu đạt tới T, trả về số bước
        if current == T:
            return steps
        
        # Thao tác (a): Trừ 1
        if current - 1 >= 0 and not visited[current - 1]:
            visited[current - 1] = True
            queue.append((current - 1, steps + 1))
        
        # Thao tác (b): Nhân đôi
        if current * 2 <= T * 2 and not visited[current * 2]:
            visited[current * 2] = True
            queue.append((current * 2, steps + 1))
    
    return -1  # Trường hợp không thể tìm thấy (không thể xảy ra trong bài toán này)

# Đọc đầu vào và xử lý các test case
T = int(input())  # Số lượng test
for _ in range(T):
    S, T = map(int, input().split())
    print(min_operations(S, T))
