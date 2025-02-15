# chương trình python về số lộc phát
from collections import deque

# Hàm để sinh ra các số lộc phát
def sinh_loc_phat(N):
    queue = deque(["6", "8"])  # Bắt đầu với "6" và "8"
    result = []

    while queue:
        num = queue.popleft()

        # Nếu độ dài của số nhỏ hơn hoặc bằng N, thêm vào kết quả
        if len(num) <= N:
            result.append(num)
            # Tiếp tục tạo số mới bằng cách thêm "6" hoặc "8"
            queue.append(num + "6")
            queue.append(num + "8")

    # Đếm và in ra số lượng số lộc phát
    result.sort(reverse=True)  # Sắp xếp theo thứ tự giảm dần
    return len(result), result

# Hàm chính để xử lý các bộ test
def main():
    T = int(input())  # Đọc số lượng bộ test
    for _ in range(T):
        N = int(input())  # Đọc N cho mỗi bộ test
        count, result = sinh_loc_phat(N)
        print(count)  # In ra số lượng số lộc phát
        print(" ".join(result))  # In ra các số lộc phát theo thứ tự giảm dần

# Gọi hàm chính
main()
