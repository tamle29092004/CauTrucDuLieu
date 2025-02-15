# đây là chương trình julia về deque
mutable struct Queue{A}
    # Hàng đợi chứa các phần tử
    elements::Vector{A}

    # Hàm khởi tạo hàng đợi rỗng
    function Queue{A}() where A
        return new{A}(Vector{A}()) # Khởi tạo Vector rỗng
    end
end

# Hàm thêm phần tử vào hàng đợi
function enqueue(q::Queue{A}, item::A) where A
    Base.push!(q.elements, item) # Sử dụng Base.push! để thêm vào Vector
    println("Đã thêm phần tử: ", item)
end

# Hàm lấy và xóa phần tử đầu tiên khỏi hàng đợi
function dequeue(q::Queue)
    if isempty(q.elements)
        println("Hàng đợi trống! Không thể lấy phần tử.")
        return nothing
    end
    element = q.elements[1]          # Lấy phần tử đầu tiên
    q.elements = q.elements[2:end]   # Loại bỏ phần tử đầu
    println("Đã lấy phần tử: ", element)
    return element
end

# Hàm lấy phần tử đầu tiên của hàng đợi mà không xóa
function front(q::Queue)
    if isempty(q.elements)
        println("Hàng đợi trống! Không có phần tử đầu tiên.")
        return nothing
    end
    return q.elements[1] # Trả về phần tử đầu tiên
end

# Hàm kiểm tra xem hàng đợi có rỗng hay không
function is_empty(q::Queue)
    return isempty(q.elements)
end

# Hàm hiển thị các phần tử trong hàng đợi
function display(q::Queue)
    if is_empty(q)
        println("Hàng đợi rỗng.")
    else
        println("Hàng đợi (đầu đến cuối): ", q.elements)
    end
end

# Hàm chính để minh họa cách hoạt động của hàng đợi
function main()
    # Tạo hàng đợi rỗng
    queue = Queue{String}()
    
    # Thêm các phần tử vào hàng đợi
    enqueue(queue, "Tai Lieu 1")
    enqueue(queue, "Tai Lieu 2")
    enqueue(queue, "Tai Lieu 3")
    
    # Hiển thị hàng đợi hiện tại
    display(queue)
    
    # Lấy phần tử đầu tiên
    println("Phần tử đầu tiên: ", front(queue)) # Tai Lieu 1
    
    # Xóa phần tử đầu tiên khỏi hàng đợi
    dequeue(queue)
    
    # Hiển thị phần tử đầu tiên sau khi xóa
    println("Phần tử đầu tiên sau khi dequeue: ", front(queue)) # Tai Lieu 2
    
    # Hiển thị hàng đợi còn lại
    display(queue)
end

# Gọi hàm chính
main()
