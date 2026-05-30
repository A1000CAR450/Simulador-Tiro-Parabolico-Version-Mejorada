#ifndef PHYSICS_H
#define PHYSICS_H

#include <cmath>
#include <vector>
#include <utility>

const float PI = 3.14159265359f;

// Structure to hold projectile state
struct ProjectileState {
    float x;        // Horizontal position
    float y;        // Vertical position
    float vx;       // Horizontal velocity
    float vy;       // Vertical velocity
    float time;     // Time elapsed
};

// Structure to hold trajectory data
struct TrajectoryPoint {
    float x;
    float y;
    float t;
};

class Physics {
private:
    float gravity;
    float initialVelocity;
    float launchAngle;
    float initialHeight;
    float airResistance;
    float deltaTime;

public:
    Physics(float g = 9.81f, float dt = 0.01f);
    
    // Setters
    void setGravity(float g);
    void setInitialVelocity(float v);
    void setLaunchAngle(float angle);
    void setInitialHeight(float h);
    void setAirResistance(float ar);
    void setDeltaTime(float dt);
    
    // Getters
    float getGravity() const { return gravity; }
    float getInitialVelocity() const { return initialVelocity; }
    float getLaunchAngle() const { return launchAngle; }
    float getInitialHeight() const { return initialHeight; }
    float getAirResistance() const { return airResistance; }
    
    // Core physics calculations
    float calculateMaxHeight() const;
    float calculateRange() const;
    float calculateFlightTime() const;
    
    // Position at time t
    float getPositionX(float t) const;
    float getPositionY(float t) const;
    
    // Calculate complete trajectory
    std::vector<TrajectoryPoint> calculateTrajectory() const;
    
    // Update projectile state
    void updateProjectile(ProjectileState& state) const;
    
    // Convert angle from degrees to radians
    static float degToRad(float degrees);
    
    // Convert angle from radians to degrees
    static float radToDeg(float radians);
};

#endif // PHYSICS_H
