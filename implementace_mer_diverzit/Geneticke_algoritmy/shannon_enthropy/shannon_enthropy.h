#ifndef SHANNON_ENTHROPY_HEADER
#define SHANNON_ENTHROPY_HEADER


#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

template<typename Container, typename Chromosome, typename Item>
/**
 * @brief Metoda pro výpočet Shanonovy entropie 
 * 
 * @param population - konteiner chromozomů populace
 *
 * @return - double hodnota Shanonovy entropie
 *
 * @version 1.0
 * @author SCH0414
 */
double shannon_enthrophy( const Chromosome& population );

#endif
