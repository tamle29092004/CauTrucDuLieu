#đây là chương trình julia về deque
using DataStructures

# Định nghĩa cấu trúc Stack
struct Stack
    elements::Deque{Any}  # Sử dụng Deque để lưu trữ phần tử
end

# Hàm khởi tạo
function Stack()
    Stack(Deque{Any}())  # Khởi tạo Deque rỗng
end

# Thêm phần tử vào ngăn xếp
function push!(s::Stack, item)
    enqueue!(s.elements, item)  # Sử dụng enqueue! để thêm phần tử vào cuối
    println("Da them \"$item\" vao ngan xep.")
end

# Loại bỏ phần tử ở đỉnh
function pop!(s::Stack)
    if !isempty(s.elements)
        item = poplast!(s.elements)  # Sử dụng poplast! để loại bỏ phần tử cuối
        println("Da loai bo \"$item\" ra khoi ngan xep.")
        return item
    else
        println("Ngan xep trong!")
        return nothing
    end
end

# Xem phần tử đỉnh
function peek(s::Stack)
    if !isempty(s.elements)
        return last(s.elements)  # Lấy phần tử cuối mà không loại bỏ
    else
        println("Ngan xep trong!")
        return nothing
    end
end

# Kiểm tra rỗng
function is_empty(s::Stack)
    return isempty(s.elements)  # Kiểm tra nếu ngăn xếp rỗng
end

# Hiển thị nội dung
function display(s::Stack)
    println("Noi dung ngan xep (tu dinh den day): ", collect(reverse(s.elements)))
end

# Hàm minh họa
function main()
    stack = Stack()  # Khởi tạo ngăn xếp rỗng
    push!(stack, "Sach A")
    push!(stack, "Sach B")
    push!(stack, "Sach C")
    display(stack)

    top_item = peek(stack)
    println("Phan tu o dinh ngan xep: ", top_item)

    pop!(stack)  # Loại bỏ phần tử ở đỉnh
    display(stack)

    println("Ngan xep co trong khong? ", is_empty(stack) ? "Co" : "Khong")
end

main()
