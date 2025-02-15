from collections import deque

# Hàm kiểm tra xem tọa độ (x, y) có hợp lệ trong bảng không
def is_valid(x, y, N, grid):
    return 0 <= x < N and 0 <= y < N and grid[x][y] == '.'

# Hàm tìm số bước di chuyển ít nhất từ (a, b) đến (c, d)
def bfs(N, grid, start, end):
    # Định nghĩa các hướng di chuyển: lên, xuống, trái, phải
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    # Khởi tạo hàng đợi BFS
    queue = deque([(start[0], start[1], 0)])  # (x, y, bước)
    visited = [[False] * N for _ in range(N)]  # Mảng đánh dấu đã thăm
    visited[start[0]][start[1]] = True

    # BFS
    while queue:
        x, y, steps = queue.popleft()

        # Nếu đã đến điểm đích, trả về số bước
        if (x, y) == end:
            return steps

        # Di chuyển theo 4 hướng (lên, xuống, trái, phải)
        for dx, dy in directions:
            nx, ny = x, y
            # Tiến xa trong cùng một hàng hoặc cột miễn là không gặp vật cản
            while is_valid(nx + dx, ny + dy, N, grid):
                nx += dx
                ny += dy
                if not visited[nx][ny]:
                    visited[nx][ny] = True
                    queue.append((nx, ny, steps + 1))

    return -1  # Nếu không thể đến đích

# Hàm chính để xử lý đầu vào và gọi BFS
def main():
    T = int(input())  # Số lượng test
    for _ in range(T):
        N = int(input())  # Kích thước bảng N x N
        grid = [input().strip() for _ in range(N)]  # Bảng N x N
        a, b, c, d = map(int, input().split())  # Tọa độ xuất phát và đích

        start = (a, b)
        end = (c, d)

        # Tính và in kết quả
        result = bfs(N, grid, start, end)
        print(result)

if __name__ == "__main__":
    main()
