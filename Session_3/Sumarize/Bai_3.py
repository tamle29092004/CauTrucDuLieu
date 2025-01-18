# this is a progam about history of robot operation
class Robot:
    def __init__(self):
        self.position = [0, 0]  # [x, y]
        self.direction = 'N'  # Hướng ban đầu
        self.history = []  # Ngăn xếp lưu trữ các lệnh

    # Hàm di chuyển về phía trước
    def move_forward(self):
        if self.direction == 'N':
            self.position[1] += 1
        elif self.direction == 'E':
            self.position[0] += 1
        elif self.direction == 'S':
            self.position[1] -= 1
        elif self.direction == 'W':
            self.position[0] -= 1
        self.history.append('forward')  # Lưu lại lệnh di chuyển
        print(f"Đã di chuyển tới: {self.position}, Hướng: {self.direction}")

    # Hàm di chuyển lùi
    def move_backward(self):
        if self.direction == 'N':
            self.position[1] -= 1
        elif self.direction == 'E':
            self.position[0] -= 1
        elif self.direction == 'S':
            self.position[1] += 1
        elif self.direction == 'W':
            self.position[0] += 1
        self.history.append('backward')  # Lưu lại lệnh di chuyển
        print(f"Đang di chuyển lại: {self.position}, Hướng: {self.direction}")

    # Hàm quay trái
    def turn_left(self):
        dirs = ['N', 'E', 'S', 'W']
        idx = dirs.index(self.direction)
        self.direction = dirs[(idx + 1) % 4]  # Quay trái một bước trong hướng
        self.history.append('left')  # Lưu lại lệnh quay trái
        print(f"Đã quay trái. Vị trí hiện tại: {self.position}, Hướng: {self.direction}")

    # Hàm quay phải
    def turn_right(self):
        dirs = ['N', 'E', 'S', 'W']
        idx = dirs.index(self.direction)
        self.direction = dirs[(idx + 1) % 4]  # Quay phải một bước trong hướng
        self.history.append('right')  # Lưu lại lệnh quay phải
        print(f"Đã quay phải. Vị trí hiện tại: {self.position}, Hướng: {self.direction}")

    

    # Hàm hoàn tác lệnh cuối cùng
    def undo(self):
        if not self.history:
            print("Không có lệnh nào để hoàn tác.")
            return

        last_command = self.history.pop()  # Lấy lệnh cuối cùng ra
        if last_command == 'forward':
            self.move_backward()  # Quay lại bước trước đó
        elif last_command == 'backward':
            self.move_forward()  # Quay lại bước trước đó
        elif last_command == 'left':
            self.turn_right()  # Quay lại theo chiều ngược lại
        elif last_command == 'right':
            self.turn_left()  # Quay lại theo chiều ngược lại
        print(f"Đã hoàn tác lệnh '{last_command}'.")
# Hàm hiển thị trạng thái
    def display_status(self):
       
        print(f"Vị trí hiện tại: {self.position}, Hướng: {self.direction}")
# Minh họa
if __name__ == "__main__":
    robot = Robot()
    robot.move_forward()  # Di chuyển về phía trước
    robot.turn_right()  # Quay phải
    robot.move_forward()  # Di chuyển về phía trước
    robot.turn_left()  # Quay trái
    robot.move_backward()  # Di chuyển lùi
    robot.display_status()  # Hiển thị trạng thái hiện tại

    print('\nThực hiện Undo:')
    robot.undo()  # Hoàn tác lệnh cuối cùng
    robot.undo()  # Hoàn tác lệnh cuối cùng
    robot.display_status()  # Hiển thị trạng thái sau khi hoàn tác
