#include "../Public/MeshComponent.h"

using namespace Lumen::Game;

MeshComponent::MeshComponent()
{

}

// This following is generated by Ubpa::USRefl::AutoRefl

RTTR_REGISTRATION
{
	registration::class_<Lumen::Game::MeshComponent>("MeshComponent")
		.constructor<>()
		.property("meshRef", &MeshComponent::meshRef)
		(
			metadata("serialize", true)
		)
	;
}