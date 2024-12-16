#ifndef EUCLIDEAN_DISTANCE_HEADER
#define EUCLIDEAN_DISTANCE_HEADER

template<typename Chromosome, typename Container>
/**
 * @brief Metoda pro vypocet Mahalanobisovi vzdálenosti
 *
 * @param chromosomeOne - Konteiner chromozomu, musí implementovat metodu size a operátor []
 * @param chromosomeTwo - Konteiner chromozomu, musí implementovat metodu size a operátor []
 * @param population- Konteiner populace, musí implementovat metodu size a operátor []
 *
 * @return - double hodnota Mahalanobisovi vzdálenosti
 * @note - předpokládá se, že všichni předaní jedinci mají stejný počet dimenzí
 * @version 1.0
 * @author SCH0414
 */
double mahalanobis_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo, const Container& population );

#endif
