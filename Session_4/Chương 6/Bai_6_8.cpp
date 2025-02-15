#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;

// Hàm kiểm tra số K có thỏa mãn yêu cầu không
bool is_valid_number(int K) {
    string s = to_string(K);
    set<char> digit_set;  // Dùng set để kiểm tra các chữ số đã gặp

    for (char digit : s) {
        if (digit > '5' || digit_set.count(digit)) {  // Nếu chữ số > 5 hoặc đã gặp
            return false;
        }
        digit_set.insert(digit);  // Thêm chữ số vào set
    }
    return true;
}

// Hàm đếm số lượng các số hợp lệ trong khoảng từ L đến R sử dụng hàng đợi
int count_valid_numbers(int L, int R) {
    int count = 0;
    queue<int> q;
    
    // Duyệt từ L đến R
    for (int K = L; K <= R; ++K) {
        q.push(K);
    }

    // Duyệt qua các số trong hàng đợi
    while (!q.empty()) {
        int K = q.front();
        q.pop();
        
        if (is_valid_number(K)) {
            count++;
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;  // Đọc số lượng test
    while (T--) {
        int L, R;
        cin >> L >> R;  // Đọc L và R cho mỗi test case
        cout << count_valid_numbers(L, R) << endl;  // In kết quả cho mỗi test case
    }
    return 0;
}
