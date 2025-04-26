#include "DE_Diversity_logger.h"

template class DE_Diversity_logger< std::vector< double > >;

template < typename Individual >
DE_Diversity_logger < Individual >::DE_Diversity_logger( std::string filename, int interval, bool reset, std::vector< std::pair < double, double > > bounds ) : interval( interval ), bounds( bounds )
{



    if ( reset )
    {
    this->log_file = std::ofstream( filename );
    	this->log_file << "generation|average_dimension_diversities| average_dimension_diversity" << "|intra_cluster_diverisities" << "|euclidean_w_MPD" << "|manhattan_w_MPD" << "|mahalanobis_w_MPD" << "|shannon_entropy|average_fitness" <<"|best_fitness" <<"\n";
    }
    else
    {
        this->log_file = std::ofstream( filename, std::ios::app );
        this->log_file << "\n";
    }
   
}

template < typename Individual >
void DE_Diversity_logger < Individual >::log_Diversities( const std::vector< std::pair < Individual, double > >& population, int generation )
{
    if ( ! log_file ) return;
    if ( ( generation % this->interval != 0 )  && generation != 1 ) 
	    return;

    double average_fitness = population[ 0 ].second;
    double best_fitness = population[ 0 ].second;

    for ( std::size_t i = 0; i < population.size(); ++i )
    {
    	average_fitness += population[ i ].second;
    	if ( best_fitness < population[ i ].second )
	{
		best_fitness = population[ i ].second;
	}
    }
 

    this->log_file << "|" <<generation<< " | ";

    std::vector< Individual > individuals;
    for ( int individual = 0; individual < population.size(); ++individual )
    {
        individuals.emplace_back( static_cast< Individual >( population.at( individual ).first ) );
    }


    for ( int i = 0; i < individuals.at( 0 ).size(); ++i )
    {
        double dimension_diversity = dimension_wise_diversity< std::vector< Individual >, Individual >( individuals, i );
        this->log_file << dimension_diversity << ",";
    }

    double dimension_diversity = all_dimensions_wise_diversity< std::vector< Individual >, Individual >( individuals );
    
    
    
    int cluster_count = cluster_count_determiner< std::vector< Individual >, Individual >( individuals, 10, euclidean_distance< Individual >, 12 );

    std::vector< Individual > centroids= {};
    std::vector< unsigned int > labels = {};
    
    k_means_clustering< std::vector< Individual >, Individual >( individuals, cluster_count, centroids, labels, euclidean_distance< Individual >, 12 );
    
    std::vector< double > intra_cluster_diversities = centroid_diversity< std::vector< Individual >, Individual >( individuals, centroids, labels, euclidean_distance< Individual > );
 
 
    auto mahalanobis_distance_caller = [&]( const Individual& prvni, const Individual& druhy )
        {
		return 0.0;
           // return mahalanobis_distance< Individual >( prvni, druhy, individuals );
        };

    double MPD_euclidean = mean_pairwise_distance< std::vector< Individual >, Individual >( individuals, euclidean_distance< Individual > );
    double MPD_mahalanobis = mean_pairwise_distance< std::vector< Individual >, Individual >( individuals, mahalanobis_distance_caller );
    double MPD_manhattan = mean_pairwise_distance< std::vector< Individual >, Individual >( individuals, manhattan_distance< Individual > );
    double shannon = shannon_entropy( individuals, this->bounds );



    this->log_file << "|" <<dimension_diversity << " | ";
    for ( int i = 0; i < intra_cluster_diversities.size(); ++i )
    {
        this->log_file << intra_cluster_diversities.at( i ) << ",";
    }
    this->log_file << " | " << MPD_euclidean << " | ";
   
    this->log_file << MPD_manhattan << " | ";

     this->log_file << MPD_mahalanobis << " | ";
     this->log_file << shannon << " | ";
     this->log_file << average_fitness << " | ";
     this->log_file << best_fitness << " | ";
    
    this->log_file << "\n";    
    return;
}

template < typename Chromosome >
void DE_Diversity_logger< Chromosome >::close( )
{
    this->log_file.close();
}
