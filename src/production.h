#ifndef PRODUCTION_H
#define PRODUCTION_H

#define WOOD_PER_PENCIL         0.21
#define GRAPHITE_PER_PENCIL     0.2

#include "wallet.h"
#include <iostream>
#include <ctime>

/**
 * @brief The Production class handles the resources used for producing pencils,
 * meaning wood and graphite and the also handles the generation of the resources' prices periodically.
 */

class Production{

public:
    double wood_left = 1000.00; /**< wood in the inventory */
    double graphite_left = 1000.00; /**< graphite in the inventory */
    double price_wood; /**< price of wood */
    double price_graphite; /**< price of graphite */

    /**
     * @brief function to decrease wood in the inventory by given amount
     */
    bool remove_wood(double wood){
        if(wood_left >= wood){
            wood_left -= wood;
        }
        return true;
    }

    /**
     * @brief function to decrease graphite in the inventory by given amount
     */
    bool remove_graphite(double graphite){
        if(graphite_left >= graphite){
            graphite_left -= graphite;
        }
        return true;
    }

    /**
     * @brief function to increase wood in the inventory by given amount
     */
    bool add_wood(double wood){
        wood_left+=wood;
        return true;
    }

    /**
     * @brief function to increae graphite in the inventory by given amount
     */
    bool add_graphite(double graphite){
        graphite_left += graphite;
        return true;
    }

    /**
     * @brief function to update prices of graphite and wood every 5 secs
     */
    void update_price(){
        std::srand(std::time(0));
        price_graphite = 1500.00 + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(2500.00-1500.00)));
        price_wood =  1000.00 + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(2000.00-1000.00)));
    }
};

#endif // PRODUCTION_H
