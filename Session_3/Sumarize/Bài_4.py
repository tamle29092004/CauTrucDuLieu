# this is a program to simulate a robot controller that processes commands from a queue
from collections import deque
import threading
import time  # Thêm thư viện time để sử dụng time.sleep

class CommandQueue:
    def __init__(self):
        self.queue = deque()  # Sử dụng deque để làm hàng đợi
        self.lock = threading.Lock()  # Khóa để bảo vệ dữ liệu khỏi truy cập đồng thời
    
    def enqueue(self, command):
        """Thêm lệnh vào hàng đợi"""
        with self.lock:
            self.queue.append(command)
            print(f'Đã thêm lệnh vào hàng đợi: {command}')

    def dequeue(self):
        """Lấy và thực thi lệnh từ hàng đợi"""
        with self.lock:
            if self.queue:
                command = self.queue.popleft()  # Lấy lệnh đầu tiên
                print(f'Đang thực thi lệnh: {command}')
                return command
            else:
                return None

    def is_empty(self):
        """Kiểm tra xem hàng đợi có rỗng không"""
        with self.lock:
            return len(self.queue) == 0

class RobotController:
    def __init__(self, command_queue):
        self.command_queue = command_queue
        self.thread = threading.Thread(target=self.process_commands, daemon=True)  # Tạo thread để xử lý lệnh
        self.thread.start()  # Khởi động thread ngay khi controller được tạo

    def process_commands(self):
        """Xử lý các lệnh trong hàng đợi"""
        while True:
            if self.command_queue.is_empty():
                time.sleep(1)  # Nếu hàng đợi rỗng, chờ 1 giây
                continue

            command = self.command_queue.dequeue()  # Lấy lệnh ra khỏi hàng đợi
            if command:
                self.execute_command(command)  # Thực thi lệnh

    def execute_command(self, command):
        """Thực thi lệnh cụ thể"""
        if command == "forward":
            print("Robot đang đi tới.")
        elif command == "backward":
            print("Robot đang lùi lại.")
        elif command == "right":
            print("Robot đang quay phải.")
        elif command == "left":
            print("Robot đang quay trái.")
        elif command == "stop":
            print("Robot đã dừng lại.")
        else:
            print(f"Lệnh không hợp lệ: {command}")
        time.sleep(1)  # Giả lập thời gian thực thi lệnh

# Minh họa
def main():
    command_queue = CommandQueue()  # Tạo đối tượng hàng đợi lệnh
    controller = RobotController(command_queue)  # Tạo điều khiển robot

    # Thêm các lệnh vào hàng đợi
    commands = ['forward', 'left', 'forward', 'right', 'backward', 'stop']
    for cmd in commands:
        command_queue.enqueue(cmd)

    time.sleep(10)  # Chờ một thời gian để các lệnh được thực thi trước khi kết thúc chương trình

if __name__ == "__main__":
    main()  # Chạy chương trình
