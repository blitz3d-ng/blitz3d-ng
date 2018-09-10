// AUTOGENERATED. DO NOT EDIT.
// RUN `bin/blitz3d config` TO UPDATE.

#include <bb/blitz/module.h>
#include <bb/filesystem/filesystem.h>

#ifdef WIN32
BBMODULE_LINK( filesystem ){
	rtSym( "ChangeDir$dir",bbChangeDir );
	rtSym( "CloseDir%dir",bbCloseDir );
	rtSym( "CloseFile%file_stream",bbCloseFile );
	rtSym( "CopyFile$file$to",bbCopyFile );
	rtSym( "CreateDir$dir",bbCreateDir );
	rtSym( "$CurrentDir",bbCurrentDir );
	rtSym( "DeleteDir$dir",bbDeleteDir );
	rtSym( "DeleteFile$file",bbDeleteFile );
	rtSym( "%FilePos%file_stream",bbFilePos );
	rtSym( "%FileSize$file",bbFileSize );
	rtSym( "%FileType$file",bbFileType );
	rtSym( "$NextFile%dir",bbNextFile );
	rtSym( "%OpenFile$filename",bbOpenFile );
	rtSym( "%ReadDir$dirname",bbReadDir );
	rtSym( "%ReadFile$filename",bbReadFile );
	rtSym( "%SeekFile%file_stream%pos",bbSeekFile );
	rtSym( "%WriteFile$filename",bbWriteFile );
}
#endif