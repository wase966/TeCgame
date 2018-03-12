#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"Title.h"
#include"GameSystem.h"

void Title::init() {

}

void Title::update() {
	if (GameSystem::get().input.enter.clicked == true) {
		changeScene(L"Select");
	}
}

void Title::draw() const {
	Println(L"Title (click space)");
}
