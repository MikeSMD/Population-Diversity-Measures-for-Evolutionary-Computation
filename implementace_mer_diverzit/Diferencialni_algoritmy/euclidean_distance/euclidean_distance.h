#ifndef EUCLIDEAN_DISTANCE_HEADER
#define EUCLIDEAN_DISTANCE_HEADER

template<typename Chromosome>

/**
 * @brief Metoda pro vypocet Euclidovy vzdálenosti
 *
 * @param chromosomeOne - Konteiner chromozomu, musí implementovat metodu size a operátor []
 * @param chromosomeTwo - Konteiner chromozomu, musí implementovat metodu size a operátor []
 *
 * @return - double hodnota euklidovy vzdálenosti
 * @note - předpokládá se, že oba chromozomy mají stejný počet dimenzí
 * @version 1.0
 * @author SCH0414
 */
double euclidean_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo );

#endif
