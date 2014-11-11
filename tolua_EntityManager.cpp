/*
** Lua binding: EntityManager
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
TOLUA_API int tolua_EntityManager_open (lua_State* tolua_S);
LUALIB_API int luaopen_EntityManager (lua_State* tolua_S);

#include "EntityManager.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Item");
 tolua_usertype(tolua_S,"NPC");
 tolua_usertype(tolua_S,"Entity");
 tolua_usertype(tolua_S,"EntityManager");
}

/* method: new of class  EntityManager */
static int tolua_EntityManager_EntityManager_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"EntityManager",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  EntityManager* tolua_ret = (EntityManager*)  new EntityManager();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"EntityManager");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: Add of class  EntityManager */
static int tolua_EntityManager_EntityManager_Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"EntityManager",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  EntityManager* self = (EntityManager*)  tolua_tousertype(tolua_S,1,0);
  Entity* tolua_var_1 = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
 {
  self->Add(tolua_var_1);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: Remove of class  EntityManager */
static int tolua_EntityManager_EntityManager_Remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"EntityManager",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  EntityManager* self = (EntityManager*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Remove'",NULL);
#endif
 {
  self->Remove(index);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Remove'.",&tolua_err);
 return 0;
#endif
}

/* method: getIndex of class  EntityManager */
static int tolua_EntityManager_EntityManager_getIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"EntityManager",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  EntityManager* self = (EntityManager*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIndex'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getIndex(name);
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

/* method: getNPC of class  EntityManager */
static int tolua_EntityManager_EntityManager_getNPC00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"EntityManager",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  EntityManager* self = (EntityManager*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNPC'",NULL);
#endif
 {
  NPC* tolua_ret = (NPC*)  self->getNPC(name);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"NPC");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNPC'.",&tolua_err);
 return 0;
#endif
}

/* method: getItem of class  EntityManager */
static int tolua_EntityManager_EntityManager_getItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"EntityManager",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  EntityManager* self = (EntityManager*)  tolua_tousertype(tolua_S,1,0);
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getItem'",NULL);
#endif
 {
  Item* tolua_ret = (Item*)  self->getItem(name);
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

/* method: getSize of class  EntityManager */
static int tolua_EntityManager_EntityManager_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"EntityManager",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  EntityManager* self = (EntityManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}

/* method: getInstance of class  EntityManager */
static int tolua_EntityManager_EntityManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"EntityManager",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  EntityManager* tolua_ret = (EntityManager*)  EntityManager::getInstance();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"EntityManager");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_EntityManager (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"EntityManager","EntityManager","",NULL);
 tolua_beginmodule(tolua_S,"EntityManager");
 tolua_function(tolua_S,"new",tolua_EntityManager_EntityManager_new00);
 tolua_function(tolua_S,"Add",tolua_EntityManager_EntityManager_Add00);
 tolua_function(tolua_S,"Remove",tolua_EntityManager_EntityManager_Remove00);
 tolua_function(tolua_S,"getIndex",tolua_EntityManager_EntityManager_getIndex00);
 tolua_function(tolua_S,"getNPC",tolua_EntityManager_EntityManager_getNPC00);
 tolua_function(tolua_S,"getItem",tolua_EntityManager_EntityManager_getItem00);
 tolua_function(tolua_S,"getSize",tolua_EntityManager_EntityManager_getSize00);
 tolua_function(tolua_S,"getInstance",tolua_EntityManager_EntityManager_getInstance00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_EntityManager_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_EntityManager);
 lua_pushstring(tolua_S, "EntityManager");
 lua_call(tolua_S, 1, 0);
 return 1;
}
