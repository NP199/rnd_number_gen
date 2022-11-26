#include <iostream>
#include <random>
#include <stdexcept>
#include <cmath>
#include <CLI/CLI.hpp>
#include <string>

uint16_t rand_uint16_t(int min, int max){
    if(min < std::pow(2, 16) && max < std::pow(2, 16)){
    uint16_t rnd_number;
    std::random_device r;
        std::mt19937 gen(r());
        std::uniform_int_distribution<uint16_t> uniform_dist(min, max);

        return uniform_dist(gen);
    }else{
        throw std::runtime_error("out of range!");
    }
}

uint16_t rand_uint8_t(int min, int max){
    if(min < std::pow(2, 8) && max < std::pow(2, 8)){
        uint8_t rnd_number;
        std::random_device r;
        std::mt19937 gen(r());
        std::uniform_int_distribution<uint8_t> uniform_dist(min, max);
        return uniform_dist(gen);
    }else{
        throw std::runtime_error("out of range!");
    }
}



int main(int argc, char** argv){
    CLI::App app{"rnd number"};

    std::string device{};
    uint16_t min{};
    uint16_t max{};

    app.add_option("-d,--device", device, "Help String");
    app.add_option("--min", min, "Help String");
    app.add_option("--max", max, "Help String");

    try{
        app.parse(argc, argv);
    }catch(const CLI::ParseError& e){
        return app.exit(e);
    }

    std::cout << device <<"\n";

    for(int i=0 ; i < 5 ; i++ ){
        std::cout << rand_uint8_t(min, max) << " \n";
    }

}
