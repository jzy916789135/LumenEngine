#include "../Public/Scene.h"

// This following is generated by Ubpa::USRefl::AutoRefl

using namespace Lumen::Game;

RTTR_REGISTRATION
{
	registration::class_<Lumen::Game::Scene>("Scene")
		.constructor<>()
		.property("entities", &Scene::entities)
		(
			metadata("serialize", true)
		)
	;
}