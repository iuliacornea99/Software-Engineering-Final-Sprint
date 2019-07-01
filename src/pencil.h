#ifndef _PENCIL_H
#define _PENCIL_H

#define MIN_PENCIL_PRICE    0.05

/**
 * @brief The Pencil class handles the current number of pencils that are in the inventory,
 * the total number of pencils since the start of the game. It also has defined a function that increase
 * both the number of pencils in the inventory and the number of pencils produced since the start of the game.
 */
class Pencil {

public:
    int lifetime_produced = 0; /**< total pencils produced */
    int inventory = 0; /**< pencils in the inventory */

    /**
     * @brief function to increase pencils in the inventory and total pencils
     * produced by given amount
     */
    void increase_pencil_inv(int amount = 1){
        inventory += amount;
        lifetime_produced += amount;
    }
};

#endif /* _PENCIL_H */
