#ifndef __ABSTRACT_GAME_H__
#define __ABSTRACT_GAME_H__

#include "GameEngine.h"

class AbstractGame {
	private:
		void handleMouseEvents();
		void updatePhysics();

	protected:
		AbstractGame();
		virtual ~AbstractGame();

		/* ENGINE OBJECTS */
		std::shared_ptr<GraphicsEngine> xcGraphics;
		std::shared_ptr<AudioEngine>    xcAudio;
		std::shared_ptr<EventEngine>    xcInput;
		std::shared_ptr<PhysicsEngine>  xcPhysics;
		std::shared_ptr<Camera>         xcCamera;

		/* Main loop control */
		bool running;
		double gameTime;

		virtual void handleKeyEvents();

		virtual void onLeftMouseButton();
		virtual void onRightMouseButton();

		virtual void update();
		virtual void render();

		virtual void renderUI();
	public:
		int runMainLoop();
};

#endif