#ifndef JACCARD_INDEX_HEADER
#define JACCARD_INDEX_HEADER

#include <set>
#include <algorithm>

template<typename Chromosome, typename Item>

/**
 * @brief Metoda pro výpočet Jaccardovy vzdálenosti mezi dvěma chromozomy
 *
 * @param chromosomeOne - Konteiner prvního chromozomu, musí mít implementovanou metodu size a operátor []
 * @param chromosomeTwo - Konteiner druhého chromozomu, musí mít implementovanou metodu size a operátor []
 *
 * @return double - hodnota výsledku Jaccardovy vzdálenosti mezi poskytnutými chromozomy
 *
 * @version 1.0
 * @author SCH0414
 */
double jaccard_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo );

#endif
