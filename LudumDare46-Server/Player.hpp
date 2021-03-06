#pragma once

#include <SFML/Network/IpAddress.hpp>
#include <Enlivengine/Math/Vector2.hpp>
#include <Enlivengine/System/Time.hpp>
#include <Common.hpp>

struct Player
{
	sf::IpAddress remoteAddress;
	en::U16 remotePort;
	en::U32 clientID;
	en::Time lastPacketTime;

	std::string nickname;
	Chicken chicken;

	en::Time cooldown;
	bool needUpdate;
};