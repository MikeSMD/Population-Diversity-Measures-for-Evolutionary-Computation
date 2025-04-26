#include "shannon_entropy.h"
template< typename Individual >

double shannon_entropy( const std::vector< Individual >& population, const std::vector < std::pair < double, double > >& bounds, const unsigned int m ) 
{
	if (population.empty() || bounds.empty()) 
		throw std::runtime_error("shannon_entropy: populace či rozsahy jsou příliš malé") ;


	const std::size_t dimensions = bounds.size();
	const int size = population.size();  
	for ( std::size_t i = 0 ; i < size; ++i )
	{
		if ( population[ i ] != dimensions )
			throw std::runtime_error("shannon_entropy: rozsahy neodpovídají pčotu dimenzí v populaci") ;
	}

    std::vector<std::vector<double>> normalized( size, std::vector<double>( dimensions ));

    for ( std::size_t i = 0; i < size; ++i) {
        for ( std::size_t j = 0; j < dimensions; ++j)
	{
            normalized[i][j] = (population[i][j] - bounds[j].first) / (bounds[j].second - bounds[j].first);
        }
    }

    double entropy = 0.0;
    for ( std::size_t j = 0; j < dimensions; ++j) {
        std::unordered_map< std::size_t ,  std::size_t > bin_counts;
        for ( std::size_t k = 0; k < m; ++k )
		bin_counts[ k ] = 0;

        for ( std::size_t i = 0; i < size; ++i ) {
            double gene = normalized[ i ][ j ];
	    std::size_t bin = gene * m;
	    if ( bin >= m )
	    {
	    	bin = m - 1;
	    }
            bin_counts[ bin ] ++;
        }

        double local_entropy = 0.0;
        for (const auto& bins : bin_counts) {
            if (bins.second > 0) {
                double p = static_cast<double>( bins.second ) / size;
                local_entropy += p * std::log(p);
            }
        }
        entropy += - local_entropy;
    }
    return entropy / ( dimensions * std::log(m));
}
