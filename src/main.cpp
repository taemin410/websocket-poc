#include <iostream>
// #include <vector>
#include <string>
// #include <regex>

#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_client.hpp>

#include <websocketc/handlers.h>
#include <websocketc/config.h>

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

int main(int argc, char* argv[]) {

    client c;
    


    //////////////////////////////////////////
    //          Proof of Concept            //
    //////////////////////////////////////////

    // 스트림 
    // Pipeline consumer1; 데이터 사용자 (ex) MM or arbitrage signaler
    // Pipeline consumer2; or feed data to another program(python program or order book UI, ...) 
    // Pipeline producer;
    // Pipeline splitter;
    
    // mainPipeline.connect(&websocket)
    //             .connect(&producer)
    //             .connect(&splitter)

    // splitter.add(consumer1);
    // splitter.add(consumer2);


    // 데이터 디자인
    // Data should also be written to common generic object 
    // Data class ex) Tick is needed
    // Common fields can be Last Price, Volume, Timestamp (Best Ask, Best Bid) 

    //              Tick
    //                | 
    //  -----------------------------------------------------
    //  |             |             |           |           |
    // TradeTick    DepthTick   OrderTick       ...............

    // So all pipeline structure should take Tick as input and output 


    try {
        // Set logging to be pretty verbose (everything except message payloads)
        c.set_access_channels(websocketpp::log::alevel::all);
        c.clear_access_channels(websocketpp::log::alevel::frame_payload);
        c.set_error_channels(websocketpp::log::elevel::all);

        // Initialize ASIO
        c.init_asio();

        // Register our message handler
        c.set_message_handler(bind(&on_message, &c, ::_1, ::_2));
        c.set_tls_init_handler(bind(&on_tls_init, hostname.c_str(), ::_1));
		c.set_open_handler(bind(&on_open_handler, &c, websocketpp::lib::placeholders::_1, request));
		c.set_close_handler(bind(&on_close_handler, &c, websocketpp::lib::placeholders::_1));

        websocketpp::lib::error_code ec;
        client::connection_ptr con = c.get_connection(uri, ec);
        if (ec) {
            std::cout << "could not create connection because: " << ec.message() << std::endl;
            return 0;
        }

        // Note that connect here only requests a connection. No network messages are
        // exchanged until the event loop starts running in the next line.
        c.connect(con);

        c.get_alog().write(websocketpp::log::alevel::app, "Connecting to " + uri);

        // Start the ASIO io_service run loop
        // this will cause a single connection to be made to the server. c.run()
        // will exit when this connection is closed.
        c.run();

    } catch (websocketpp::exception const & e) {
        std::cout << e.what() << std::endl;
    } catch (std::exception const & e){
        std::cout << e.what() << std::endl;
    }

}

