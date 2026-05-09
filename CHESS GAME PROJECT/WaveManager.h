#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include <vector>
#include <memory>
#include "EnemySubtypes.h"

class WaveManager {
private:
    int currentWave;
    int enemiesToSpawn;
    sf::Time spawnTimer;
    sf::Time spawnInterval;
    std::vector<sf::Vector2f> path;
    int count;

public:
    WaveManager(std::vector<sf::Vector2f> p) 
        : path(p), currentWave(0), enemiesToSpawn(0), spawnInterval(sf::seconds(1.0f)), count(0) {}

    void startNextWave() {
        currentWave++;
        enemiesToSpawn = 5 + currentWave * 2;
        count = 0;
    }

    std::shared_ptr<Enemy> update(sf::Time dt) {
        if (enemiesToSpawn <= 0) return nullptr;

        spawnTimer += dt;
        if (spawnTimer >= spawnInterval) {
            spawnTimer = sf::Time::Zero;
            enemiesToSpawn--;
            count++;
            
            if (currentWave % 3 == 0) return std::make_shared<TankEnemy>(path);
            if (currentWave % 2 == 0) return std::make_shared<FastEnemy>(path);
            return std::make_shared<BasicEnemy>(path);
        }
        return nullptr;
    }

    int getCurrentWave() const { return currentWave; }
    bool isWaveActive() const { return enemiesToSpawn > 0; }
};

#endif
