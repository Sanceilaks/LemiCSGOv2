#pragma once
#include <cstdint>

#include <math/q_angle.h>

struct player_info_t
{
	char name[32];
	int  id;
	char guid[33];
	struct
	{
		uint32_t id;
		char name[32];
	} buddy;
	bool bot;
	bool hltv;
	uint32_t files[4];
	uint8_t  downloaded;
};

class IVEngineClient
{
public:
	bool	is_in_game()
	{
		using orig_fn = bool(__thiscall*)(IVEngineClient*);
		return(*(orig_fn**)this)[26](this);
	}

	void	get_screen_size(int& w, int& h)
	{
		using fn = void(__thiscall*)(IVEngineClient*, int&, int&);
		return (*(fn**)this)[5](this, w, h);
	}

	bool	get_player_info(int index, player_info_t* p_info)
	{
		using fn = bool(__thiscall*)(IVEngineClient*, int, player_info_t*);
		return (*(fn**)this)[8](this, index, p_info);
	}

	void	set_view_angels(Math::QAngle& va)
	{
		using fn = void(__thiscall*)(IVEngineClient*, Math::QAngle&);
		return (*(fn**)this)[19](this, va);
	}

	void	get_view_angels(Math::QAngle& va)
	{
		using fn = void(__thiscall*)(IVEngineClient*, Math::QAngle&);
		return (*(fn**)this)[18](this, va);
	}

	float	get_last_time_stamp()
	{
		using fn = float(__thiscall*)(IVEngineClient*);
		return (*(fn**)this)[14](this);
	}

	int		get_local_player()
	{
		using fn = int(__thiscall*)(IVEngineClient*);
		return (*(fn**)this)[12](this);
	}


};