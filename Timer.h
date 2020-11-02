#pragma once

#include <chrono>
#include "Header.h"

using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;
using time_point = std::chrono::time_point<hrClock>;

double praejoLaiko(time_point);
void visasLaikas(container&, container&, string);