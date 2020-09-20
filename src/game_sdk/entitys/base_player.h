#pragma once
#include "base_entity.h"
#include "base_items.h"

class CBasePlayer : public CBaseEntity
{
public:
	NETVAR("DT_BaseEntity", "m_iHealth", get_health, int32_t);
	NETVAR("DT_CSPlayer", "m_fFlags", get_flags, int);
	NETVAR("DT_BasePlayer", "m_vecViewOffset[0]", get_view_offset, Math::CVector);
	NETVAR("DT_BasePlayer", "m_lifeState", get_life_state, bool);
	NETVAR("DT_BasePlayer", "m_aimPunchAngle", get_aim_punch_angel, Math::QAngle);
	NETVAR("DT_BasePlayer", "m_viewPunchAngle", get_view_punch_angel, Math::QAngle);
	NETVAR("DT_BaseCombatCharacter", "m_hActiveWeapon", active_weapon_handle, uintptr_t);


	CBaseCombatWeapon* get_active_weapon()
	{
		return (CBaseCombatWeapon*)CInterfaces::get().client_entity_list->get_entity_by_handle(this->active_weapon_handle());
	}

	const std::string& get_name() const
	{
		player_info_t info;
		CInterfaces::get().engine->get_player_info(this->get_index(), &info);
		return info.szName;
	}

	inline bool is_alive() { return this->get_life_state() == 0; }

	inline Math::CVector get_eye_pos() { return this->get_origin() + this->get_view_offset(); }

	static inline CBasePlayer* get_local_player() { return (CBasePlayer*)(CBaseEntity::get_by_index(CInterfaces::get().engine->get_local_player())); }
};