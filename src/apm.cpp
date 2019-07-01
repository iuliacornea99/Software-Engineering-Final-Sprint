#include "apm.h"


APM::APM() {
    this->number_of_autopenciles = START_APM_NUM;
    this->price_autopencile = START_APM_PRICE;
    this->pencils_per_second = START_PENCILS_PER_SEC;
    this->required_intelligence = START_REQUIRED_INTELLIGENCE;
}

/**
 * @brief Increases the number of APMs
 */
void APM::increaseautopencil() {
    price_autopencile += price_autopencile*APM_INCREASE_RATE;
    number_of_autopenciles++;
}

/**
 * @brief Increases the pencil production rate per second
 */
void APM::increase_pencils_per_second() {
    pencils_per_second = pencils_per_second + (APM_INCREASE_RATE*pencils_per_second);
}

/**
 * @brief Increases the required intelligence to upgrade APM
 */
void APM::increase_required_intelligence() {
    required_intelligence = required_intelligence + APM_REQUIRED_INTELLIGENCE_INCREASE_RATE;
}

double APM::getPriceAutopencile() const {
    return price_autopencile;
}

void APM::setPriceAutopencile(double value) {
    price_autopencile = value;
}

double APM::getPencilsPerSecond() const {
    return pencils_per_second;
}

void APM::setPencilsPerSecond(double value) {
    pencils_per_second = value;
}

int APM::getRequiredIntelligence() const {
    return required_intelligence;
}

void APM::setRequiredIntelligence(int value) {
    required_intelligence = value;
}

int APM::getNumberOfAutopenciles() const {
    return number_of_autopenciles;
}

void APM::setNumberOfAutopenciles(int value) {
    number_of_autopenciles = value;
}
