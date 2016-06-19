/////////////////////////////////////////////////////////////////////////////
// This file is part of the Journey MMORPG client                           //
// Copyright � 2015-2016 Daniel Allendorf                                   //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.    //
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include "Clothing.h"

#include "..\..\Audio\Audio.h"

namespace jrc
{
	class Weapon : public Clothing
	{
	public:
		enum Type
		{
			NONE = 0,
			SWORD_1H = 130,
			AXE_1H = 131,
			MACE_1H = 132,
			DAGGER = 133,
			WAND = 137,
			STAFF = 138,
			SWORD_2H = 140,
			AXE_2H = 141,
			MACE_2H = 142,
			SPEAR = 143,
			POLEARM = 144,
			BOW = 145,
			CROSSBOW = 146,
			CLAW = 147,
			KNUCKLE = 148,
			GUN = 149,
			CASH = 170
		};

		static Type typebyvalue(int32_t value)
		{
			if (value < 130 || (value > 133 && value < 137) || value == 139 || (value > 149 && value < 170) || value > 170)
				return NONE;

			return static_cast<Type>(value);
		}

		Weapon(int32_t, const BodyDrawinfo&);
		Weapon();

		bool is_twohanded() const;
		uint8_t getspeed() const;
		uint8_t getattack() const;
		std::string getspeedstring() const;
		uint8_t get_attackdelay() const;
		Type gettype() const;
		Stance::Value getstand() const;
		Stance::Value getwalk() const;
		Sound getusesound(bool degenerate) const;
		const std::string& get_afterimage() const;

	private:
		Type type;
		bool twohanded;
		Stance::Value walk;
		Stance::Value stand;
		uint8_t attackspeed;
		uint8_t attack;
		BoolPair<Sound> usesounds;
		std::string afterimage;
	};
}

