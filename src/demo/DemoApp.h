#include "../engine/core/AbstractGame.h"

class DemoApp : public AbstractGame {
    private:
        
    public:
        AbstractGame();
    
        void handleKeyEvents();
        void onLeftMouseButton();
        void onRightMouseButton();
    
        void update();
        void render();
        void renderUI();
};