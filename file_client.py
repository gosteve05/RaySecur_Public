from websocket import create_connection
import json

ws = create_connection("ws://localhost:9002/websocket")
file1 = open("input.txt", "r")
file2 = open("output.txt", "w")
input_list = file1.readlines()


for line in input_list:
    #message = "{\"type\": \"" + send_type + "\", \"payload\": {\"a\": " + str(a) + ", \"b\": " + str(b) + "}}"
    #"type": "add", "payload": {"a": 1, "b": 2}}
    ws.send(line)
    result = ws.recv()
    file2.write(result + "\n")
    received = json.loads(result)
    type_received = received["type"]
    payload = received["payload"]
    print("Type: '%s'" % type_received)
    print("Payload: '%s'" % payload)
