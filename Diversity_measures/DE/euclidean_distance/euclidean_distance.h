/**
 * @file euclidean_distance.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef EUCLIDEAN_DISTANCE_HEADER
#define EUCLIDEAN_DISTANCE_HEADER
#include <vector>
#include <cmath>
#include <stdexcept>


template<typename Individual>


/**
 * @brief Metoda pro vypocet Euclidovy vzdálenosti
 *
 * @param individualOne - Konteiner jedince, musí implementovat metodu size a operátor []
 * @param individualTwo - Konteiner jedince, musí implementovat metodu size a operátor []
 *
 * @return - double hodnota euklidovy vzdálenosti
 * @throws - runtime_error pokud oba chromozomy nemají stejný počet dimenzí
 */
double euclidean_distance( const Individual& individualOne, const Individual& individualTwo );

#endif
