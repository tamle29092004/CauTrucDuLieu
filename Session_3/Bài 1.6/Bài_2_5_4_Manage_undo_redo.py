#đây là chương trình về redo/undo
class TextEditor:
    def __init__(self):
        # Khởi tạo nội dung trình soạn thảo và hai ngăn xếp để quản lý undo/redo
        self.text_editor = ""
        self.undo_stack = []
        self.redo_stack = []

    def type_text(self, new_text):
        """Thêm văn bản mới vào trình soạn thảo."""
        # Lưu trạng thái hiện tại vào ngăn xếp undo trước khi chỉnh sửa
        self.undo_stack.append(self.text_editor)
        # Xóa redo_stack vì mỗi thay đổi mới sẽ làm mất hiệu lực redo trước đó
        self.redo_stack.clear()
        # Cập nhật nội dung
        self.text_editor += new_text
        self.display()

    def undo(self):
        """Hoàn tác hành động cuối cùng."""
        if self.undo_stack:
            # Đẩy trạng thái hiện tại vào ngăn xếp redo
            self.redo_stack.append(self.text_editor)
            # Lấy trạng thái cuối cùng từ undo_stack
            self.text_editor = self.undo_stack.pop()
            self.display()
        else:
            print("Không có hành động nào để hoàn tác.")

    def redo(self):
        """Làm lại hành động vừa hoàn tác."""
        if self.redo_stack:
            # Đẩy trạng thái hiện tại vào ngăn xếp undo
            self.undo_stack.append(self.text_editor)
            # Lấy trạng thái cuối cùng từ redo_stack
            self.text_editor = self.redo_stack.pop()
            self.display()
        else:
            print("Không có hành động nào để làm lại.")

    def display(self):
        """Hiển thị nội dung hiện tại của trình soạn thảo."""
        print(f"Nội dung hiện tại: '{self.text_editor}'")


# Minh họa
editor = TextEditor()
editor.type_text("Hello")      # Thêm "Hello"
editor.type_text(" World")     # Thêm " World"
editor.undo()                  # Hoàn tác: xóa " World"
editor.undo()                  # Hoàn tác: xóa "Hello"
editor.redo()                  # Làm lại: thêm lại "Hello"
