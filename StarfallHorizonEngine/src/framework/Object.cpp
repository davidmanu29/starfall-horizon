#include "framework/Object.h"
#include "framework/Core.h"

namespace sh
{
	Object::Object()
		:mIsPendingDestroy{ false }
	{

	}

	Object::~Object()
	{
		LOG("Object destroyed");
	}

	void Object::Destroy()
	{
		mIsPendingDestroy = true;
	}
}