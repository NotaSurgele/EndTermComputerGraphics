#include "raylib.h"
#include "core.h"
#include "particle.h"

class Arrow {
public:
    Arrow() = default;
    Arrow(const cyclone::Vector3& position, const cyclone::Vector3& direction, float speed, float mass)
            : _position(position), _direction(direction), _speed(speed), _particle()
    {
        _particle.setMass(mass); //mass
        _particle.setDamping(0.2f); //damping
        _particle.setAcceleration(cyclone::Vector3::GRAVITY);  //initial acc.
    }

    void launch() {
        _velocity = _direction * _speed;
        _particle.setVelocity(_velocity);
    }

    void update(float deltaTime) {
        _particle.integrate(deltaTime);
        _position = _particle.getPosition();
    }

    // Add your collision detection logic here
    bool checkCollision() {
        // Implement collision detection
        return false;
    }

    cyclone::Vector3 getPosition() const {
        return _position;
    }

    Vector3 getPositionRayLib() const {
        return {(float)_position.x, (float)_position.y, (float)_position.z};
    }

private:
    cyclone::Vector3 _position;
    cyclone::Vector3 _velocity;
    cyclone::Vector3 _direction;
    cyclone::Particle _particle;

    float _speed = 10;
};