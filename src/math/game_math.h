#pragma once
#include "vector.h"
#include "v_matrix.h"
#include <interfaces.h>
#include "vector2d.h" 

namespace Math
{
	struct b_coords
	{
	public:
		int x1, y1;
		int x2, y2;
	};

	struct b_box
	{
	public:
		int x, y, w, h;

		void get_b_coords(b_coords & coords)
		{
			coords.x1 = x; coords.y1 = y;
			coords.x2 = x + w; coords.y2 = y + h;
		}
	};


	static bool WorldToScreen(Math::CVector in, Math::CVector& out)
	{
		const Math::VMatrix w2sm = CInterfaces::get().engine->world_to_screen_matrix();
		float w = w2sm[3][0] * in.x + w2sm[3][1] * in.y + w2sm[3][2] * in.z + w2sm[3][3];

		if (w > 0.001f)
		{
			int width, height; CInterfaces::get().engine->get_screen_size(width, height);

			float fl1DBw = 1 / w;
			out.x = (width / 2) + (0.5f * ((w2sm[0][0] * in.x + w2sm[0][1] * in.y + w2sm[0][2] * in.z + w2sm[0][3]) * fl1DBw) * width + 0.5f);
			out.y = (height / 2) - (0.5f * ((w2sm[1][0] * in.x + w2sm[1][1] * in.y + w2sm[1][2] * in.z + w2sm[1][3]) * fl1DBw) * height + 0.5f);
			return true;
		}
		return false;
	}
}