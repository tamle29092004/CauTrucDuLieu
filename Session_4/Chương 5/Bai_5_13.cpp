// Chuong trinh tinh gia tri cua bieu thuc trung to
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;

// Lớp CustomStack tự xây dựng (chỉ dùng cho số nguyên)
class CustomStack {
private:
    vector<int> elements; // Dùng vector để lưu trữ dữ liệu trong stack

public:
    void push(int item) { elements.push_back(item); }
    void pop() { if (!isEmpty()) elements.pop_back(); }
    int top() const { 
        if (!isEmpty()) return elements.back();
        throw out_of_range("Stack is empty!");
    }
    bool isEmpty() const { return elements.empty(); }
};

// Hàm xác định độ ưu tiên của toán tử
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Hàm thực hiện phép toán
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Hàm tính giá trị biểu thức trung tố
int evaluateExpression(string s) {
    CustomStack values;  // Stack lưu số
    vector<char> ops;    // Dùng vector để lưu toán tử

    for (int i = 0; i < s.length(); i++) {
        if (isspace(s[i])) continue; // Bỏ qua khoảng trắng

        if (isdigit(s[i])) { 
            int num = 0;
            while (i < s.length() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0'); // Chuyển thành số nguyên
                i++;
            }
            values.push(num);
            i--; // Giảm lại vì vòng for sẽ tăng
        } 
        else if (s[i] == '(') {
            ops.push_back(s[i]); // Đẩy dấu ngoặc vào stack toán tử
        } 
        else if (s[i] == ')') {
            while (!ops.empty() && ops.back() != '(') { 
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.back(); ops.pop_back();
                values.push(applyOperation(val1, val2, op));
            }
            ops.pop_back(); // Loại bỏ dấu '('
        } 
        else {
            while (!ops.empty() && precedence(ops.back()) >= precedence(s[i])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.back(); ops.pop_back();
                values.push(applyOperation(val1, val2, op));
            }
            ops.push_back(s[i]); // Đẩy toán tử vào stack
        }
    }

    // Xử lý toán tử còn lại
    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.back(); ops.pop_back();
        values.push(applyOperation(val1, val2, op));
    }

    return values.top(); // Kết quả cuối cùng
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Loại bỏ ký tự xuống dòng

    while (T--) {
        string expression;
        getline(cin, expression);
        cout << evaluateExpression(expression) << endl;
    }

    return 0;
}
