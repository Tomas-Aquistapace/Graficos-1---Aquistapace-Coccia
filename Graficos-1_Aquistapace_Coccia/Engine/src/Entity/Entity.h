#ifndef ENTITY_H
#define ENTITY_H

#include "..\Export\Export.h"
#include "..\Renderer\Renderer.h"
#include "glm\glm\vec3.hpp"
#include "glm\glm\mat4x4.hpp"

#include <string>

using namespace std;
using namespace glm;

namespace Engine
{
	enum class ENTITY_COLOR
	{
		WHITE, BLACK, GRAY,
		RED, GREEN, BLUE
	};

	struct Transform
	{
		vec3 position;
		vec3 rotation;
		vec3 scale;
		
		vec3 preb_position;
		vec3 preb_rotation;
		vec3 preb_scale;
	};

	struct GeneralMatrix
	{
		mat4 model;
		mat4 translate;
		mat4 rotateX;
		mat4 rotateY;
		mat4 rotateZ;
		mat4 scale;
	};

	class EXPORT_API Entity 
	{
	private:
		void SetPrebPosition(vec3 position);
		void SetPrebRotation(vec3 rotation);
		void SetPrebRotationX(float x);
		void SetPrebRotationY(float y);
		void SetPrebRotationZ(float z);
		void SetPrebScale(vec3 scale);

	protected:
		Renderer* _renderer;
		GeneralMatrix _generalMatrix;

		bool _isTrigger;
		bool _isStatic;

		bool _colliderState;

		string _tag;

	public:
		Entity(Renderer* renderer);
		~Entity();

		Transform _transform;

		void SetPosition(float x, float y, float z);
		void SetPosition(vec3 position);

		void SetRotation(float x, float y, float z);
		void SetRotation(vec3 rotation);
		void SetRotationX(float x);
		void SetRotationY(float y);
		void SetRotationZ(float z);

		void SetScale(float x, float y, float z);
		void SetScale(vec3 scale);

		void UpdateMatrix();
		void ReturnToPrevTransform();
		void ReturnToPrevPosition();
		void ReturnToPrevRotation();
		void ReturnToPrevScale();

		void SetTag(string tag);
		string GetTag();

		void SetTriggerState(bool state);
		bool GetTriggerState();
		void SetStaticState(bool state);
		bool GetStaticState();
		void SetColliderState(bool state);
		bool GetColliderState();

		virtual void SetColor(ENTITY_COLOR color) = 0;
		virtual void SetColor(float r, float g, float b) = 0;

		virtual void TriggerCollision(Entity* other) = 0;
	};
}

#endif