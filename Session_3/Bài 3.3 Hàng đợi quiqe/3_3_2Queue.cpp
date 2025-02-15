//đây là chương trình C++ về queue
#include <iostream>  
#include <queue>  
#include <string>  
using namespace std;  

int main() {  
    // Khởi tạo một hàng đợi kiểu chuỗi
    queue<string> queue;  
    
    // Thêm phần tử vào hàng đợi
    queue.push("Tai Lieu 1");  
    cout << "Da them 'Tai Lieu 1' vao hang doi." << endl;  
    
    queue.push("Tai Lieu 2");  
    cout << "Da them 'Tai Lieu 2' vao hang doi." << endl;  
    
    queue.push("Tai Lieu 3");  
    cout << "Da them 'Tai Lieu 3' vao hang doi." << endl;  
    
    // Hiển thị phần tử ở đầu hàng đợi
    cout << "Phan tu o dau hang doi: " << queue.front() << endl;  // Output: Tai Lieu 1  
    
    // Xóa phần tử đầu tiên khỏi hàng đợi
    queue.pop();  
    cout << "Da lay phan tu ra khoi hang doi." << endl;  
    
    // Kiểm tra xem hàng đợi còn phần tử nào không
    if (!queue.empty()) {
        cout << "Phan tu o dau hang doi sau khi pop: " << queue.front() << endl;
    } else {
        cout << "Hang doi rong!" << endl;
    }

    // Hiển thị kích thước của hàng đợi
    cout << "Kich thuoc hang doi hien tai: " << queue.size() << endl;

    return 0;  
}
