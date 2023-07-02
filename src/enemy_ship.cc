#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include "../headers/enemy_ship.h"
#include "../headers/player.h"
#include <iostream>
#include <math.h>
#include <ostream>
#include "../headers/bullet.h"
#include "../lib/traits.h"


__BEGIN_API

void EnemyShip::init() {

	}



EnemyShip::~EnemyShip(){

}

void EnemyShip::run() {
    isAlive = true;
	const float dt = 1.0f / 120.0f;
	while (true) {
		if (window == nullptr) {
			Thread::yield();
		}
		update(dt);
		Thread::yield();
	}
}

void EnemyShip::die() {
	shootTimer = 0.f;
	isAlive = false;
	deathClock.restart();
}

void EnemyShip::update(float dt) {
	speed = init_speed + (window->getGameVelocity()*1.25f)*10.f;

	if (!isAlive) {
		if (deathClock.getElapsedTime().asSeconds() >= 2.f) {
			if (algo == Algorithm::SNIPER) {
				sf::Vector2f respawnPosition;
				Direction respawnDirection;

				do {
					respawnPosition.x = std::rand() % int(window->left_frame.getSize().x);
					bool isUpperQuadrant = (std::rand() % 2 == 0);
					respawnPosition.y = isUpperQuadrant 
						? std::rand() % int(window->left_frame.getSize().y / 4) 
						: window->left_frame.getSize().y - (std::rand() % int(window->left_frame.getSize().y / 4));

					respawnDirection = isUpperQuadrant ? Direction::DOWN : Direction::UP;
				} while (!isSafeRespawnPosition(respawnPosition, 50.f, 100.f));

				sprite.setPosition(respawnPosition);
				direction = respawnDirection; // Update direction
				updateDirectionVector(); 
				isAlive = true;
			} else if (algo == Algorithm::FOLLOW_PLAYER) {
				sf::Vector2f respawnPosition;
				do {
					respawnPosition.x = std::rand() % int(window->left_frame.getSize().x);
					respawnPosition.y = std::rand() % int(window->left_frame.getSize().y);
				} while (!isSafeRespawnPosition(respawnPosition, 50.f, 250.f));
				sprite.setPosition(respawnPosition);
				isAlive = true;
			}
			deathClock.restart();
		}
	} else {
		this->move(dt);
		shootTimer += dt;
		if (shootTimer > shootDelay) {
			this->shoot();
		}
	}
}

bool EnemyShip::isSafeRespawnPosition(const sf::Vector2f& position, float minDistanceToShip, float minDistanceToPlayer) {
    // Check distance to player
    sf::Vector2f playerPosition = window->getPlayerPosition();
    float distanceToPlayer = std::sqrt(std::pow(position.x - playerPosition.x, 2) 
                            + std::pow(position.y - playerPosition.y, 2));
    if (distanceToPlayer < minDistanceToPlayer) {
        return false;
    }

    // Check distance to other enemy ships
    for (auto& enemy : window->enemies) {
        if (enemy.get() != this) { // Do not check against self
            sf::Vector2f enemyPosition = enemy->sprite.getPosition();
            float distanceToEnemy = std::sqrt(std::pow(position.x - enemyPosition.x, 2) 
                            + std::pow(position.y - enemyPosition.y, 2));
            if (distanceToEnemy < minDistanceToShip) {
                return false;
            }
        }
    }

    return true;
}

sf::FloatRect EnemyShip::getBoundaryRectangle(const sf::Vector2f& newPosition) {
    float offset_x = texture.getSize().x * sprite.getScale().x / 2.f;
    float offset_y = texture.getSize().y * sprite.getScale().y / 2.f;

    sf::Vector2f centeredPosition(newPosition.x - offset_x, newPosition.y - offset_y);

	return sf::FloatRect(centeredPosition, sf::Vector2f(texture.getSize().x * sprite.getScale().x, texture.getSize().y * sprite.getScale().y));
}

void EnemyShip::act(float dt) {
	if (!isAlive) {
		return;
	}
	switch (_behavior) {
		case Behavior::SUICIDAL:
			{
				std::tuple<int,int> pos = Player::get_player_position();
                std::tuple<int,int> self_pos = get_position();
				int x_to_player = std::get<0>(pos) - std::get<0>(self_pos);
                int y_to_player = std::get<1>(pos) - std::get<1>(self_pos);

                // Normalize the direction
                float magnitude = sqrt((x_to_player * x_to_player) + (y_to_player * y_to_player));
                std::tuple<int,int> direction_vector = std::make_tuple(x_to_player/magnitude, y_to_player/ magnitude);
                shoot();

                break;
            }
		case Behavior::LONG_RANGE:
            {
				sf::FloatRect shipBounds = sprite.getGlobalBounds();
				sf::FloatRect frameBounds = window->left_frame.getGlobalBounds();

				directionVector.y = 0.f;
                
                if (randomMoveClock.getElapsedTime().asSeconds() == 0.f) {
                    directionVector.x = (static_cast<float>(rand()) / RAND_MAX) > 0.5f ? 1.f : -1.f;
                }

                if (shipBounds.left <= frameBounds.left) {
                    directionVector.x = 1.f;  // Move to the right
                    randomMoveClock.restart();
                }
                else if (shipBounds.left + shipBounds.width >= frameBounds.left + frameBounds.width) {
                    directionVector.x = -1.f;  // Move to the left
                    randomMoveClock.restart();
                }
                else if (randomMoveClock.getElapsedTime().asSeconds() >= 2.f) {
                    directionVector.x *= (static_cast<float>(rand()) / RAND_MAX) > 0.5f ? 1.f : -1.f;  // Reverse direction
                    randomMoveClock.restart();
                }

				float middleOfLeftFrame = window->left_frame.getSize().y / 2.0f;
				if (sprite.getPosition().y < middleOfLeftFrame) {
					direction = Direction::DOWN;
				} else {
					direction = Direction::UP;
				}
				updateSprite();
				
                sprite.move(directionVector * speed * dt);
                break;
            }
    }
}






__END_API
