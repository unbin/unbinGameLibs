#include "unbinSDL.h"
#include <iostream>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//unbinSDL_GuiElement Start:
  unbinSDL_GuiElement::unbinSDL_GuiElement(std::string nameArg, std::string path, SDL_Renderer* &rendererArg, int width, int height) {
    name = nameArg;
    SDL_Surface *surface;
    if (unbinSDL_LoadImg(surface, path)) {
      if (unbinSDL_CreateTextureFromSurface(rendererArg, surface, texture)) {
        destination.w = width;
        destination.h = height;
        SDL_FreeSurface(surface);
      }
    }
  }

  unbinSDL_GuiElement::~unbinSDL_GuiElement(){
    SDL_DestroyTexture(texture);
  }

    void unbinSDL_GuiElement::render(SDL_Renderer* &rendererArg){
    SDL_RenderCopy(rendererArg, texture, NULL, &destination);
  }

  bool unbinSDL_GuiElement::isTouchingElement(unbinSDL_GuiElement elementArg){
    bool xTouch = false;
    bool yTouch = false;
    for (int x = destination.x; x <= destination.x + destination.w; x++) {
      if (x > elementArg.getX() && x < elementArg.getX() + elementArg.getWidth()) xTouch = true;
    }
    for (int y = destination.y; y <= destination.y + destination.h; y++) {
      if (y > elementArg.getY() && y < elementArg.getY() + elementArg.getHeight()) yTouch = true;
    }
    if (xTouch && yTouch) return true;
    else return false;
  }

  bool unbinSDL_GuiElement::isTouchingElement(int xArg, int yArg, int wArg, int hArg){
    bool xTouch = false;
    bool yTouch = false;
    for (int x = destination.x; x <= destination.x + destination.w; x++) {
      if (x > xArg && x < xArg + wArg) xTouch = true;
    }
    for (int y = destination.y; y <= destination.y + destination.h; y++) {
      if (y > yArg && y < yArg + hArg) yTouch = true;
    }
    if (xTouch && yTouch) return true;
    else return false;
  }

  bool unbinSDL_GuiElement::mouseIsTouching(){
    int mouseX, mouseY = 0;
    bool touch = false;
    for (int x = unbinSDL_GuiElement::getX(); x < unbinSDL_GuiElement::getX() + unbinSDL_GuiElement::getWidth() && touch == false; x++) {
      for (int y = unbinSDL_GuiElement::getY(); y < unbinSDL_GuiElement::getY() + unbinSDL_GuiElement::getHeight() && touch == false; y++) {
        SDL_GetMouseState(&mouseX, &mouseY);
        if (mouseX == x && mouseY == y) {
          touch = true;
        }
      }
    }
    return touch;
  }

  bool unbinSDL_GuiElement::isClickedLMB(SDL_Event eventArg){
    bool click = false;
    if (eventArg.type == SDL_MOUSEBUTTONDOWN) {
      if (eventArg.button.button == SDL_BUTTON_LEFT) {
        if (mouseIsTouching()) click = true;
      }
    }
    return click;
  }

  bool unbinSDL_GuiElement::isClickedRMB(SDL_Event eventArg){
    bool click = false;
    if (eventArg.type == SDL_MOUSEBUTTONDOWN) {
      if (eventArg.button.button == SDL_BUTTON_RIGHT) {
        if (mouseIsTouching()) click = true;
      }
    }
    return click;
  }

  bool unbinSDL_GuiElement::isClickedMMB(SDL_Event eventArg){
    bool click = false;
    if (eventArg.type == SDL_MOUSEBUTTONDOWN) {
      if (eventArg.button.button == SDL_BUTTON_MIDDLE) {
        if (mouseIsTouching()) click = true;
      }
    }
    return click;
  }

  //GETTERS

  bool unbinSDL_GuiElement::getSuccess(){
    return success;
  }

  int unbinSDL_GuiElement::getHeight(){
    return destination.h;
  }

  int unbinSDL_GuiElement::getWidth(){
    return destination.w;
  }

  int unbinSDL_GuiElement::getX(){
    return destination.x;
  }

  int unbinSDL_GuiElement::getY(){
    return destination.y;
  }

  SDL_Texture* unbinSDL_GuiElement::getTexture(){
    return texture;
  }

  SDL_Rect* unbinSDL_GuiElement::getDestination(){
    return &destination;
  }

  std::string unbinSDL_GuiElement::getName(){
    return name;
  }

  //SETTERS

  void unbinSDL_GuiElement::setHeight(int newHeight){
    destination.h = newHeight;
  }

  void unbinSDL_GuiElement::setWidth(int newWidth){
    destination.w = newWidth;
  }

  void unbinSDL_GuiElement::setX(int newX){
    destination.x = newX;
  }

  void unbinSDL_GuiElement::setY(int newY){
    destination.y = newY;
  }
//unbinSDL_GuiElement End

//unbinSDL_Scene Start:
unbinSDL_Scene::unbinSDL_Scene(bool activeArg) : active(activeArg) {};

unbinSDL_Scene::~unbinSDL_Scene() {
  elementVect.clear();
};

//MISC
/*
void unbinSDL_Scene::updateActivity(SDL_Window *windowArg) {
  int winW, winH;
  SDL_GetWindowSize(windowArg, &winW, &winH);
  for (int i = 0; i < elementVect.size(); i++) {
    elementVect[i].setX(winW);
    elementVect[i].setY(winH);
  }
}
*/
void unbinSDL_Scene::createElement(unbinSDL_GuiElement &elementArg) {
  elementVect.push_back(&elementArg);
}

bool unbinSDL_Scene::elementIsTouchingElement(std::string nameArg, std::string name2Arg) {
  if (elementVect[getElementId(nameArg)]->isTouchingElement(elementVect[getElementId(name2Arg)]->getX(), elementVect[getElementId(name2Arg)]->getY(), elementVect[getElementId(name2Arg)]->getWidth(), elementVect[getElementId(name2Arg)]->getHeight())) return true;
  else return false;
}

bool unbinSDL_Scene::elementIsTouchingElement(int idArg, std::string name2Arg) {
  if (elementVect[idArg]->isTouchingElement(elementVect[getElementId(name2Arg)]->getX(), elementVect[getElementId(name2Arg)]->getY(), elementVect[getElementId(name2Arg)]->getWidth(), elementVect[getElementId(name2Arg)]->getHeight())) return true;
  else return false;
}

bool unbinSDL_Scene::elementIsTouchingElement(int idArg, int id2Arg) {
  if (elementVect[idArg]->isTouchingElement(elementVect[id2Arg]->getX(), elementVect[id2Arg]->getY(), elementVect[id2Arg]->getWidth(), elementVect[id2Arg]->getHeight())) return true;
  else return false;
}

bool unbinSDL_Scene::mouseIsTouchingElement(std::string nameArg) {
  if (elementVect[getElementId(nameArg)]->mouseIsTouching()) return true;
  else return false;
}

bool unbinSDL_Scene::mouseIsTouchingElement(int idArg) {
  if (elementVect[idArg]->mouseIsTouching()) return true;
  else return false;
}

bool unbinSDL_Scene::elementIsClickedLMB(std::string nameArg, SDL_Event eventArg) {
  if (elementVect[getElementId(nameArg)]->isClickedLMB(eventArg)) {
    return true;
  }
  else return false;
}

bool unbinSDL_Scene::elementIsClickedLMB(int idArg, SDL_Event eventArg) {
  if (elementVect[idArg]->isClickedLMB(eventArg)) {
    return true;
  }
  else return false;
}

bool unbinSDL_Scene::elementIsClickedRMB(std::string nameArg, SDL_Event eventArg) {
  if (elementVect[getElementId(nameArg)]->isClickedRMB(eventArg)) {
    return true;
  }
  else return false;
}

bool unbinSDL_Scene::elementIsClickedRMB(int idArg, SDL_Event eventArg) {
  if (elementVect[idArg]->isClickedRMB(eventArg)) {
    return true;
  }
  else return false;
}

bool unbinSDL_Scene::elementIsClickedMMB(std::string nameArg, SDL_Event eventArg) {
  if (elementVect[getElementId(nameArg)]->isClickedMMB(eventArg)) {
    return true;
  }
  else return false;
}

bool unbinSDL_Scene::elementIsClickedMMB(int idArg, SDL_Event eventArg) {
  if (elementVect[idArg]->isClickedMMB(eventArg)) {
    return true;
  }
  else return false;
}

void unbinSDL_Scene::render(SDL_Renderer* &rendererArg) {
  for (unsigned int i = 0; i < elementVect.size(); i++) {
    elementVect[i]->render(rendererArg);
  }
}

//GETTERS

int unbinSDL_Scene::getElementId(std::string nameArg) {
  int id = -1;
  for (unsigned int i = 0; i < elementVect.size(); i++) {
    if (elementVect[i]->getName() == nameArg) {
      id = i;
      break;
    }
  }
  if (id < 0) std::cout << "unbinSDL Error: Failed to get element '" << nameArg << "' id\n";
  return id;
}

bool unbinSDL_Scene::getActive() {
  return active;
}

int unbinSDL_Scene::getElementVectSize() {
  return elementVect.size();
}

int unbinSDL_Scene::getElementX(std::string nameArg) {
  return elementVect[getElementId(nameArg)]->getX();
}

int unbinSDL_Scene::getElementX(int idArg) {
  return elementVect[idArg]->getX();
}

int unbinSDL_Scene::getElementY(std::string nameArg) {
  return elementVect[getElementId(nameArg)]->getY();
}

int unbinSDL_Scene::getElementY(int idArg) {
  return elementVect[idArg]->getY();
}

int unbinSDL_Scene::getElementWidth(std::string nameArg) {
  return elementVect[getElementId(nameArg)]->getWidth();
}

int unbinSDL_Scene::getElementWidth(int idArg) {
  return elementVect[idArg]->getWidth();
}

int unbinSDL_Scene::getElementHeight(std::string nameArg) {
  return elementVect[getElementId(nameArg)]->getHeight();
}

int unbinSDL_Scene::getElementHeight(int idArg) {
  return elementVect[idArg]->getHeight();
}

//SETTERS

void unbinSDL_Scene::setActive(bool activeArg) {
  active = activeArg;
}

void unbinSDL_Scene::setElementPos(std::string nameArg, int xArg, int yArg) {
  elementVect[getElementId(nameArg)]->setX(xArg);
  elementVect[getElementId(nameArg)]->setY(yArg);
}

void unbinSDL_Scene::setElementPos(int idArg, int xArg, int yArg) {
  elementVect[idArg]->setX(xArg);
  elementVect[idArg]->setY(yArg);
}

void unbinSDL_Scene::setElementX(std::string nameArg, int xArg) {
  elementVect[getElementId(nameArg)]->setX(xArg);
}

void unbinSDL_Scene::setElementX(int idArg, int xArg) {
  elementVect[idArg]->setX(xArg);
}

void unbinSDL_Scene::setElementY(std::string nameArg, int yArg) {
  elementVect[getElementId(nameArg)]->setY(yArg);
}

void unbinSDL_Scene::setElementY(int idArg, int yArg) {
  elementVect[idArg]->setY(yArg);
}
//unbinSDL_Scene End

//Functions:
bool unbinSDL_Init() {
  bool success = true;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    success = false;
    std::cout << "unbinSDL Error: Could not initialize SDL_Video, SDL Error: " << SDL_GetError() << std::endl;
  }
  else {
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
      std::cout << "unbinSDL Warning: Linear texture filtering not enabled\n";
    }
  }
  return success;
}

bool unbinIMG_Init() {
  bool success = true;
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    success = false;
    std::cout << "unbinSDL Error: Could not initialize SDL_image, SDL_image Error: " << IMG_GetError() << std::endl;
  }
  return success;
}

bool unbinSDL_WindowInit(SDL_Window* &windowArg, std::string windowName, int screenW, int screenH) {
  bool success = true;
  windowArg = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenW, screenH, SDL_WINDOW_SHOWN);
  if (windowArg == NULL) {
    success = false;
    std::cout << "unbinSDL Error: Could not create SDL_Window, SDL Error: " << SDL_GetError() << std::endl;
  }
  return success;
}

bool unbinSDL_RendererInit(SDL_Window* &windowArg, SDL_Renderer* &rendererArg){
  bool success = true;
  rendererArg = SDL_CreateRenderer(windowArg, -1, SDL_RENDERER_ACCELERATED);
  if (rendererArg == NULL) {
    success = false;
    std::cout << "unbinSDL Error: Could not create SDL_Renderer, SDL_Error: " << SDL_GetError() << std::endl;
  }
  else SDL_SetRenderDrawColor(rendererArg, 255, 255, 255, 255);
  return success;
}

bool unbinSDL_LoadImg(SDL_Surface* &image, std::string path){
  bool success = true;
  image = IMG_Load(path.c_str());
  if (image == NULL) {
    std::cout << "unbinSDL Error: Could not load image " << path << ", SDL_Error: " << SDL_GetError() << std::endl;
    success = false;
  }
  return success;
}

void unbinSDL_ApplyImageToSurface(SDL_Surface* &image, SDL_Surface* &surfaceArg, int screenW, int screenH){
  SDL_Rect stretchRect;
  stretchRect.x = 0;
  stretchRect.y = 0;
  stretchRect.w = screenW;
  stretchRect.h = screenH;
  SDL_BlitScaled(image, NULL, surfaceArg, &stretchRect);
}

bool unbinSDL_CreateTextureFromSurface(SDL_Renderer* &rendererArg, SDL_Surface* &image, SDL_Texture* &textureArg){
  bool success = true;
  textureArg = SDL_CreateTextureFromSurface(rendererArg, image);
  if (textureArg == NULL) {
    std::cout << "unbinSDL Error: Could not create texture from surface, SDL_Error: " << SDL_GetError() << std::endl;
    success = false;
  }
  return success;
}

void unbinSDL_WindowClose(SDL_Window* &windowArg){
  SDL_DestroyWindow(windowArg);
  windowArg = NULL;
}

void unbinSDL_RendererClose(SDL_Renderer* &rendererArg) {
  SDL_DestroyRenderer(rendererArg);
  rendererArg = NULL;
}

void unbinSDL_SurfaceClose(SDL_Surface* &surfaceArg){
  SDL_FreeSurface(surfaceArg);
  surfaceArg = NULL;
}
