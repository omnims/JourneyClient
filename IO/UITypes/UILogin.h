/////////////////////////////////////////////////////////////////////////////
// This file is part of the Journey MMORPG client                           //
// Copyright � 2015 Daniel Allendorf                                        //
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
#include "IO\Element.h"
#include "IO\UI.h"
#include "IO\Components\Textfield.h"
#include "Net\Session.h"
#include "Util\Configuration.h"

namespace IO
{
	using::Net::Session;
	using::Util::Configuration;
	using::Graphics::Texture;

	class UILogin : public UIElement
	{
	public:
		enum Buttons
		{
			BT_LOGIN,
			BT_REGISTER,
			BT_HOMEPAGE,
			BT_PASSLOST,
			BT_IDLOST,
			BT_SAVEID,
			BT_QUIT
		};

		UILogin(Session&, UI&, Configuration&);
		void draw(float) const;
		void update();
		void buttonpressed(uint16_t);
		Mousestate sendmouse(bool, vector2d<int32_t>);

	private:
		Session& session;
		UI& ui;
		Configuration& config;

		Textfield account;
		Textfield password;
		Texture accountbg;
		Texture passwordbg;
		map<bool, Texture> checkbox;
		bool saveid;
	};

	class ElementLogin : public Element
	{
	public:
		ElementLogin(Session& ses, UI& u, Configuration& cfg) : session(ses), ui(u), config(cfg){}

		UIType type() const
		{
			return UI_LOGIN;
		}

		UIElement* instantiate() const
		{
			return new UILogin(session, ui, config);
		}

	private:
		Session& session;
		UI& ui;
		Configuration& config;
	};
}