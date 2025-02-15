// chương trình về độ dài chuổi () hợp lệ dài nhất
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// Hàm tính độ dài lớn nhất của biểu thức đúng
int longestValidParentheses(string s) {
    stack<int> stk;  // Sử dụng stack để lưu trữ vị trí các dấu ngoặc
    stk.push(-1);  // Đẩy -1 vào stack để tính độ dài khi gặp ngoặc hợp lệ

    int maxLength = 0;  // Biến lưu trữ độ dài biểu thức đúng lớn nhất
    // Duyệt qua tất cả các ký tự trong chuỗi
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);  // Nếu gặp ngoặc mở '(', đẩy vị trí của nó vào stack
        } else {
            stk.pop();  // Nếu gặp ngoặc đóng ')', pop vị trí ngoặc mở gần nhất
            if (stk.empty()) {
                stk.push(i);  // Nếu stack rỗng, đẩy vị trí của ngoặc đóng vào stack
            } else {
                // Tính độ dài của biểu thức đúng và cập nhật maxLength nếu cần
                maxLength = max(maxLength, i - stk.top());
            }
        }
    }
    return maxLength;  // Trả về độ dài lớn nhất của biểu thức đúng
}

int main() {
    int T;
    cin >> T;  // Đọc số lượng bộ test

    while (T--) {
        string s;
        cin >> s;  // Đọc xâu ký tự biểu thức
        cout << longestValidParentheses(s) << endl;  // In ra độ dài biểu thức đúng lớn nhất
    }

    return 0;
}
