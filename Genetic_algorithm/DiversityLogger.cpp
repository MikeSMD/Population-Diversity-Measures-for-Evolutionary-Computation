#include "DiversityLogger.h"

template class DiversityLogger< std::vector< int > >;
template class DiversityLogger< std::vector< bool > >;

template < typename Chromosome >
DiversityLogger < Chromosome >::DiversityLogger( std::string filename, bool reset_file_content, int interval, std::size_t genes_count ) : interval(interval), genes_count ( genes_count )
{
    measure_hamming_distance = true;
    measure_edit_distance= true;
    measure_unpresented_genes= true;
    measure_shannon_enthropy= true;
    measure_simpson_index= true;
    measure_jaccard_index= true;
    measure_kendalls_tau= true;
    if ( reset_file_content )
    {
        this->log_file = std::ofstream( filename );
        this->log_file << "generation,edit_distance_MPD,hamming_distance_MPD,shannon_enthropy,simpson_index_of_diversity,jaccard_index,unpresented_genes,kendalls_tau,average_fitness,best_fitness" << std::endl;
    }
    else
    {
        this->log_file = std::ofstream( filename, std::ios::app );
        this->log_file << "\n";
    }
   
}
template < typename Chromosome >
void DiversityLogger < Chromosome >::setHammingDistance( bool set_value )
{
	this->measure_hamming_distance = set_value;
}
template < typename Chromosome >
void DiversityLogger < Chromosome >::setJaccardDistance( bool set_value )
{
	this->measure_jaccard_index= set_value;
}
template < typename Chromosome >
void DiversityLogger < Chromosome >::setSimpsonIndex( bool set_value )
{
	this->measure_simpson_index = set_value;
}
template < typename Chromosome >
void DiversityLogger < Chromosome >::setShannonEnthropy( bool set_value )
{
	this->measure_shannon_enthropy = set_value;
}
template < typename Chromosome >
void DiversityLogger < Chromosome >::setEditDistance( bool set_value )
{
	this->measure_edit_distance = set_value;
}
 template < typename Chromosome >
void DiversityLogger < Chromosome >::setUnpresentedGenes( bool set_value )
{
	this->measure_unpresented_genes = set_value;
}
 template < typename Chromosome >
void DiversityLogger < Chromosome >::setKendallsTau( bool set_value )
{
	this->measure_kendalls_tau = set_value;
};
template < typename Chromosome >
void DiversityLogger < Chromosome >::logDiversities( const std::vector< std::pair < Chromosome, double > >& population, int generation )
{
    if ( ( generation % this->interval != 0 )  && generation != 1 ) 
	    return;

    if ( ! log_file ) return;
 
    using Gene = std::remove_const_t<std::decay_t<decltype(population.at(0).first.at(0))>>;


    std::vector< Chromosome > chromosomes;
    for ( int chromosome = 0; chromosome < population.size(); ++chromosome )
    {
        chromosomes.emplace_back( population.at( chromosome ).first );
    }



   auto edit_distance_caller = []( const Chromosome& prvni, const Chromosome& druhy )
   {
   	return static_cast< double >(edit_distance< Chromosome >(prvni, druhy));
   };


    auto edit_hamming_caller = []( const Chromosome& prvni, const Chromosome& druhy )
   {
   	return static_cast< double >(hamming_distance< Chromosome >(prvni, druhy));
   };
  auto kendalls_tau_caller = []( const Chromosome& prvni, const Chromosome& druhy )
   {
   	return kendalls_tau< Chromosome >(prvni, druhy);
   };
    double best_fitness;
    double fitness_sum = 0.0;
	
    int index = 0;
    do{
    	if ( population[ index ].second > best_fitness )
    		best_fitness = population[ index ].second;

	fitness_sum += population[ index ].second;
    }
    while( ++index < population.size() );


    fitness_sum /= static_cast< double >( population.size() );
    double MPD_edit_distance = 0.0;
    double MPD_hamming_distance = 0.0;
   double shannon_entropy_value = 0.0; 
double simpson_index = 0.0;
 double MPD_jaccard_distance = 0.0;
 double unpresented_genes_diversity = 0.0;
double MPD_Kendalls_tau = 0.0;

	if( this->measure_edit_distance )
    		MPD_edit_distance = mean_pairwise_distance< std::vector< Chromosome >, Chromosome >( chromosomes, edit_distance_caller );

	if( this->measure_hamming_distance )
    		MPD_hamming_distance = mean_pairwise_distance< std::vector< Chromosome >, Chromosome >( chromosomes, edit_hamming_caller );

	if( this->measure_shannon_enthropy )
    		shannon_entropy_value = shannon_enthrophy< std::vector< Chromosome >, Chromosome, Gene >( chromosomes );

	if( this->measure_simpson_index )	
    		simpson_index = simpson_index_of_diversity< std::vector< Chromosome >, Chromosome, Gene >( chromosomes );

	if ( this->measure_jaccard_index )
    		MPD_jaccard_distance = mean_pairwise_distance< std::vector< Chromosome >, Chromosome>( chromosomes, jaccard_distance< Chromosome, Gene > );
	if( this->measure_unpresented_genes )
    		unpresented_genes_diversity = unpresented_genes<Chromosome, Gene  >( this->genes_count , chromosomes);
	
	if( this->measure_kendalls_tau )
 MPD_Kendalls_tau = mean_pairwise_distance< std::vector< Chromosome >, Chromosome >( chromosomes, kendalls_tau_caller );
    this->log_file << generation << ",";
    this->log_file << MPD_edit_distance << ",";
    this->log_file << MPD_hamming_distance << ",";
    this->log_file << shannon_entropy_value << ",";
    this->log_file << simpson_index << ",";
    this->log_file << MPD_jaccard_distance << ",";
    this->log_file << unpresented_genes_diversity<< ",";
    this->log_file << MPD_Kendalls_tau << ",";
    this->log_file << fitness_sum << ",";
    this->log_file << best_fitness << ",";

    this->log_file << "\n";

    return;
}

template < typename Chromosome >
void DiversityLogger< Chromosome >::close( )
{
    this->log_file.close();
}
