#pragma once
#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"Enemy.h"

//posを適当に追加した（直しといて）
class Player {
public:
	PhysicsBody body;
	RectF range;
	int hp;
	int dir;
	Vec2 pos;

	const static Vec2 PLAYER_SIZE;



	Player(PhysicsWorld& world);

	void update(const EnemyManager& enemymanager);
	void draw() const;
};