#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

// Hàm kiểm tra số BDN nhỏ nhất của N
int find_bdn(int N) {
    // Dùng hàng đợi để tìm số BDN nhỏ nhất chia hết cho N
    queue<string> q;
    q.push("1");  // Khởi tạo hàng đợi với số BDN ban đầu là "1"

    unordered_set<int> visited;  // Để tránh xử lý lại những số đã gặp

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        // Chuyển chuỗi BDN thành số nguyên và kiểm tra chia hết cho N
        int num = 0;
        for (char c : current) {
            num = num * 10 + (c - '0');
        }

        if (num % N == 0) {
            return num;  // Nếu chia hết cho N, trả về số đó
        }

        // Thêm các số tiếp theo vào hàng đợi
        if (visited.find(num % N) == visited.end()) {  // Tránh xử lý lại những số đã gặp
            visited.insert(num % N);
            q.push(current + "0");
            q.push(current + "1");
        }
    }

    return -1;  // Trường hợp không tìm thấy, mặc dù không thể xảy ra trong bài này
}

int main() {
    int T;
    cin >> T;  // Số lượng test
    while (T--) {
        int N;
        cin >> N;  // Đọc số N cho từng test
        cout << find_bdn(N) << endl;  // In kết quả của mỗi test
    }
    return 0;
}
