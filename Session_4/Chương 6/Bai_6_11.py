from collections import deque

# Hàm di chuyển trong không gian 3D
def bfs(A, B, C, box, start, end):
    # Các hướng di chuyển (trái, phải, trên, dưới, trên-lên, dưới-xuống)
    directions = [(-1, 0, 0), (1, 0, 0), (0, -1, 0), (0, 1, 0), (0, 0, -1), (0, 0, 1)]
    
    # Queue lưu trữ các ô và số bước di chuyển
    queue = deque([(start[0], start[1], start[2], 0)])  # (x, y, z, steps)
    
    # Mảng đã thăm
    visited = [[[False] * C for _ in range(B)] for _ in range(A)]
    visited[start[0]][start[1]][start[2]] = True
    
    # BFS
    while queue:
        x, y, z, steps = queue.popleft()

        # Nếu tới điểm kết thúc
        if (x, y, z) == end:
            return steps
        
        # Kiểm tra các hướng di chuyển
        for dx, dy, dz in directions:
            nx, ny, nz = x + dx, y + dy, z + dz

            # Kiểm tra nếu vị trí mới hợp lệ
            if 0 <= nx < A and 0 <= ny < B and 0 <= nz < C and not visited[nx][ny][nz] and box[nx][ny][nz] != '#':
                visited[nx][ny][nz] = True
                queue.append((nx, ny, nz, steps + 1))
    
    return -1  # Không thể tìm được đường đi

# Hàm chính để xử lý từng bộ test
def solve():
    T = int(input())  # Số lượng bộ test

    for _ in range(T):
        A, B, C = map(int, input().split())  # Chiều cao, rộng, dài của hình hộp chữ nhật
        box = []
        start = end = None
        
        # Đọc dữ liệu ma trận cho từng bộ test
        for i in range(A):
            level = []
            for j in range(B):
                line = input().strip()
                level.append(line)
                for k in range(C):
                    if line[k] == 'S':
                        start = (i, j, k)
                    if line[k] == 'E':
                        end = (i, j, k)
            box.append(level)
        
        # Gọi hàm BFS để tìm đường đi
        result = bfs(A, B, C, box, start, end)
        print(result)

# Gọi hàm giải quyết bài toán
solve()
