//Chương trình chuyển đổi biểu thức tiền tố sang hậu tố
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Xây dựng ngăn xếp tùy chỉnh
class CustomStack {
private:
    vector<string> elements; // Dùng vector để lưu trữ dữ liệu trong stack

public:
    void push(const string &item) {
        elements.push_back(item);
    }

    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        }
    }

    string top() const {
        if (!isEmpty()) {
            return elements.back();
        }
        throw out_of_range("Stack is empty!");
    }

    bool isEmpty() const {
        return elements.empty();
    }
};

// Kiểm tra xem một ký tự có phải toán tử không
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Hàm chuyển đổi biểu thức tiền tố sang hậu tố
string prefixToPostfix(const string &prefix) {
    CustomStack s;
    
    // Duyệt chuỗi từ phải sang trái
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];
        
        if (isOperator(ch)) {
            // Lấy hai toán hạng từ stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            
            // Ghép thành biểu thức hậu tố
            string newExpr = op1 + op2 + ch;
            
            // Đẩy lại vào stack
            s.push(newExpr);
        } else {
            // Nếu là toán hạng, đẩy vào stack
            s.push(string(1, ch));
        }
    }
    
    // Phần tử cuối cùng trong stack là biểu thức hậu tố hoàn chỉnh
    return s.top();
}

int main() {
    int t; // Số bộ test
    cin >> t;
    cin.ignore(); // Bỏ ký tự xuống dòng sau khi nhập số test
    
    while (t--) {
        string prefix;
        getline(cin, prefix); // Đọc biểu thức tiền tố
        
        // Chuyển đổi và in kết quả
        cout << prefixToPostfix(prefix) << endl;
    }
    
    return 0;
}
