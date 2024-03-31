#include <iostream>
#include <chrono>
#include <thread>
#include <random>

std::mt19937_64 eng{std::random_device{}()};
std::uniform_int_distribution<> dist{200, 600};

std::ostream& typewrite(std::ostream &out, const std::string &message)
{
    for (char ch : message)
    {
        out << ch << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds{dist(eng)});
    }
    out << '\n';
    return out;
}

int main()
{
    if (!(typewrite(std::cout, "Hello there")))
    {
        std::cerr << "Failed to write.\n";
    }
    return 0;
}
