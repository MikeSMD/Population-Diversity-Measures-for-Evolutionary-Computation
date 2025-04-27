/**
 * @file unpresented_genes.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef GA_UNPRESENTED_GENES_HEADER
#define GA_UNPRESENTED_GENES_HEADER

#include <vector>
#include <set>
#include <stdexcept>
template< typename Chromosome, typename Item >

/**
 * @brief Metoda pro výpočet množství zahrnutých genů
 * 
 * @param count_of_genes - maximální počet genů v populaci
 * @param population - konteiner chromozomů populace
 *
 * @return - double hodnota 
 *
 * @throws runtime_error - pokud je count_of_genes < 1
 */
double unpresented_genes( std::size_t count_of_genes, const std::vector< Chromosome >& population );

#endif
