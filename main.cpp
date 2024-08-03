
#include <argparse/argparse.hpp>
#include <string>
#include <cstdlib>

int main(int argc, char *argv[]) {
    argparse::ArgumentParser program("linuxScrips");

    std::string command;
    program.add_argument("--twitch")
        .help("Open a pop-up that streams Twitch with a given name")
        .nargs(1)
        .action([&command](const std::string& name) {
            command = "./scrips/twitch-popup.sh " + name;
            std::system(command.c_str());
        });   

    program.add_argument("--dock_autohide")
        .help("Toggle dock autohide")
        .nargs(0)
        .action([&command](const std::string& c) {
            command = "./scrips/toggle-dock-autohide.sh";
            std::system(command.c_str());
        });
    
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

