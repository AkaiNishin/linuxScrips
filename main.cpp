#include <argparse/argparse.hpp>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>
#include <cstdlib>
#include <iostream>
#include <Commands.hpp>

int main(int argc, char *argv[]) {
    argparse::ArgumentParser program("linuxScrips");
    
    argparse::ArgumentParser twitch_command("twitch");
    twitch_command.add_description("Twitch related command for api request and media");
    
    twitch_command.add_argument("--reproduce")
        .help("Open a pop-up that streams Twitch with a given name")
        .nargs(1)
        .action([&](const std::string& name) {
            mFunctions::twitch_reproduce(name);
        });   
    
    twitch_command.add_argument("--followed")
        .help("This request for user information to Twitch API")
        .nargs(0)
        .action([&](const auto &){
            mFunctions::twitch_followed();
        });

    twitch_command.add_argument("--comment")
        .help("Send comment to bradcaster")
        .nargs(1)
        .action([&](const std::string& comment){
            mFunctions::twitch_comment(comment);
        });
    
    argparse::ArgumentParser dock_command("dock");
    dock_command.add_description("Allow toggle auto-hide dock in linux. Require --toggle");

    dock_command.add_argument("--toggle")
        .help("Toggle dock autohide")
        .nargs(0)
        .required()
        .action([&](const auto &) {
            mFunctions::dock_toggle();
        });

    program.add_subparser(twitch_command);
    program.add_subparser(dock_command);

        
    try {
        program.parse_args(argc, argv);
    } 
        catch (const std::exception &err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        return 1;
    }
    
    return 0;
}

