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
    

def sendWindow(client_socket,window,sender):
    for i in window:
        client_socket.send(sender.frames[i].encode())


client_socket, client_address = server_socket.accept()
print(f"\n\nConnection established with {client_address}")

file_name="message_data.txt"
sender = Sender(file_name)

start=time.time()

frames_len = len(sender.frames)
window_size = 4

client_socket.settimeout(1)




window=[]
for i in range(0,min(frames_len,window_size)):
    window.append(i)

# sendWindow(client_socket,window,sender)

next_to_send=window_size

while True:
    try:

        if len(window)==0:
            break


        print(f"\nCurrent window: {window}")
        #send the frame
        message_to_send = sender.frames[window[0]]
        parts = message_to_send.split(':')
        header, seq, payload, received_checksum = parts
        errored_payload = sender.run_injectError(payload)
        new_frame = sender.header + ':' + seq + ":" + errored_payload + ':' + received_checksum

        message_bytes = bytes(new_frame, "utf-8")
        client_socket.send(message_bytes)

        waiting_for=window[0]
        print(f"Waiting for ack of frame {waiting_for}")
        received_data = client_socket.recv(1024).decode()
        ack_message, seq=received_data.split(":")
        # print(f"seq: {seq}")
        if(waiting_for==int(seq) and ack_message=="ACK"):
            print(f"Ack received for frame {seq}")
            window=window[1:]
            if next_to_send<frames_len:
                window.append(next_to_send)
                next_to_send+=1
                


    except socket.timeout:
        print(f"Timeout: No ACK received for frame {window[0]}. Resending frame: {window[0]}.")
        # window=window[1:].append(window[0])
        temp=window[0]
        window=window[1:]
        window.append(temp)

        # sendWindow(client_socket,window,sender)


# Close the socket
client_socket.close()
end=time.time()
duration=end-start
print(f"The time taken to complete the transmission is {duration} s")
