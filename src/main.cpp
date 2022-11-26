#include <iostream>
#include <random>
#include <stdexcept>
#include <cmath>
#include <CLI/CLI.hpp>
#include <string>
#include <typeinfo>
#include <fmt/format.h>

template <typename T>
T rand_number_gen(T min, T max){
        //fmt::print("Function 1\n");
        fmt::print("min:\t{}\tmax:\t{}\n", std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
        T rnd_number;
        std::random_device r;
        std::mt19937 gen(r());
        std::uniform_int_distribution<uint16_t> uniform_dist(min, max);
        return uniform_dist(gen);

}

template <typename T>
T rand_number_gen(){
        //fmt::print("Function 2\n");
        T min{std::numeric_limits<T>::min()};
        T max{std::numeric_limits<T>::max()};
        fmt::print("min:\t{}\tmax:\t{}\n", std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
        T rnd_number;
        std::random_device r;
        std::mt19937 gen(r());
        std::uniform_int_distribution<uint16_t> uniform_dist(min, max);
        return uniform_dist(gen);

}

int main(int argc, char** argv){
    CLI::App app{"rnd number"};

    std::string device{};
    uint16_t min{};
    uint16_t max{};

    app.add_option("-d,--device", device, "Help String");
    app.add_option("--min", min, "random number range min");
    app.add_option("--max", max, "random number range max");

    try{
        app.parse(argc, argv);
    }catch(const CLI::ParseError& e){
        return app.exit(e);
    }

    std::cout << device <<"\n";
    std::uint8_t min_8{20};
    std::uint8_t max_8{255};
    min = 0;
    max = 65535;
    std::uint8_t rnd_number_uint8_t{rand_number_gen<uint8_t>(0, UINT8_MAX)};
    std::int8_t rnd_number_int8_t{rand_number_gen<int8_t>(INT8_MIN, INT8_MAX )};
    std::cout <<"uint8_t:\t" << rnd_number_uint8_t << "\tint8_t\t" << rnd_number_int8_t <<"\n\n";
    std::uint16_t rnd_number_uint16_t{rand_number_gen<uint16_t>(0, UINT16_MAX)};
    std::int16_t rnd_number_int16_t{rand_number_gen<int16_t>(INT16_MIN, INT16_MAX )};
    std::cout <<"uint32_t:\t" << rnd_number_uint16_t << "\tint16_t\t" << rnd_number_int16_t <<"\n\n";
    std::uint32_t rnd_number_uint32_t{rand_number_gen<uint32_t>(0, UINT32_MAX )};
    std::int32_t rnd_number_int32_t{rand_number_gen<int32_t>(INT32_MIN, INT32_MAX )};
    std::cout <<"uint32_t:\t" << rnd_number_uint32_t << "\tint32_t\t" << rnd_number_int32_t <<"\n\n";
    fmt::print("\n");

    fmt::print("uint8_t:\t{}\tint8_t\t{}\n", rnd_number_uint8_t, rnd_number_int8_t);
    fmt::print("uint16_t:\t{}\tint16_t\t{}\n", rnd_number_uint16_t, rnd_number_int16_t);
    fmt::print("uint32_t:\t{}\tint32_t\t{}\n", rnd_number_uint32_t, rnd_number_int32_t);
    fmt::print("\n");


    std::cout <<"uint8_t:\t" << rand_number_gen<uint8_t>() << "\tint8_t\t" << rand_number_gen<int8_t>() <<"\n\n";
    std::cout <<"uint32_t:\t" << rand_number_gen<uint16_t>() << "\tint16_t\t" << rand_number_gen<int16_t>() <<"\n\n";
    std::cout <<"uint32_t:\t" << rand_number_gen<uint32_t>() << "\tint32_t\t" << rand_number_gen<int32_t>() <<"\n\n";
    fmt::print("\n");


    fmt::print("uint8_t:\t{}\tint8_t\t{}\n", rand_number_gen<uint8_t>(), rand_number_gen<int8_t>());
    fmt::print("uint16_t:\t{}\tint16_t\t{}\n", rand_number_gen<uint16_t>(), rand_number_gen<int16_t>());
    fmt::print("uint32_t:\t{}\tint32_t\t{}\n", rand_number_gen<uint32_t>(), rand_number_gen<int32_t>());
}
