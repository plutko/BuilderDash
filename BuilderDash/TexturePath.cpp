#include "TexturePath.h"

//const char * texturePath::texPathGround = "../Resources/Ground.png";
//const char * texturePath::texPathWall = "../Resources/Wall.png";

const char * texturePath::texPathArray[3] = {"", "../Resources/Ground.png", "../Resources/Wall.png" };

const char * texturePath::getTexturePath(int ID)
{
	return texPathArray[ID];
}