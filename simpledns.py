import binascii
import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = ("", 5353)
print('starting up on {} port {}'.format(*server_address))
domain = "046d61696c066c747063676f03636f6d"
reversedns = "033134390234310233310331373207696e2d616464720461727061"
message = []
message.append("81830001000000000000033134390234310233310331373207696e2d61646472046172706100000c0001")
message.append("81800001000100000000046d61696c066c747063676f03636f6d0000010001c00c000100010000012b0004ac1f2995")
message.append("81800001000000010000046d61696c066c747063676f03636f6d00001c0001c01100060001000003830048076e732d3136333709617773646e732d313202636f02756b0011617773646e732d686f73746d617374657206616d617a6f6ec0180000000100001c20000003840012750000015180")
sock.bind(server_address)

while True:
	i=0
	print('\nwaiting to receive message')
	data, address = sock.recvfrom(1024)
	print('received {} bytes from {}'.format(len(data), address))
	print(binascii.hexlify(data).decode("utf-8"))
	if binascii.hexlify(data).decode("utf-8").find(reversedns) > 0:
		sent = sock.sendto(data[:2] + binascii.unhexlify(message[i]), address)
		print('sent {} bytes back to {}'.format(sent, address))
		print(binascii.hexlify(data[:2]) + message[i])
		data = ""
	i=1
	if data == "":
		print('waiting to receive message')
		data, address = sock.recvfrom(1024)
		print('received {} bytes from {}'.format(len(data), address))
	print(binascii.hexlify(data).decode("utf-8"))
	if binascii.hexlify(data).decode("utf-8").find(domain) > 0 and binascii.hexlify(data[len(data)-3:]) == "010001":
		sent = sock.sendto(data[:2] + binascii.unhexlify(message[i]), address)
		print('sent {} bytes back to {}'.format(sent, address))
		print(binascii.hexlify(data[:2]) + message[i])
		data = ""
	i=2
	if data == "":
		print('waiting to receive message')
		data, address = sock.recvfrom(1024)
		print('received {} bytes from {}'.format(len(data), address))
	print(binascii.hexlify(data).decode("utf-8"))
	if binascii.hexlify(data).decode("utf-8").find(domain) > 0 and binascii.hexlify(data[len(data)-3:]) == "1c0001":
		sent = sock.sendto(data[:2] + binascii.unhexlify(message[i]), address)
		print('sent {} bytes back to {}'.format(sent, address))
		print(binascii.hexlify(data[:2]) + message[i])
		data = ""
	print(binascii.hexlify(data[len(data)-2:]))

#Test with
#import binascii
#import socket
#
#def send_udp_message(message, address, port):
#	message = message.replace(" ", "").replace("\n", "")
#	server_address = (address, port)
#	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#	sock.sendto(binascii.unhexlify(message), server_address)
#	data, _ = sock.recvfrom(4096)
#	return binascii.hexlify(data).decode("utf-8")
#
#def format_hex(hex):
#	octets = [hex[i:i+2] for i in range(0, len(hex), 2)]
#	pairs = [" ".join(octets[i:i+2]) for i in range(0, len(octets), 2)]
#	return " ".join(pairs)
#
#message = "AA AA 01 00 00 01 00 00 00 00 00 00 04 6d 61 69 6c 06 6c 74 70 63 67 6f 03 63 6f 6d 00 00 01 00 01"
#
#response = send_udp_message(message, "8.8.8.8", 53)
#print(format_hex(response))
