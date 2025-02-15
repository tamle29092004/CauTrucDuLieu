// chương trình về nhịp độ chứng khoán 
#include <iostream>
#include <vector>
using namespace std;

// Lớp stack tùy chỉnh
class MyStack {
public:
    vector<int> stack;  // Dùng vector để mô phỏng stack

    // Hàm push
    void push(int value) {
        stack.push_back(value);
    }

    // Hàm pop
    void pop() {
        if (!isEmpty()) {
            stack.pop_back();
        }
    }

    // Hàm top (lấy phần tử trên cùng)
    int top() {
        if (!isEmpty()) {
            return stack.back();
        }
        return -1; // nếu stack rỗng, trả về -1
    }

    // Hàm kiểm tra stack có rỗng không
    bool isEmpty() {
        return stack.empty();
    }

    // Hàm lấy kích thước của stack
    int size() {
        return stack.size();
    }
};

// Hàm tính nhịp chứng khoán cho mỗi bộ test
void calculate_stock_wave(int n, vector<int>& prices) {
    vector<int> result(n);  // Mảng lưu nhịp chứng khoán của từng ngày
    MyStack stack;  // Khởi tạo stack tùy chỉnh

    for (int i = 0; i < n; ++i) {
        // Tính nhịp chứng khoán cho ngày i
        while (!stack.isEmpty() && prices[stack.top()] <= prices[i]) {
            stack.pop();
        }
        
        // Nếu stack rỗng, tức là không có ngày nào có giá chứng khoán nhỏ hơn hoặc bằng
        // Với giá của ngày i, ta có nhịp là i + 1 (nghĩa là tất cả các ngày trước đó đều nhỏ hơn hoặc bằng)
        result[i] = (stack.isEmpty()) ? i + 1 : i - stack.top();

        // Thêm ngày i vào stack
        stack.push(i);
    }

    // In kết quả
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;  // Số lượng bộ test
    cin >> T;

    while (T--) {
        int N;  // Số ngày
        cin >> N;
        vector<int> prices(N);  // Mảng lưu giá chứng khoán
        for (int i = 0; i < N; ++i) {
            cin >> prices[i];
        }

        // Tính nhịp chứng khoán cho bộ test hiện tại
        calculate_stock_wave(N, prices);
    }

    return 0;
}
