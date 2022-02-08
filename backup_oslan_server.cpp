#include <websocketpp/config/asio_no_tls.hpp>

#include <websocketpp/server.hpp>

#include <iostream>

typedef websocketpp::server<websocketpp::config::asio> server;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

// pull out the type of messages sent by our config
typedef server::message_ptr message_ptr;

// Write a new callback to respond to incoming messages
void on_message(server* s, websocketpp::connection_hdl hdl, message_ptr msg) {
	try
	{
		std::cout << "Does not currently parse JSON" << std::endl;
		std::cout << "Payload: " << msg->get_payload() << std::endl;
		/*
		   {"type":"add","payload":{"a":1,"b":2}}

		 
		 */
		/*
		 std::string type;
		 double a;
		 double b;
		 */
		std::string type = "add";
		std::string newline = "\n";
		double a = 3;
		double b = 4;
		double result = 0;
		std::string out_type = "";
		if(!type.compare("add"))
		{
			out_type = "sum";
			result = a + b;
		}
		else if(!type.compare("subtract"))
		{
			out_type = "difference";
			result = a - b;
		}
		std::string return_message = "{";
		return_message = return_message + "\n\t\"type\": ";
		return_message = return_message + out_type + "\n\t\"payload\": ";
		return_message = return_message + std::to_string(result) + "\n}";
		s->send(hdl, return_message, msg->get_opcode());
	} catch (websocketpp::exception const & e) {
		std::cout << "Failure because: (" << e.what() << ")" << std::endl;
	}
}

// Define a callback to handle incoming messages
/*void on_message(server* s, websocketpp::connection_hdl hdl, message_ptr msg) {
    std::cout << "on_message called with hdl: " << hdl.lock().get()
              << " and message: " << msg->get_payload()
              << std::endl;

    // check for a special command to instruct the server to stop listening so
    // it can be cleanly exited.
    if (msg->get_payload() == "stop-listening") {
        s->stop_listening();
        return;
    }

    try {
        s->send(hdl, msg->get_payload(), msg->get_opcode());
    } catch (websocketpp::exception const & e) {
        std::cout << "Echo failed because: "
                  << "(" << e.what() << ")" << std::endl;
    }
}*/

int main() {
    // Create a server endpoint
    server echo_server;

    try {
        // Set logging settings
        //echo_server.set_access_channels(websocketpp::log::alevel::all);
        //echo_server.clear_access_channels(websocketpp::log::alevel::frame_payload);

        // Initialize Asio
        echo_server.init_asio();

        // Register our message handler
        echo_server.set_message_handler(bind(&on_message,&echo_server,::_1,::_2));

        // Listen on port 9002
        echo_server.listen(9002);

        // Start the server accept loop
        echo_server.start_accept();

        // Start the ASIO io_service run loop
        echo_server.run();
    } catch (websocketpp::exception const & e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "other exception" << std::endl;
    }
}
