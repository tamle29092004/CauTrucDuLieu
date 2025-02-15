#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Hàm kiểm tra nếu hai xâu chỉ khác nhau 1 ký tự
bool isOneLetterDifference(const string& a, const string& b) {
    int diffCount = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            diffCount++;
        }
        if (diffCount > 1) return false;
    }
    return diffCount == 1;
}

// Hàm BFS để tìm khoảng cách ngắn nhất từ s đến t
int bfs(const string& s, const string& t, const vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());  // Tập các từ trong danh sách
    if (wordSet.find(t) == wordSet.end()) return 0;  // Nếu t không có trong danh sách, trả về 0

    queue<pair<string, int>> q;  // Queue lưu (xâu hiện tại, số bước)
    q.push({s, 1});
    wordSet.erase(s);  // Đánh dấu s là đã thăm

    while (!q.empty()) {
        string current = q.front().first;
        int steps = q.front().second;
        q.pop();

        // Duyệt qua tất cả các xâu còn lại
        for (auto it = wordSet.begin(); it != wordSet.end();) {
            if (isOneLetterDifference(current, *it)) {
                if (*it == t) return steps + 1;  // Nếu tìm được t, trả về số bước
                q.push({*it, steps + 1});
                it = wordSet.erase(it);  // Xóa xâu đã thăm
            } else {
                ++it;
            }
        }
    }
    
    return 0;  // Nếu không thể tìm đường, trả về 0
}

int main() {
    int T;
    cin >> T;  // Số lượng test

    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;  // Đọc n, s và t
        
        vector<string> wordList(n);
        for (int i = 0; i < n; ++i) {
            cin >> wordList[i];  // Đọc các từ trong danh sách
        }

        cout << bfs(s, t, wordList) << endl;  // In kết quả cho mỗi test
    }

    return 0;
}
