/*
** Lua binding: NPC
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
TOLUA_API int tolua_NPC_open (lua_State* tolua_S);
LUALIB_API int luaopen_NPC (lua_State* tolua_S);

#include "NPC.h"
#include "Character.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"NPC");
 tolua_usertype(tolua_S,"Character");
}

/* method: new of class  NPC */
static int tolua_NPC_NPC_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"NPC",0,&tolua_err) || 
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
  int HP = ((int)  tolua_tonumber(tolua_S,7,0));
  int MP = ((int)  tolua_tonumber(tolua_S,8,0));
  char* filename = ((char*)  tolua_tostring(tolua_S,9,0));
 {
  NPC* tolua_ret = (NPC*)  new NPC(X,Y,W,H,name,HP,MP,filename);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"NPC");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: setConversation of class  NPC */
static int tolua_NPC_NPC_setConversation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"NPC",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  NPC* self = (NPC*)  tolua_tousertype(tolua_S,1,0);
  char* c = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setConversation'",NULL);
#endif
 {
  self->setConversation(c);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setConversation'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_NPC (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"NPC","NPC","Character",NULL);
 tolua_beginmodule(tolua_S,"NPC");
 tolua_function(tolua_S,"new",tolua_NPC_NPC_new00);
 tolua_function(tolua_S,"setConversation",tolua_NPC_NPC_setConversation00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_NPC_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_NPC);
 lua_pushstring(tolua_S, "NPC");
 lua_call(tolua_S, 1, 0);
 return 1;
}
