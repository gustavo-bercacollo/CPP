#pragma once

template <typename T>
void iter(T arr[], int const size, void (*func)(T &));

template <typename T>
void iter(T const arr[], int const size, void (*func)(T const &));

#include "iter.tpp"