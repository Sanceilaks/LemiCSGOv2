#pragma once


class IVEngineClient
{
public:
	bool isInGame()
	{
		using orig_fn = bool(__thiscall*)(IVEngineClient*);
		return(*(orig_fn**)this)[26](this);
	}
};