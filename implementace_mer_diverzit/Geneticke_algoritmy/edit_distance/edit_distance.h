#ifndef EDIT_DISTANCE_HEADER
#define EDIT_DISTANCE_HEADER

#include <iostream>
#include <vector>

template<typename Chromosome>

/**
 * @brief Metoda pro výpočet Levenshteinvoy vzdálenosti
 *
 * @param chromosomeOne - Konteiner odkazující na první chromozom, musi implementovat metodu size()
 * @param chromosomeTwo - Konteiner odkazující na druhý chromozom, musí implementovat metodu size()
 *
 * @return bezznaménková celočíselná hodnota predstavujici vysledek vzdalenosti mezi prvnim a druhym chromnozomem
 *
 * @version 1.0
 * @author SCH0414
 */
unsigned int edit_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo );

#endif


