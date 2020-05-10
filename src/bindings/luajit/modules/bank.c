// AUTOGENERATED. DO NOT EDIT.
// RUN `ruby src/bindings/luajit/generate.rb` TO UPDATE.

#include <bb/bank/commands.h>

#if defined(BB_WIN32) || defined(BB_WIN64) || defined(BB_MINGW32) || defined(BB_MACOS) || defined(BB_LINUX) || defined(BB_IOS) || defined(BB_ANDROID) || defined(BB_EMSCRIPTEN)
#define BB_BANK_ENABLED

static int l_bank_BankSize( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  lua_pushnumber( L,(bb_int_t)bbBankSize( __bank ) );
  return 1;
}

static int l_bank_CopyBank( lua_State *L ){
  bb_int_t __src_bank = luaL_checknumber( L,1 );
  bb_int_t __src_offset = luaL_checknumber( L,2 );
  bb_int_t __dest_bank = luaL_checknumber( L,3 );
  bb_int_t __dest_offset = luaL_checknumber( L,4 );
  bb_int_t __count = luaL_checknumber( L,5 );
  bbCopyBank( __src_bank,__src_offset,__dest_bank,__dest_offset,__count );
  return 0;
}

static int l_bank_CreateBank( lua_State *L ){
  bb_int_t __size;
  if( lua_gettop( L ) > 0 ){
    __size = luaL_checknumber( L,1 );
  }else{
   __size = 0;
  }
  lua_pushnumber( L,(bb_int_t)bbCreateBank( __size ) );
  return 1;
}

static int l_bank_FreeBank( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  bbFreeBank( __bank );
  return 0;
}

static int l_bank_PeekByte( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  bb_int_t __offset = luaL_checknumber( L,2 );
  lua_pushnumber( L,(bb_int_t)bbPeekByte( __bank,__offset ) );
  return 1;
}

static int l_bank_PeekFloat( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  bb_int_t __offset = luaL_checknumber( L,2 );
  lua_pushnumber( L,(bb_float_t)bbPeekFloat( __bank,__offset ) );
  return 1;
}

static int l_bank_PeekInt( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  bb_int_t __offset = luaL_checknumber( L,2 );
  lua_pushnumber( L,(bb_int_t)bbPeekInt( __bank,__offset ) );
  return 1;
}

static int l_bank_PeekShort( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  bb_int_t __offset = luaL_checknumber( L,2 );
  lua_pushnumber( L,(bb_int_t)bbPeekShort( __bank,__offset ) );
  return 1;
}

static int l_bank_PokeByte( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  bb_int_t __offset = luaL_checknumber( L,2 );
  bb_int_t __value = luaL_checknumber( L,3 );
  bbPokeByte( __bank,__offset,__value );
  return 0;
}

static int l_bank_PokeFloat( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  bb_int_t __offset = luaL_checknumber( L,2 );
  bb_float_t __value = luaL_checknumber( L,3 );
  bbPokeFloat( __bank,__offset,__value );
  return 0;
}

static int l_bank_PokeInt( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  bb_int_t __offset = luaL_checknumber( L,2 );
  bb_int_t __value = luaL_checknumber( L,3 );
  bbPokeInt( __bank,__offset,__value );
  return 0;
}

static int l_bank_PokeShort( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  bb_int_t __offset = luaL_checknumber( L,2 );
  bb_int_t __value = luaL_checknumber( L,3 );
  bbPokeShort( __bank,__offset,__value );
  return 0;
}

static int l_bank_ReadBytes( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  bb_int_t __file = luaL_checknumber( L,2 );
  bb_int_t __offset = luaL_checknumber( L,3 );
  bb_int_t __count = luaL_checknumber( L,4 );
  lua_pushnumber( L,(bb_int_t)bbReadBytes( __bank,__file,__offset,__count ) );
  return 1;
}

static int l_bank_ResizeBank( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  bb_int_t __size = luaL_checknumber( L,2 );
  bbResizeBank( __bank,__size );
  return 0;
}

static int l_bank_WriteBytes( lua_State *L ){
  bb_int_t __bank = luaL_checknumber( L,1 );
  bb_int_t __file = luaL_checknumber( L,2 );
  bb_int_t __offset = luaL_checknumber( L,3 );
  bb_int_t __count = luaL_checknumber( L,4 );
  lua_pushnumber( L,(bb_int_t)bbWriteBytes( __bank,__file,__offset,__count ) );
  return 1;
}

#endif
