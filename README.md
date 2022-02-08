# RaySecur_Public
A simple server/client technical exercise using WebSocket++ and Python

Server: server.cpp

Client: file_client.py

Client reads from "input.txt" file and outputs to "output.txt" file

Compile server with "g++ -std=c++0x server.cpp -lboost_system -D_WEBSOCKETPP_CPP11_STL_ -pthread"

Python3 is recommended

Run server.cpp before file_client.py

Unexpected input will not be handled gracefully

Server will run continuously; client will go through each line of input.txt then exit.

--I recommend running the server as a background process
