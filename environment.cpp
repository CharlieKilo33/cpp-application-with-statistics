#include "environment.h"
#include <iostream> // Для отладки

Environment::Environment(int numberOfPeople, int consumerPercentage, int shelfLife, QObject *parent) : QObject(parent),
    numberOfPeople(numberOfPeople), consumerPercentage(consumerPercentage), gen(std::random_device{}()), dis(0, numberOfPeople - 1) {
    for (int i = 0; i < numberOfPeople; ++i) {
        agents.append(new Agent(shelfLife, this));
    }
}

void Environment::updateEnvironment(int dayNumber) {
    if (dayNumber == 0) {
        for (auto& agent : agents) {
            agent->reset();
        }
        productUsers = 0;
        currentDay = dayNumber;
        notifyedAgents.clear();
        std::cout << "Reset all agents." << std::endl;
    } else if(dayNumber <= currentDay) {
        for (auto& agent : agents) {
            agent->reset();
        }
        productUsers = 0;
        notifyedAgents.clear();
        buyerAndDays.clear();

        // Считаем всё заново до текущего дня
        for (int day = 1; day <= dayNumber; ++day) {
            std::cout << "Updating environment for day " << dayNumber << std::endl;

            // Выводим состояние всех агентов в начале дня
            std::cout << "Agents states at start of day " << dayNumber << ": ";
            for (int i = 0; i < agents.size(); ++i) {
                std::cout << "Agent " << i << ": " << agents[i]->getState() << ", ";
            }
            std::cout << std::endl;

            std::cout << "Processing day " << day << std::endl;
            int consumerCount = numberOfPeople * (consumerPercentage * 0.01);

            while (!notifyedAgents.empty()) {
                auto agent = notifyedAgents.front();
                notifyedAgents.pop_front();

                if (productUsers < numberOfPeople && agent->getState() != Agent::State::ProductUser) {
                    agent->becomeBuyer();
                    ++productUsers;
                    buyerAndDays[agent] = agent->getDays();
                    std::cout << "Notified agent became a buyer." << std::endl;
                }
            }

            for (int i = 0; i < consumerCount; ++i) {
                if (productUsers >= numberOfPeople) {
                    break;
                }
                int randomIndex1;
                do {
                    randomIndex1 = dis(gen);
                } while (getAgentState(randomIndex1) == Agent::State::ProductUser);

                if (randomIndex1 < 0 || randomIndex1 >= agents.size()) {
                    std::cerr << "Error: randomIndex1 out of bounds: " << randomIndex1 << std::endl;
                    return;
                }

                agents[randomIndex1]->becomeBuyer();
                buyerAndDays[agents[randomIndex1]] = agents[randomIndex1]->getDays();
                ++productUsers;
                std::cout << "Random agent " << randomIndex1 << " became a buyer." << std::endl;

                if (productUsers >= numberOfPeople) {
                    break;
                }

                int randomIndex2;
                do {
                    randomIndex2 = dis(gen);
                } while (getAgentState(randomIndex2) == Agent::State::ProductUser || randomIndex2 == randomIndex1);

                if (randomIndex2 < 0 || randomIndex2 >= agents.size()) {
                    std::cerr << "Error: randomIndex2 out of bounds: " << randomIndex2 << std::endl;
                    return;
                }

                agents[randomIndex1]->notifyOtherAgent(agents[randomIndex2]);
                notifyedAgents.push_back(agents[randomIndex2]);
                std::cout << "Random agent " << randomIndex1 << " notified agent " << randomIndex2 << std::endl;
            }

            // Обрабатываем покупателей по времени действия продукта
            for (auto &[agent, day] : buyerAndDays) {
                agent->decayProduct();
                day = agent->getDays();
                if (agent->getState() == Agent::State::PotentialBuyer) {
                    --productUsers;
                }
            }
        }
        currentDay = dayNumber;
    } else {
        for (int day = currentDay + 1; day <= dayNumber; ++day) {
            std::cout << "Updating environment for day " << dayNumber << std::endl;
            std::cout << "Agents states at start of day " << dayNumber << ": ";
            for (int i = 0; i < agents.size(); ++i) {
                std::cout << "Agent " << i << ": " << agents[i]->getState() << ", ";
            }
            std::cout << std::endl;

            std::cout << "Processing future day " << day << std::endl;
            int consumerCount = numberOfPeople * (consumerPercentage * 0.01);

            while (!notifyedAgents.empty()) {
                auto agent = notifyedAgents.front();
                notifyedAgents.pop_front();

                if (productUsers < numberOfPeople && agent->getState() != Agent::State::ProductUser) {
                    agent->becomeBuyer();
                    ++productUsers;
                    buyerAndDays[agent] = agent->getDays();
                    std::cout << "Notified agent became a buyer." << std::endl;
                }
            }
            for (int i = 0; i < consumerCount; ++i) {
                if (productUsers >= numberOfPeople) {
                    break;
                }

                int randomIndex1;
                do {
                    randomIndex1 = dis(gen);
                } while (getAgentState(randomIndex1) == Agent::State::ProductUser);

                if (randomIndex1 < 0 || randomIndex1 >= agents.size()) {
                    std::cerr << "Error: randomIndex1 out of bounds: " << randomIndex1 << std::endl;
                    return;
                }

                agents[randomIndex1]->becomeBuyer();
                buyerAndDays[agents[randomIndex1]] = 0;
                ++productUsers;
                std::cout << "Random agent " << randomIndex1 << " became a buyer." << std::endl;

                if (productUsers >= numberOfPeople) {
                    break;
                }

                int randomIndex2;
                do {
                    randomIndex2 = dis(gen);
                } while (getAgentState(randomIndex2) == Agent::State::ProductUser || randomIndex2 == randomIndex1);

                if (randomIndex2 < 0 || randomIndex2 >= agents.size()) {
                    std::cerr << "Error: randomIndex2 out of bounds: " << randomIndex2 << std::endl;
                    return;
                }

                agents[randomIndex1]->notifyOtherAgent(agents[randomIndex2]);
                notifyedAgents.push_back(agents[randomIndex2]);
                std::cout << "Random agent " << randomIndex1 << " notified agent " << randomIndex2 << std::endl;
            }

            for (auto &[agent, day] : buyerAndDays) {
                if(agent->getState() == Agent::State::PotentialBuyer) continue;
                agent->decayProduct();
                day = agent->getDays();
                if (agent->getState() == Agent::State::PotentialBuyer) {
                    --productUsers;
                }
            }
            std::cout << productUsers << std::endl;
        }
        currentDay = dayNumber;
    }
}

Agent::State Environment::getAgentState(int index) const {
    if (index >= 0 && index < agents.size()) {
        return agents[index]->getState();
    }
    return Agent::State();
}

int Environment::getNumberOfPeople() const {
    return numberOfPeople;
}
