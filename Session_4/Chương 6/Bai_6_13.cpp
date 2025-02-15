//chương trình số lộc phát 
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void sinhLocPhat(int N) {
    queue<string> q;
    vector<string> result;
    
    // Khởi tạo queue với số lộc phát đơn giản
    q.push("6");
    q.push("8");

    // Sinh số lộc phát cho đến khi độ dài không vượt quá N
    while (!q.empty()) {
        string num = q.front();
        q.pop();

        // Nếu độ dài của số không quá N, thêm vào kết quả
        if (num.size() <= N) {
            result.push_back(num);
            // Tiếp tục sinh ra các số mới từ số hiện tại bằng cách thêm 6 hoặc 8 vào cuối
            q.push(num + "6");
            q.push(num + "8");
        }
    }

    // Sắp xếp kết quả theo thứ tự giảm dần
    sort(result.rbegin(), result.rend());

    // In ra kết quả
    for (const string& num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;  // Số lượng bộ test

    // Xử lý từng bộ test
    while (T--) {
        int N;
        cin >> N;  // Đọc N cho mỗi bộ test

        sinhLocPhat(N);  // Sinh và in kết quả số lộc phát cho N chữ số
    }

    return 0;
}
