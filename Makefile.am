bin_PROGRAMS = XCDemoApp

XCApp_SOURCES = src/engine/audio/AudioEngine.cpp
XCApp_SOURCES += src/engine/core/GameEngine.cpp src/engine/core/Debug.cpp src/engine/core/ResourceManager.cpp src/engine/core/Timer.cpp
XCApp_SOURCES += src/engine/graphics/GraphicsEngine.cpp src/engine/graphics/Primitives3d.cpp src/engine/graphics/MD3Object.cpp src/engine/graphics/ShaderManager.cpp src/engine/graphics/Movable.cpp
XCApp_SOURCES += src/engine/input/EventEngine.cpp
XCApp_SOURCES += src/engine/physics/PhysicsEngine.cpp

XCApp_SOURCES += src/engine/core/AbstractGame.cpp

XCApp_SOURCES += src/demo/Main.cpp src/demo/DemoApp.cpp

AM_CPPFLAGS = -std=c++11
AM_CPPFLAGS += $(gl_CFLAGS) $(glew_CFLAGS) $(sdl2_CFLAGS)
LIBS += $(gl_LIBS) $(glew_LIBS) $(sdl2_LIBS) $(SDL2_image_LIBS) $(SDL2_ttf_LIBS) $(SDL2_net_LIBS) $(SDL2_mixer_LIBS)
