#!/usr/bin/python

import random
import sys
from socket import*

if len(sys.argv) != 2:
	print "No port number entered"
	sys.exit

#create a UDP socket for the server
serversocket = socket(AF_INET, SOCK_DGRAM)

serversocket.bind(('',int(sys.argv[1])))

while True:
	rand = random.randint(0,10)
	message, address = serversocket.recvfrom(1024)
	message = message.upper()
	if rand<4:
		continue
	serversocket.sendto(message, address)
