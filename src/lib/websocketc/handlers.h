
#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_client.hpp>

typedef websocketpp::client<websocketpp::config::asio_tls_client> client;
typedef websocketpp::lib::shared_ptr<websocketpp::lib::asio::ssl::context> context_ptr;

void on_message(client* c, websocketpp::connection_hdl, client::message_ptr msg) {
    c->get_alog().write(websocketpp::log::alevel::app, "Received Data: "+msg->get_payload());
    std::cout << msg->get_payload() << std::endl;
    // here we deal with message.
}

context_ptr on_tls_init(const char * hostname, websocketpp::connection_hdl) {
    context_ptr ctx = websocketpp::lib::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::sslv23);
    return ctx;
}

void on_open_handler(client* c, websocketpp::connection_hdl hdl, const std::string& requestMsg) {
    std::cout << "on_open with: "<< requestMsg << std::endl;

    // send request to websocket server
    // c->send(hdl,requestMsg,websocketpp::frame::opcode::text);
    // std::cout << "return code for client.send(): " << res << std::endl;
    c->get_alog().write(websocketpp::log::alevel::app, "Connection Opened");
}
void on_close_handler(client* c, websocketpp::connection_hdl) {
    std::cout << "on_close" << std::endl;
    c->get_alog().write(websocketpp::log::alevel::app, "Connection Closed");
}
