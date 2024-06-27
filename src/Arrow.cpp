//
// Created by alexi on 27/06/2024.
//

#include "Arrow.hpp"

Arrow::Arrow(const cyclone::Vector3& position, const cyclone::Vector3& direction, float speed, float mass)
        : _position(position), _direction(direction), _speed(speed), _particle()
{
    _particle.setMass(mass); //mass
    _particle.setDamping(0.2f); //damping
    _particle.setAcceleration(cyclone::Vector3::GRAVITY);  //initial acc.
}

void Arrow::launch() {
    _velocity = _direction * _speed;
    _particle.setVelocity(_velocity);
}

void Arrow::update(float deltaTime) {
    _particle.integrate(deltaTime);
    _position = _particle.getPosition();
}

bool Arrow::checkCollision() {
    // Implement collision detection
    return false;
}

cyclone::Vector3 Arrow::getPosition() const {
    return _position;
}

Vector3 Arrow::getPositionRayLib() const {
    return {(float)_position.x, (float)_position.y, (float)_position.z};
}