from websocket import create_connection
import json

ws = create_connection("ws://localhost:9002/websocket")
result = "nonempty"
while(result != ""):
    ws.send("Message")
    result = ws.recv()
    received = json.loads(result)
    type_received = received["type"]
    payload = received["payload"]
    print("Type: '%s'" % type_received)
    print("Payload: '%s'" % payload)
    result = ""
