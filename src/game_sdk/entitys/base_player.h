#pragma once
#include "base_entity.h"

class CBasePlayer : public CBaseEntity
{
public:
	NETVAR("DT_BaseEntity", "m_iHealth", get_health, int32_t);
	NETVAR("DT_CSPlayer", "m_fFlags", get_flags, int);
	NETVAR("DT_BasePlayer", "m_vecViewOffset[0]", get_view_offset, Math::CVector);


	inline Math::CVector get_eye_pos() { return this->get_origin() + this->get_view_offset(); }

	static inline CBasePlayer* get_local_player() { return (CBasePlayer*)(CBaseEntity::get_by_index(CInterfaces::get().engine->get_local_player())); }
};