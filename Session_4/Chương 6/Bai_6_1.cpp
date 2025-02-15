//chương trình sử dụng queue  in ra các số nhị phân từ 1 đến n
#include <iostream>
#include <string>
using namespace std;

// Định nghĩa cấu trúc Queue
class Queue {
private:
    string* arr;    // Mảng lưu trữ các phần tử của hàng đợi
    int front, rear; // Các chỉ số front và rear
    int capacity;    // Dung lượng của hàng đợi

public:
    // Constructor: Khởi tạo hàng đợi với dung lượng tối đa
    Queue(int size) {
        capacity = size;
        arr = new string[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor: Giải phóng bộ nhớ
    ~Queue() {
        delete[] arr;
    }

    // Kiểm tra hàng đợi có rỗng hay không
    bool isEmpty() {
        return front == -1;
    }

    // Kiểm tra hàng đợi có đầy hay không
    bool isFull() {
        return rear == capacity - 1;
    }

    // Thêm phần tử vào hàng đợi
    void enqueue(string value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
    }

    // Lấy phần tử đầu tiên ra khỏi hàng đợi
    string dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return "";
        }
        string item = arr[front];
        if (front == rear) {
            front = rear = -1; // Nếu chỉ có một phần tử
        } else {
            front++;
        }
        return item;
    }
};

// Hàm in các số nhị phân từ 1 đến n
void printBinaryNumbers(int n) {
    Queue q(n);

    // Thêm số nhị phân '1' vào hàng đợi ban đầu
    q.enqueue("1");

    while (n--) {
        // Lấy số nhị phân đầu tiên trong hàng đợi và in ra
        string current = q.dequeue();
        cout << current << " ";

        // Thêm các số nhị phân tiếp theo vào hàng đợi
        q.enqueue(current + "0");
        q.enqueue(current + "1");
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        printBinaryNumbers(n);
    }

    return 0;
}
