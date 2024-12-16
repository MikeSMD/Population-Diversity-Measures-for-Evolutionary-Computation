#ifndef HAMMING_DISTANCE_HEADER
#define HAMMING_DISTANCE_HEADER

#include <algorithm>

template<typename Chromosome>

/**
 * @brief Metoda pro výpočet Hammingovy vzdálenosti mezi dvěma chromozomy
 *
 * @param chromosomeOne - konteiner prvního chromozomu, musí mít definovanou metodu size a operátor []
 * @param chromosomeTwo - konteiner druhého chromozomu, musí mít definovanou metodu size a operátor []
 *
 * @return Integer hodnota - Výsledek Hammingovyv vzdáelenosti mezi chromosomeOne a chromosomeTwo
 *
 * @note - pro správný výpočet musí být délka chromozomů chromosomeOne a chomosomeTwo stejná. Také musí být jejich genotypy složeny maximálně ze dvou alel
 * @version 1.0
 * @author SCH0414
 */
unsigned int hamming_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo );

#endif
