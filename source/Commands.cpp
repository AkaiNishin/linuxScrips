#include <Commands.hpp>
#include <cstdlib>
#include <iostream>
#include <nlohmann/json.hpp>

std::string url = "https://api.twitch.tv/helix/channels/followed?user_id=634074494";
cpr::Header header = {
    {"Authorization", "Bearer 96se4yvf6s4pmi1700knbq58nhsi1c"},
    {"Client-Id", "1m2s416adykxp0z0ag74cm5xko4jj4"}
};

void mFunctions::twitch_reproduce(const std::string &name) {
  std::string command = "./scrips/twitch-popup.sh " + name;
  std::system(command.c_str());
}

void mFunctions::twitch_followed() {

  cpr::Response response = cpr::Get(cpr::Url{url}, cpr::Header{header});
  if (response.status_code == 200) {
    auto jsondata = nlohmann::json::parse(response.text);
    int i;
    for (i = 0; i < jsondata["total"]; i++) {
      std::cout << jsondata["data"][i]["broadcaster_name"] << "\n";
    }
  } else {
        mHelper::failedRequest(response);
    }
}

void mFunctions::twitch_comment(const std::string &comment) {
  cpr::Response response = cpr::Get(cpr::Url(url), cpr::Header{header});
  if (response.status_code == 200) {
    std::cout << "Comment: \n";
  } else {
        mHelper::failedRequest(response);
    }
}

void mFunctions::dock_toggle() {
  std::string command = "./scrips/toggle-dock-autohide.sh";
  std::system(command.c_str());
}

void mHelper::failedRequest(const cpr::Response &response) {
  std::cerr << "Request failed with status code: " << response.status_code
            << "\n"
            << "Error message: " << response.error.message << "\n";
}

