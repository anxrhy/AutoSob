#include <curl/curl.h> 
#include <nlohmann/json.hpp>
#include <iostream>

std::string get_username(const std::string& token) {
    CURL* curl = curl_easy_init();
    if (!curl) return "Failed to initialize via curl_easy_init()";

    // Create a variable to store server response in
    std::string response;

    // request URL configuration
    curl_easy_setopt(curl, CURLOPT_URL, "https://discord.com/api/v10/users/@me");

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, +[](char* data, size_t size, size_t count, void* output) {
        static_cast<std::string*>(output)->append(data, size * count);
        return size * count;
    });

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // form headers
    std::string auth = "Authorization: " + token;

    curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, auth.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // send request
    CURLcode result = curl_easy_perform(curl);

    // store error code
    long status = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);

    // clean up
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (result != CURLE_OK || status != 200) {
        std::cout << "Status: " << status << '\n';
        std::cout << response << '\n';
        return "Request failed";
    }

    return nlohmann::json::parse(response)["username"].get<std::string>();
}
