#include "Scene.h"
#include "../Base.h"

void Kyuubi::Scene::addObject(Object& object) {
	objects.push_back(object);
}

void Kyuubi::Scene::addObject(std::vector<Object> newObjects) {
	objects.insert(objects.end(), newObjects.begin(), newObjects.end());
}

void Kyuubi::Scene::draw(SDL_Renderer* renderer) {
	KYEngine("No implementation of draw(SDL_Renderer*) in scene found!");
}