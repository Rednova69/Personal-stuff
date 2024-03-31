#include <iostream>
#include <chrono>
#include <thread>

std::ostream& typewrite(std::ostream &out,

const std::string &message)

{
    for (char ch : message)
    {
        out << ch << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(400));
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
