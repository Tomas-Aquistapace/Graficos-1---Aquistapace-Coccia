#ifndef ANIMATION_H
#define ANIMATION_H

#include "..\Export\Export.h"
#include "..\Renderer\Renderer.h"
#include "glm/glm/glm.hpp"
#include <vector>

using namespace glm;
using namespace std;

namespace Engine
{
	struct EXPORT_API Frame
	{
		vec4 _uv;
	};

	struct EXPORT_API UVs
	{
		float u;
		float v;
	};

	class Sprite;
	
	class EXPORT_API Animation
	{
	private:
		float _vertex[36]
		{
			// positions          // colors					// texture coords
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 0.0f,   0.0f, 1.0f    // top left
		};

		Renderer* _renderer;

		vec4 uvs = vec4(0, 0, 0, 0);
		UVs _uv[4];

		ivec2 _dimensions;
		vector<Frame> _frames;

		int _currentFrame;
		int _maxFrames;

		int _firstIndex;
		int _lastIndex;

		float _length;
		float _time;
	
		void ChangeFrame();

	public:
		Animation(const ivec2& tileDimensions);
		~Animation();

		void AddFrame(float durationInSec, int firstIndex, int lastIndex);
		void UpdateFrame(float deltaTime);

		void DrawAnimation(glm::vec4 uvRect);

		vec4 GetUVs(int index);
		vec4 GetUVsFromVector(int index);
		int GetCurrentFrame();
		ivec2 GetDimensions();
		float* GetVertex();
	};
}
#endif