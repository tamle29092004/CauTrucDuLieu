from collections import deque

# Hàm quay một miếng ghép (chỉ quay theo chiều kim đồng hồ)
def rotate(state, idx):
    # Quay miếng ghép tại vị trí idx (bắt đầu từ 0, index từ 0 đến 5)
    if idx == 0:
        # Quay miếng ghép đầu tiên (phần tử 0 đến 3)
        return state[:4][::-1] + state[4:]
    elif idx == 1:
        # Quay miếng ghép số 1
        return state[1:] + state[:1][::-1]
    return

# Hàm thực hiện BFS để tìm số bước ít nhất
def bfs(start, goal):
    queue = deque([(start, 0)])  # Mỗi phần tử trong queue là một tuple (trạng thái, bước)
    visited = set()  # Tập hợp các trạng thái đã thăm
    visited.add(tuple(start))  # Chuyển start thành tuple để có thể thêm vào visited

    # Duyệt qua các trạng thái trong queue
    while queue:
        state, steps = queue.popleft()  # Lấy trạng thái và số bước hiện tại

        # Kiểm tra nếu trạng thái đã là đích
        if state == goal:
            return steps  # Nếu đã đến đích, trả về số bước

        # Quay từng miếng ghép và thêm vào queue nếu trạng thái chưa thăm
        for i in range(6):
            new_state = state.copy()  # Sao chép trạng thái hiện tại
            rotate(new_state, i)  # Quay miếng ghép tại vị trí i

            # Nếu trạng thái mới chưa thăm thì thêm vào queue
            if tuple(new_state) not in visited:
                visited.add(tuple(new_state))  # Đánh dấu trạng thái đã thăm
                queue.append((new_state, steps + 1))  # Thêm trạng thái mới vào queue

    return -1  # Nếu không thể đạt được trạng thái đích, trả về -1

# Hàm main để đọc input và gọi hàm bfs
def main():
    t = int(input())  # Đọc số lượng bộ test

    # Duyệt qua các bộ test
    for _ in range(t):
        # Đọc trạng thái ban đầu và trạng thái đích
        start = list(map(int, input().split()))  # Chuyển trạng thái ban đầu thành danh sách
        goal = list(map(int, input().split()))  # Chuyển trạng thái đích thành danh sách

        # Gọi hàm BFS để tìm số bước ít nhất
        print(bfs(start, goal))  # In kết quả

if __name__ == "__main__":
    main()  # Gọi hàm main để bắt đầu thực thi chương trình
