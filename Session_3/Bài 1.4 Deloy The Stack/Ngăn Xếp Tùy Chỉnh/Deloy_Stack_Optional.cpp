
//chương trình sử dụng ngăn xếp tùy chỉnh để thêm, xóa và hiển thị phần tử
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack {
private:
    vector<string> elements; // Sử dụng vector để lưu trữ các phần tử trong ngăn xếp

public:
    // Thêm phần tử vào ngăn xếp
    void push(const string& item) {
        elements.push_back(item);
        cout << "\"" << item << "\" da duoc them vao ngan xep." << endl;
    }

    // Loại bỏ phần tử khỏi đỉnh ngăn xếp
    void pop() {
        if (!isEmpty()) {
            string item = elements.back(); // Lấy phần tử ở đỉnh
            elements.pop_back();          // Xóa phần tử đó khỏi ngăn xếp
            cout << "\"" << item << "\" da bi loai bo khoi ngan xep." << endl;
        } else {
            cout << "Ngan xep dang rong!" << endl;
        }
    }

    // Xem phần tử ở đỉnh ngăn xếp mà không loại bỏ
    string peek() const {
        if (isEmpty()) {
            throw out_of_range("Ngan xep trong!");
        } else {
            return elements.back();
        }
    }

    // Kiểm tra xem ngăn xếp có rỗng không
    bool isEmpty() const {
        return elements.empty();
    }

    // Lấy kích thước hiện tại của ngăn xếp
    size_t size() const {
        return elements.size();
    }

    // In toàn bộ nội dung ngăn xếp từ đỉnh đến đáy
    void display() const {
        cout << "Noi dung ngan xep (tu dinh den day): ";
        for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    // Thêm các phần tử vào ngăn xếp
    stack.push("Sach A");
    stack.push("Sach B");
    stack.push("Sach C");

    // Hiển thị nội dung ngăn xếp
    stack.display(); // Output: Sach C Sach B Sach A

    // Xem phần tử ở đỉnh ngăn xếp
    try {
        cout << "Phan tu o dinh ngan xep: " << stack.peek() << endl; // Output: Sach C
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    // Loại bỏ phần tử ở đỉnh
    stack.pop(); // Output: "Sach C" da bi loai bo

    // Hiển thị nội dung ngăn xếp sau khi loại bỏ
    stack.display(); // Output: Sach B Sach A

    // Kiểm tra ngăn xếp có rỗng không
    cout << "Ngan xep co trong khong? " << (stack.isEmpty() ? "Co" : "Khong") << endl;

    return 0;
}
