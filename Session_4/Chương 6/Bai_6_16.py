from collections import deque

# Hàm BFS để tìm số bước ít nhất từ A[0][0] đến A[M-1][N-1]
def min_steps(M, N, matrix):
    # Queue lưu cặp (i, j, steps) - vị trí và số bước
    queue = deque([(0, 0, 0)])
    visited = set((0, 0))  # Sử dụng set để lưu các vị trí đã thăm
    
    # Duyệt qua queue
    while queue:
        i, j, steps = queue.popleft()
        
        # Nếu đã đến đích, trả về số bước
        if i == M - 1 and j == N - 1:
            return steps
        
        # Cập nhật các vị trí có thể di chuyển
        # Di chuyển theo chiều ngang
        if j + matrix[i][j] < N and (i, j + matrix[i][j]) not in visited:
            queue.append((i, j + matrix[i][j], steps + 1))
            visited.add((i, j + matrix[i][j]))
        
        # Di chuyển theo chiều dọc
        if i + matrix[i][j] < M and (i + matrix[i][j], j) not in visited:
            queue.append((i + matrix[i][j], j, steps + 1))
            visited.add((i + matrix[i][j], j))
    
    # Nếu không tìm thấy đường đi đến đích
    return -1

# Hàm xử lý đầu vào và đầu ra
def solve():
    # Đọc số bộ test
    T = int(input())
    
    # Xử lý từng bộ test
    for _ in range(T):
        # Đọc kích thước ma trận M và N
        M, N = map(int, input().split())
        
        # Đọc ma trận
        matrix = [list(map(int, input().split())) for _ in range(M)]
        
        # Tính số bước ít nhất
        result = min_steps(M, N, matrix)
        print(result)

# Đọc đầu vào và gọi hàm solve()
solve()
