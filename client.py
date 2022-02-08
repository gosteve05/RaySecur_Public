from websocket import create_connection
import json

ws = create_connection("ws://localhost:9002/websocket")
result = "nonempty"
while(result != ""):
    send_type = "subtract"
    a = 5.2
    b = -7
    message = "{\"type\": \"" + send_type + "\", \"payload\": {\"a\": " + str(a) + ", \"b\": " + str(b) + "}}"
    #"type": "add", "payload": {"a": 1, "b": 2}}
    ws.send(message)
    result = ws.recv()
    received = json.loads(result)
    type_received = received["type"]
    payload = received["payload"]
    print("Type: '%s'" % type_received)
    print("Payload: '%s'" % payload)
    result = ""
