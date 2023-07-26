#ifndef ANIMATION_H
#define ANIMATION_H

#include "..\Export\Export.h"
#include "glm/glm/glm.hpp"
#include <vector>
#include <string>

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
	
		string _id;

		bool _loop;

		void UpdateFrame(float deltaTime);
		vec4 GetUVs(int index);
		vec4 GetUVsFromVector();
		int GetCurrentFrame();
		void ChangeFrame();

	public:
		Animation(string id, const ivec2& tileDimensions);
		~Animation();

		void SetFrame(float durationInSec, int firstIndex, int lastIndex);

		void DrawAnimation(int index);
		void DrawAnimation(float deltaTime);

		ivec2 GetDimensions();
		float* GetVertex();
		string GetId();
	};
}
#endif