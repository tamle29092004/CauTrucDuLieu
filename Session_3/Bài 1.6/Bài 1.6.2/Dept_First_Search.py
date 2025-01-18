def dfs(graph, start):
    stack = [start]
    visited = set()

    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            print(vertex, end=' ')
            visited.add(vertex)
            # Thêm các đỉnh kề chưa được thăm vào ngăn xếp theo thứ tự gốc
            neighbors = [neighbor for neighbor in graph[vertex] if neighbor not in visited]
            # Để theo thứ tự đúng, thêm từ cuối danh sách (vì stack là ngăn xếp, pop sẽ lấy phần tử cuối cùng)
            stack.extend(reversed(neighbors))

            # Hiển thị các đỉnh kề đã được đẩy vào ngăn xếp
            print(f"Đã đẩy các nút kề của '{vertex}' vào ngăn xếp: {neighbors}")

# Minh họa
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A', 'E'],
    'D': ['B'],
    'E': ['C'],
    'F': []
}

print("DFS từ nút A:")
dfs(graph, 'A')  # A C F B D
