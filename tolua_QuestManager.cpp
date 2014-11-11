/*
** Lua binding: QuestManager
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
TOLUA_API int tolua_QuestManager_open (lua_State* tolua_S);
LUALIB_API int luaopen_QuestManager (lua_State* tolua_S);

#include "QuestManager.h"
#include "Quest.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"QuestManager");
 tolua_usertype(tolua_S,"Quest");
}

/* method: new of class  QuestManager */
static int tolua_QuestManager_QuestManager_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"QuestManager",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  QuestManager* tolua_ret = (QuestManager*)  new QuestManager();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"QuestManager");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: addQuest of class  QuestManager */
static int tolua_QuestManager_QuestManager_addQuest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"QuestManager",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Quest",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  QuestManager* self = (QuestManager*)  tolua_tousertype(tolua_S,1,0);
  Quest* q = ((Quest*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addQuest'",NULL);
#endif
 {
  self->addQuest(q);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addQuest'.",&tolua_err);
 return 0;
#endif
}

/* method: deleteQuest of class  QuestManager */
static int tolua_QuestManager_QuestManager_deleteQuest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"QuestManager",0,&tolua_err) || 
 !tolua_isstring(tolua_S,2,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  QuestManager* self = (QuestManager*)  tolua_tousertype(tolua_S,1,0);
  char* q = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'deleteQuest'",NULL);
#endif
 {
  self->deleteQuest(q);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'deleteQuest'.",&tolua_err);
 return 0;
#endif
}

/* method: setConvo of class  QuestManager */
static int tolua_QuestManager_QuestManager_setConvo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"QuestManager",0,&tolua_err) || 
 !tolua_isusertype(tolua_S,2,"Quest",0,&tolua_err) || 
 !tolua_isstring(tolua_S,3,0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  QuestManager* self = (QuestManager*)  tolua_tousertype(tolua_S,1,0);
  Quest* q = ((Quest*)  tolua_tousertype(tolua_S,2,0));
  char* name = ((char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setConvo'",NULL);
#endif
 {
  self->setConvo(q,name);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setConvo'.",&tolua_err);
 return 0;
#endif
}

/* method: Update of class  QuestManager */
static int tolua_QuestManager_QuestManager_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"QuestManager",0,&tolua_err) || 
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  QuestManager* self = (QuestManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'",NULL);
#endif
 {
  self->Update();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}

/* Open lib function */
LUALIB_API int luaopen_QuestManager (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"QuestManager","QuestManager","",NULL);
 tolua_beginmodule(tolua_S,"QuestManager");
 tolua_function(tolua_S,"new",tolua_QuestManager_QuestManager_new00);
 tolua_function(tolua_S,"addQuest",tolua_QuestManager_QuestManager_addQuest00);
 tolua_function(tolua_S,"deleteQuest",tolua_QuestManager_QuestManager_deleteQuest00);
 tolua_function(tolua_S,"setConvo",tolua_QuestManager_QuestManager_setConvo00);
 tolua_function(tolua_S,"Update",tolua_QuestManager_QuestManager_Update00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
/* Open tolua function */
TOLUA_API int tolua_QuestManager_open (lua_State* tolua_S)
{
 lua_pushcfunction(tolua_S, luaopen_QuestManager);
 lua_pushstring(tolua_S, "QuestManager");
 lua_call(tolua_S, 1, 0);
 return 1;
}
