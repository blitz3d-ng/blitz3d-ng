// AUTOGENERATED. DO NOT EDIT.
// RUN `bin/blitz3d config` TO UPDATE.

#include <bb/stub/stub.h>


#include "../../stdutil/stdutil.h"

BBMODULE_DECL( math );
BBMODULE_DECL( blitz );
BBMODULE_DECL( string );
BBMODULE_DECL( stream );
BBMODULE_DECL( bank );
BBMODULE_DECL( stdio );
BBMODULE_DECL( hook );
BBMODULE_DECL( enet );
BBMODULE_DECL( runtime );
BBMODULE_DECL( system );
BBMODULE_DECL( system_linux );
BBMODULE_DECL( filesystem );
BBMODULE_DECL( filesystem_posix );
BBMODULE_DECL( timer );
BBMODULE_DECL( timer_noop );
BBMODULE_DECL( input );
BBMODULE_DECL( audio );
BBMODULE_DECL( event );
BBMODULE_DECL( runtime_console );
BBMODULE_DECL( unit_test );

class BBRuntime;
BBRuntime *bbCreateConsoleRuntime();
BBRuntime *bbCreateRuntime(){
	return bbCreateConsoleRuntime();
}

#ifdef WIN32
void bbruntime_link( void (*link)( const char *sym,void *pc ) ){
	math_link( link );
	blitz_link( link );
	string_link( link );
	stream_link( link );
	bank_link( link );
	stdio_link( link );
	enet_link( link );
	runtime_link( link );
	system_link( link );
	filesystem_link( link );
	timer_link( link );
	input_link( link );
	audio_link( link );
	unit_test_link( link );
}
#endif
bool bbruntime_create(){
	if( math_create() ){
				if( blitz_create() ){
						if( string_create() ){
								if( stream_create() ){
										if( bank_create() ){
												if( stdio_create() ){
														if( hook_create() ){
																if( enet_create() ){
																		if( runtime_create() ){
																				if( system_create() ){
																						if( system_linux_create() ){
																								if( filesystem_create() ){
																										if( filesystem_posix_create() ){
																												if( timer_create() ){
																														if( timer_noop_create() ){
																																if( input_create() ){
																																		if( audio_create() ){
																																				if( event_create() ){
																																						if( runtime_console_create() ){
																																								if( unit_test_create() ){
																																										return true;
																				}else sue( "unit_test_create failed" );
																				runtime_console_destroy();
																			}else sue( "runtime_console_create failed" );
																			event_destroy();
																		}else sue( "event_create failed" );
																		audio_destroy();
																	}else sue( "audio_create failed" );
																	input_destroy();
																}else sue( "input_create failed" );
																timer_noop_destroy();
															}else sue( "timer_noop_create failed" );
															timer_destroy();
														}else sue( "timer_create failed" );
														filesystem_posix_destroy();
													}else sue( "filesystem_posix_create failed" );
													filesystem_destroy();
												}else sue( "filesystem_create failed" );
												system_linux_destroy();
											}else sue( "system_linux_create failed" );
											system_destroy();
										}else sue( "system_create failed" );
										runtime_destroy();
									}else sue( "runtime_create failed" );
									enet_destroy();
								}else sue( "enet_create failed" );
								hook_destroy();
							}else sue( "hook_create failed" );
							stdio_destroy();
						}else sue( "stdio_create failed" );
						bank_destroy();
					}else sue( "bank_create failed" );
					stream_destroy();
				}else sue( "stream_create failed" );
				string_destroy();
			}else sue( "string_create failed" );
			blitz_destroy();
		}else sue( "blitz_create failed" );
		math_destroy();
	}else sue( "math_create failed" );
	return false;
}

bool bbruntime_destroy(){
	unit_test_destroy();
	runtime_console_destroy();
	event_destroy();
	audio_destroy();
	input_destroy();
	timer_noop_destroy();
	timer_destroy();
	filesystem_posix_destroy();
	filesystem_destroy();
	system_linux_destroy();
	system_destroy();
	runtime_destroy();
	enet_destroy();
	hook_destroy();
	stdio_destroy();
	bank_destroy();
	stream_destroy();
	string_destroy();
	blitz_destroy();
	math_destroy();
	return true;
}
