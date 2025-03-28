#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>

std::string renderHTML(const std::string& title, const std::vector<std::string>& messages) {
    std::ostringstream html;
    html << '<!DOCTYPE html>
<html>
<head>
';
    html << '<title>' << title << '</title>
';
    html << '</head>
<body>
';
    html << '<h1>' << title << '</h1>
';
    for (const std::string& message : messages) {
        html << '<p>' << message << '</p>
';
    }
    html << '</body>
</html>';
    return html.str();
}

void handleGet(web::http::http_request request) {
    std::vector<std::string> messages = {'Welcome to my C++ Web Service', 'Hello, World!'};
    std::string htmlContent = renderHTML('C++ with HTML', messages);
    request.reply(web::http::status_codes::OK, htmlContent, 'text/html');
}

int main() {
    web::http::experimental::listener::http_listener listener('http://localhost:6502');

    listener.support(web::http::methods::GET, handleGet);

    try {
        listener.open().wait();
        std::cout << 'Server is running on http://localhost:6502' << std::endl;
        while (true);
    } catch (std::exception const & e) {
        std::cerr << 'There was an error while setting up the HTTP listener: ' << e.what() << std::endl;
    }

    return 0;
}
