#pragma once

#include "raylib.h"
#include "core.h"
#include "particle.h"

class Arrow {
public:
    Arrow(const cyclone::Vector3& position, const cyclone::Vector3& direction, float speed, float mass);

    void launch();
    void update(float deltaTime);
    bool checkCollision();

    cyclone::Vector3 getPosition() const;
    Vector3 getPositionRayLib() const;

private:
    cyclone::Vector3 _position;
    cyclone::Vector3 _velocity;
    cyclone::Vector3 _direction;
    cyclone::Particle _particle;
    float _speed = 10;
};
