#include <fmt/format.h>
#include <iostream>
#include <random>

template<typename T>
T rand_number_gen()
{
    T min{std::numeric_limits<T>::min()};
    T max{std::numeric_limits<T>::max()};
    T                              rnd_number;
    std::random_device                      r;
    std::mt19937                            gen(r());
    std::uniform_int_distribution<T> uniform_dist(min, max);
    return uniform_dist(gen);
}

int main(int argc, char** argv)
{
    std::uint8_t rnd_num_uint8_t{rand_number_gen<uint8_t>()};
    std::int8_t rnd_num_int8_t{rand_number_gen<int8_t>()};
    std::uint16_t rnd_num_uint16_t{rand_number_gen<uint16_t>()};
    std::int16_t rnd_num_int16_t{rand_number_gen<int16_t>()};
    std::uint32_t rnd_num_uint32_t{rand_number_gen<uint32_t>()};
    std::int32_t rnd_num_int32_t{rand_number_gen<int32_t>()};

    std::cout << "uint8_t:\t" << rnd_num_uint8_t << "\tint8_t\t"
              << rnd_num_int8_t << "\n\n";
    std::cout << "uint32_t:\t" << rnd_num_uint16_t << "\tint16_t\t"
              << rnd_num_int16_t << "\n\n";
    std::cout << "uint32_t:\t" << rnd_num_uint32_t << "\tint32_t\t"
              << rnd_num_int32_t << "\n\n";
    fmt::print("\n");

    fmt::print("uint8_t:\t{}\tint8_t\t{}\n", rnd_num_uint8_t, rnd_num_int8_t);
    fmt::print("uint16_t:\t{}\tint16_t\t{}\n", rnd_num_uint16_t, rnd_num_int16_t);
    fmt::print("uint32_t:\t{}\tint32_t\t{}\n", rnd_num_uint32_t, rnd_num_int32_t);
    return 0;
}
