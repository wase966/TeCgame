#pragma once
#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"EnemyManager.h"
#include"Attack.h"


class Player {
public:
	PhysicsBody body;

	class Range {
	public:
		RectF body;
		RectF foot_main;
		RectF bottomRight, bottomLeft, upperRight, upperLeft; //手足

		Range(PhysicsBody Pbody);
	} range;

	int hp;
	int dir;
	Vec2 pos;
	Vec2 velocity;

	std::vector<std::shared_ptr<Attack>> attacks;
	//std::vector<std::shared_ptr<Animation>> animations;


	Player(PhysicsWorld& world);
	void update(/*const EnemyManager& enemymanager*/const std::vector<std::shared_ptr<Enemy>>& enemys, const std::vector<std::shared_ptr<Block>>& obj, double& time_speed);
	void draw() const;

private:
	double jumpCount;
	double slashCount;
	double shootCount;
	double hitCount;
	double wallJumpCount;

	class Flag {
	public:
		bool onGround;
		bool onRightWall;
		bool onLeftWall;
		bool inRising;
		bool wallJump;
		bool slash;
		bool shoot;
		int slashPhase;
		bool notDoubleJumpYet;
		bool notSlashInAirYet;
		bool hit;

		Flag();

	} flag;

	std::vector<std::weak_ptr<Attack>> hitEnemyAttack;

	const static Vec2 PLAYER_SIZE;
	const static Vec2 FOOT_SIZE_MAIN;
	const static Vec2 SIDE_SIZE;
	const static double MAX_SPEED_GROUND; //地上での横移動の最大速度
	const static double MAX_SPEED_AIR; //空中での横移動の最大速度
	const static double FORCE_AIR; //空中横移動の際の力の強さ
	const static double FORCE_JUMP; //縦方向ジャンプ力
	const static int JUMP_LIMIT; //ジャンプ入力受付時間
	const static int SLASH_LIMIT; //slash状態解除までのフレーム数
	const static int SLASH_COOLTIME; //次の攻撃が入力できるまでのフレーム数
	const static int SHOOT_COOLTIME; //次の射撃が入力できるまでのフレーム数
	//つまり SLASH_LIMIT > SLASH_COOLTIME

	void move(const std::vector<std::shared_ptr<Block>>& obj, const double& time_speed);
	void jump(const std::vector<std::shared_ptr<Block>>& obj, const double& time_speed);
	void checkDir();
	void checkTouch(const std::vector<std::shared_ptr<Block>>& obj);
	void timeControl(double& time_speed);
	void reflectPhysics();
	void slash(const double& time_speed);
	void addSlash();
	void shoot(const double& time_speed);
	void attack(const std::vector<std::shared_ptr<Block>>& obj, const double& time_speed);
	void checkHit(const std::vector<std::shared_ptr<Enemy>>& enemys, const double& time_speed);
};