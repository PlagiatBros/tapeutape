/***************************************************************************
 *            setup.h
 *
 *  Copyright  2006  Florent Berthaut
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
 
#ifndef _SETUP_H
#define _SETUP_H


#include "kit.h" 
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

class setup
{
	public:
		setup();
		setup(const setup&);
		~setup();
		void setName(std::string);
		std::string getName();
		const std::vector<tap*>& getTap(const unsigned short&, const unsigned short&, const unsigned short&);
		int getNbKits();
		kit *getKit(int);
		void addKit(kit*);
		void setKit(int,kit*);
		void removeKit(int );
		int changeKit(unsigned short);
		void setCC(short,short);
		short getChannel();
		short getCC();
	
	private:
		std::vector<kit*> kits;	
		unsigned short currentKit;
		short channel,cc;
		std::string name;
};



#endif /* _SETUP_H */
