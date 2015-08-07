#include "physicssystem.h"

using namespace ecs;

void PhysicsSystem::update(const double gameTime)
{
	dynamicsWorld->stepSimulation(1/80.0f, 10);

	for (auto node : nodes)
	{
		btTransform trans;
		node->BTcomp->body->getMotionState()->getWorldTransform(trans);
		float matrix[16];

		trans.getOpenGLMatrix(matrix);
		glm::mat4 tra = glm::make_mat4x4(matrix);

		node->GLmat->matrix = tra;
		btVector3 scale = node->BTcomp->scale;
		node->GLmat->scale(scale.x(), scale.y(), scale.z());
	}
}

void PhysicsSystem::registerNode(PhysicsNode& node)
{
	dynamicsWorld->addRigidBody(node.BTcomp->body);
}

void PhysicsSystem::deregisterNode(PhysicsNode& node)
{
	dynamicsWorld->removeRigidBody(node.BTcomp->body);
}

PhysicsSystem::PhysicsSystem()
{
	broadphase = new btDbvtBroadphase();

	collisionConfiguration = new btDefaultCollisionConfiguration();

	dispatcher = new btCollisionDispatcher(collisionConfiguration);

	solver = new btSequentialImpulseConstraintSolver();

	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);

	dynamicsWorld->setGravity(btVector3{0, -10, 0});
}

PhysicsSystem::~PhysicsSystem()
{
	delete dynamicsWorld;
	delete solver;
	delete dispatcher;
	delete collisionConfiguration;
	delete broadphase;
}