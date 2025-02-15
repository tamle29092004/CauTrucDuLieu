//Chương trình chuyển biểu thức có ngoặc thành biểu thức tương đương không có ngoặc
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Định nghĩa lớp Stack tự xây dựng
template <typename T>
class Stack {
private:
    vector<T> data; // Dùng vector để lưu dữ liệu trong stack

public:
    void push(T x) {
        data.push_back(x);
    }
    
    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        }
    }
    
    T top() {
        return isEmpty() ? T() : data.back();
    }
    
    bool isEmpty() {
        return data.empty();
    }
};

// Hàm chuyển biểu thức có ngoặc về dạng tương đương không ngoặc
string equivalentExpression(const string &expr) {
    Stack<int> s; // Ngăn xếp lưu dấu phía trước dấu ngoặc
    string result;
    int sign = 1; // 1 là dấu dương, -1 là dấu âm

    for (char ch : expr) {
        if (ch == '(') {
            s.push(sign); // Lưu dấu hiện tại trước ngoặc
        } else if (ch == ')') {
            s.pop(); // Khi gặp ')', loại bỏ dấu tương ứng
        } else if (ch == '-') {
            if (s.isEmpty() || s.top() == 1) {
                result += '-'; // Dấu '-' giữ nguyên
            } else {
                result += '+'; // Nếu có dấu '-' trước ngoặc, đổi thành '+'
            }
        } else if (ch == '+') {
            if (s.isEmpty() || s.top() == 1) {
                result += '+'; // Giữ nguyên dấu '+'
            } else {
                result += '-'; // Nếu có dấu '-' trước ngoặc, đổi thành '-'
            }
        } else {
            result += ch; // Nếu là toán hạng thì giữ nguyên
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Loại bỏ ký tự xuống dòng sau khi nhập số T
    
    while (T--) {
        string expr;
        getline(cin, expr); // Đọc biểu thức từ đầu vào
        cout << equivalentExpression(expr) << endl; // Xuất kết quả
    }
    
    return 0;
}
