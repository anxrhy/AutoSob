#include <iostream>
#include "discord.h"
#include "app-window.h"

int main() {
    auto ui = AppWindow::create();

    ui->on_login([ui](const slint::SharedString& token) {
        std::string username = get_username(std::string(token));
        std::cout << "Logged in as " + username + "\n" << std::endl;

        if (username != "Request failed" && username != "Failed to parse username") {
            ui->set_username(slint::SharedString(username));
            ui->set_logged_in(true);
        }
    });

    ui->on_start_sobbing([](const slint::SharedString& channel_id, const slint::SharedString user_id) {
        if (channel_id.empty()) {
            std::cout << "Please enter a Channel Id" << std::endl;
            return;
        } 
        
        std::cout << "Channel id: " + channel_id << std::endl;

        if (user_id.empty()) {
            std::cout << "Monitoring all new messages" << std::endl;
        } else {
            std::cout << "Monitoring messages from user ID: " + user_id << std::endl;
        }

        // Message monitoring
    });

    ui->run();
    
}
