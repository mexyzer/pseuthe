/*********************************************************************
Matt Marchant 2015
http://trederia.blogspot.com

pseuthe Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

//script component for plankton behaviour

#ifndef PLANKTON_CONTROLLER_HPP_
#define PLANKTON_CONTROLLER_HPP_

#include <Component.hpp>

class AnimatedDrawable;
class PhysicsComponent;
class ParticleSystem;
class PlanktonController final : public Component
{
public:
    enum class Type
    {
        Good = 0,
        Bad,
        /*Ugly*/Bonus
    };

    explicit PlanktonController(MessageBus&);
    ~PlanktonController() = default;

    Component::Type type() const override;
    void entityUpdate(Entity&, float) override;
    void handleMessage(const Message&) override;
    void onStart(Entity&) override;

    void setType(Type);

    void setEnemyId(sf::Uint64);

private:

    enum Flags
    {
        HealthHit       = 0x1,
        RequestRotation = 0x2,
        Suicide         = 0x4
    };
    sf::Uint32 m_flags;

    Type m_type;
    PhysicsComponent* m_physComponent;
    AnimatedDrawable* m_drawable;
    ParticleSystem* m_trail;

    float m_health;
    sf::Uint64 m_enemyId;

    float m_targetRotation;
    float m_currentRotation;
};


#endif //PLANKTON_CONTROLLER_HPP_