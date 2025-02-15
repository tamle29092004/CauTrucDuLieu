//đây là chương trình về tính hậu tố
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

// Lớp CustomStack để quản lý ngăn xếp số nguyên
class CustomStack {
private:
    vector<int> elements; // Dùng vector để lưu trữ dữ liệu trong stack

public:
    // Hàm đẩy phần tử vào stack
    void push(int item) {
        elements.push_back(item);
    }

    // Hàm loại bỏ phần tử trên cùng của stack
    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        }
    }

    // Hàm lấy phần tử trên cùng của stack mà không xóa nó
    int top() const {
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

// Hàm tính giá trị biểu thức hậu tố
int evaluatePostfix(const string &expression) {
    CustomStack stack;

    // Duyệt từng ký tự trong biểu thức hậu tố
    for (char ch : expression) {
        if (isdigit(ch)) {
            // Nếu là số, chuyển sang số nguyên rồi đẩy vào stack
            stack.push(ch - '0');
        } else {
            // Nếu là toán tử, lấy hai toán hạng từ stack
            int op2 = stack.top(); stack.pop();
            int op1 = stack.top(); stack.pop();

            int result;
            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break; // Chia lấy phần nguyên
                default: throw invalid_argument("Invalid operator");
            }

            // Đẩy kết quả vào stack
            stack.push(result);
        }
    }

    // **Trả về kết quả cuối cùng trong stack**
    return stack.top();
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        string expression;
        cin >> expression;
        cout << evaluatePostfix(expression) << endl;
    }
    return 0;
}
