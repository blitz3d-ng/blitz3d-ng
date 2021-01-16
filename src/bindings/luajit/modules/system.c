// AUTOGENERATED. DO NOT EDIT.
// RUN `ruby src/bindings/luajit/generate.rb` TO UPDATE.

#include <bb/system/commands.h>

#if defined(BB_WIN32) || defined(BB_WIN64) || defined(BB_MINGW32) || defined(BB_MACOS) || defined(BB_LINUX) || defined(BB_IOS) || defined(BB_ANDROID) || defined(BB_EMSCRIPTEN) || defined(BB_NX)
#define BB_SYSTEM_ENABLED

static int l_system_DPIScaleX( lua_State *L ){
  lua_pushnumber( L,(bb_float_t)bbDPIScaleX(  ) );
  return 1;
}

static int l_system_DPIScaleY( lua_State *L ){
  lua_pushnumber( L,(bb_float_t)bbDPIScaleY(  ) );
  return 1;
}

static int l_system_Delay( lua_State *L ){
  bb_int_t __millisecs = luaL_checknumber( L,1 );
  bbDelay( __millisecs );
  return 0;
}

static int l_system_ExecFile( lua_State *L ){
  BBStr * __file = _bbStrConst( luaL_checkstring( L,1 ) );
  bbExecFile( __file );
  return 0;
}

static int l_system_GetEnv( lua_State *L ){
  BBStr * __env_var = _bbStrConst( luaL_checkstring( L,1 ) );
  lua_pushstring( L,bbGetEnv( __env_var ) );
  return 1;
}

static int l_system_MilliSecs( lua_State *L ){
  lua_pushnumber( L,(bb_int_t)bbMilliSecs(  ) );
  return 1;
}

static int l_system_ScreenHeight( lua_State *L ){
  bb_int_t __i;
  if( lua_gettop( L ) > 0 ){
    __i = luaL_checknumber( L,1 );
  }else{
   __i = -1;
  }
  lua_pushnumber( L,(bb_int_t)bbScreenHeight( __i ) );
  return 1;
}

static int l_system_ScreenWidth( lua_State *L ){
  bb_int_t __i;
  if( lua_gettop( L ) > 0 ){
    __i = luaL_checknumber( L,1 );
  }else{
   __i = -1;
  }
  lua_pushnumber( L,(bb_int_t)bbScreenWidth( __i ) );
  return 1;
}

static int l_system_SetEnv( lua_State *L ){
  BBStr * __env_var = _bbStrConst( luaL_checkstring( L,1 ) );
  BBStr * __value = _bbStrConst( luaL_checkstring( L,2 ) );
  bbSetEnv( __env_var,__value );
  return 0;
}

static int l_system_SystemProperty( lua_State *L ){
  BBStr * __property = _bbStrConst( luaL_checkstring( L,1 ) );
  lua_pushstring( L,bbSystemProperty( __property ) );
  return 1;
}

#endif
