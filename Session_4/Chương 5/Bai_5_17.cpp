//đây là chương trình C++ tính số lần ngoặc đúng dài nhất trong một chuỗi ngoặc
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

// Lớp Stack tùy chỉnh
class MyStack {
public:
    MyStack() {
        // Khởi tạo stack rỗng
    }

    void push(int value) {
        // Thêm phần tử vào stack
        stack.push(value);
    }

    int pop() {
        // Loại bỏ phần tử trên đỉnh stack và trả về giá trị của nó
        if (!isEmpty()) {
            int topValue = stack.top();
            stack.pop();
            return topValue;
        }
        return -1;  // Nếu stack rỗng thì trả về -1
    }

    int top() {
        // Trả về phần tử trên đỉnh stack mà không loại bỏ nó
        if (!isEmpty()) {
            return stack.top();
        }
        return -1;  // Nếu stack rỗng thì trả về -1
    }

    bool isEmpty() {
        // Kiểm tra xem stack có rỗng không
        return stack.empty();
    }

private:
    stack<int> stack;  // Sử dụng stack chuẩn của C++ làm cơ sở
};

// Hàm tính dãy ngoặc đúng dài nhất
int longestValidParentheses(string s) {
    MyStack stack;  // Sử dụng stack tùy chỉnh
    stack.push(-1);  // Khởi tạo stack với giá trị -1 để xử lý trường hợp dãy ngoặc đúng bắt đầu từ chỉ số 0
    int maxLength = 0;  // Biến lưu trữ độ dài dãy ngoặc đúng dài nhất

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            // Nếu gặp dấu ngoặc mở, thêm chỉ số vào stack
            stack.push(i);
        } else {
            // Nếu gặp dấu ngoặc đóng, xử lý
            stack.pop();  // Loại bỏ dấu ngoặc mở trên cùng của stack
            
            if (!stack.isEmpty()) {
                // Nếu stack không rỗng, tính chiều dài của dãy ngoặc đúng
                maxLength = max(maxLength, i - stack.top());
            } else {
                // Nếu stack rỗng, thêm chỉ số của dấu ngoặc đóng vào stack để đánh dấu vị trí bắt đầu dãy ngoặc đúng tiếp theo
                stack.push(i);
            }
        }
    }

    return maxLength;
}

int main() {
    int T;  // Số lượng bộ test
    cin >> T;

    while (T--) {
        string s;  // Chuỗi ngoặc
        cin >> s;

        // In ra độ dài dãy ngoặc đúng dài nhất
        cout << longestValidParentheses(s) << endl;
    }

    return 0;
}
