#pragma once
#include <singleton.h>
#include <vector>

class AimSettings
{
public:
	bool enable = true;
	int smooth = 10;
	int fov = 5;
	bool check_team = true;

};

class EspSettings
{
public:
	bool enable = true;
	bool check_team = true;


};

class G : public Singleton<G>
{
public:
	AimSettings* aim = new AimSettings();
	EspSettings* esp = new EspSettings();

	/*max 100*/
	std::vector<unsigned long> dFont;
	

	float d = 2.5;
};

