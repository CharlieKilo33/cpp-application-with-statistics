#include "agent.h"

Agent::Agent(int life_time, QObject *parent) : QObject(parent), currentState(PotentialBuyer), productLifeTime(life_time), daysHasTheProduct(0) {}

Agent::State Agent::getState() const {
    return currentState;
}

void Agent::becomeBuyer() {
    if (currentState == PotentialBuyer) {
        currentState = ProductUser;
        notifyed = false;
        daysHasTheProduct = 0;
    }
}

void Agent::notifyOtherAgent(Agent *other) {
    if (currentState == ProductUser && other->getState() == PotentialBuyer) {
        other->notifyed = true;
    }
}

void Agent::decayProduct() {
    if (currentState == ProductUser && daysHasTheProduct < productLifeTime) {
        ++daysHasTheProduct;
        if (daysHasTheProduct == productLifeTime) {
            reset();
        }
    }
}

void Agent::reset(){
    currentState = PotentialBuyer;
    daysHasTheProduct = 0;
    notifyed = false;
}

int Agent::getDays() const {
    return daysHasTheProduct;
}

bool Agent::isNotifyed() const {
    return notifyed;
}
