#ifndef ANIMATION_H
#define ANIMATION_H

#include "..\Export\Export.h"
#include "glm/glm/glm.hpp"
#include <vector>

using namespace glm;
namespace Engine
{
	struct  UVcoords
	{
		float u, v;
	};
	struct Frame
	{
		UVcoords uv[4];
		int _framesCount;
	};
	class Sprite;
	class EXPORT_API Animation
	{
	private:
		vec4 uvs = vec4(0, 0, 0, 0);
		Sprite* _sprite;

		ivec2 _dimensions;
		std::vector<Frame> _frames;

		int _currentFrame;
		int _maxFrames;
		int _currentAnims;
		int _animsCount;

		float _length;

		float _time;

		//sprite
		float _spriteWidth;
		float _spriteHeight;

		//sprite sheet 
		int _spriteSheetWidth;
		int _spriteSheetHeight;
	
	public:
		Animation();
		~Animation();
		void InitSpriteSheet(Sprite* spriteSheet, const glm::ivec2& tileDimensions);
		void AddFrame(float frameX, float frameY, float frameWidth, float frameHeight, float textureWidth, float textureHeight, float durationInSec);
		void AddFrame(float frameX, float frameY, float frameWidth, float frameHeight, float textureWidth, float textureHeight, float durationInSec, int frameCount);
		void ChangeFrame();
		void UpdateFrame(float deltaTime);
		vec4 GetUVs(int index);
		vec4 GetUVs();
		int GetCurrentFrame();
	};
}
#endif
