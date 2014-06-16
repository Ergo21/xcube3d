#include "DemoApp.h"

int main(int argc, char * args[]) {
    try {
        DemoApp app;
        app.runMainLoop();
    }
    catch (EngineException & e) {
        e.what();
        getchar();
    }
    
    return 0;
}