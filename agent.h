#ifndef AGENT_H
#define AGENT_H

#include <QObject>

class Agent : public QObject {
    Q_OBJECT

public:
    enum State {
        PotentialBuyer,
        ProductUser
    };

    Agent(int life_time, QObject *parent = nullptr);

    State getState() const;
    void becomeBuyer();
    void notifyOtherAgent(Agent *other);
    void decayProduct();
    int getDays() const;
    void reset();
    bool operator==(const Agent& other) const {
        return this == &other;
    }
    bool isNotifyed() const;

private:
    State currentState;
    int productLifeTime;
    int daysHasTheProduct;
    bool notifyed = false;
};

namespace std {
template<>
struct hash<Agent> {
    std::size_t operator()(const Agent& agent) const noexcept {
        return std::hash<const Agent*>()(&agent);
    }
};
};

#endif // AGENT_H
