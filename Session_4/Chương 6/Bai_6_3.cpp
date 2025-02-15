#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Lớp BDN sử dụng queue để sinh các số BDN
class BDN {
public:
    // Hàm đếm số BDN nhỏ hơn N
    int count(long long N) {
        queue<string> q;  // Hàng đợi lưu trữ các số BDN dưới dạng chuỗi
        int count = 0;

        // Bắt đầu với số BDN nhỏ nhất là "1"
        q.push("1");

        while (!q.empty()) {
            // Lấy số BDN hiện tại ra khỏi hàng đợi
            string current = q.front();
            q.pop();

            // Chuyển chuỗi hiện tại sang số nguyên và kiểm tra xem có nhỏ hơn N không
            long long num = stoll(current);
            if (num < N) {
                count++;  // Nếu nhỏ hơn N, tăng bộ đếm
                // Thêm các số BDN tiếp theo vào hàng đợi
                q.push(current + "0");
                q.push(current + "1");
            }
        }

        return count;
    }
};

int main() {
    int T;
    cin >> T;  // Đọc số lượng test cases

    BDN bdn;  // Tạo đối tượng BDN

    while (T--) {
        long long N;
        cin >> N;  // Đọc giá trị N cho mỗi test case
        
        cout << bdn.count(N) << endl;  // Đếm số lượng số BDN nhỏ hơn N bắt đầu từ số 1
    }

    return 0;
}
