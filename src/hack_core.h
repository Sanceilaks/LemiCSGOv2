#pragma once
#include "singleton.h"
#include <functional>


typedef std::function<bool()> init_callback;


class CHackCore
{
public:
	static bool init();
	static bool shutdown();

	static void set_pre_init(init_callback preInitFuncion);
	static void set_post_init(init_callback prePostFuncion);
};

