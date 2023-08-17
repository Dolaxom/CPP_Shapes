#include "controller.h"

#include "../model/components/figures/square.h"
#include "../model/components/figures/triangle.h"
#include "../model/components/figures/circle.h"

namespace ts {
    void Controller::Create(const SpawnInfo& spawnInfo) {
        std::shared_ptr<Figure> obj;

        if (spawnInfo.type == "Triangle") {
            obj = std::make_shared<Triangle>();
        } else if (spawnInfo.type == "Square") {
            obj = std::make_shared<Square>();
        } else if (spawnInfo.type == "Circle") {
            obj = std::make_shared<Circle>();
        }

        obj->SetColor(spawnInfo.color[0], spawnInfo.color[1], spawnInfo.color[2]);
        obj->SetLocation(spawnInfo.location[0], spawnInfo.location[1]);

        model.AddObject(obj);
    }

    std::vector<std::shared_ptr<Figure>> Controller::GetDrawData() const noexcept {
        return model.GetObjects();
    }

} // ts
