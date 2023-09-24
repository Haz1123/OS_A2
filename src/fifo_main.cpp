#include <iostream>
#include "loader.h"

const std::string program_usage = "Program usage: fifo [datafile]";

int main(int argc, char** argv) {

    Loader loader = Loader("");
    try {
        loader.get_processes();
    } catch(PcbParseException e) {
        std::cout << "Error parsing datafile: " << e.what() << std::endl;
        exit(1);
    }
}

