#include "AbstractGame.h"

AbstractGame::AbstractGame() : running(true), gameTime(0.0) {
	std::shared_ptr<GameEngine> xcEngine = GameEngine::getInstance();

	// engine ready, get subsystems
	xcGraphics = xcEngine->getGraphicsEngine();
	xcAudio    = xcEngine->getAudioEngine();
	xcInput    = xcEngine->getEventEngine();
	xcPhysics  = xcEngine->getPhysicsEngine();
	xcCamera   = xcGraphics->getCamera();
}

AbstractGame::~AbstractGame() {
#ifdef __DEBUG
	debug("AbstractGame::~AbstractGame() started");
#endif

	// kill Game class' instance pointers
	// so that engine is isolated from the outside world
	// before shutting down
	xcCamera.reset();
	xcGraphics.reset();
    xcAudio.reset();
	xcInput.reset();
    xcPhysics.reset();

	// kill engine
	GameEngine::quit();

#ifdef __DEBUG
	debug("AbstractGame::~AbstractGame() finished");
	debug("The game finished and cleaned up successfully. Press Enter to exit");
	getchar();
#endif
}

int AbstractGame::runMainLoop() {
#ifdef __DEBUG
	debug("Entered Main Loop");
#endif

	while (running) {
		xcGraphics->setFrameStart();
		xcInput->pollEvents();

		if (xcInput->isPressed(Key::ESC) || xcInput->isPressed(Key::QUIT))
			running = false;

		handleKeyEvents();
		handleMouseEvents();

		update();
		updatePhysics();
		xcCamera->updateView();

		gameTime += 0.016;	// 60 times a sec

		xcGraphics->clearScreen();
		render();
		renderUI();
		xcGraphics->showScreen();

		xcGraphics->adjustFPSDelay(16);	// atm hardcoded to ~60 FPS
	}

#ifdef __DEBUG
	debug("Exited Main Loop");
#endif

	return 0;
}

void AbstractGame::handleMouseEvents() {
	if (xcInput->isPressed(Mouse::BTN_LEFT)) onLeftMouseButton();
	if (xcInput->isPressed(Mouse::BTN_RIGHT)) onRightMouseButton();
}

void AbstractGame::updatePhysics() {
	xcPhysics->update();
}

void AbstractGame::handleKeyEvents() {}
void AbstractGame::onLeftMouseButton() {}
void AbstractGame::onRightMouseButton() {}

void AbstractGame::update() {}
void AbstractGame::render() {}
void AbstractGame::renderUI() {}