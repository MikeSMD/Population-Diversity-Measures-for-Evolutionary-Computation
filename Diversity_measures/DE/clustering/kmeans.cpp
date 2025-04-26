#include "kmeans.h"


template<typename Container, typename Chromosome>

void k_means_clustering( const Container& population, const unsigned int cluster_count, std::vector< Chromosome >& centroids, std::vector< unsigned int >& labels, std::function< double( const Chromosome&, const Chromosome& ) > distance_method, const unsigned int seed )
{

	if ( cluster_count == 0 || cluster_count > population.size() )
	{
		throw std::runtime_error ( "k_means_clustering: počet shluků je roven nule či je větší než velikost populace " );
	}

	std::mt19937 generator(seed);
	std::size_t size = population.size();
	std::uniform_int_distribution< std::size_t > distribution( 0, size - 1 );

    	labels = {};

    	for ( std::size_t i = 0; i < size; ++i )
   	{
	 	labels.emplace_back( 0 );
	}

	centroids = {};
	std::unordered_set < std::size_t > indexes = {}; 

	while ( indexes.size() != cluster_count )
	{
		std::size_t generated = distribution( generator );
		if ( ! indexes.count ( generated ) )
		{
			centroids.emplace_back( population [ generated ] );
			indexes.insert( generated );
		}
	}

	bool centroids_changed = true;

	while ( centroids_changed )
	{
		centroids_changed = false;
		for ( std::size_t i = 0; i < size; ++i )
		{

			unsigned int centroid_id = 0;
			double dist = distance_method( population[ i ], centroids[ 0 ] );

			for ( unsigned int j = 1; j < cluster_count; ++j )
			{

				double actual_distance = distance_method( population[ i ], centroids[ j ] );
				if ( dist > actual_distance)
				{
					dist = actual_distance;
					centroid_id = j;
				}
			}

			if ( labels[ i ] != centroid_id )
			{
				centroids_changed = true;
				labels[ i ] = centroid_id;
			}
		}

		std::size_t dimension_count = population[ 0 ].size();

		for ( unsigned int centroid_id = 0; centroid_id < cluster_count; ++centroid_id )
		{
			for ( std::size_t dimension = 0; dimension < dimension_count; ++dimension )
			{
				centroids[ centroid_id ][ dimension ] = 0;
			}
		}

		std::vector< std::size_t > cluster_size = {};
		for ( std::size_t cluster_id = 0; cluster_id < cluster_count; ++cluster_id )
		{
			cluster_size.emplace_back( 0 );
		}

		for ( std::size_t chromosome = 0; chromosome < size; ++chromosome )
		{
			unsigned int cluster_id = labels [ chromosome ];
			for ( size_t dimension = 0; dimension < dimension_count; ++dimension )
			{
				centroids[ cluster_id ][ dimension ] += population[ chromosome ][ dimension ];
			}

			cluster_size[ cluster_id ] += 1;
		}

		for ( unsigned int cluster_id = 0; cluster_id < cluster_count; ++cluster_id )
		{
			if ( cluster_size[ cluster_id ] > 0.0 )
			{
				for ( std::size_t dimension = 0; dimension < dimension_count; ++dimension )
				{
					centroids[ cluster_id ][ dimension ] /= cluster_size[ cluster_id ];   
				}
			}
		}

	}

	return;
}

template void k_means_clustering< std::vector< std::vector< double > >, std::vector< double > >( const std::vector< std::vector< double > >&, const unsigned int, std::vector< std::vector< double > >&, std::vector< unsigned int >&, std::function< double( const std::vector< double >&, const std::vector< double >& ) >, const unsigned int );

template<typename Container, typename Chromosome>

int cluster_count_determiner( const Container& population, const unsigned int max_cluster_count, std::function< double( const Chromosome&, const Chromosome& ) > distance_method, const unsigned int seed )
{



		if ( max_cluster_count == 0 || population.size() < max_cluster_count )
		{
			throw std::runtime_error ( "cluster_count_determiner: maximální počet clusterů musí být nastaven na hodnotu větší než 0 a musí být menší či roven velikosti populace " );
		}
		

	std::vector< double > sses = {};
	for ( unsigned int cluster_count = 1; cluster_count <= max_cluster_count; ++cluster_count )
	{
		std::vector< unsigned int > labels = {};
		std::vector < Chromosome > centroids = {};

		k_means_clustering<Container, Chromosome>( population, cluster_count, centroids, labels, distance_method, seed );

		double sse = 0.0;
		for ( std::size_t chromosome = 0; chromosome < population.size(); ++chromosome )
		{
			sse += pow( distance_method( population[ chromosome ], centroids[ labels[ chromosome ] ] ), 2 );
		}
		sses.emplace_back( sse );
	}

	int cluster_count = 1;
	double max_sse_delta = -1.0;
	for ( std::size_t i = 1; i < sses.size(); ++i )
	{
		double sse_delta = sses[ i - 1 ] - sses[ i ];
		if ( sse_delta > max_sse_delta )
		{
			max_sse_delta = sse_delta;
			cluster_count = i;
		}
	}

	return cluster_count + 1;
}


template int cluster_count_determiner< std::vector< std::vector< double > >, std::vector< double > >( const std::vector< std::vector< double > >&, const unsigned int, std::function< double ( const std::vector< double >&, const std::vector< double >& ) >, const unsigned int );


template<typename Container, typename Chromosome>
std::vector< double > centroid_diversity( const Container& population, const std::vector< Chromosome >& centroids,const std::vector< unsigned int >& labels, std::function< double( const Chromosome&, const Chromosome& ) > distance_method )
{
    std::vector < double > centroid_diversities( centroids.size(), 0 );
    std::vector < int > centroid_size( centroids.size(), 0 );
    for ( std::size_t i = 0; i < population.size(); ++i )
    {
        unsigned int cluster_id = labels[ i ];
        centroid_diversities[ cluster_id ] += distance_method( population[ i ], centroids[ cluster_id ] );
        centroid_size[ cluster_id ] += 1;
    }
    for ( std::size_t i = 0; i < centroid_diversities.size(); ++i )
    {
        if ( centroid_size[ i ] > 0 )
        {
            centroid_diversities[ i ] /= centroid_size[ i ];
        }
    }

    return centroid_diversities;
}
template std::vector< double > centroid_diversity< std::vector< std::vector< double > >, std::vector< double > >( const std::vector< std::vector < double> >&, const std::vector< std::vector< double > >&, const std::vector< unsigned int >&, std::function < double ( const std::vector< double >&, const std::vector< double >& ) > );

