# chương trình julia về hàng đợi
mutable struct Queue
    elements::Vector{Any}  # Vector chứa các phần tử
end

# Constructor khởi tạo hàng đợi rỗng mà không sử dụng `new`
function Queue()
    q = Queue(Vector{Any}())  # Khởi tạo hàng đợi rỗng
    return q
end

# Hàm thêm phần tử vào hàng đợi
function enqueue(q::Queue, item)
    push!(q.elements, item)  # Thêm phần tử vào cuối hàng đợi
end

# Hàm logic bỏ phần tử khỏi hàng đợi
function dequeue(q::Queue)
    if !isempty(q.elements)  # Kiểm tra nếu hàng đợi không rỗng
        item = popfirst!(q.elements)  # Lấy và loại bỏ phần tử đầu tiên
        println("Đã lấy '$item' ra khỏi hàng đợi.")
        return item
    else
        println("Hàng đợi trống!")
        return nothing  # Nếu hàng đợi trống, trả về nothing
    end
end

# Hàm xem phần tử đầu hàng đợi
function front(q::Queue)
    if !isempty(q.elements)  # Kiểm tra nếu hàng đợi không rỗng
        return q.elements[1]  # Trả về phần tử đầu tiên
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
        println("Hàng đợi (đầu đến cuối): ", q.elements)  # In toàn bộ hàng đợi
    end
end

# Minh họa sử dụng hàng đợi
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
