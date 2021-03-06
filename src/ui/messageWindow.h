/***************************************************************************
 *            messageWindow.h
 *
 *  Copyright  2007  Florent Berthaut
 *  florentberthaut@no-log.org
 ****************************************************************************/

/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <iostream>
#include <string>

 
#ifndef _MESSAGEWINDOW_H
#define _MESSAGEWINDOW_H

class messageWindow : public Fl_Window 
{
	public:
			messageWindow(int ,int ,const char*);
			~messageWindow();

			void addMessage(std::string);
			void clear();

	private:
  			Fl_Text_Display *messages;
			Fl_Text_Buffer *buf;
};

#endif
