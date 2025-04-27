/**
 * @file shannon_enthrophy.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef SHANNON_ENTHROPY_HEADER
#define SHANNON_ENTHROPY_HEADER


#include <stdexcept>
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
 * @throws runtime_error - pokud populace nedisponuje žádnými geny
 */
double shannon_enthrophy( const Container& population );

#endif
