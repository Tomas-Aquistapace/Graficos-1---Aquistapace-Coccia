#include "Animation.h"

using namespace std;

namespace Engine
{
	Animation::Animation()
	{
		_sprite = NULL;
		_dimensions.x = 0;
		_dimensions.y = 0;
		_currentFrame = 0;

		_firstIndex = 0;
		_lastIndex  = 0;
	}

	Animation::~Animation()
	{

	}

	void Animation::InitSpriteSheet(Sprite* spriteSheet, const  glm::ivec2& tileDimensions)
	{
		_sprite = spriteSheet;
		_dimensions = tileDimensions;
	}	
	
	void Animation::AddFrame(float durationInSec, int firstIndex, int lastIndex)
	{
		_length = durationInSec;
		_firstIndex = firstIndex;
		_lastIndex = lastIndex;
		_currentFrame = firstIndex;

		for (int i = firstIndex; i <= lastIndex; i++)
		{
			Frame frame;
			int xTile = i % _dimensions.x;
			int yTile = i / _dimensions.x;

			frame._uv.x = xTile / (float)_dimensions.x;
			frame._uv.y = yTile / (float)_dimensions.y;
			frame._uv.z = 1.0f / (float)_dimensions.x;
			frame._uv.w = 1.0f / (float)_dimensions.y;

			frame._framesCount = i;
			_frames.push_back(frame);
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
			if (_currentFrame > _lastIndex)
				_currentFrame = _firstIndex;

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