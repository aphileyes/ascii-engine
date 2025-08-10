//
// Created by Aphile on 24.07.2025.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include <algorithm>
#include <any>
#include <cstdint>
#include <memory>
#include <string>
#include <typeindex>
#include <unordered_map>
#include <vector>

namespace Entity {

    using Entity = uint32_t;

    class EntityManager {
    public:
        EntityManager() = default;

        Entity CreateEntity() {
            _components[_entity_counter];
            return _entity_counter++;
        }

        template <typename T>
        void AddComponent(Entity entity, const std::any& component) {
            if (_components.find(entity) == _components.end()) {
                return;
            }
            _components[entity][std::type_index(typeid(T))] = component;
        }

        template <typename T>
        void RemoveComponent(Entity entity) {
            auto& entity_map = _components;
            if (entity_map.find(entity) == _components.end()) {
                return;
            }

            auto& components_map = entity_map[entity];
            if (components_map.find(std::type_index(typeid(T))) == components_map.end()) {
                return;
            }
            components_map.erase(std::type_index(typeid(T)));
        }

        template <typename T>
        std::shared_ptr<T> GetComponent(Entity entity) {
            if (!_components.contains(entity) || !_components[entity].contains(std::type_index(typeid(T)))) {
                return nullptr;
            }
            return std::any_cast<std::shared_ptr<T>>(_components[entity][std::type_index(typeid(T))]);
        }

        template <typename... T>
        std::vector<Entity> GetEntitiesWithComponent() {
            std::vector<Entity> entities_with_specific_components;
            for (const auto& [entity, components] : _components) {
                if ((components.contains(std::type_index(typeid(T))) && ...)) {
                    entities_with_specific_components.push_back(entity);
                }
            }
            return entities_with_specific_components;
        }

        size_t GetEntityCount() { return _entity_counter; }

    private:
        Entity _entity_counter = 0;
        std::unordered_map<Entity, std::unordered_map<std::type_index, std::any>> _components;
    };

}  // namespace Entity

#endif