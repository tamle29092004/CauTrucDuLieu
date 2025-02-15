#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lớp CustomStack mô phỏng ngăn xếp bằng vector
class CustomStack {
private:
    vector<char> elements; // Dùng vector để lưu trữ phần tử trong ngăn xếp

public:
    void push(char item) {
        elements.push_back(item); // Thêm phần tử vào cuối vector
    }

    void pop() {
        if (!isEmpty()) {
            elements.pop_back(); // Xóa phần tử sau cùng của stack
        }
    }

    char top() const {
        if (!isEmpty()) {
            return elements.back(); // Lấy phần tử trên cùng của stack
        }
        throw out_of_range("Stack is empty!"); // Ném lỗi nếu stack rỗng
    }

    bool isEmpty() const {
        return elements.empty(); // Kiểm tra stack có rỗng không
    }
};

// Lớp kiểm tra dấu ngoặc dư thừa
class ExpressionChecker {
public:
    bool hasRedundantParentheses(const string &expression) {
        CustomStack s; // Khởi tạo stack để kiểm tra biểu thức
        
        for (char ch : expression) {
            if (ch == ')') {
                bool hasOperator = false;  // Kiểm tra có toán tử hay không
                bool hasOperand = false;   // Kiểm tra có toán hạng hay không

                // Duyệt ngăn xếp đến khi gặp dấu '('
                while (!s.isEmpty() && s.top() != '(') {
                    char top = s.top();
                    
                    // Kiểm tra nếu có toán tử trong dấu ngoặc
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    } else if (isalnum(top)) { // Kiểm tra chữ hoặc số (toán hạng)
                        hasOperand = true;
                    }
                    
                    s.pop(); // Xóa phần tử đã kiểm tra khỏi stack
                }

                if (!s.isEmpty()) s.pop(); // Loại bỏ '(' khỏi stack

                // Nếu không có toán tử hoặc không có toán hạng, dấu ngoặc là dư thừa
                if (!hasOperator || !hasOperand) {
                    return true;
                }
            } else {
                s.push(ch); // Đưa ký tự vào stack nếu không phải ')'
            }
        }
        
        return false; // Nếu không tìm thấy dấu ngoặc dư thừa, trả về false
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập số lượng test cases
    
    ExpressionChecker checker;
    
    while (t--) {
        string expression;
        getline(cin, expression); // Đọc biểu thức từ input
        
        // Xuất kết quả: "Yes" nếu có dấu ngoặc dư thừa, "No" nếu không
        cout << (checker.hasRedundantParentheses(expression) ? "Yes" : "No") << endl;
    }
    
    return 0;
}
