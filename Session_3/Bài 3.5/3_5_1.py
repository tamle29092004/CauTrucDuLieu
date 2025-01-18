def bfs(graph, start):
    queue = [start]
    visited = set()

    while queue:
        vertex = queue.pop(0)
        if vertex not in visited:
            print(vertex)
            visited.add(vertex)
            # Thêm các nút chưa được thêm vào cuối hàng đợi
            queue.extend(graph[vertex])

# Minh họa
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

print("BFS từ nút A:")
bfs(graph, 'A')  # Output: A B C D E F