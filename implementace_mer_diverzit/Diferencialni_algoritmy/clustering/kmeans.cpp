#include "kmeans.h"

template<typename Container, typename Chromosome>
void k_means_clustering( const Container& population, const unsigned int cluster_count, std::vector< Chromosome >& centroids, std::vector< unsigned int >& labels, std::function< double( const Chromosome&, const Chromosome& ) > distance_method, unsigned int seed )
{
    srand( seed );

    size_t size = population.size();
    labels = {};

    for ( size_t i = 0; i < size; ++i )
    {
        labels.emplace_back( 0 );
    }
    centroids = {};

    for ( size_t i = 0; i < cluster_count; ++i )
    {
        centroids.emplace_back( population [ rand() % size ] );
    }

    bool centroids_changed = true;
    while ( centroids_changed )
    {
        centroids_changed = false;
        for ( size_t i = 0; i < size; ++i )
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

        size_t dimension_count = population[ 0 ].size();

        for ( unsigned int centroid_id = 0; centroid_id < cluster_count; ++centroid_id )
        {
            for ( size_t dimension = 0; dimension < dimension_count; ++dimension )
            {
                centroids[ centroid_id ][ dimension ] = 0;
            }
        }

        std::vector< int > cluster_size = {};
        for ( size_t cluster_id = 0; cluster_id < cluster_count; ++cluster_id )
        {
            cluster_size.emplace_back( 0 );
        }

        for ( size_t chromosome = 0; chromosome < size; ++chromosome )
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
                for ( size_t dimension = 0; dimension < dimension_count; ++dimension )
                {
                    centroids[ cluster_id ][ dimension ] /= cluster_size[ cluster_id ];   
                }
            }
        }

    }   // while
    
    return;
}

template<typename Container, typename Chromosome>
int cluster_count_determiner( const Container& population, int max_cluster_count, std::function< double( const Chromosome&, const Chromosome& ) > distance_method )
{
    std::vector< double > sses = {};
    for ( int cluster_count = 1; cluster_count < max_cluster_count; ++cluster_count )
    {
        std::vector< unsigned int > labels = {};
        std::vector < Chromosome > centroids = {};

        k_means_clustering<Container, Chromosome>( population, cluster_count, centroids, labels, distance_method );

        double sse = 0.0;
        for ( size_t chromosome = 0; chromosome < population.size(); ++chromosome )
        {
            sse += pow( distance_method( population[ chromosome ], centroids[ labels[ chromosome ] ] ), 2 );
        }
        sses.emplace_back( sse );
    }

    int cluster_count = 1;
    double max_sse_delta = -1.0;
    for ( size_t i = 1; i < sses.size(); ++i )
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

template<typename Container, typename Chromosome>
std::vector< double > centroid_diversity( const Container& population, const std::vector< Chromosome >& centroids,const std::vector< unsigned int >& labels, std::function< double( const Chromosome&, const Chromosome& ) > distance_method )
{
    std::vector < double > centroid_diversities( centroids.size(), 0 );
    std::vector < int > centroid_size( centroids.size(), 0 );
    for ( size_t i = 0; i < population.size(); ++i )
    {
        unsigned int cluster_id = labels[ i ];
        centroid_diversities[ cluster_id ] += distance_method( population[ i ], centroids[ cluster_id ] );
        centroid_size[ cluster_id ] += 1;
    }
    for ( size_t i = 0; i < centroid_diversities.size(); ++i )
    {
        if ( centroid_size[ i ] > 0 )
        {
            centroid_diversities[ i ] /= centroid_size[ i ];
        }
    }

    return centroid_diversities;

}
