// AUTOGENERATED. DO NOT EDIT.
// RUN `ruby src/bindings/luajit/generate.rb` TO UPDATE.

#include <bb/runtime/commands.h>

#if defined(BB_WIN32) || defined(BB_WIN64) || defined(BB_MINGW32) || defined(BB_MACOS) || defined(BB_LINUX) || defined(BB_IOS) || defined(BB_ANDROID) || defined(BB_EMSCRIPTEN)
#define BB_RUNTIME_ENABLED

static int l_runtime_HidePointer( lua_State *L ){
  bbHidePointer(  );
  return 0;
}

static int l_runtime_MoveMouse( lua_State *L ){
  bb_int_t __x = luaL_checknumber( L,1 );
  bb_int_t __y = luaL_checknumber( L,2 );
  bbMoveMouse( __x,__y );
  return 0;
}

static int l_runtime_RuntimeError( lua_State *L ){
  BBStr * __message = _bbStrConst( luaL_checkstring( L,1 ) );
  bbRuntimeError( __message );
  return 0;
}

static int l_runtime_ShowPointer( lua_State *L ){
  bbShowPointer(  );
  return 0;
}

#endif
