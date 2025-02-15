//Chương trình chuyển đổi biểu thức hậu tố sang tiền tố
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Xây dựng ngăn xếp tùy chỉnh
class CustomStack {
private:
    vector<string> elements; // Dùng vector để lưu trữ dữ liệu trong stack

public:
    // Hàm đẩy phần tử vào stack
    void push(const string &item) {
        elements.push_back(item);
    }

    // Hàm loại bỏ phần tử trên cùng của stack
    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        }
    }

    // Hàm lấy phần tử trên cùng của stack mà không xóa nó
    string top() const {
        if (!isEmpty()) {
            return elements.back();
        }
        throw out_of_range("Stack is empty!"); // Ném lỗi nếu stack rỗng
    }

    // Hàm kiểm tra stack có rỗng không
    bool isEmpty() const {
        return elements.empty();
    }
};

// Kiểm tra xem một ký tự có phải toán tử không
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Hàm chuyển đổi biểu thức hậu tố sang tiền tố
string postfixToPrefix(const string &postfix) {
    CustomStack s;
    
    // Duyệt chuỗi từ trái sang phải
    for (char ch : postfix) {
        if (isOperator(ch)) {
            // Lấy hai toán hạng từ stack
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            
            // Ghép thành biểu thức tiền tố
            string newExpr = ch + op1 + op2;
            
            // Đẩy lại vào stack
            s.push(newExpr);
        } else {
            // Nếu là toán hạng, đẩy vào stack như một chuỗi riêng lẻ
            s.push(string(1, ch));
        }
    }
    
    // Phần tử cuối cùng trong stack là biểu thức tiền tố hoàn chỉnh
    return s.top();
}

int main() {
    int t; // Số bộ test
    cin >> t;
    cin.ignore(); // Bỏ ký tự xuống dòng sau khi nhập số test
    
    while (t--) {
        string postfix;
        getline(cin, postfix); // Đọc biểu thức hậu tố
        
        // Chuyển đổi và in kết quả
        cout << postfixToPrefix(postfix) << endl;
    }
    
    return 0;
}
