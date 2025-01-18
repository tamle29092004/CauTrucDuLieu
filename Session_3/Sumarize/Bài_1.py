
#đây là chương trình về depth first search để tìm đường đi ngắn nhất cho robot
# Khai báo hàm tìm đường đi
def dfs(grid, start, goal):
    # Khởi tạo ngăn xếp cho DFS
    stack = [start]
    visited = set()
    path = []

    while stack:
        current = stack.pop()
        if current in visited:
            continue
        visited.add(current)
        path.append(current)

        # Kiểm tra nếu đã đến đích
        if current == goal:
            return path

        # Thêm các hàng xóm chưa được thăm vào ngăn xếp
        for neighbor in get_neighbors(grid, current):
            if neighbor not in visited:
                stack.append(neighbor)

    return None  # Nếu không tìm thấy đường đi

# Hàm để lấy các hàng xóm của một ô
def get_neighbors(grid, pos):
    neighbors = []
    x, y = pos
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    for dx, dy in directions:
        nx, ny = x + dx, y + dy
        if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and grid[nx][ny] == 0:
            neighbors.append((nx, ny))
    
    return neighbors

# Minh họa
if __name__ == "__main__":
    # 0: đường đi, 1: chướng ngại vật
    grid = [
        [0, 0, 0, 0, 0],
        [1,1, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 1,1, 1, 0],
        [0, 0, 0,0, 0]
    ]

    start = (0, 0)
    goal = (4, 4)
    path = dfs(grid, start, goal)

    if path:
        print("Đường đi tìm được:")
        print(path)
    else:
        print("Không tìm thấy đường đi.")