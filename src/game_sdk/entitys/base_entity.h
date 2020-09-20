#pragma once
#include "i_client_entity.h"
#include <tools/netvars.h>
#include <cstdint>
#include "interfaces.h"


enum ECSPlayerBones {
	pelvis = 0,
	spine_0,
	spine_1,
	spine_2,
	spine_3,
	neck_0,
	head_0,
	clavicle_L,
	arm_upper_L,
	arm_lower_L,
	hand_L
};

class CBaseEntity : public IClientEntity
{
public:
	NETVAR("DT_DynamicProp", "m_bShouldGlow", is_should_glow, bool);
	NETVAR("DT_BaseEntity", "m_vecOrigin", get_origin, Math::CVector);
	NETVAR("DT_BaseEntity", "m_vecAngles", get_angels, Math::CVector);
	NETVAR("DT_BaseEntity", "m_nModelIndex", get_model_index, int32_t);
	NETVAR("DT_BaseEntity", "m_iTeamNum", get_team_num, int32_t);

	bool is_player()
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

	const Math::CVector& get_entity_bone(ECSPlayerBones Bone)
	{
		Math::matrix3x4_t boneMatrix[128];

		if (!this->setup_bones(boneMatrix, 128, 0x00000100, CInterfaces::get().engine->get_last_time_stamp()))
			return Math::CVector();

		Math::matrix3x4_t hitbox = boneMatrix[Bone];

		return Math::CVector(hitbox[0][3], hitbox[1][3], hitbox[2][3]);
	}
};