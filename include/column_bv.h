//
// Created by dlcgold on 28/01/22.
//

#ifndef RLPBWT_COLUMN_BV_H
#define RLPBWT_COLUMN_BV_H

#include <vector>
#include <sdsl/int_vector.hpp>
#include <sdsl/bit_vectors.hpp>
#include <ostream>

/**
 * @brief class to represent a column that supports naive matching using
 * sparse bitvectors
 */
class column_bv {
public:
    /**
    * @brief bool to check first value of the column in PBWT matrix
    * (assuming biallelic)
    */
    bool zero_first{};

    /**
     * @brief total number of zeros in the column
     */
    unsigned int count_0{};

    /**
     * @brief sparse bit vector representing run
     */
    sdsl::sd_vector<> runs;

    /**
     * @brief rank support for runs sparse bitvector
     */
    sdsl::sd_vector<>::rank_1_type rank_runs;

    /**
     * @brief select support for runs sparse bitvector
     */
    sdsl::sd_vector<>::select_1_type select_runs;

    /**
     * @brief sparse bit vector representing u (as in Durbin)
     */
    sdsl::sd_vector<> u;

    /**
    * @brief rank support for u sparse bitvector
    */
    sdsl::sd_vector<>::rank_1_type rank_u;

    /**
    * @brief select support for u sparse bitvector
    */
    sdsl::sd_vector<>::select_1_type select_u;

    /**
     * @brief sparse bit vector representing v (as in Durbin)
     */
    sdsl::sd_vector<> v;

    /**
     * @brief rank support for v sparse bitvector
    */
    sdsl::sd_vector<>::rank_1_type rank_v;

    /**
     * @brief select support for v sparse bitvector
     */
    sdsl::sd_vector<>::select_1_type select_v;

    /**
     * @brief compressed sdsl int vector for lcp
     */
    sdsl::int_vector<> lcp;

    /**
     * @brief constructor for a column that supports naive matching using
     * sparse bitvectors
     * @param zeroFirst
     * @param count0
     * @param runs
     * @param u
     * @param v
     * @param lcp
     */
    column_bv(bool zeroFirst, unsigned int count0,
             const sdsl::bit_vector& runs,
             const sdsl::bit_vector& u,
             const sdsl::bit_vector& v,
             sdsl::int_vector<> lcp);

    /**
     * @brief default constructor
     */
    column_bv();

    /**
     * @brief default destructor
     */
    virtual ~column_bv();

    friend std::ostream &operator<<(std::ostream &os, const column_bv &columnbv);

    /**
     * @brief function to obtain size in bytes of the column
     * @param verbose bool for extra prints
     * @return size in bytes
     */
    unsigned long long size_in_bytes(bool verbose = false) const;

    /**
    * @brief function to obtain size in megabytes of the column
    * @param verbose bool for extra prints
    * @return size in megabytes
    */
    double size_in_mega_bytes(bool verbose = false) const;

    /**
     * @brief function to serialize the column object
     * @param out std::ostream object to stream the serialization
     * @return size of the serialization
     */
    size_t serialize(std::ostream &out, sdsl::structure_tree_node *v = nullptr,
                     const std::string& name = "");

    /**
     * @brief function to load the column object
     * @param in std::istream object from which load the column
     */
    void load(std::istream &in);
};


#endif //RLPBWT_COLUMN_BV_H
