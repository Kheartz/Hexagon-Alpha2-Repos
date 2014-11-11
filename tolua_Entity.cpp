/*
** Lua binding: Entity
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
TOLUA_API int tolua_Entity_open (lua_State* tolua_S);
LUALIB_API int luaopen_Entity (lua_State* tolua_S);

#include "Entity.h"

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
 tolua_usertype(tolua_S,"sf::Sprite");
 tolua_usertype(tolua_S,"Entity");
}

/* method: new of class  Entity */
static int tolua_Entity_Entity_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isstring(tolua_S,6,0,&tolua_err) || 
 !tolua_isstring(tolua_S,7,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  int w = ((int)  tolua_tonumber(tolua_S,4,0));
  int h = ((int)  tolua_tonumber(tolua_S,5,0));
  char* name = ((char*)  tolua_tostring(tolua_S,6,0));
  char* filename = ((char*)  tolua_tostring(tolua_S,7,0));
 {
  Entity* tolua_ret = (Entity*)  new Entity(x,y,w,h,name,filename);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Entity");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: getSprite of class  Entity */
static int tolua_Entity_Entity_getSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getX of class  Entity */
static int tolua_Entity_Entity_getX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getX'",NULL);
#endif
 {
  float tolua_ret = (float)  self->getX();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getX'.",&tolua_err);
 return 0;
#endif
}

/* method: getY of class  Entity */
static int tolua_Entity_Entity_getY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getY'",NULL);
#endif
 {
  float tolua_ret = (float)  self->getY();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getY'.",&tolua_err);
 return 0;
#endif
}

/* method: getW of class  Entity */
static int tolua_Entity_Entity_getW00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getW'",NULL);
#endif
 {
  const int tolua_ret = (const int)  self->getW();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getW'.",&tolua_err);
 return 0;
#endif
}

/* method: getH of class  Entity */
static int tolua_Entity_Entity_getH00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getH'",NULL);
#endif
 {
  const int tolua_ret = (const int)  self->getH();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getH'.",&tolua_err);
 return 0;
#endif
}

/* method: getName of class  Entity */
static int tolua_Entity_Entity_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: xFrame of class  Entity */
static int tolua_get_Entity_Entity_xFrame(lua_State* tolua_S)
{
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'xFrame'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->xFrame);
 return 1;
}

/* set function: xFrame of class  Entity */
static int tolua_set_Entity_Entity_xFrame(lua_State* tolua_S)
{
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'xFrame'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->xFrame = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: yFrame of class  Entity */
static int tolua_get_Entity_Entity_yFrame(lua_State* tolua_S)
{
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'yFrame'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->yFrame);
 return 1;
}

/* set function: yFrame of class  Entity */
static int tolua_set_Entity_Entity_yFrame(lua_State* tolua_S)
{
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'yFrame'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->yFrame = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: getCurFrame of class  Entity */
static int tolua_Entity_Entity_getCurFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurFrame'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getCurFrame();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurFrame'.",&tolua_err);
 return 0;
#endif
}

/* method: incFrame of class  Entity */
static int tolua_Entity_Entity_incFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'incFrame'",NULL);
#endif
 {
  self->incFrame();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'incFrame'.",&tolua_err);
 return 0;
#endif
}

/* method: decFrame of class  Entity */
static int tolua_Entity_Entity_decFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'decFrame'",NULL);
#endif
 {
  self->decFrame();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decFrame'.",&tolua_err);
 return 0;
#endif
}

/* method: isSolid of class  Entity */
static int tolua_Entity_Entity_isSolid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isSolid'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isSolid();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isSolid'.",&tolua_err);
 return 0;
#endif
}

/* method: setHardPosition of class  Entity */
static int tolua_Entity_Entity_setHardPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHardPosition'",NULL);
#endif
 {
  self->setHardPosition(x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHardPosition'.",&tolua_err);
 return 0;
#endif
}

/* method: move of class  Entity */
static int tolua_Entity_Entity_move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
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

/* method: changeAlpha of class  Entity */
static int tolua_Entity_Entity_changeAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  int del = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeAlpha'",NULL);
#endif
 {
  self->changeAlpha(del);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeAlpha'.",&tolua_err);
 return 0;
#endif
}

/* method: setIndex of class  Entity */
static int tolua_Entity_Entity_setIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIndex'",NULL);
#endif
 {
  self->setIndex(index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIndex'.",&tolua_err);
 return 0;
#endif
}

/* method: getIndex of class  Entity */
static int tolua_Entity_Entity_getIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIndex'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getIndex();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIndex'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_Entity (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"Entity","Entity","",NULL);
 tolua_beginmodule(tolua_S,"Entity");
 tolua_function(tolua_S,"new",tolua_Entity_Entity_new00);
 tolua_function(tolua_S,"getSprite",tolua_Entity_Entity_getSprite00);
 tolua_function(tolua_S,"getX",tolua_Entity_Entity_getX00);
 tolua_function(tolua_S,"getY",tolua_Entity_Entity_getY00);
 tolua_function(tolua_S,"getW",tolua_Entity_Entity_getW00);
 tolua_function(tolua_S,"getH",tolua_Entity_Entity_getH00);
 tolua_function(tolua_S,"getName",tolua_Entity_Entity_getName00);
 tolua_variable(tolua_S,"xFrame",tolua_get_Entity_Entity_xFrame,tolua_set_Entity_Entity_xFrame);
 tolua_variable(tolua_S,"yFrame",tolua_get_Entity_Entity_yFrame,tolua_set_Entity_Entity_yFrame);
 tolua_function(tolua_S,"getCurFrame",tolua_Entity_Entity_getCurFrame00);
 tolua_function(tolua_S,"incFrame",tolua_Entity_Entity_incFrame00);
 tolua_function(tolua_S,"decFrame",tolua_Entity_Entity_decFrame00);
 tolua_function(tolua_S,"isSolid",tolua_Entity_Entity_isSolid00);
 tolua_function(tolua_S,"setHardPosition",tolua_Entity_Entity_setHardPosition00);
 tolua_function(tolua_S,"move",tolua_Entity_Entity_move00);
 tolua_function(tolua_S,"changeAlpha",tolua_Entity_Entity_changeAlpha00);
 tolua_function(tolua_S,"setIndex",tolua_Entity_Entity_setIndex00);
 tolua_function(tolua_S,"getIndex",tolua_Entity_Entity_getIndex00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_Entity_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_Entity);
 lua_pushstring(tolua_S, "Entity");
 lua_call(tolua_S, 1, 0);
 return 1;
}
