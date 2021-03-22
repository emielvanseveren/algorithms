#ifndef CHRONO_HPP
#define CHRONO_HPP

#endif

#include <chrono>

class Chrono {
public:
    Chrono();
    void start();
    void stop();
    double time() const;

private:
    std::chrono::time_point<std::chrono::steady_clock> begin;
    std::chrono::time_point<std::chrono::steady_clock> end;
};
