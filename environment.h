#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QObject>
#include <QVector>
#include <deque>
#include <random>
#include "agent.h"



class Environment : public QObject {
    Q_OBJECT

public:
    Environment(int numberOfPeople, int consumerPercentage, int shelfLife, QObject *parent = nullptr);
    void updateEnvironment(int dayNumber);
    Agent::State getAgentState(int index) const;
    int getNumberOfPeople() const;

private:
    QVector<Agent*> agents;
    int numberOfPeople;
    int consumerPercentage;
    int currentDay = 0;
    int productUsers = 0;
    std::unordered_map<Agent*, int> buyerAndDays;
    std::deque<Agent*> notifyedAgents;

    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
};

#endif // ENVIRONMENT_H
