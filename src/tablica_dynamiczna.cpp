#include <iostream>
#include "tablica_dynamiczna.hpp"

tablicaDynamiczna::tablicaDynamiczna(int initialCapacity)
    : data(nullptr), size_(0), capacity_(initialCapacity) {}

tablicaDynamiczna::~tablicaDynamiczna() {}
