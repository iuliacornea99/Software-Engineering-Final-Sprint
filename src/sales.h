#ifndef SALES_H
#define SALES_H

#include<cmath>
/**
 * @brief The SALES class handles the price of pencils, the amount of marketing and the price of it and the public demand.
 */

class SALES{
public:
    double price = 1; /**< price of pencil */
    int marketing = 0; /**< marketing number */
    double public_demand = ((1/price)*pow(1.1, marketing)); /**< public demand */
    double marketing_price = 500; /**< price of marketing */
    int buymarketing = 0;

    /**
     * @brief function to increase price of pencil by 0.05
     */
    void increaseprice(){
        price += 0.05;
        public_demand = ((1/price)*pow(1.1, marketing));
    }

    /**
     * @brief function to decrease price of pencil by 0.05
     */
    void decreaseprice(){
        price-=0.05;
        public_demand = ((1/price)*pow(1.1, marketing));
    }

    /**
     * @brief function to increase marketing number by 1
     */
    void increasemarketing(){
        marketing++;
        public_demand = ((1/price)*pow(1.1, marketing));
    }

    /**
     * @brief function to increase maketing price by 10% multiplicatively.
     */
    void increasingmarketingprice(){
        marketing_price = marketing_price + (0.1*marketing_price);
    }


};

#endif // SALES_H
