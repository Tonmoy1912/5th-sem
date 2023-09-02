import socket
from injectError import *
import time

server_socket = socket.socket()
print("Socket Created")

server_socket.bind(("localhost", 8000))
server_socket.listen(1)

print("Waiting for connections....")

class Sender:
    def __init__(self, file_name):
        self.file_name = file_name
        self.header = '1011000101001010'  # it is set as a constant
        self.frame_size = 32  # Set the frame size to 32
        self.file_content = self.read_file()
        if self.file_content is not None:
            # print("File Contents:")
            # print(self.file_content)
            # print("Length of the file content:", len(self.file_content), "\n")
            self.payloads = self.break_into_payloads()
            print("Payloads :")
            print(self.payloads,"\n")
            self.frames = self.break_into_frames(self.payloads)
            # print(self.frames)
            print(f"Frames (total frame= {len(self.frames)}) : ")
            for frame in self.frames : 
                print(frame)
            print("\n")

    def read_file(self):
        try:
            # with open(self.file_name, 'r') as file:
            #     content = file.read()
            #     return content
            f=open(self.file_name)
            return f.read()
        except FileNotFoundError:
            print(f"Error: File '{self.file_name}' not found.")
            return None
        except Exception as e:
            print(f"Error: Unable to read file '{self.file_name}'.")
            print(f"Exception: {e}")
            return None
        
    def run_injectError(self, payload):
        error_injector = InjectError(payload)
        return error_injector.inject_error()


    def break_into_payloads(self):
        if self.file_content is None:
            return None

        payloads = []
        for i in range(0, len(self.file_content), self.frame_size):
            payloads.append(self.file_content[i:i + self.frame_size])
        return payloads
    

    def divide_into_substrings(self, string):
        substrings = []
        for i in range(0, len(string), 16):
            substrings.append(string[i:i + 16])
        return substrings

    def calculate_checksum(self, substrings):
        total_sum = 0
        for substring in substrings:
            binary_num = int(substring, 2)
            total_sum += binary_num
            carry = total_sum >> 16
            total_sum = (total_sum & 0xFFFF) + carry

        checksum = total_sum & 0xFFFF
        checksum = ~checksum & 0xFFFF

        checksum_str = ""
        for i in range(16):
            val = (checksum & 1)
            checksum_str = str(val) + checksum_str
            checksum >>= 1

        return checksum_str

    def break_into_frames(self, payloads):
        frames = []
        frame_seq=0
        for payload in payloads:
            trailer = self.calculate_checksum(self.divide_into_substrings(payload))
            frame = self.header + ':' + str(frame_seq) + ":" + payload + ':' + trailer
            # calculate crc or checksum and append it as well
            frames.append(frame)
            frame_seq+=1

        # print("\nFrames: ")
        # print(frames)

        return frames


client_socket, client_address = server_socket.accept()
print(f"\n\nConnection established with {client_address}")

file_name="message_data.txt"
sender = Sender(file_name)

frames_len = len(sender.frames)
curr_frame = 0

client_socket.settimeout(1)

start=time.time()

while curr_frame < frames_len:
    message_to_send = sender.frames[curr_frame]
    parts = message_to_send.split(':')
    header, seq, payload, received_checksum = parts
    errored_payload = sender.run_injectError(payload)
    new_frame = sender.header + ':' + seq + ":" + errored_payload + ':' + received_checksum

    message_bytes = bytes(new_frame, "utf-8")

    client_socket.send(message_bytes)
    print(f"Frame {curr_frame} sent")

    try:
        received_data = client_socket.recv(1024).decode()
        # print(f"Received from Client: {received_data}")

        if received_data == "ACK":
            print(f"Received ACK from the client for frame {curr_frame}")
            curr_frame += 1
    except socket.timeout:
        print(f"Timeout: No ACK received. Resending frame {curr_frame}.")
        continue 


client_socket.close()

end=time.time()

duration=end-start
print(f"Time taken to complete the transmission {duration} s")
