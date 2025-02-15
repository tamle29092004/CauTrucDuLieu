
#this is a program about a sensor that sends data to a print queue
import random
import collections
import threading
import time

class Sensor:
    def __init__(self, id, print_queue):
        self.id = id
        self.print_queue = print_queue

    def run(self):
        while True:
            data = f"Dữ liệu từ cảm biến (ID: {self.id}, giá trị: {random.randint(1, 100)})"
            time.sleep(random.uniform(0.5, 2))  # Giả lập dữ liệu ngẫu nhiên
            self.print_queue.enqueue(data)

class PrintQueue:
    def __init__(self):
        self.queue = collections.deque()
        self.lock = threading.Lock()

    def enqueue(self, data):
        with self.lock:
            self.queue.append(data)
            print(f"Đã thêm vào hàng đợi: {data}")

    def process_queue(self):
        while True:
            with self.lock:
                if self.queue:
                    data = self.queue.popleft()
                    print(data)  # In dữ liệu đã lấy từ hàng đợi
                    time.sleep(1)  # Giả lập thời gian xử lý

# Minh họa
def main():
    print_queue = PrintQueue()

    # Khởi động thread xử lý hàng đợi
    processor = threading.Thread(target=print_queue.process_queue, daemon=True)
    processor.start()

    # Tạo và khởi động các cảm biến
    sensors = [Sensor(i, print_queue) for i in range(5)]
    for sensor in sensors:
        threading.Thread(target=sensor.run, daemon=True).start()

    # Giữ chương trình chạy
    while True:
        time.sleep(10)  # Thực hiện một chút thời gian để các thread chạy

if __name__ == "__main__":
    main()
