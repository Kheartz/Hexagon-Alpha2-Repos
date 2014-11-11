/*
** Lua binding: Item
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
TOLUA_API int tolua_Item_open (lua_State* tolua_S);
LUALIB_API int luaopen_Item (lua_State* tolua_S);

#include "Entity.h"
#include "Item.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Entity");
 tolua_usertype(tolua_S,"Item");
}

/* method: new of class  Item */
static int tolua_Item_Item_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,3,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,4,0,&tolua_err) || 
 !tolua_isnumber(tolua_S,5,0,&tolua_err) || 
 !tolua_isstring(tolua_S,6,0,&tolua_err) || 
 !tolua_isstring(tolua_S,7,0,&tolua_err) || 
 !tolua_isstring(tolua_S,8,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,9,&tolua_err)
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
  char* examine = ((char*)  tolua_tostring(tolua_S,7,0));
  char* filename = ((char*)  tolua_tostring(tolua_S,8,0));
 {
  Item* tolua_ret = (Item*)  new Item(x,y,w,h,name,examine,filename);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Item");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  Item */
static int tolua_Item_Item_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
  char* type = ((char*)  tolua_tostring(tolua_S,3,0));
 {
  Item* tolua_ret = (Item*)  new Item(name,type);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Item");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Item_Item_new00(tolua_S);
}

/* method: getScript of class  Item */
static int tolua_Item_Item_getScript00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScript'",NULL);
#endif
 {
  const char* tolua_ret = (const char*)  self->getScript();
 tolua_pushstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScript'.",&tolua_err);
 return 0;
#endif
}

/* method: getExamine of class  Item */
static int tolua_Item_Item_getExamine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
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

/* method: isQuestItem of class  Item */
static int tolua_Item_Item_isQuestItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isQuestItem'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isQuestItem();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isQuestItem'.",&tolua_err);
 return 0;
#endif
}

/* method: isPublic of class  Item */
static int tolua_Item_Item_isPublic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPublic'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isPublic();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPublic'.",&tolua_err);
 return 0;
#endif
}

/* method: setPublic of class  Item */
static int tolua_Item_Item_setPublic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isboolean(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
  bool p = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPublic'",NULL);
#endif
 {
  self->setPublic(p);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPublic'.",&tolua_err);
 return 0;
#endif
}

/* method: getNumberOf of class  Item */
static int tolua_Item_Item_getNumberOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumberOf'",NULL);
#endif
 {
  int tolua_ret = (int)  self->getNumberOf();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumberOf'.",&tolua_err);
 return 0;
#endif
}

/* method: changeNumBy of class  Item */
static int tolua_Item_Item_changeNumBy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isnumber(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
  int n = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeNumBy'",NULL);
#endif
 {
  self->changeNumBy(n);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeNumBy'.",&tolua_err);
 return 0;
#endif
}

/* method: incrNum of class  Item */
static int tolua_Item_Item_incrNum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'incrNum'",NULL);
#endif
 {
  self->incrNum();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'incrNum'.",&tolua_err);
 return 0;
#endif
}

/* method: decrNum of class  Item */
static int tolua_Item_Item_decrNum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'decrNum'",NULL);
#endif
 {
  self->decrNum();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decrNum'.",&tolua_err);
 return 0;
#endif
}

/* method: isStackable of class  Item */
static int tolua_Item_Item_isStackable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isStackable'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->isStackable();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isStackable'.",&tolua_err);
 return 0;
#endif
}

/* method: setStackable of class  Item */
static int tolua_Item_Item_setStackable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Item",0,&tolua_err) || 
 !tolua_isboolean(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Item* self = (Item*)  tolua_tousertype(tolua_S,1,0);
  bool stackable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setStackable'",NULL);
#endif
 {
  self->setStackable(stackable);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setStackable'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_Item (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"Item","Item","Entity",NULL);
 tolua_beginmodule(tolua_S,"Item");
 tolua_function(tolua_S,"new",tolua_Item_Item_new00);
 tolua_function(tolua_S,"new",tolua_Item_Item_new01);
 tolua_function(tolua_S,"getScript",tolua_Item_Item_getScript00);
 tolua_function(tolua_S,"getExamine",tolua_Item_Item_getExamine00);
 tolua_function(tolua_S,"isQuestItem",tolua_Item_Item_isQuestItem00);
 tolua_function(tolua_S,"isPublic",tolua_Item_Item_isPublic00);
 tolua_function(tolua_S,"setPublic",tolua_Item_Item_setPublic00);
 tolua_function(tolua_S,"getNumberOf",tolua_Item_Item_getNumberOf00);
 tolua_function(tolua_S,"changeNumBy",tolua_Item_Item_changeNumBy00);
 tolua_function(tolua_S,"incrNum",tolua_Item_Item_incrNum00);
 tolua_function(tolua_S,"decrNum",tolua_Item_Item_decrNum00);
 tolua_function(tolua_S,"isStackable",tolua_Item_Item_isStackable00);
 tolua_function(tolua_S,"setStackable",tolua_Item_Item_setStackable00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_Item_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_Item);
 lua_pushstring(tolua_S, "Item");
 lua_call(tolua_S, 1, 0);
 return 1;
}
