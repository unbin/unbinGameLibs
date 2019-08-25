#ifndef FLUID_H_INCLUDED
#define FLUID_H_INCLUDED

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

class Object;
class Stage;
class Subsystem;
class SystemPhysics;
class SystemGraphics;
class SystemAudio;
class SystemCore;

// OBJECT
class Object {
private:

public:
  Object();
  virtual ~Object();
};

// STAGE
class Stage {
private:
  SDL_Surface background;
public:
  Stage();
  virtual ~Stage();
};

// SUBSYSTEM
class Subsystem {
protected:
  virtual void tick() = 0;
public:
  Subsystem();
  virtual ~Subsystem();
};

// PHYSICS SUBSYSTEM
class SystemPhysics : public Subsystem {
  friend SystemCore;
private:
  float gravity;
public:
  SystemPhysics();
  ~SystemPhysics();
  void tick();
};

// GRAPHICS SUBSYSTEM
class SystemGraphics : public Subsystem {
  friend SystemCore;
private:
  SDL_Renderer *renderer = NULL;
public:
  SystemGraphics(SDL_Window *window = NULL);
  ~SystemGraphics();
  void tick();
};

// AUDIO SUBSYSTEM
class SystemAudio : public Subsystem {
  friend SystemCore;
private:

public:
  SystemAudio();
  ~SystemAudio();
  void tick();
};

// SYSTEM CORE
class SystemCore {
private:
  SDL_Window *window = NULL;
  SystemPhysics physics;
  SystemGraphics graphics;
  SystemAudio audio;
  std::vector<Stage> stage;
public:
  SystemCore(uint, uint, const char*);
  ~SystemCore();
};

#endif
