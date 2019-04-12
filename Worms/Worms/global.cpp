#include "global.h"




Hero CreateHero(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int curFrameIndex, int maxFrameSize)
{
	Hero hero;
	hero.hBmp = hBmp;
	hero.step = 0;
	hero.pos.x = posX;
	hero.pos.y = posY;
	hero.vel.x = 0;
	hero.vel.y = 0;
	hero.size.cx = sizeX;
	hero.size.cy = sizeY;
	hero.life = 100;
	hero.collision = 0;
	hero.jump = 1;
	hero.curFrameIndex = curFrameIndex;
	hero.maxFrameSize = maxFrameSize;
	return hero;
}

Plane CreatePlane(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBlockBmp)
{
	Plane plane;
	plane.pos.x = posX;
	plane.pos.y = posY;
	plane.size.cx = sizeX;
	plane.size.cy = sizeY;
	plane.vel.x = 0;
	plane.vel.y = 0;
	plane.hBmp = hBlockBmp;
	return plane;
}

Focus CreateFocus(LONG posX, LONG posY, LONG sizeX, LONG sizeY,
	HBITMAP hBlockBmp)
{
	Focus focus;
	focus.pos.x = posX;
	focus.pos.y = posY;
	focus.size.cx = sizeX;
	focus.size.cy = sizeY;
	focus.status = 1;
	focus.hBmp = hBlockBmp;
	return focus;
}

Biu CreateBiu(LONG posX, LONG posY, LONG sizeX, LONG sizeY,
	HBITMAP hBlockBmp)
{
	Biu biu;
	biu.pos.x = posX;
	biu.pos.y = posY;
	biu.vel.x = 0;
	biu.vel.y = 0;
	biu.size.cx = sizeX;
	biu.size.cy = sizeY;
	biu.status = 1;
	biu.hBmp = hBlockBmp;
	return biu;
}

Force CreateForce(LONG posX, LONG posY, LONG dirX, LONG dirY, LONG sizeX, LONG sizeY,
				  HBITMAP hBlockBmp)
{
	Force force;
	force.pos.x = posX;
	force.pos.y = posY;
	force.size.cx = sizeX;
	force.size.cy = sizeY;
	force.status = 1;
	force.hBmp = hBlockBmp;
	return force;
}


Life CreateLife(LONG posX, LONG posY, LONG sizeX, LONG sizeY,
	HBITMAP hBlockBmp)
{
	Life life;
	life.pos.x = posX;
	life.pos.y = posY;
	life.size.cx = sizeX;
	life.size.cy = sizeY;
	life.hBmp = hBlockBmp;
	return life;
}

Arrow CreateArrow(LONG posX, LONG posY, LONG sizeX, LONG sizeY,
	HBITMAP hBlockBmp)
{
	Arrow arrow;
	arrow.pos.x = posX;
	arrow.pos.y = posY;
	arrow.size.cx = sizeX;
	arrow.size.cy = sizeY;
	arrow.hBmp = hBlockBmp;
	return arrow;
}

GameButton CreateGameButton(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int status)
{
	GameButton gameButton;
	gameButton.pos.x = posX;
	gameButton.pos.y = posY;
	gameButton.size.cx = sizeX;
	gameButton.size.cy = sizeY;
	gameButton.hBmp = hBmp;
	gameButton.status = 0;
	return gameButton;
}

Terrian CreateTerrian(LONG posX, LONG posY, LONG sizeX, LONG sizeY,
	HBITMAP hBlockBmp)
{
	Terrian terrian;
	terrian.pos.x = posX;
	terrian.pos.y = posY;
	terrian.size.cx = sizeX;
	terrian.size.cy = sizeY;
	terrian.hBmp = hBlockBmp;
	return terrian;
}

Wind CreateWind(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBlockBmp)
{
	Wind wind;
	wind.pos.x = posX;
	wind.pos.y = posY;
	wind.size.cx = sizeX;
	wind.size.cy = sizeY;
	wind.hBmp = hBlockBmp;
	return wind;
}

Bomb CreateBomb(LONG posX, LONG posY, LONG sizeX, LONG sizeY,
	HBITMAP hBlockBmp)
{
	Bomb bomb;
	bomb.pos.x = posX;
	bomb.pos.y = posY;
	bomb.size.cx = sizeX;
	bomb.size.cy = sizeY;
	bomb.vel.x = 0;
	bomb.vel.y = 0;
	bomb.collision = 0;
	bomb.hBmp = hBlockBmp;
	return bomb;
}


Boom CreateBoom(LONG posX, LONG posY, LONG sizeX, LONG sizeY,
	HBITMAP hBlockBmp)
{
	Boom boom;
	boom.pos.x = posX;
	boom.pos.y = posY;
	boom.size.cx = sizeX;
	boom.size.cy = sizeY;
	boom.status = 0;
	boom.hBmp = hBlockBmp;
	return boom;
}

Ocean CreateOcean(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBlockBmp)
{
	Ocean ocean;
	ocean.pos.x = posX;
	ocean.pos.y = posY;
	ocean.size.cx = sizeX;
	ocean.size.cy = sizeY;
	ocean.hBmp = hBlockBmp;
	return ocean;
}

Clock CreateClock(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBlockBmp)
{
	Clock clock;
	clock.pos.x = posX;
	clock.pos.y = posY;
	clock.size.cx = sizeX;
	clock.size.cy = sizeY;
	clock.hBmp = hBlockBmp;
	return clock;
}