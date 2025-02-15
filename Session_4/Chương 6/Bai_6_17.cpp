#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Các hướng di chuyển của quân mã
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; // Di chuyển theo chiều ngang (x)
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1}; // Di chuyển theo chiều dọc (y)

// Hàm chuyển đổi tọa độ từ dạng chuỗi (vd: "a1") sang chỉ số mảng (0-7)
void convert(string s, int &x, int &y) {
    x = s[0] - 'a';  // Chuyển ký tự 'a'-'h' thành chỉ số từ 0 đến 7 (chỉ số hàng)
    y = s[1] - '1';  // Chuyển số '1'-'8' thành chỉ số từ 0 đến 7 (chỉ số cột)
}

// Hàm BFS để tìm số bước di chuyển ít nhất từ vị trí bắt đầu đến vị trí đích
int bfs(int startX, int startY, int endX, int endY) {
    queue<pair<int, int>> q; // Queue lưu trữ các vị trí (x, y) cần thăm
    vector<vector<bool>> visited(8, vector<bool>(8, false)); // Mảng đánh dấu ô đã thăm

    // Đưa vị trí bắt đầu vào queue và đánh dấu là đã thăm
    q.push({startX, startY});
    visited[startX][startY] = true;
    int steps = 0;  // Số bước di chuyển

    // Thực hiện BFS
    while (!q.empty()) {
        int size = q.size(); // Số lượng vị trí cần thăm trong lần lặp này
        for (int i = 0; i < size; ++i) {
            int x = q.front().first; // Lấy vị trí đầu tiên trong queue
            int y = q.front().second;
            q.pop(); // Loại bỏ vị trí này khỏi queue

            // Nếu đã đến đích
            if (x == endX && y == endY) {
                return steps; // Trả về số bước đã đi được
            }

            // Kiểm tra tất cả các hướng di chuyển của quân mã
            for (int dir = 0; dir < 8; ++dir) {
                int newX = x + dx[dir]; // Tính toán vị trí mới theo hướng di chuyển
                int newY = y + dy[dir];

                // Kiểm tra xem tọa độ mới có hợp lệ và chưa thăm không
                if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && !visited[newX][newY]) {
                    visited[newX][newY] = true;  // Đánh dấu ô này đã thăm
                    q.push({newX, newY});  // Thêm vị trí mới vào queue
                }
            }
        }
        steps++;  // Tăng số bước khi đã duyệt xong tất cả các vị trí trong queue
    }
    
    return -1;  // Nếu không tìm được đường đi đến đích, trả về -1
}

int main() {
    int T;
    cin >> T; // Đọc số lượng bộ test

    while (T--) {
        string start, end;
        cin >> start >> end; // Đọc vị trí bắt đầu và kết thúc

        int startX, startY, endX, endY;
        convert(start, startX, startY);  // Chuyển vị trí bắt đầu thành chỉ số mảng
        convert(end, endX, endY);  // Chuyển vị trí kết thúc thành chỉ số mảng

        // Gọi hàm BFS để tính số bước di chuyển và in kết quả
        cout << bfs(startX, startY, endX, endY) << endl;
    }

    return 0;
}
