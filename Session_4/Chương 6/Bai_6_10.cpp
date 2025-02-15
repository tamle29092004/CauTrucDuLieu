#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class GieoMam {
private:
    int R, C;  // Số hàng và cột
    vector<vector<int>> grid;  // Ma trận ô, lưu trạng thái của các ô (0: trống, 1: hạt chưa nảy mầm, 2: cây non)
    int dx[4] = {-1, 1, 0, 0};  // Di chuyển theo chiều dọc (trái, phải, trên, dưới)
    int dy[4] = {0, 0, -1, 1};  // Di chuyển theo chiều ngang (trái, phải, trên, dưới)

public:
    // Constructor khởi tạo số hàng và cột, đồng thời tạo ma trận grid
    GieoMam(int R, int C) : R(R), C(C) {
        grid.resize(R, vector<int>(C));  // Tạo ma trận kích thước R x C
    }

    // Hàm nhập dữ liệu vào ma trận
    void nhapDuLieu() {
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> grid[i][j];
            }
        }
    }

    // Hàm BFS để lan truyền chất dinh dưỡng từ cây non
    int bfs() {
        queue<pair<int, int>> q;  // Queue chứa các vị trí của cây non
        int maxDay = 0;  // Biến lưu số ngày dài nhất

        // Thêm tất cả các cây non vào queue
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 2) {  // Nếu là cây non, thêm vào queue
                    q.push({i, j});
                }
            }
        }

        // Nếu không có cây non, trả về -1 (không thể nảy mầm)
        if (q.empty()) return -1;

        // Thực hiện BFS
        while (!q.empty()) {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();

            // Thử di chuyển đến các ô xung quanh (trái, phải, trên, dưới)
            for (int i = 0; i < 4; ++i) {
                int nx = curX + dx[i];
                int ny = curY + dy[i];

                // Kiểm tra giới hạn của ma trận và nếu ô đó là hạt chưa nảy mầm
                if (nx >= 0 && ny >= 0 && nx < R && ny < C && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;  // Chuyển hạt thành cây non
                    q.push({nx, ny});  // Thêm vào queue để tiếp tục lan truyền
                    maxDay = max(maxDay, maxDay + 1);  // Cập nhật số ngày lớn nhất
                }
            }
        }

        // Kiểm tra xem có hạt nào còn chưa nảy mầm không
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 1) {
                    return -1;  // Nếu có hạt chưa nảy mầm, trả về -1
                }
            }
        }

        return maxDay;  // Trả về số ngày cần thiết để tất cả đều nảy mầm
    }
};

int main() {
    int t;
    cin >> t;  // Đọc số bộ test

    while (t--) {
        int R, C;
        cin >> R >> C;  // Đọc số hàng và cột của ma trận

        GieoMam gieoMam(R, C);  // Tạo đối tượng gieoMam với ma trận kích thước R x C
        gieoMam.nhapDuLieu();  // Nhập dữ liệu vào ma trận

        cout << gieoMam.bfs() << endl;  // In kết quả
    }

    return 0;
}
