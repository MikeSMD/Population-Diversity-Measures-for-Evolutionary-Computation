#ifndef SHANNON_ENTHROPY_HEADER
#define SHANNON_ENTHROPY_HEADER


#include <iostream>
#include <unordered_map>
#include <vector>

template<typename Container, typename Chromosome, typename Item>
/**
 * @brief Metoda pro výpočet Simpsonova Indexu populace
 *
 * @param population - Konteiner populace genetického algorimu
 *
 * @return double hodnota simpsonovy diverzity
 *
 * @version 1.0
 * @author SCH0414
 */
double simpson_index_of_diversity( const Container& population);

#endif
