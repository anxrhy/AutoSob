#pragma once // include heading only once per compilation unit
#include <atomic>
#include <functional>
#include <string>

std::string get_username(const std::string& token);
std::string sob_message(
    const std::string& token,
    const std::string& channel_id,
    const std::string& message_id
);
std::string listen_for_messages(
    const std::string& token,
    const std::string& channel_id,
    const std::string& user_id,
    const std::atomic<bool>& stop_requested,
    const std::function<void(const std::string&)>& status_changed
);