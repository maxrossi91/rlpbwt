//
// Created by dlcgold on 27/01/22.
//

#ifndef RLPBWT_MATCH_END_H
#define RLPBWT_MATCH_END_H

//
// Created by dlcgold on 17/01/22.
//

#ifndef RLPBWT_MATCH_H
#define RLPBWT_MATCH_H


#include <ostream>

/**
 * @brief class to rapresent a maximal match
 */
class match_end {
public:
    /**
     * @brief index on columns for the begin of a match
     */
    unsigned int begin;

    /**
     * @brief index on columns for the end of a match
     */
    unsigned int end;

    /**
     * @brief number of haplotypes in the match
     */
    unsigned int nhaplo;

    /**
    * @brief interval in the row of match
    */
    std::pair<unsigned int, unsigned int> interval;

    friend std::ostream &operator<<(std::ostream &os, const match_end &anEnd);

    bool operator==(const match_end &rhs) const;

    bool operator!=(const match_end &rhs) const;

    match_end(unsigned int begin, unsigned int anEnd, unsigned int nhaplo,
              std::pair<unsigned int, unsigned int> interval);

    virtual ~match_end();

};


#endif //RLPBWT_MATCH_H


#endif //RLPBWT_MATCH_END_H
