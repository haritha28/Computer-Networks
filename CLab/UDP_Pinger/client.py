#!/usr/bin/python
import sys
import time 
from socket import*

if len(sys.argv) != 3:
	print "Not enough argurments"
	sys.exit()


clientsocket = socket(AF_INET, SOCK_DGRAM)

#one second waiting time to get the packet from the client
clientsocket.settimeout(1)

#declare server's socket address
remoteAddr = (sys.argv[1], int(sys.argv[2]))

#Ping ten times
for i in range(10):
	
	sendTime = time.time()
	message = 'PING'+ str(i+1) + " " + str(time.strftime("%H:%M:%S"))
	clientsocket.sendto(message, remoteAddr)

	recievedtime = time.time()
	rtt = recievedtime - sendTime
	print "Message Recieved", data
	print "Round Trip Time", rtt
	print
