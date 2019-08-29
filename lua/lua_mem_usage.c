#include <stdio.h>
#include <stdlib.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

// Measuring lua vm memory usage.
// build: gcc main.c -llua5.1 -lm -ldl -fPIC
static size_t mem_used = 0;
static void *l_alloc(void *ud, void *ptr, size_t osize, size_t nsize) {
  (void)ud; mem_used -= osize; mem_used += nsize;
  if (nsize == 0) {
    free(ptr);
    return NULL;
  } else {
    return realloc(ptr, nsize);
  }
}

static int panic(lua_State *L) {
  printf("PANIC\n");
  exit(1);
  return 0;
}

int main() {
  lua_State *L = lua_newstate(l_alloc, NULL);
  if (L) lua_atpanic(L, &panic);
  printf("initial memory used: %zu\n", mem_used);
  luaL_openlibs(L);
  printf("after base libs loaded: %zu\n", mem_used);
  // luaL_dostring(L, "print(100);"); // Change here
  luaL_dofile(L, "test3.lua");
  printf("after print called: %zu\n", mem_used);
  lua_close(L);
  return 0;
}