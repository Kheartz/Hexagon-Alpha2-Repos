/*
** Lua binding: Character
*/

#include "tolua.h"

#ifndef __cplusplus
#include <stdlib.h>
#endif
#ifdef __cplusplus
 extern "C" int tolua_bnd_takeownership (lua_State* L); // from tolua_map.c
#else
 int tolua_bnd_takeownership (lua_State* L); /* from tolua_map.c */
#endif
#include <string.h>

/* Exported function */
TOLUA_API int tolua_Character_open (lua_State* tolua_S);
LUALIB_API int luaopen_Character (lua_State* tolua_S);

#include "Character.h"
#include "Item.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_sf_Sprite (lua_State* tolua_S)
{
 sf::Sprite* self = (sf::Sprite*) tolua_tousertype(tolua_S,1,0);
 tolua_release(tolua_S,self);
 delete self;
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Entity");
 tolua_usertype(tolua_S,"sf::Sprite");
 tolua_usertype(tolua_S,"Character");
}

/* method: new of class  Character */
static int tolua_Character_Character_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isstring(tolua_S,6,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,7,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,8,0,&tolua_err) || 
 !tolua_isstring(tolua_S,9,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float X = ((float)  tolua_tonumber(tolua_S,2,0));
  float Y = ((float)  tolua_tonumber(tolua_S,3,0));
  int W = ((int)  tolua_tonumber(tolua_S,4,0));
  int H = ((int)  tolua_tonumber(tolua_S,5,0));
  char* name = ((char*)  tolua_tostring(tolua_S,6,0));
  int Hp = ((int)  tolua_tonumber(tolua_S,7,0));
  int Mp = ((int)  tolua_tonumber(tolua_S,8,0));
  char* filename = ((char*)  tolua_tostring(tolua_S,9,0));
 {
  Character* tolua_ret = (Character*)  new Character(X,Y,W,H,name,Hp,Mp,filename);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Character");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: getXVel of class  Character */
static int tolua_Character_Character_getXVel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getXVel'",NULL);
#endif
 {
  float tolua_ret = (float)  self->getXVel();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getXVel'.",&tolua_err);
 return 0;
#endif
}

/* method: getYVel of class  Character */
static int tolua_Character_Character_getYVel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getYVel'",NULL);
#endif
 {
  float tolua_ret = (float)  self->getYVel();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getYVel'.",&tolua_err);
 return 0;
#endif
}

/* method: setXVel of class  Character */
static int tolua_Character_Character_setXVel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  float xvel = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setXVel'",NULL);
#endif
 {
  self->setXVel(xvel);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setXVel'.",&tolua_err);
 return 0;
#endif
}

/* method: setYVel of class  Character */
static int tolua_Character_Character_setYVel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  float yvel = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setYVel'",NULL);
#endif
 {
  self->setYVel(yvel);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setYVel'.",&tolua_err);
 return 0;
#endif
}

/* method: incXVel of class  Character */
static int tolua_Character_Character_incXVel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  float xvel = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'incXVel'",NULL);
#endif
 {
  self->incXVel(xvel);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'incXVel'.",&tolua_err);
 return 0;
#endif
}

/* method: incYVel of class  Character */
static int tolua_Character_Character_incYVel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  float yvel = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'incYVel'",NULL);
#endif
 {
  self->incYVel(yvel);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'incYVel'.",&tolua_err);
 return 0;
#endif
}

/* method: setName of class  Character */
static int tolua_Character_Character_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  char* n = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setName'",NULL);
#endif
 {
  self->setName(n);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setName'.",&tolua_err);
 return 0;
#endif
}

/* method: getName of class  Character */
static int tolua_Character_Character_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'",NULL);
#endif
 {
  char* tolua_ret = (char*)  self->getName();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}

/* method: setHP of class  Character */
static int tolua_Character_Character_setHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  int tolua_var_1 = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHP'",NULL);
#endif
 {
  self->setHP(tolua_var_1);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHP'.",&tolua_err);
 return 0;
#endif
}

/* method: setMP of class  Character */
static int tolua_Character_Character_setMP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  int tolua_var_2 = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMP'",NULL);
#endif
 {
  self->setMP(tolua_var_2);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMP'.",&tolua_err);
 return 0;
#endif
}

/* method: getMaxHP of class  Character */
static int tolua_Character_Character_getMaxHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaxHP'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getMaxHP();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaxHP'.",&tolua_err);
 return 0;
#endif
}

/* method: getMaxMP of class  Character */
static int tolua_Character_Character_getMaxMP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaxMP'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getMaxMP();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaxMP'.",&tolua_err);
 return 0;
#endif
}

/* method: changeHP of class  Character */
static int tolua_Character_Character_changeHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  int tolua_var_3 = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeHP'",NULL);
#endif
 {
  self->changeHP(tolua_var_3);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeHP'.",&tolua_err);
 return 0;
#endif
}

/* method: changeMP of class  Character */
static int tolua_Character_Character_changeMP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  int tolua_var_4 = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeMP'",NULL);
#endif
 {
  self->changeMP(tolua_var_4);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeMP'.",&tolua_err);
 return 0;
#endif
}

/* method: getHP of class  Character */
static int tolua_Character_Character_getHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHP'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getHP();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHP'.",&tolua_err);
 return 0;
#endif
}

/* method: getMP of class  Character */
static int tolua_Character_Character_getMP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMP'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getMP();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMP'.",&tolua_err);
 return 0;
#endif
}

/* method: setMaxHP of class  Character */
static int tolua_Character_Character_setMaxHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  int MHP = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaxHP'",NULL);
#endif
 {
  self->setMaxHP(MHP);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaxHP'.",&tolua_err);
 return 0;
#endif
}

/* method: setMaxMP of class  Character */
static int tolua_Character_Character_setMaxMP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  int MMP = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaxMP'",NULL);
#endif
 {
  self->setMaxMP(MMP);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaxMP'.",&tolua_err);
 return 0;
#endif
}

/* get function: direction of class  Character */
static int tolua_get_Character_Character_direction(lua_State* tolua_S)
{
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'direction'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->direction);
 return 1;
}

/* set function: direction of class  Character */
static int tolua_set_Character_Character_direction(lua_State* tolua_S)
{
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'direction'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->direction = ((Character::FACING_DIRECTION) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: getDir of class  Character */
static int tolua_Character_Character_getDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDir'",NULL);
#endif
 {
  Character::FACING_DIRECTION tolua_ret = (Character::FACING_DIRECTION)  self->getDir();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDir'.",&tolua_err);
 return 0;
#endif
}

/* method: setDir of class  Character */
static int tolua_Character_Character_setDir00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  Character::FACING_DIRECTION fd = ((Character::FACING_DIRECTION) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDir'",NULL);
#endif
 {
  self->setDir(fd);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDir'.",&tolua_err);
 return 0;
#endif
}

/* method: move of class  Character */
static int tolua_Character_Character_move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'move'",NULL);
#endif
 {
  self->move(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'move'.",&tolua_err);
 return 0;
#endif
}

/* method: getSprite of class  Character */
static int tolua_Character_Character_getSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Character",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSprite'",NULL);
#endif
 {
  sf::Sprite tolua_ret =  self->getSprite();
 {
#ifdef __cplusplus
 void* tolua_obj = new sf::Sprite(tolua_ret);
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,tolua_collect_sf_Sprite),"sf::Sprite");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(sf::Sprite));
 tolua_pushusertype(tolua_S,tolua_clone(tolua_S,tolua_obj,NULL),"sf::Sprite");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSprite'.",&tolua_err);
 return 0;
#endif
}

/* get function: isMoving of class  Character */
static int tolua_get_Character_Character_isMoving(lua_State* tolua_S)
{
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isMoving'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->isMoving);
 return 1;
}

/* set function: isMoving of class  Character */
static int tolua_set_Character_Character_isMoving(lua_State* tolua_S)
{
  Character* self = (Character*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isMoving'",NULL);
 if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isMoving = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* Open lib function */
LUALIB_API int luaopen_Character (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"Character","Character","Entity",NULL);
 tolua_beginmodule(tolua_S,"Character");
 tolua_function(tolua_S,"new",tolua_Character_Character_new00);
 tolua_function(tolua_S,"getXVel",tolua_Character_Character_getXVel00);
 tolua_function(tolua_S,"getYVel",tolua_Character_Character_getYVel00);
 tolua_function(tolua_S,"setXVel",tolua_Character_Character_setXVel00);
 tolua_function(tolua_S,"setYVel",tolua_Character_Character_setYVel00);
 tolua_function(tolua_S,"incXVel",tolua_Character_Character_incXVel00);
 tolua_function(tolua_S,"incYVel",tolua_Character_Character_incYVel00);
 tolua_function(tolua_S,"setName",tolua_Character_Character_setName00);
 tolua_function(tolua_S,"getName",tolua_Character_Character_getName00);
 tolua_function(tolua_S,"setHP",tolua_Character_Character_setHP00);
 tolua_function(tolua_S,"setMP",tolua_Character_Character_setMP00);
 tolua_function(tolua_S,"getMaxHP",tolua_Character_Character_getMaxHP00);
 tolua_function(tolua_S,"getMaxMP",tolua_Character_Character_getMaxMP00);
 tolua_function(tolua_S,"changeHP",tolua_Character_Character_changeHP00);
 tolua_function(tolua_S,"changeMP",tolua_Character_Character_changeMP00);
 tolua_function(tolua_S,"getHP",tolua_Character_Character_getHP00);
 tolua_function(tolua_S,"getMP",tolua_Character_Character_getMP00);
 tolua_function(tolua_S,"setMaxHP",tolua_Character_Character_setMaxHP00);
 tolua_function(tolua_S,"setMaxMP",tolua_Character_Character_setMaxMP00);
 tolua_constant(tolua_S,"LEFT",Character::LEFT);
 tolua_constant(tolua_S,"RIGHT",Character::RIGHT);
 tolua_constant(tolua_S,"DOWN",Character::DOWN);
 tolua_constant(tolua_S,"UP",Character::UP);
 tolua_variable(tolua_S,"direction",tolua_get_Character_Character_direction,tolua_set_Character_Character_direction);
 tolua_function(tolua_S,"getDir",tolua_Character_Character_getDir00);
 tolua_function(tolua_S,"setDir",tolua_Character_Character_setDir00);
 tolua_function(tolua_S,"move",tolua_Character_Character_move00);
 tolua_function(tolua_S,"getSprite",tolua_Character_Character_getSprite00);
 tolua_variable(tolua_S,"isMoving",tolua_get_Character_Character_isMoving,tolua_set_Character_Character_isMoving);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_Character_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_Character);
 lua_pushstring(tolua_S, "Character");
 lua_call(tolua_S, 1, 0);
 return 1;
}
