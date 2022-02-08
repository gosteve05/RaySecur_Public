# RaySecur_Public
A simple server/client technical exercise using WebSocket++ and Python
Compile server with "g++ -std=c++0x server.cpp -lboost_system -D_WEBSOCKETPP_CPP11_STL_ -pthread"
Python3 is recommended
Run server.cpp before client.py
client.py must be manually modified to send different messages to the server
Unexpected input will not be handled gracefully
Server will run continuously; client will run for the duration of one exchange

--I recommend running the server as a background process
