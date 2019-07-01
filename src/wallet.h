#ifndef WALLET_H
#define WALLET_H

/**
 * @brief The Wallet class handles the bank balance and the amount of intelligence
 */

class Wallet{

public:
    double bank_balance = 145; /**< total bank balance */
    int intelligence = 0; /**< total intelligence */

    /**
     * @brief function to increase bank balances by given amount
     */
    bool add_money(double money){
        bank_balance +=money;
        return true;
    }

    /**
     * @brief function to decrease bank balance by given amount
     */
    bool reduce_money(double money){
        if(bank_balance - money < 0.00){
            return false;
        }else{
            bank_balance-=money;
        }
        return true;
    }

    /**
     * @brief function to increase intelligence by 1
     */
    void increaseintelligence(){
        intelligence++;
    }

    /**
     * @brief function to decrease intelligence by given amount
     */
    void decreaseintelligence(int total_intelligence){
        intelligence = intelligence - total_intelligence;
    }
};

#endif // WALLET_H
