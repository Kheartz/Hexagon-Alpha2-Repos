/*
** Lua binding: Quest
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
TOLUA_API int tolua_Quest_open (lua_State* tolua_S);
LUALIB_API int luaopen_Quest (lua_State* tolua_S);

#include "Quest.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"NPC");
 tolua_usertype(tolua_S,"Quest_GoTo_NPC");
 tolua_usertype(tolua_S,"Quest");
 tolua_usertype(tolua_S,"Quest_Deliver");
 tolua_usertype(tolua_S,"Item");
 tolua_usertype(tolua_S,"Quest_GoTo_Area");
}

/* method: new of class  Quest */
static int tolua_Quest_Quest_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Quest* tolua_ret = (Quest*)  new Quest();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quest");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: Satisfy of class  Quest */
static int tolua_Quest_Quest_Satisfy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Satisfy'",NULL);
#endif
 {
  self->Satisfy();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Satisfy'.",&tolua_err);
 return 0;
#endif
}

/* method: completeQuest of class  Quest */
static int tolua_Quest_Quest_completeQuest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'completeQuest'",NULL);
#endif
 {
  self->completeQuest();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'completeQuest'.",&tolua_err);
 return 0;
#endif
}

/* method: setStartNPC of class  Quest */
static int tolua_Quest_Quest_setStartNPC00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"NPC",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  NPC* n = ((NPC*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartNPC'",NULL);
#endif
 {
  self->setStartNPC(n);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartNPC'.",&tolua_err);
 return 0;
#endif
}

/* method: getStartNPC of class  Quest */
static int tolua_Quest_Quest_getStartNPC00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartNPC'",NULL);
#endif
 {
  NPC* tolua_ret = (NPC*)  self->getStartNPC();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"NPC");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartNPC'.",&tolua_err);
 return 0;
#endif
}

/* method: setEndNPC of class  Quest */
static int tolua_Quest_Quest_setEndNPC00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"NPC",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  NPC* n = ((NPC*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEndNPC'",NULL);
#endif
 {
  self->setEndNPC(n);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEndNPC'.",&tolua_err);
 return 0;
#endif
}

/* method: getEndNPC of class  Quest */
static int tolua_Quest_Quest_getEndNPC00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getEndNPC'",NULL);
#endif
 {
  NPC* tolua_ret = (NPC*)  self->getEndNPC();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"NPC");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getEndNPC'.",&tolua_err);
 return 0;
#endif
}

/* method: setName of class  Quest */
static int tolua_Quest_Quest_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  char* Name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setName'",NULL);
#endif
 {
  self->setName(Name);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setName'.",&tolua_err);
 return 0;
#endif
}

/* method: getName of class  Quest */
static int tolua_Quest_Quest_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setExamine of class  Quest */
static int tolua_Quest_Quest_setExamine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  char* Examine = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setExamine'",NULL);
#endif
 {
  self->setExamine(Examine);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setExamine'.",&tolua_err);
 return 0;
#endif
}

/* method: getExamine of class  Quest */
static int tolua_Quest_Quest_getExamine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getExamine'",NULL);
#endif
 {
  char* tolua_ret = (char*)  self->getExamine();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getExamine'.",&tolua_err);
 return 0;
#endif
}

/* method: isActive of class  Quest */
static int tolua_Quest_Quest_isActive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isActive'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isActive();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isActive'.",&tolua_err);
 return 0;
#endif
}

/* method: isStarted of class  Quest */
static int tolua_Quest_Quest_isStarted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isStarted'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isStarted();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isStarted'.",&tolua_err);
 return 0;
#endif
}

/* method: isSatisfied of class  Quest */
static int tolua_Quest_Quest_isSatisfied00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isSatisfied'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isSatisfied();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isSatisfied'.",&tolua_err);
 return 0;
#endif
}

/* method: isCompleted of class  Quest */
static int tolua_Quest_Quest_isCompleted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isCompleted'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isCompleted();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isCompleted'.",&tolua_err);
 return 0;
#endif
}

/* method: setGiveXP of class  Quest */
static int tolua_Quest_Quest_setGiveXP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  int xp = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setGiveXP'",NULL);
#endif
 {
  self->setGiveXP(xp);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setGiveXP'.",&tolua_err);
 return 0;
#endif
}

/* method: getGiveXP of class  Quest */
static int tolua_Quest_Quest_getGiveXP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGiveXP'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getGiveXP();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGiveXP'.",&tolua_err);
 return 0;
#endif
}

/* method: activate of class  Quest */
static int tolua_Quest_Quest_activate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'activate'",NULL);
#endif
 {
  self->activate();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'activate'.",&tolua_err);
 return 0;
#endif
}

/* method: start of class  Quest */
static int tolua_Quest_Quest_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'",NULL);
#endif
 {
  self->start();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}

/* method: complete of class  Quest */
static int tolua_Quest_Quest_complete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'complete'",NULL);
#endif
 {
  self->complete();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'complete'.",&tolua_err);
 return 0;
#endif
}

/* method: update of class  Quest */
static int tolua_Quest_Quest_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'",NULL);
#endif
 {
  self->update();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}

/* method: setActiveConvo of class  Quest */
static int tolua_Quest_Quest_setActiveConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  char* s = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setActiveConvo'",NULL);
#endif
 {
  self->setActiveConvo(s);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setActiveConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: setActivecyConvo of class  Quest */
static int tolua_Quest_Quest_setActivecyConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  char* s = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setActivecyConvo'",NULL);
#endif
 {
  self->setActivecyConvo(s);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setActivecyConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: setActivecnConvo of class  Quest */
static int tolua_Quest_Quest_setActivecnConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  char* s = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setActivecnConvo'",NULL);
#endif
 {
  self->setActivecnConvo(s);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setActivecnConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: setStartedConvo of class  Quest */
static int tolua_Quest_Quest_setStartedConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  char* s = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartedConvo'",NULL);
#endif
 {
  self->setStartedConvo(s);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartedConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: setStartedcnConvo of class  Quest */
static int tolua_Quest_Quest_setStartedcnConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  char* s = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartedcnConvo'",NULL);
#endif
 {
  self->setStartedcnConvo(s);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartedcnConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: setStartedcyfConvo of class  Quest */
static int tolua_Quest_Quest_setStartedcyfConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  char* s = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartedcyfConvo'",NULL);
#endif
 {
  self->setStartedcyfConvo(s);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartedcyfConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: setStartedcytConvo of class  Quest */
static int tolua_Quest_Quest_setStartedcytConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  char* s = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStartedcytConvo'",NULL);
#endif
 {
  self->setStartedcytConvo(s);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStartedcytConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: setDoneConvo of class  Quest */
static int tolua_Quest_Quest_setDoneConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  char* s = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDoneConvo'",NULL);
#endif
 {
  self->setDoneConvo(s);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDoneConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: printConversations of class  Quest */
static int tolua_Quest_Quest_printConversations00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Quest* self = (const Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'printConversations'",NULL);
#endif
 {
  self->printConversations();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'printConversations'.",&tolua_err);
 return 0;
#endif
}

/* method: getType of class  Quest */
static int tolua_Quest_Quest_getType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getType'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getType();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getType'.",&tolua_err);
 return 0;
#endif
}

/* method: getActiveConvo of class  Quest */
static int tolua_Quest_Quest_getActiveConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActiveConvo'",NULL);
#endif
 {
  char* tolua_ret = (char*)  self->getActiveConvo();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActiveConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: getActivecyConvo of class  Quest */
static int tolua_Quest_Quest_getActivecyConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActivecyConvo'",NULL);
#endif
 {
  char* tolua_ret = (char*)  self->getActivecyConvo();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActivecyConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: getActivecnConvo of class  Quest */
static int tolua_Quest_Quest_getActivecnConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActivecnConvo'",NULL);
#endif
 {
  char* tolua_ret = (char*)  self->getActivecnConvo();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActivecnConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: getStartedConvo of class  Quest */
static int tolua_Quest_Quest_getStartedConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartedConvo'",NULL);
#endif
 {
  char* tolua_ret = (char*)  self->getStartedConvo();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartedConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: getStartedcnConvo of class  Quest */
static int tolua_Quest_Quest_getStartedcnConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartedcnConvo'",NULL);
#endif
 {
  char* tolua_ret = (char*)  self->getStartedcnConvo();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartedcnConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: getStartedcyfConvo of class  Quest */
static int tolua_Quest_Quest_getStartedcyfConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartedcyfConvo'",NULL);
#endif
 {
  char* tolua_ret = (char*)  self->getStartedcyfConvo();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartedcyfConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: getStartedcytConvo of class  Quest */
static int tolua_Quest_Quest_getStartedcytConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getStartedcytConvo'",NULL);
#endif
 {
  char* tolua_ret = (char*)  self->getStartedcytConvo();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getStartedcytConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: getDoneConvo of class  Quest */
static int tolua_Quest_Quest_getDoneConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDoneConvo'",NULL);
#endif
 {
  char* tolua_ret = (char*)  self->getDoneConvo();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDoneConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: addPreReqQ of class  Quest */
static int tolua_Quest_Quest_addPreReqQ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  Quest* q = ((Quest*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addPreReqQ'",NULL);
#endif
 {
  self->addPreReqQ(q);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addPreReqQ'.",&tolua_err);
 return 0;
#endif
}

/* method: preReqsCompleted of class  Quest */
static int tolua_Quest_Quest_preReqsCompleted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'preReqsCompleted'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->preReqsCompleted();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'preReqsCompleted'.",&tolua_err);
 return 0;
#endif
}

/* method: pushItemsGive of class  Quest */
static int tolua_Quest_Quest_pushItemsGive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest* self = (Quest*)  tolua_tousertype(tolua_S,1,0);
  char* i = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushItemsGive'",NULL);
#endif
 {
  self->pushItemsGive(i);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushItemsGive'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Quest_GoTo_NPC */
static int tolua_Quest_Quest_GoTo_NPC_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quest_GoTo_NPC",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Quest_GoTo_NPC* tolua_ret = (Quest_GoTo_NPC*)  new Quest_GoTo_NPC();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quest_GoTo_NPC");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: getTargetNPC of class  Quest_GoTo_NPC */
static int tolua_Quest_Quest_GoTo_NPC_getTargetNPC00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest_GoTo_NPC",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest_GoTo_NPC* self = (Quest_GoTo_NPC*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTargetNPC'",NULL);
#endif
 {
  NPC* tolua_ret = (NPC*)  self->getTargetNPC();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"NPC");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTargetNPC'.",&tolua_err);
 return 0;
#endif
}

/* method: setTargetNPC of class  Quest_GoTo_NPC */
static int tolua_Quest_Quest_GoTo_NPC_setTargetNPC00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest_GoTo_NPC",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"NPC",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest_GoTo_NPC* self = (Quest_GoTo_NPC*)  tolua_tousertype(tolua_S,1,0);
  NPC* tar = ((NPC*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTargetNPC'",NULL);
#endif
 {
  self->setTargetNPC(tar);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTargetNPC'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Quest_Deliver */
static int tolua_Quest_Quest_Deliver_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quest_Deliver",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Quest_Deliver* tolua_ret = (Quest_Deliver*)  new Quest_Deliver();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quest_Deliver");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: getItem of class  Quest_Deliver */
static int tolua_Quest_Quest_Deliver_getItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest_Deliver",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest_Deliver* self = (Quest_Deliver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getItem'",NULL);
#endif
 {
  Item* tolua_ret = (Item*)  self->getItem();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Item");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getItem'.",&tolua_err);
 return 0;
#endif
}

/* method: setItem of class  Quest_Deliver */
static int tolua_Quest_Quest_Deliver_setItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest_Deliver",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Item",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest_Deliver* self = (Quest_Deliver*)  tolua_tousertype(tolua_S,1,0);
  Item* i = ((Item*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setItem'",NULL);
#endif
 {
  self->setItem(i);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setItem'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Quest_GoTo_Area */
static int tolua_Quest_Quest_GoTo_Area_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Quest_GoTo_Area",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Quest_GoTo_Area* tolua_ret = (Quest_GoTo_Area*)  new Quest_GoTo_Area();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quest_GoTo_Area");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: setTargetArea of class  Quest_GoTo_Area */
static int tolua_Quest_Quest_GoTo_Area_setTargetArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Quest_GoTo_Area",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Quest_GoTo_Area* self = (Quest_GoTo_Area*)  tolua_tousertype(tolua_S,1,0);
  float X = ((float)  tolua_tonumber(tolua_S,2,0));
  float Y = ((float)  tolua_tonumber(tolua_S,3,0));
  int W = ((int)  tolua_tonumber(tolua_S,4,0));
  int H = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTargetArea'",NULL);
#endif
 {
  self->setTargetArea(X,Y,W,H);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTargetArea'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_Quest (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"Quest","Quest","",NULL);
 tolua_beginmodule(tolua_S,"Quest");
 tolua_function(tolua_S,"new",tolua_Quest_Quest_new00);
 tolua_function(tolua_S,"Satisfy",tolua_Quest_Quest_Satisfy00);
 tolua_function(tolua_S,"completeQuest",tolua_Quest_Quest_completeQuest00);
 tolua_function(tolua_S,"setStartNPC",tolua_Quest_Quest_setStartNPC00);
 tolua_function(tolua_S,"getStartNPC",tolua_Quest_Quest_getStartNPC00);
 tolua_function(tolua_S,"setEndNPC",tolua_Quest_Quest_setEndNPC00);
 tolua_function(tolua_S,"getEndNPC",tolua_Quest_Quest_getEndNPC00);
 tolua_function(tolua_S,"setName",tolua_Quest_Quest_setName00);
 tolua_function(tolua_S,"getName",tolua_Quest_Quest_getName00);
 tolua_function(tolua_S,"setExamine",tolua_Quest_Quest_setExamine00);
 tolua_function(tolua_S,"getExamine",tolua_Quest_Quest_getExamine00);
 tolua_function(tolua_S,"isActive",tolua_Quest_Quest_isActive00);
 tolua_function(tolua_S,"isStarted",tolua_Quest_Quest_isStarted00);
 tolua_function(tolua_S,"isSatisfied",tolua_Quest_Quest_isSatisfied00);
 tolua_function(tolua_S,"isCompleted",tolua_Quest_Quest_isCompleted00);
 tolua_function(tolua_S,"setGiveXP",tolua_Quest_Quest_setGiveXP00);
 tolua_function(tolua_S,"getGiveXP",tolua_Quest_Quest_getGiveXP00);
 tolua_function(tolua_S,"activate",tolua_Quest_Quest_activate00);
 tolua_function(tolua_S,"start",tolua_Quest_Quest_start00);
 tolua_function(tolua_S,"complete",tolua_Quest_Quest_complete00);
 tolua_function(tolua_S,"update",tolua_Quest_Quest_update00);
 tolua_function(tolua_S,"setActiveConvo",tolua_Quest_Quest_setActiveConvo00);
 tolua_function(tolua_S,"setActivecyConvo",tolua_Quest_Quest_setActivecyConvo00);
 tolua_function(tolua_S,"setActivecnConvo",tolua_Quest_Quest_setActivecnConvo00);
 tolua_function(tolua_S,"setStartedConvo",tolua_Quest_Quest_setStartedConvo00);
 tolua_function(tolua_S,"setStartedcnConvo",tolua_Quest_Quest_setStartedcnConvo00);
 tolua_function(tolua_S,"setStartedcyfConvo",tolua_Quest_Quest_setStartedcyfConvo00);
 tolua_function(tolua_S,"setStartedcytConvo",tolua_Quest_Quest_setStartedcytConvo00);
 tolua_function(tolua_S,"setDoneConvo",tolua_Quest_Quest_setDoneConvo00);
 tolua_function(tolua_S,"printConversations",tolua_Quest_Quest_printConversations00);
 tolua_function(tolua_S,"getType",tolua_Quest_Quest_getType00);
 tolua_function(tolua_S,"getActiveConvo",tolua_Quest_Quest_getActiveConvo00);
 tolua_function(tolua_S,"getActivecyConvo",tolua_Quest_Quest_getActivecyConvo00);
 tolua_function(tolua_S,"getActivecnConvo",tolua_Quest_Quest_getActivecnConvo00);
 tolua_function(tolua_S,"getStartedConvo",tolua_Quest_Quest_getStartedConvo00);
 tolua_function(tolua_S,"getStartedcnConvo",tolua_Quest_Quest_getStartedcnConvo00);
 tolua_function(tolua_S,"getStartedcyfConvo",tolua_Quest_Quest_getStartedcyfConvo00);
 tolua_function(tolua_S,"getStartedcytConvo",tolua_Quest_Quest_getStartedcytConvo00);
 tolua_function(tolua_S,"getDoneConvo",tolua_Quest_Quest_getDoneConvo00);
 tolua_function(tolua_S,"addPreReqQ",tolua_Quest_Quest_addPreReqQ00);
 tolua_function(tolua_S,"preReqsCompleted",tolua_Quest_Quest_preReqsCompleted00);
 tolua_function(tolua_S,"pushItemsGive",tolua_Quest_Quest_pushItemsGive00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Quest_GoTo_NPC","Quest_GoTo_NPC","Quest",NULL);
 tolua_beginmodule(tolua_S,"Quest_GoTo_NPC");
 tolua_function(tolua_S,"new",tolua_Quest_Quest_GoTo_NPC_new00);
 tolua_function(tolua_S,"getTargetNPC",tolua_Quest_Quest_GoTo_NPC_getTargetNPC00);
 tolua_function(tolua_S,"setTargetNPC",tolua_Quest_Quest_GoTo_NPC_setTargetNPC00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Quest_Deliver","Quest_Deliver","Quest",NULL);
 tolua_beginmodule(tolua_S,"Quest_Deliver");
 tolua_function(tolua_S,"new",tolua_Quest_Quest_Deliver_new00);
 tolua_function(tolua_S,"getItem",tolua_Quest_Quest_Deliver_getItem00);
 tolua_function(tolua_S,"setItem",tolua_Quest_Quest_Deliver_setItem00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"Quest_GoTo_Area","Quest_GoTo_Area","Quest",NULL);
 tolua_beginmodule(tolua_S,"Quest_GoTo_Area");
 tolua_function(tolua_S,"new",tolua_Quest_Quest_GoTo_Area_new00);
 tolua_function(tolua_S,"setTargetArea",tolua_Quest_Quest_GoTo_Area_setTargetArea00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_Quest_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_Quest);
 lua_pushstring(tolua_S, "Quest");
 lua_call(tolua_S, 1, 0);
 return 1;
}
