#include "Plane.h"
#include "MeshComponent.h"
#include "Assets.h"

Plane::Plane() : Actor()
{
	setScale(10.0f);
	MeshComponent* mc = new MeshComponent(this);
	Mesh* mesh = &Assets::getMesh("Mesh_Plane");
	mc->setMesh(*mesh);
}
