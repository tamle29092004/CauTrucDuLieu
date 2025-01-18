class Queue:  
    def __init__(self):  
        # Khởi tạo danh sách để lưu các phần tử của hàng đợi
        self.elements = []  

    def enqueue(self, item):  
        """Thêm một phần tử vào cuối hàng đợi."""
        self.elements.append(item)  
        print(f"Đã thêm '{item}' vào hàng đợi.")  

    def dequeue(self):  
        """Xóa và trả về phần tử ở đầu hàng đợi."""
        if not self.is_empty():  # Kiểm tra nếu hàng đợi không trống
            item = self.elements.pop(0)  # Lấy phần tử đầu tiên
            print(f"Đã lấy '{item}' ra khỏi hàng đợi.")  
            return item  
        else:  
            print("Hàng đợi trống!")  
            return None  

    def front(self):  
        """Trả về phần tử đầu tiên của hàng đợi mà không xóa nó."""
        if not self.is_empty():  # Kiểm tra nếu hàng đợi không trống
            return self.elements[0]  
        else:  
            print("Hàng đợi trống!")  
            return None  

    def is_empty(self):  
        """Kiểm tra xem hàng đợi có trống hay không."""
        return len(self.elements) == 0  

    def size(self):  
        """Trả về số lượng phần tử trong hàng đợi."""
        return len(self.elements)  

    def display(self):  
        """Hiển thị toàn bộ hàng đợi từ đầu đến cuối."""
        print("Hàng đợi (đầu đến cuối):", self.elements)  


# Minh họa sử dụng hàng đợi  
if __name__ == "__main__":  
    # Tạo đối tượng hàng đợi
    queue = Queue()  
    
    # Thêm các phần tử vào hàng đợi
    queue.enqueue("Tài Liệu 1")  
    queue.enqueue("Tài Liệu 2")  
    queue.enqueue("Tài Liệu 3")  
    
    # Hiển thị hàng đợi
    queue.display()  

    # Lấy một phần tử ra khỏi hàng đợi
    queue.dequeue()  
    
    # Hiển thị phần tử đầu tiên mà không xóa nó
    print(f"Phần tử đầu tiên: {queue.front()}")  
    
    # Hiển thị kích thước của hàng đợi
    print(f"Kích thước hàng đợi: {queue.size()}")  
    
    # Kiểm tra hàng đợi có trống không
    print(f"Hàng đợi trống: {queue.is_empty()}")  
    
    # Hiển thị hàng đợi sau các thao tác
    queue.display()
