#include "Animation.h"
#include <iostream>

using namespace std;

namespace Engine
{
	Animation::Animation()
	{
		_sprite = NULL;
		_dimensions.x = 0;
		_dimensions.y = 0;
		_currentFrame = 0;
		_maxFrames = 0;
		_currentAnims = 0;
		_animsCount = 0;
	}
	Animation::~Animation()
	{

	}
	void Animation::InitSpriteSheet(Sprite* spriteSheet, const  glm::ivec2& tileDimensions)
	{
		_sprite = spriteSheet;
		_dimensions = tileDimensions;
	}
	void Animation::AddFrame(float frameX, float frameY, float frameWidth, float frameHeight, float textureWidth, float textureHeight, float durationInSec)
	{
		_length = durationInSec ;
		Frame frame;

		frame.uv[0].u = (frameX / textureWidth);
		frame.uv[0].v = (frameY / textureHeight);

		frame.uv[1].u = ((frameX + frameWidth) / textureWidth);
		frame.uv[1].v = (frameX / textureWidth);

		frame.uv[2].u = (frameX / textureWidth);
		frame.uv[2].v = ((frameY + frameHeight) / textureHeight);

		frame.uv[3].u = ((frameX + frameWidth) / textureWidth);
		frame.uv[3].v = ((frameY + frameHeight) / textureHeight);
		
		frame._framesCount++;
		_maxFrames++;
		_frames.push_back(frame);
	}
	void Animation::AddFrame(float frameX, float frameY, float frameWidth, float frameHeight, float textureWidth, float textureHeight, float durationInSec , int frameCount)
	{
		_length = durationInSec;
		_maxFrames = 0;
		float frameXIndex = 0;

		for (int i = 0; i < frameCount; i++)
		{
			Frame frame;

			frame.uv[0].u = ((frameX + frameXIndex ) / textureWidth);
			frame.uv[0].v = (frameY / textureHeight);

			frame.uv[1].u = (((frameX + frameXIndex) + frameWidth) / textureWidth);
			frame.uv[1].v = (frameX / textureWidth);

			frame.uv[2].u = ((frameX + frameXIndex ) / textureWidth);
			frame.uv[2].v = ((frameY + frameHeight) / textureHeight);

			frame.uv[3].u = (((frameX + frameXIndex) + frameWidth) / textureWidth);
			frame.uv[3].v = ((frameY + frameHeight) / textureHeight);

			_maxFrames = frameXIndex;
			frame._framesCount = _maxFrames;

			_frames.push_back(frame);
			frameXIndex++;
		}
	}
	void Animation::UpdateFrame(float deltaTime)
	{
		float t = 0;
		t = deltaTime;
		_time += t;

		if (_time >= _length)
		{
			_time -= _length;

			_currentFrame++;
			if (_currentFrame > _maxFrames)
				_currentFrame = 0;

			ChangeFrame();
			_time = t;
		}
	}
	void Animation::ChangeFrame()
	{
		uvs = GetUVs(_currentFrame);
	}
	vec4 Animation::GetUVs(int index)
	{
		int xTile = index % _dimensions.x;
		int yTile = index / _dimensions.x;
		
		uvs.x = xTile / (float)_dimensions.x;
		uvs.y = yTile / (float)_dimensions.y;
		uvs.z = 1.0f / (float)_dimensions.x;
		uvs.w = 1.0f / (float)_dimensions.y;

		return uvs;
	}
	
	int Animation::GetCurrentFrame()
	{
		return _currentFrame;
	}
}