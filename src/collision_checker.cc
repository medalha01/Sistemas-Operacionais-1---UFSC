#include "../headers/collision_checker.h"

__BEGIN_API

CollisionChecker::CollisionChecker() {

}

CollisionChecker::~CollisionChecker() {

}

void CollisionChecker::run() {
    std::list<EnemyShip *> _enemy_ships = EnemyController::getEnemies();
}

bool CollisionChecker::check_collision(GameObject * obj1, GameObject * obj2) {
    sf::Sprite * sprite1 = obj1->get_sprite();
    sf::Sprite * sprite2 = obj2->get_sprite();

    sf::FloatRect sprite1_bounds = sprite1->getGlobalBounds();
    sf::FloatRect sprite2_bounds = sprite2->getGlobalBounds();
    return sprite1_bounds.intersects(sprite2_bounds);
}

__END_API