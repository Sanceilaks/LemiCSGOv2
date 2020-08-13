#pragma once
#include "singleton.h"
#include <functional>


typedef std::function<bool()> init_callback;


class CHackCore: public Singleton<CHackCore>
{
	std::function<bool()> fnPreInit_ = nullptr;
	std::function<bool()> fnPostInit_ = nullptr;

public:
	bool init();
	bool shutdown();

	void setPreInit(init_callback preInitFuncion);
	void setPostInit(init_callback prePostFuncion);
};

