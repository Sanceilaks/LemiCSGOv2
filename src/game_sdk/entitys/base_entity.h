#pragma once
#include "i_client_entity.h"
#include <tools/netvars.h>
#include <cstdint>
#include "interfaces.h"

class CBaseEntity : public IClientEntity
{
public:
	NETVAR("DT_DynamicProp", "m_bShouldGlow", is_should_glow, bool);
	NETVAR("DT_BaseEntity", "m_vecOrigin", get_origin, Math::CVector);
	NETVAR("DT_BaseEntity", "m_vecAngles", get_angels, Math::CVector);
	NETVAR("DT_BaseEntity", "m_nModelIndex", get_model_index, int32_t);
	NETVAR("DT_BaseEntity", "m_iTeamNum", get_team_num, int32_t);

	bool isPlayer()
	{
		using original_fn = bool(__thiscall*)(void*);
		return (*(original_fn**)this)[157](this);
	}

	bool isWeapon() 
	{
		using original_fn = bool(__thiscall*)(CBaseEntity*);
		return (*(original_fn**)this)[165](this);
	}

	static inline CBaseEntity* get_by_index(int index)
	{
		return (CBaseEntity*)(CInterfaces::get().client_entity_list->get_entity_by_index(index));
	}
};