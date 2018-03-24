#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>
#include "Player.h"
#include "Enemy.h"
#include"Camera.h"
#include"Map.h"


class Action : public SceneManager<String>::Scene
{
public:
	Map map;
	Player player;
	EnemyManager enemymanager;
	CameraManager camera;

	Action();
	void init() override;

	void update() override;

	void draw() const override;

};