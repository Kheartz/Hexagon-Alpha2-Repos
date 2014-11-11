$#include "tolua_Player.h"
print("tesst");
Playa = Player:new(1, 1, 1, 1, 1, 1, 1, "test");
print("works");
print (Playa:getMonies());

--[[
    int   lua_gettop (lua_State *L); //Returns #elements on stack; Number of elementes is index of top element 
    void  lua_settop (lua_State *L, int index);  //Sets the top element to a value to [index]
    void  lua_pushvalue (lua_State *L, int index); //Puts the value of index to the top of the stack. 
    void  lua_remove (lua_State *L, int index); //Removes value at [index]. Will push down all elemnets at higher stacks.
    void  lua_insert (lua_State *L, int index); //Puts the value of the top of the stack to another index in the stack
    void  lua_replace (lua_State *L, int index); //Takes the value of the top of the stack and replaces the value at the given index.

	void  lua_getglobal (lua_State *L, string name) //Finds global variable called "name" and places it to the stop of the stack (now -1)

    --Negative index = gettop - x + 1 -- -1 always on top

--]]