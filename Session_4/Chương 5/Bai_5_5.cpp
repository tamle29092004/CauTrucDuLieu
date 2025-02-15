// Chương trình so sánh hai biểu thức bằng cách loại bỏ dấu ngoặc và chuẩn hóa dấu
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lớp ngăn xếp tự xây dựng
class CustomStack {
private:
    vector<char> elements; // Dùng vector để lưu trữ phần tử trong ngăn xếp

public:
    // Đẩy phần tử vào ngăn xếp
    void push(char item) {
        elements.push_back(item);
    }

    // Loại bỏ phần tử trên đỉnh ngăn xếp
    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        }
    }

    // Lấy phần tử trên đỉnh ngăn xếp mà không loại bỏ
    char top() const {
        if (!isEmpty()) {
            return elements.back();
        }
        throw out_of_range("Stack is empty!");
    }

    // Kiểm tra ngăn xếp có rỗng không
    bool isEmpty() const {
        return elements.empty();
    }
};

// Lớp chuẩn hóa biểu thức để so sánh
class ExpressionNormalizer {
public:
    // Hàm chuẩn hóa biểu thức bằng cách loại bỏ dấu ngoặc và điều chỉnh dấu
    string normalizeExpression(const string &expression) {
        CustomStack s;
        string result;
        vector<int> signStack;
        signStack.push_back(1); // Dấu tổng thể mặc định là dương

        for (size_t i = 0; i < expression.size(); i++) {
            char ch = expression[i];
            
            if (ch == '(') {
                // Nếu trước '(' là '-', thay đổi dấu bên trong ngoặc
                if (i > 0 && expression[i - 1] == '-') {
                    signStack.push_back(-signStack.back());
                } else {
                    signStack.push_back(signStack.back());
                }
            } else if (ch == ')') {
                // Khi gặp ')', bỏ dấu tương ứng khỏi stack
                signStack.pop_back();
            } else if (ch == '+' || ch == '-') {
                // Nếu trước đó có dấu '-', thay đổi dấu hiện tại
                if (signStack.back() == -1) {
                    result += (ch == '+') ? '-' : '+';
                } else {
                    result += ch;
                }
            } else {
                // Toán hạng giữ nguyên
                result += ch;
            }
        }
        return result;
    }
};

int main() {
    int t; // Số bộ test
    cin >> t;
    cin.ignore();
    
    ExpressionNormalizer normalizer;
    
    while (t--) {
        string expr1, expr2;
        getline(cin, expr1);
        getline(cin, expr2);
        
        // Chuẩn hóa hai biểu thức để so sánh
        string normExpr1 = normalizer.normalizeExpression(expr1);
        string normExpr2 = normalizer.normalizeExpression(expr2);
        
        // Nếu hai biểu thức sau khi chuẩn hóa giống nhau thì in YES, ngược lại NO
        cout << (normExpr1 == normExpr2 ? "YES" : "NO") << endl;
    }
    
    return 0;
}
