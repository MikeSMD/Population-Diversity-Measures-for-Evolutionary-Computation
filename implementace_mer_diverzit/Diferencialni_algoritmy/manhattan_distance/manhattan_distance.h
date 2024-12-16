#ifndef MANHATTAN_DISTANCE_HEADER
#define MANHATTAN_DISTANCE_HEADER

#include <iostream>

template<typename Chromosome>
/**
 * @brief Metoda pro výpočet Mahnhattan vzdálenosti
 *
 * @param chromosomeOne - Konteiner chromozomu, musí implementovat metodu size a operátor []
 * @param chromosomeTwo - Konteiner chromozomu, musí implementovat metodu size a operátor []
 *
 * @return - double hodnota Manhattan vzdálenosti
 * @note - předpokládá se, že všichni předaní jedinci mají stejný počet dimenzí
 * @version 1.0
 * @author SCH0414
 */
double manhattan_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo );

#endif
