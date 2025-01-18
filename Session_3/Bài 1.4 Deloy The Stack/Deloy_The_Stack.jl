import Base: push!, pop!, show # Import các phương thức cần thiết

mutable struct Stack
    elements::Vector{Any}
    Stack() = new(Vector{Any}())
end

function push!(s::Stack, item)
    push!(s.elements, item) # Sử dụng push! trực tiếp với s.elements
    println("Đã thêm '$item' vào ngăn xếp.")
end

function pop!(s::Stack)
    if !isempty(s.elements)
        item = pop!(s.elements)
        println("Đã lấy '$item' ra khỏi ngăn xếp.")
        return item
    else
        println("Ngăn xếp rỗng.")
        return nothing
    end
end

function peek(s::Stack)
    if !isempty(s.elements)
        return s.elements[end]
    else
        println("Ngăn xếp rỗng.")
        return nothing
    end
end

function is_empty(s::Stack)
    return isempty(s.elements)
end

function Base.show(io::IO, s::Stack) 
    println(io, "Ngăn xếp (đỉnh bên này): ", reverse(s.elements))
end

function main()
    stack = Stack()
    push!(stack, "Sách A")
    push!(stack, "Sách B")
    push!(stack, "Sách C")
    println(stack)

    top_item = peek(stack)
    println("Phần tử ở đỉnh ngăn xếp: ", top_item)

    pop!(stack) # Lấy phần tử ra khỏi ngăn xếp
    println(stack)

    println("Ngăn xếp có trống không: ", is_empty(stack) ? "Có" : "Không")
end

main()
