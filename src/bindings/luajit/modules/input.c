// AUTOGENERATED. DO NOT EDIT.
// RUN `ruby src/bindings/luajit/generate.rb` TO UPDATE.

#include <bb/input/commands.h>

#if defined(BB_WIN32) || defined(BB_WIN64) || defined(BB_MINGW32) || defined(BB_MACOS) || defined(BB_LINUX) || defined(BB_IOS) || defined(BB_ANDROID) || defined(BB_EMSCRIPTEN)
#define BB_INPUT_ENABLED

static int l_input_CountJoys( lua_State *L ){
  lua_pushnumber( L,(bb_int_t)bbCountJoys(  ) );
  return 1;
}

static int l_input_FindJoy( lua_State *L ){
  BBStr * __id = _bbStrConst( luaL_checkstring( L,1 ) );
  lua_pushnumber( L,(bb_int_t)bbFindJoy( __id ) );
  return 1;
}

static int l_input_FlushJoy( lua_State *L ){
  bbFlushJoy(  );
  return 0;
}

static int l_input_FlushKeys( lua_State *L ){
  bbFlushKeys(  );
  return 0;
}

static int l_input_FlushMouse( lua_State *L ){
  bbFlushMouse(  );
  return 0;
}

static int l_input_GetJoy( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbGetJoy( __port ) );
  return 1;
}

static int l_input_GetKey( lua_State *L ){
  bb_int_t __ascii;
  if( lua_gettop( L ) > 0 ){
    __ascii = luaL_checknumber( L,1 );
  }else{
   __ascii = 1;
  }
  lua_pushnumber( L,(bb_int_t)bbGetKey( __ascii ) );
  return 1;
}

static int l_input_GetMouse( lua_State *L ){
  lua_pushnumber( L,(bb_int_t)bbGetMouse(  ) );
  return 1;
}

static int l_input_JoyDown( lua_State *L ){
  bb_int_t __button = luaL_checknumber( L,1 );
  bb_int_t __port;
  if( lua_gettop( L ) > 1 ){
    __port = luaL_checknumber( L,2 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbJoyDown( __button,__port ) );
  return 1;
}

static int l_input_JoyHat( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbJoyHat( __port ) );
  return 1;
}

static int l_input_JoyHit( lua_State *L ){
  bb_int_t __button = luaL_checknumber( L,1 );
  bb_int_t __port;
  if( lua_gettop( L ) > 1 ){
    __port = luaL_checknumber( L,2 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbJoyHit( __button,__port ) );
  return 1;
}

static int l_input_JoyID( lua_State *L ){
  bb_int_t __port = luaL_checknumber( L,1 );
  lua_pushstring( L,bbJoyID( __port ) );
  return 1;
}

static int l_input_JoyName( lua_State *L ){
  bb_int_t __port = luaL_checknumber( L,1 );
  lua_pushstring( L,bbJoyName( __port ) );
  return 1;
}

static int l_input_JoyPitch( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_float_t)bbJoyPitch( __port ) );
  return 1;
}

static int l_input_JoyRoll( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_float_t)bbJoyRoll( __port ) );
  return 1;
}

static int l_input_JoyType( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbJoyType( __port ) );
  return 1;
}

static int l_input_JoyU( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_float_t)bbJoyU( __port ) );
  return 1;
}

static int l_input_JoyUDir( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbJoyUDir( __port ) );
  return 1;
}

static int l_input_JoyV( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_float_t)bbJoyV( __port ) );
  return 1;
}

static int l_input_JoyVDir( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbJoyVDir( __port ) );
  return 1;
}

static int l_input_JoyWait( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbWaitJoy( __port ) );
  return 1;
}

static int l_input_JoyX( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_float_t)bbJoyX( __port ) );
  return 1;
}

static int l_input_JoyXDir( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbJoyXDir( __port ) );
  return 1;
}

static int l_input_JoyY( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_float_t)bbJoyY( __port ) );
  return 1;
}

static int l_input_JoyYDir( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbJoyYDir( __port ) );
  return 1;
}

static int l_input_JoyYaw( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_float_t)bbJoyYaw( __port ) );
  return 1;
}

static int l_input_JoyZ( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_float_t)bbJoyZ( __port ) );
  return 1;
}

static int l_input_JoyZDir( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbJoyZDir( __port ) );
  return 1;
}

static int l_input_KeyDown( lua_State *L ){
  bb_int_t __key = luaL_checknumber( L,1 );
  lua_pushnumber( L,(bb_int_t)bbKeyDown( __key ) );
  return 1;
}

static int l_input_KeyHit( lua_State *L ){
  bb_int_t __key = luaL_checknumber( L,1 );
  lua_pushnumber( L,(bb_int_t)bbKeyHit( __key ) );
  return 1;
}

static int l_input_MouseDown( lua_State *L ){
  bb_int_t __button = luaL_checknumber( L,1 );
  lua_pushnumber( L,(bb_int_t)bbMouseDown( __button ) );
  return 1;
}

static int l_input_MouseHit( lua_State *L ){
  bb_int_t __button = luaL_checknumber( L,1 );
  lua_pushnumber( L,(bb_int_t)bbMouseHit( __button ) );
  return 1;
}

static int l_input_MouseWait( lua_State *L ){
  lua_pushnumber( L,(bb_int_t)bbWaitMouse(  ) );
  return 1;
}

static int l_input_MouseX( lua_State *L ){
  lua_pushnumber( L,(bb_int_t)bbMouseX(  ) );
  return 1;
}

static int l_input_MouseXSpeed( lua_State *L ){
  lua_pushnumber( L,(bb_int_t)bbMouseXSpeed(  ) );
  return 1;
}

static int l_input_MouseY( lua_State *L ){
  lua_pushnumber( L,(bb_int_t)bbMouseY(  ) );
  return 1;
}

static int l_input_MouseYSpeed( lua_State *L ){
  lua_pushnumber( L,(bb_int_t)bbMouseYSpeed(  ) );
  return 1;
}

static int l_input_MouseZ( lua_State *L ){
  lua_pushnumber( L,(bb_int_t)bbMouseZ(  ) );
  return 1;
}

static int l_input_MouseZSpeed( lua_State *L ){
  lua_pushnumber( L,(bb_int_t)bbMouseZSpeed(  ) );
  return 1;
}

static int l_input_WaitJoy( lua_State *L ){
  bb_int_t __port;
  if( lua_gettop( L ) > 0 ){
    __port = luaL_checknumber( L,1 );
  }else{
   __port = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbWaitJoy( __port ) );
  return 1;
}

static int l_input_WaitKey( lua_State *L ){
  lua_pushnumber( L,(bb_int_t)bbWaitKey(  ) );
  return 1;
}

static int l_input_WaitMouse( lua_State *L ){
  lua_pushnumber( L,(bb_int_t)bbWaitMouse(  ) );
  return 1;
}

#endif
