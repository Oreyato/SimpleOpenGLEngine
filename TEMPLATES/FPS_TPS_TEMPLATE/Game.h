#pragma once
#include <vector>
#include "Actor.h"
#include "SpriteComponent.h"
#include "Window.h"
#include "Vector2.h"
#include "RendererOGL.h"
#include "AudioSystem.h"
#include "InputSystem.h"


using std::vector;

enum class GameState {
	MainMenu, Gameplay, Pause, Quit
};

class Game
{
public:
	static Game& instance()
	{
		static Game inst;
		return inst;
	}

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;

private:
	Game() : state(GameState::Gameplay), isRunning(true), isUpdatingActors(false), fps(nullptr), follow(nullptr) {}

public:
	bool initialize();
	void load();
	void loop();
	void unload();
	void close();

	GameState getState() const { return state; }
	void setState(GameState stateP);

	void addActor(Actor* actor);
	void removeActor(Actor* actor);
	RendererOGL& getRenderer() { return renderer; }
	AudioSystem& getAudioSystem() { return audioSystem; }
	InputSystem& getInputSystem() { return inputSystem; }

	//v Game specifics ===============================================

	//^ Game specifics ===============================================

private:
	void processInput();
	void update(float dt);
	void render();

	bool isRunning;
	GameState state;
	Window window;
	RendererOGL renderer;
	AudioSystem audioSystem;
	InputSystem inputSystem;

	bool isUpdatingActors;
	vector<Actor*> actors;
	vector<Actor*> pendingActors;

	//v Game specifics ===============================================
	void changeCamera(int mode);

	SoundEvent musicEvent;
	class FPSActor* fps;
	class FollowActor* follow;

	//^ Game specifics ===============================================
};

