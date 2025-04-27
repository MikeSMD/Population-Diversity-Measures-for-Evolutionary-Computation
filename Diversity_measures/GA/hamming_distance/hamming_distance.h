/**
 * @file hamming_distance.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef HAMMING_DISTANCE_HEADER
#define HAMMING_DISTANCE_HEADER

#include <algorithm>
#include <vector>
#include <stdexcept>

template<typename Chromosome>

/**
 * @brief Metoda pro výpočet Hammingovy vzdálenosti mezi dvěma chromozomy
 *
 * @param chromosomeOne - konteiner prvního chromozomu, musí mít definovanou metodu size a operátor []
 * @param chromosomeTwo - konteiner druhého chromozomu, musí mít definovanou metodu size a operátor []
 *
 * @return Integer hodnota - Výsledek Hammingovy vzdáelenosti mezi chromosomeOne a chromosomeTwo
 *
 * @throws runtime_error pokud mají chromozomy různý počet genů
 */
unsigned int hamming_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo );

#endif
