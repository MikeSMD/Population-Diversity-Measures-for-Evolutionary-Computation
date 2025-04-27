/**
 * @file simpson_index_diversity.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef SIMPSON_INDEX_HEADER
#define SIMPSON_INDEX_HEADER


#include <iostream>
#include <unordered_map>
#include <vector>

template<typename Container, typename Chromosome, typename Item>
/**
 * @brief Metoda pro výpočet Simpsonova Indexu populace
 *
 * @param population - Konteiner populace genetického algorimu
 *
 * @return double hodnota simpsonova indexu diverzity
 * @throws runtime_error - pokud populace nedisponuje žádnými geny
 *
 */
double simpson_index_of_diversity( const Container& population);

#endif
