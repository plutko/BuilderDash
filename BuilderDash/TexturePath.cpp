#include "TexturePath.h"

const char * texturePath::texPathArray[6] = 
{"",
"../Resources/Wall.png",		//	1
"../Resources/Ground.png",		//	2
"../Resources/Diamond.png",		//	3
"../Resources/Boulder.png",		//	4
"../Resources/BrickWall.png"	//	5
};

const char * texturePath::getTexturePath(int ID)
{
	return texPathArray[ID];
}