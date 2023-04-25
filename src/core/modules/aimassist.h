#pragma once

#include "../module.h"
#include "../sdk.h"
#include "../pid.h"

class AimAssist : public Module {
    public:
    Player target;

    // Randomly chosen values
    PID yaw_controller = PID(17.1, -5.8, 0.2, -15.0, 15.0);
    PID pitch_controller = PID(17.5, -5.8, 0.2, -15.0, 15.0);

    AimAssist() : Module() {
        active = true;
    }
    
    void tick(float delta_time) override;
    void draw() override;
    void init() override;
};