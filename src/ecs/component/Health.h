//
// Created by Aphile on 24.07.2025.
//

#ifndef HEALTH_H
#define HEALTH_H

namespace Component {

    struct Health {
        float health;
        explicit Health(float hp) : health(hp) {}
    };

}  // namespace Component

#endif  // HEALTH_H
