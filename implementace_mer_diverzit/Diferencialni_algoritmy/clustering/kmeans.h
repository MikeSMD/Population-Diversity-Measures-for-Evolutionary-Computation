#ifndef KMEANS_DIVERSITY_HEADER
#define KMEANS_DIVERSITY_HEADER


#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stdlib.h>

template<typename Container, typename Chromosome>
/**
 * @brief funkce pro shlukování populace
 *
 * @param population - Konteiner populace, musí implementovat metodu size a operátor []
 * @param cluster_count - počet shluků do kterých se má populace rozdělit
 * @param centroids - vektor, do něhož se uloží centroidy jednotlivých shluků
 * @param labels - vektor, do něhož se uloží index shluku ke konkrétnímu indexu chromozomu populace
 * @param distance_method - odkaz na metodu porovnávající dva jedince z populace
 * @param seed - hodnota ovlivňující náhodnou generaci čísel při incializaci centroidů jednotlivých shluků ( nemusí být zadán )
 *
 * @return - samotná funkce nevrací žádnou hodnotu
 * @note - předpokládá se, že všichni předaní jedinci mají stejný počet dimenzí
 * @version 1.0
 * @author SCH0414
 */
void k_means_clustering( const Container& population, const unsigned int cluster_count, std::vector< Chromosome >& centroids, std::vector< unsigned int >& labels, std::function< double( const Chromosome&, const Chromosome& ) > distance_method, unsigned int seed = 13 );

template<typename Container, typename Chromosome>
/**
 * @brief funkce pro určení ideálního počtu shluků v populaci pomocí elbow metody
 *
 * @param population - Konteiner populace, musí implementovat metodu size a operátor []
 * @param cluster_count - počet shluků do kterých se má populace rozdělit
 * @param distance_method - odkaz na metodu porovnávající dva jedince z populace
 *
 * @return - celočíselná hodnota korespondující s ideálním počtem shluků v poskytnuté populaci.
 * @note - předpokládá se, že všechny předaní jedinci mají stejný počet dimenzí
 * @version 1.0
 * @author SCH0414
 */
int cluster_count_determiner( const Container& population, int max_cluster_count, std::function< double( const Chromosome&, const Chromosome& ) > distance_method );

template<typename Container, typename Chromosome>
/**
 * @brief funkce pro výpočet Intra-cluster-diverzity jednotlivých shluků
 *
 * @param population - Konteiner populace, musí implementovat metodu size a operátor []
 * @param centroids - vektor s centroidy jednotlivých shluků
 * @param labels - vektor, indexů shluků ke konkrétnímu indexu chromozomu populace
 * @param distance_method - odkaz na metodu porovnávající dva jedince z populace
 *
 * @return - vektor double hodnot označujících diverzitu jednotkivých shluků
 * @note - předpokládá se, že všechny předaní jedinci mají stejný počet dimenzí
 * @version 1.0
 * @author SCH0414
 */
std::vector< double >& centroid_diversity( const Container& population, const std::vector< Chromosome >& centroids,const std::vector< unsigned int >& labels, std::function< double( const Chromosome&, const Chromosome& ) > distance_method );

#endif
