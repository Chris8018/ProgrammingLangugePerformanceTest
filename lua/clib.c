// C library function for performance test in Lua

#include "clib.h"

// #include "lua.h"
// #include "lauxlib.h"
// #include "lualib.h"

// static int isCFun(lua_State *L);

// static int sum_written_in_c(lua_State *L);

// int luaopen_clib(lua_State *L);

static int isCFun(lua_State *L)
{
    // Push boolean to stack
    lua_pushboolean(L, 1);

    return 1;
}

static int sum_written_in_c(lua_State *L)
{
    // Local Decl
    int temp;
    double a, b, c;

    // Extract parameters from lua stack
    a = lua_tonumber(L, 1);
    b = lua_tonumber(L, 2);
    c = lua_tonumber(L, 3);

    // Sum
    temp = a + b + c;

    // Push result on Lua stack
    lua_pushnumber(L, temp);

    // Return numb of args
    return 1;
}

/* Register this file's functions with the
 * luaopen_libraryname() function, where libraryname
 * is the name of the compiled .so/.dll output.
 *
 * This function should contain lua_register() commands for
 * each function you want available from Lua.
 *
*/
int luaopen_clib(lua_State *L)
{
    // lua_register(Lua State var, func name know in Lua, func name in file)
    lua_register(L, "isCFun", isCFun);
    lua_register(L, "sum_written_in_c", sum_written_in_c);

    return 0;

}
