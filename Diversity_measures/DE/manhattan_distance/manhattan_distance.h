/**
 * @file manhattan_distance.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef MANHATTAN_DISTANCE_HEADER
#define MANHATTAN_DISTANCE_HEADER

#include <vector>
#include <stdexcept>

template<typename Individual>
/**
 * @brief Metoda pro vypocet Mahnhattan vzdálenosti
 *
 * @param chromosomeOne - Konteiner chromozomu, musí implementovat metodu size a operátor []
 * @param chromosomeTwo - Konteiner chromozomu, musí implementovat metodu size a operátor []
 *
 * 
 *
 * @throws runtime_error - pokud jedinci nemají stejný počet dimenzí
 * @return - double hodnota Manhattan vzdálenosti
 */


double manhattan_distance( const Individual& individualOne, const Individual& individualTwo );

#endif
