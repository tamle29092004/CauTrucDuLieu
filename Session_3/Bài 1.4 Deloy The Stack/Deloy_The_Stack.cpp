// đây là chương trình c++ về triển khai ngăn xếp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack <string> stack;
    //push các phần tử vào ngăn xếp
    stack.push("Sach A");
    cout <<"Da them 'Sach A' vao ngan xep\n";
    stack.push("Sach B");
    cout <<"Da them 'Sach B' vao ngan xep\n";
    stack.push("Sach C");
    cout <<"Da them 'Sach C' vao ngan xep\n";

    //hiển thị phẩn đỉnh ở ngăn xếp
    cout <<"Phan tu o dinh ngan xep:  "<< stack.top() << endl; // Output: Sach C

    //pop phần tử khỏi ngăn xếp
    stack.pop();
    cout <<"Da xoa phan tu o dinh ngan xep\n";

    // Hiển thị phần tử ở đỉnh sắp xếp sau khi pop
    cout << "Phan tu dinh ngan xep sau khi pop: " << stack.top() << endl; // Output: Sach B

    //kiểm tra ngăn xếp có rỗng không
    if(stack.empty())
    {
        cout <<"Ngan xep rong\n";
    }
    else
    {
        cout <<"Ngan xep khong rong\n";
    }
    return 0;
}
