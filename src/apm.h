#ifndef APM_H
#define APM_H

#define START_APM_NUM                               1
#define START_APM_PRICE                             150.0
#define START_PENCILS_PER_SEC                       2
#define START_REQUIRED_INTELLIGENCE                 50
#define MAX_APMS                                    10
#define APM_INCREASE_RATE                           0.1
#define APM_REQUIRED_INTELLIGENCE_INCREASE_RATE     150

/**
 * @brief The APM class is used to represent and store all member variables
 * and functionalities used by the APM machine.
 */
class APM{
private:

    /**
     * @brief number_of_autopenciles number of APMs
     */
    int number_of_autopenciles;

    /**
     * @brief price_autopencile price of APMs
     */
    double price_autopencile;

    /**
     * @brief pencils_per_second pencil production rate per second
     */
    double pencils_per_second;

    /**
     * @brief required_intelligence required intelligence to upgrade APM
     */
    int required_intelligence;

public:

    /**
     * @brief APM Constructor
     */
    APM();

    /**
     * @brief Increases the number of APMs
     */
    void increaseautopencil();

    /**
     * @brief Increases the pencil production rate per second
     */
    void increase_pencils_per_second();

    /**
     * @brief Increases the required intelligence to upgrade APM
     */
    void increase_required_intelligence();

    /**
     * @return number of autopenciles
     */
    int getNumberOfAutopenciles() const;

    /**
     * @brief set a new value for autopenciles.
     * @param value the new value of autopenciles.
     */
    void setNumberOfAutopenciles(int value);

    /**
     * @return price of autopenciles
     */
    double getPriceAutopencile() const;

    /**
     * @brief set a new value for price of autopenciles.
     * @param value the new value of price of autopenciles.
     */
    void setPriceAutopencile(double value);

    /**
     * @return rate of pencil production
     */
    double getPencilsPerSecond() const;

    /**
     * @brief set a new value for rate of pencil production.
     * @param value the new value of rate of pencil production.
     */
    void setPencilsPerSecond(double value);

    /**
     * @return number of required intelligence
     */
    int getRequiredIntelligence() const;

    /**
     * @brief set a new value for required intelligence.
     * @param value the new value of required intelligence.
     */
    void setRequiredIntelligence(int value);
};

#endif // APM_H
