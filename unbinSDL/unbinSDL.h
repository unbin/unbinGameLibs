#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#ifndef UNBINSDL_H
#define UNBINSDL_H

int const defaultW = 1280;
int const defaultH = 720;

//Classes:
class unbinSDL_GuiElement {
  private:
    std::string name;
    bool success;
    SDL_Texture *texture;
    SDL_Rect destination;
  public:
    unbinSDL_GuiElement(std::string nameArg, std::string, SDL_Renderer*&, int width = 100, int height = 100);
    ~unbinSDL_GuiElement();
    virtual void render(SDL_Renderer*&);
    bool isTouchingElement(unbinSDL_GuiElement);
    bool isTouchingElement(int, int, int, int);
    bool mouseIsTouching();
    bool isClickedLMB(SDL_Event);
    bool isClickedRMB(SDL_Event);
    bool isClickedMMB(SDL_Event);
    //GETTERS
    bool getSuccess();
    int getHeight();
    int getWidth();
    int getX();
    int getY();
    SDL_Texture *getTexture();
    SDL_Rect* getDestination();
    std::string getName();
    //SETTERS
    void setHeight(int);
    void setWidth(int);
    void setX(int);
    void setY(int);
};

class unbinSDL_Scene {
private:
  bool active;
  std::vector<unbinSDL_GuiElement*> elementVect;
public:
  unbinSDL_Scene(bool activeArg = false);
  virtual ~unbinSDL_Scene();
  //MISC
  void createElement(unbinSDL_GuiElement&);
  bool elementIsTouchingElement(std::string, std::string);
  bool elementIsTouchingElement(int, std::string);
  bool elementIsTouchingElement(int, int);
  bool mouseIsTouchingElement(std::string);
  bool mouseIsTouchingElement(int);
  bool elementIsClickedLMB(std::string, SDL_Event);
  bool elementIsClickedLMB(int, SDL_Event);
  bool elementIsClickedRMB(std::string, SDL_Event);
  bool elementIsClickedRMB(int, SDL_Event);
  bool elementIsClickedMMB(std::string, SDL_Event);
  bool elementIsClickedMMB(int, SDL_Event);
  void render(SDL_Renderer*&);
  //GETTERS
  int getElementId(std::string);
  bool getActive();
  int getElementVectSize();
  int getElementX(std::string);
  int getElementX(int);
  int getElementY(std::string);
  int getElementY(int);
  int getElementWidth(std::string);
  int getElementWidth(int);
  int getElementHeight(std::string);
  int getElementHeight(int);
  //SETTERS
  void setActive(bool);
  void setElementPos(std::string, int, int);
  void setElementPos(int, int, int);
  void setElementX(std::string, int);
  void setElementX(int, int);
  void setElementY(std::string, int);
  void setElementY(int, int);
};

//Functions:
bool unbinSDL_Init();
bool unbinIMG_Init();
bool unbinSDL_WindowInit(SDL_Window*&, std::string windowName = "Application", int screenW = defaultW, int screenH = defaultH);
bool unbinSDL_RendererInit(SDL_Window*&, SDL_Renderer*&);
bool unbinSDL_LoadImg(SDL_Surface*&, std::string);
void unbinSDL_ApplyImageToSurface(SDL_Surface*&, SDL_Surface*&, int screenW = defaultW, int screenH = defaultH);
bool unbinSDL_CreateTextureFromSurface(SDL_Renderer*&, SDL_Surface*&, SDL_Texture*&);
void unbinSDL_WindowClose(SDL_Window*&);
void unbinSDL_RendererClose(SDL_Renderer*&);
void unbinSDL_SurfaceClose(SDL_Surface*&);
#endif
