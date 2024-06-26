import socket

client_socket = socket.socket()
client_socket.connect(('localhost', 8000))

def divide_into_substrings(string):
        substrings = []
        for i in range(0, len(string), 16):
            substrings.append(string[i:i + 16])
        return substrings

def calculate_checksum(substrings):
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


# waiting_for=0

received_frames=[]

while True: 
    received_message = client_socket.recv(1024).decode()

    if not received_message:
        break 

    print("Received from Server:", received_message)

    parts = received_message.split(':')
    if len(parts) == 4:
        header, seq, payload, received_checksum = parts

        # if(int(seq)!=waiting_for):
        #     print(f"Frame {seq} discarded due to out of order")
        #     continue

        calculated_checksum = calculate_checksum(divide_into_substrings(payload))

        # print(f"Received Checksum: {received_checksum}")
        # print(f"Calculated Checksum: {calculated_checksum}")

        if received_checksum == calculated_checksum:
            ack_message = f"ACK:{seq}"
            client_socket.send(ack_message.encode())
            print(f"Checksum is correct for frame {seq}. ACK sent.\n")
            received_frames.append(tuple((seq,payload)))
            # waiting_for+=1
        else:
            print(f"Checksum is incorrect for frame {seq}. No ACK sent.\n")
    else:
        print("Invalid frame format. No ACK sent.\n")

client_socket.close()

received_frames=sorted(received_frames,key= lambda x:x[0])

print("Received frames are:")
for frame in received_frames:
    print(f"seq: {frame[0]} payload: {frame[1]}")

