/**
 * @file DiversityLogger.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef GA_DIVERSITY_LOGGER_HEADER
#define GA_DIVERSITY_LOGGER_HEADER

#include <fstream>

// diversities imports
#include "../Diversity_measures/GA/edit_distance/edit_distance.h"
#include "../Diversity_measures/GA/mean_pairwise_distance/mean_pairwise_distance.h"
#include "../Diversity_measures/GA/hamming_distance/hamming_distance.h"
#include "../Diversity_measures/GA/shannon_entropy/shannon_entropy.h"
#include "../Diversity_measures/GA/simpson_index_diversity/simpson_index_diversity.h"
#include "../Diversity_measures/GA/jaccard_index/jaccard_index.h"
#include "../Diversity_measures/GA/unpresented_genes/unpresented_genes.h"
#include "../Diversity_measures/GA/Kendalls_tau/Kendalls_tau.h"

#include <vector>

template < typename Chromosome >

/**
 * @class DiversityLogger
 * @brief třída pro logování měr diverzit GA
 */

class DiversityLogger
{

	private:
		/**
		 * @brief název logovacího souboru
		 */
		std::ofstream log_file;


		/**
		 * @brief interval výpočtu a uložení měr diverzit
		 */
		int interval;
		/**
		 * @brief počet genů, jež může obsahovat populace
		 */
		unsigned int genes_count;
		/**
		 * @brief vlajka, učující měření hammingovy vzdálenosti.
		 */
		bool measure_hamming_distance;
		/**
		 * @brief vlajka, učující měření Levenshteinovi vzdálenosti.
		 */
		bool measure_edit_distance;
		/**
		 * @brief vlajka, učující měření míry zahrnutí genů.
		 */ 
		bool measure_unpresented_genes;
		/**
		 * @brief vlajka, učující měření shanonovi entropie.
		 */ 
		bool measure_shannon_enthropy;
		/**
		 * @brief vlajka, učující měření simpsonova indexu diverzity.
		 */ 
		bool measure_simpson_index;
		/**
		 * @brief vlajka, učující měření Jaccardova indexu.
		 */ 
		bool measure_jaccard_index;
		/**
		 * @brief vlajka, učující měření Kendallovy vzdálenosti.
		 */ 
		bool measure_kendalls_tau;

	public:
 /**
		 * @brief konsturktor třídy DiversityLogger
		 * @param[in] filename - název logovacího souboru
		 * @param[in] reset_file_content - zda se má logovací soubor přepsat či pouze rozšířit (bez ztráty původních dat.)
		 * @param[in] interval - interval měření
		 */  
	    DiversityLogger( std::string filename, bool reset_file_content, int interval, std::size_t genes_count );

     /**
		 * @brief metoda pro logování diverzit
		 * @param[in] population - populace
		 * @param[in] generation - generace
		 */ 
    void logDiversities( const std::vector< std::pair< Chromosome, double > >& population, int generation );

/**
		 * @brief setter pro nastavení vlajky měření Hammingovy vzdálenosti
		 * @param[in] set_value - hodnota vlajky
		 */ 
    void setHammingDistance( bool set_value );
   /**
		 * @brief setter pro nastavení vlajky měření Jaccardova indexu
		 * @param[in] set_value - hodnota vlajky
		 */  
    void setJaccardDistance( bool set_value );
   /**
		 * @brief setter pro nastavení vlajky měření Simpsonova indexu diverzity
		 * @param[in] set_value - hodnota vlajky
		 */  
    void setSimpsonIndex( bool set_value );
   /**
		 * @brief setter pro nastavení vlajky měření Shanonovi entropie
		 * @param[in] set_value - hodnota vlajky
		 */  
    void setShannonEnthropy( bool set_value );
   /**
		 * @brief setter pro nastavení vlajky měření Levenshteinovi vzdálenosti
		 * @param[in] set_value - hodnota vlajky
		 */  
    void setEditDistance( bool set_value );
   /**
		 * @brief setter pro nastavení vlajky měření míry zahrnutých genů
		 * @param[in] set_value - hodnota vlajky
		 */  
    void setUnpresentedGenes( bool set_value );
   /**
		 * @brief setter pro nastavení vlajky měření Kendallovi tau vzdálenosti.
		 * @param[in] set_value - hodnota vlajky
		 */  
    void setKendallsTau( bool set_value );

    void close();

    ~DiversityLogger() = default;
    

};

#endif
