using DataStructures

# Định nghĩa kiểu Queue sử dụng Deque
mutable struct Queue
    elements::Deque{Any}  # Deque chứa các phần tử
end

# Constructor khởi tạo hàng đợi rỗng sử dụng Deque
function Queue()
    return Queue(Deque{Any}())  # Khởi tạo hàng đợi rỗng (Deque)
end

# Hàm thêm phần tử vào cuối hàng đợi
function enqueue(q::Queue, item)
    pushlast!(q.elements, item)  # Thêm phần tử vào cuối hàng đợi
end

# Hàm bỏ phần tử đầu khỏi hàng đợi
function dequeue(q::Queue)
    if !isempty(q.elements)  # Kiểm tra nếu hàng đợi không rỗng
        item = popfirst!(q.elements)  # Lấy và loại bỏ phần tử đầu tiên
        println("Đã lấy '$item' ra khỏi hàng đợi.")
        return item
    else
        println("Hàng đợi đã trống!")
        return nothing  # Nếu hàng đợi trống, trả về nothing
    end
end

# Hàm xem phần tử đầu hàng đợi
function front(q::Queue)
    if !isempty(q.elements)  # Kiểm tra nếu hàng đợi không rỗng
        return first(q.elements)  # Trả về phần tử đầu tiên
    else
        println("Hàng đợi trống!")
        return nothing  # Nếu hàng đợi trống, trả về nothing
    end
end

# Hàm kiểm tra hàng đợi rỗng
function is_empty(q::Queue)
    return isempty(q.elements)  # Kiểm tra xem hàng đợi có rỗng không
end

# Hàm in nội dung hàng đợi
function display(q::Queue)
    if is_empty(q)
        println("Hàng đợi rỗng.")
    else
        println("Hàng đợi (đầu đến cuối): ", collect(q.elements))  # In toàn bộ hàng đợi
    end
end 

# Minh họa sử dụng hàng đợi với Deque
function main()
    queue = Queue()  # Tạo hàng đợi rỗng

    enqueue(queue, "Tài Liệu 1")  # Thêm phần tử vào hàng đợi
    enqueue(queue, "Tài Liệu 2")
    enqueue(queue, "Tài Liệu 3")

    display(queue)  # Hiển thị hàng đợi (đầu đến cuối)

    front_item = front(queue)  # Lấy phần tử đầu tiên trong hàng đợi
    println("Phần tử đầu tiên trong hàng đợi: ", front_item)

    dequeue(queue)  # Xóa phần tử đầu tiên khỏi hàng đợi
    display(queue)  # Hiển thị lại hàng đợi sau khi xóa phần tử

    println("Hàng đợi có trống không? ", is_empty(queue) ? "Có" : "Không")  # Kiểm tra xem hàng đợi có trống không
end

main()  # Chạy chương trình
