#pragma once
#include <singleton.h>


class G : public Singleton<G>
{
public:
	float f_smooth = 10.0f;
	int fov = 5;
	bool check_team = true;

	unsigned long font = 0;


	float d = 2.5;
};