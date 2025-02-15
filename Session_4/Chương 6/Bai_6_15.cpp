//chương trình biến đổi số nguyên tố sử dụng queue
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm BFS tìm số bước ít nhất từ S đến T
int minSteps(int S, int T) {
    queue<pair<int, int>> q;  // Cặp (số hiện tại, số bước)
    unordered_set<int> visited;  // Lưu các số đã thăm
    q.push({S, 0});
    visited.insert(S);

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        // Nếu đã đến T, trả về số bước
        if (current == T) {
            return steps;
        }

        // Chuyển thành chuỗi để dễ dàng thay đổi từng chữ số
        string currentStr = to_string(current);

        // Thử thay đổi từng chữ số trong số hiện tại
        for (int i = 0; i < 4; ++i) {
            for (char digit = '0'; digit <= '9'; ++digit) {
                if (digit == currentStr[i]) continue;  // Không thay đổi chữ số hiện tại

                string newStr = currentStr;
                newStr[i] = digit;

                // Chuyển lại thành số
                int newNum = stoi(newStr);

                // Nếu là số nguyên tố và chưa thăm, thêm vào queue
                if (newNum >= 1000 && isPrime(newNum) && visited.find(newNum) == visited.end()) {
                    q.push({newNum, steps + 1});
                    visited.insert(newNum);
                }
            }
        }
    }

    return -1;  // Nếu không thể chuyển từ S đến T
}

int main() {
    int T;
    cin >> T;  // Đọc số lượng bộ test

    while (T--) {
        int S, T;
        cin >> S >> T;  // Đọc S và T cho mỗi bộ test

        // Tính số bước ít nhất và in kết quả
        cout << minSteps(S, T) << endl;
    }

    return 0;
}
