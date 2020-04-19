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
	static GameMap mMap;
	static en::View mView;
	static std::vector<Player> mPlayers;
	static std::vector<Seed> mSeeds;
	static std::vector<Item> mItems;
	static std::vector<Bullet> mBullets;
	static std::vector<Blood> mBloods;
	static std::vector<en::Vector2f> mCancelSeeds;
	static en::Application::onApplicationStoppedType::ConnectionGuard mApplicationStoppedSlot;
	static sf::Sprite mCursor;
	static en::SoundID mPlayerMovementSoundID;

	static void ConnectWindowCloseSlot();
	static void HandleIncomingPackets();
	static en::I32 GetPlayerIndexFromClientID(en::U32 clientID);

	static bool IsInView(const en::Vector2f& position);

	static void SendPingPacket();
	static void SendPongPacket();
	static void SendJoinPacket();
	static void SendLeavePacket();
	static void SendDropSeedPacket(const en::Vector2f& position);

};
