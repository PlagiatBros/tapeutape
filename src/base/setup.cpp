/***************************************************************************
 *            setup.cpp
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

#include "setup.h"

using namespace std;

setup::setup():name(""),currentKit(0),channel(-1),cc(-1)
{
}

setup::setup(const setup& s):name(s.name),currentKit(0),channel(s.channel),cc(s.cc)
{
	for(unsigned int k=0;k<s.kits.size();++k)
	{
		kits.push_back(new kit(*(s.kits[k])));
	}
}

setup::~setup()
{
	for(unsigned int i=0;i<kits.size();++i)
	{
		delete kits[i];
	}
	kits.clear();
}

void setup::setName(std::string n)
{
	name = n;
}

std::string setup::getName()
{
	return name;
}

int setup::getNbKits()
{
	return kits.size();
}

kit* setup::getKit(int ind)
{
	if(ind>=0 && ind<kits.size())
		return kits[ind];
	else
		return NULL;
}

void setup::addKit(kit* k)
{
	kits.push_back(k);
}

void setup::setKit(int i,kit* k)
{
	kits[i] = k;
}

void setup::removeKit(int i)
{
	kits.erase(kits.begin()+i);
}

const vector<tap*>& setup::getTap(const unsigned short& channel, const unsigned short& note, const unsigned short& vel)
{
	return kits[currentKit]->getTap(channel,note,vel);
}

int setup::changeKit(unsigned short val)
{
	if(val>=kits.size())
		currentKit=kits.size()-1;
	else
		currentKit=val;
	return currentKit;
}



void setup::setCC(short chan,short c)
{
	channel=(chan>0)?chan-1:0;
	cc=c;
}

short setup::getChannel()
{
	return channel+1;
}

short setup::getCC()
{
	return cc;
}



