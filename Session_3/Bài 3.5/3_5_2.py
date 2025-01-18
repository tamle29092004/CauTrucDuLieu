from collections import deque

class RequestQueue:
    def __init__(self):
        self.queue = deque()
    
    def request(self, request):
        print(f"Đã thêm yêu cầu: {request}")
        self.queue.append(request)

    def process_request(self):
        if self.queue:
            request = self.queue.popleft()
            print(f"Đang xử lý yêu cầu: {request}")
        else:
            print("Không có yêu cầu nào để xử lý.")

    def display_queue(self):
        print("Hàng đợi yêu cầu:", list(self.queue))

# Minh họa sử dụng hàng đợi yêu cầu
rq = RequestQueue()
rq.request("Yêu cầu 1")
rq.request("Yêu cầu 2")
rq.request("Yêu cầu 3")
rq.display_queue()

rq.process_request()  # Output: Đang xử lý yêu cầu: Yêu cầu 1