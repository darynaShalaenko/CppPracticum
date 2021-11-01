#ifndef PASSENGER_HPP_INCLUDED
#define PASSENGER_HPP_INCLUDED

#include <string>

#include "Person.hpp"

class Passenger : protected Person
{
protected:
    std::string Departure;
    std::string Arrival;
    int place;
};

#endif // PASSENGER_HPP_INCLUDED
