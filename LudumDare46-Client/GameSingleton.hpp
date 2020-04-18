#pragma once

#include <Enlivengine/System/PrimitiveTypes.hpp>
#include <Enlivengine/System/Config.hpp>

#include <Enlivengine/Application/Application.hpp>
#include <Enlivengine/Graphics/SFMLResources.hpp>

#include <entt/entt.hpp>
#include <vector>

#include "ClientSocket.hpp"
#include "GameMap.hpp"
#include "Player.hpp"

class GameSingleton
{
public:
	static en::Application* mApplication;
	static ClientSocket mClient;
	static en::Time mLastPacketTime;
	static en::Vector2f mLocalPosition;
	static GameMap mMap;
	static en::View mView;
	static std::vector<Player> mPlayers;


	static void HandleIncomingPackets();
	static en::I32 GetPlayerIndexFromClientID(en::U32 clientID);

	static void SendPingPacket();
	static void SendPongPacket();
	static void SendJoinPacket();
	static void SendLeavePacket();
	static void SendPositionPacket(const en::Vector2f& position);
};
