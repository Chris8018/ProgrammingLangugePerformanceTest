#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

static int isCFun(lua_State *L);

static int sum_written_in_c(lua_State *L);
