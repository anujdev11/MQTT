import paho.mqtt.subscribe as subscribe

import time
import paho.mqtt.client as paho
broker="192.168.1.36"


client= paho.Client("try")
print("connecting to broker ",broker)
client.connect(broker)#connect
client.loop_start() #start loop to process received messages

time.sleep(2)
ty=""
while ty!="stop":
	ty=input("Enter message to publish:")
	client.publish("led",ty)#publish
	time.sleep(1)
client.loop_stop() #stop loop