//chương trinh c++ ve so lon hon ben phai
#include <iostream>
#include <vector>

using namespace std;

// Lớp mô phỏng stack
class MyStack {
private:
    vector<int> data;  // Mảng lưu trữ các phần tử trong stack

public:
    // Phương thức push vào stack
    void push(int value) {
        data.push_back(value);
    }

    // Phương thức pop ra khỏi stack
    void pop() {
        if (!empty()) {
            data.pop_back();
        }
    }

    // Phương thức lấy phần tử ở đỉnh stack
    int top() {
        if (!empty()) {
            return data.back();
        }
        return -1;  // Trả về -1 nếu stack trống
    }

    // Phương thức kiểm tra stack có rỗng không
    bool empty() {
        return data.empty();
    }
};

class ArrayProcessor {
private:
    vector<int> A;  // Mảng đầu vào
    vector<int> nextGreater;  // Mảng lưu Next Greater Element
    vector<int> nextSmaller;  // Mảng lưu Next Smaller Element
    int n;  // Số phần tử trong mảng

public:
    // Constructor nhận mảng A
    ArrayProcessor(int n, const vector<int>& A) : n(n), A(A), nextGreater(n, -1), nextSmaller(n, -1) {}

    // Phương thức tìm Next Greater Element (NGE)
    void findNextGreater() {
        MyStack ngeStack;  // Khởi tạo stack cho NGE
        for (int i = 0; i < n; i++) {
            while (!ngeStack.empty() && A[ngeStack.top()] < A[i]) {
                nextGreater[ngeStack.top()] = A[i];  // Cập nhật NGE cho phần tử ở đỉnh stack
                ngeStack.pop();  // Pop phần tử khỏi stack
            }
            ngeStack.push(i);  // Push chỉ số phần tử vào stack
        }
    }

    // Phương thức tìm Next Smaller Element (NSE)
    void findNextSmaller() {
        MyStack nseStack;  // Khởi tạo stack cho NSE
        for (int i = n - 1; i >= 0; i--) {
            while (!nseStack.empty() && A[nseStack.top()] > A[i]) {
                nextSmaller[nseStack.top()] = A[i];  // Cập nhật NSE cho phần tử ở đỉnh stack
                nseStack.pop();  // Pop phần tử khỏi stack
            }
            nseStack.push(i);  // Push chỉ số phần tử vào stack
        }
    }

    // Phương thức xử lý kết quả và in ra
    void process() {
        findNextGreater();  // Tìm Next Greater Element
        findNextSmaller();  // Tìm Next Smaller Element

        for (int i = 0; i < n; i++) {
            if (nextGreater[i] == -1 || nextSmaller[i] == -1) {
                cout << "-1 ";  // Nếu không có NGE hoặc NSE, in -1
            } else {
                cout << nextSmaller[i] << " ";  // In giá trị Next Smaller Element
            }
        }
        cout << endl;
    }
};

int main() {
    int T;
    cin >> T;  // Đọc số bộ test
    while (T--) {
        int n;
        cin >> n;  // Đọc số phần tử trong mảng
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];  // Đọc các phần tử mảng
        }

        // Khởi tạo đối tượng ArrayProcessor và xử lý mảng
        ArrayProcessor processor(n, A);
        processor.process();
    }
    return 0;
}
