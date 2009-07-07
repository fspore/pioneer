#include "ShipType.h"
#include "Serializer.h"

const char *ShipType::gunmountNames[GUNMOUNT_MAX] = {
	"Front", "Rear" };

const ShipType ShipType::types[] = {
	{
		// besides running a wicked corporatist regime in the
		// sirius system, Sirius corporation make a range of
		// lovely starships
		"Sirius Interdictor", "61",
		{ 4e6,-4e6,1e6,-1e6,-1e6,1e6 },
		4e7,
		{
			{ vector3f(0,-0.5,0), vector3f(0,0,-1) },
			{ vector3f(0,-0.5,0), vector3f(0,0,1) }
		},
		{ 12, 1, 2, 0 },
		12, 20, 6000000,
	}, {
		// john - you should pick names yourself or this happens
		"Ladybird Starfighter",
		"62",
		{ 2e6,-2e6,1e6,-1e6,-1e6,1e6 },
		1e7,
		{
			{ vector3f(0,-0.5,0), vector3f(0,0,-1) },
			{ vector3f(0,0,0), vector3f(0,0,1) }
		},
		{ 60, 1, 1, 0 },
		60, 15, 2200000,
	}, {
		"Taipan",
		"taipan",
		{ 4e6,-4e6,1e6,-1e6,-1e6,1e6 },
		1e7,
		{
			{ vector3f(0,-0.5,0), vector3f(0,0,-1) },
			{ vector3f(0,0,0), vector3f(0,0,1) }
		},
		{ 240, 1, 1, 0 },
		240, 96, 24000000,
	}, {
		"Flowerfairy Heavy Trader",
		"63",
		{ 1e6,-1e6,1e6,-1e6,-1e6,1e6 },
		1e7,
		{
			{ vector3f(0,-0.5,0), vector3f(0,0,-1) },
			{ vector3f(0,0,0), vector3f(0,0,1) }
		},
		{ 500, 1, 2, 0 },
		500, 125, 55000000,
	}
};

void EquipSet::Save()
{
	using namespace Serializer::Write;
	for (int i=0; i<Equip::SLOT_MAX; i++) {
		for (unsigned int j=0; j<equip[i].size(); j++) {
			wr_int(static_cast<int>(equip[i][j]));
		}
	}
}

/*
 * Should have initialised with EquipSet(ShipType::Type) first
 */
void EquipSet::Load()
{
	using namespace Serializer::Read;
	for (int i=0; i<Equip::SLOT_MAX; i++) {
		for (unsigned int j=0; j<equip[i].size(); j++) {
			equip[i][j] = static_cast<Equip::Type>(rd_int());
		}
	}
}

