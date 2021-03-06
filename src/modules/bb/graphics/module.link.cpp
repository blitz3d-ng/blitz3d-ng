// AUTOGENERATED. DO NOT EDIT.
// RUN `bin/blitz3d config` TO UPDATE.

#include <bb/blitz/module.h>
#include <bb/graphics/graphics.h>

#ifdef WIN32
BBMODULE_LINK( graphics ){
	rtSym( "AutoMidHandle%enable",bbAutoMidHandle );
	rtSym( "%AvailVidMem",bbAvailVidMem );
	rtSym( "%BackBuffer",bbBackBuffer );
	rtSym( "BufferDirty%buffer",bbBufferDirty );
	rtSym( "%CopyImage%image",bbCopyImage );
	rtSym( "CopyPixel%src_x%src_y%src_buffer%dest_x%dest_y%dest_buffer=0",bbCopyPixel );
	rtSym( "CopyPixelFast%src_x%src_y%src_buffer%dest_x%dest_y%dest_buffer=0",bbCopyPixelFast );
	rtSym( "CopyRect%source_x%source_y%width%height%dest_x%dest_y%src_buffer=0%dest_buffer=0",bbCopyRect );
	rtSym( "%CountGfxDrivers",bbCountGfxDrivers );
	rtSym( "%CountGfxModes",bbCountGfxModes );
	rtSym( "%CountGfxModes3D",bbCountGfxModes3D );
	rtSym( "%CreateImage%width%height%frames=1",bbCreateImage );
	rtSym( "DrawBlock%image%x%y%frame=0",bbDrawBlock );
	rtSym( "DrawBlockRect%image%x%y%rect_x%rect_y%rect_width%rect_height%frame=0",bbDrawBlockRect );
	rtSym( "DrawImage%image%x%y%frame=0",bbDrawImage );
	rtSym( "DrawImageRect%image%x%y%rect_x%rect_y%rect_width%rect_height%frame=0",bbDrawImageRect );
	rtSym( "EndGraphics",bbEndGraphics );
	rtSym( "Flip%vwait=1",bbFlip );
	rtSym( "FreeImage%image",bbFreeImage );
	rtSym( "%FrontBuffer",bbFrontBuffer );
	rtSym( "#GammaBlue%blue",bbGammaBlue );
	rtSym( "#GammaGreen%green",bbGammaGreen );
	rtSym( "#GammaRed%red",bbGammaRed );
	rtSym( "%GfxDriver3D%driver",bbGfxDriver3D );
	rtSym( "$GfxDriverName%driver",bbGfxDriverName );
	rtSym( "%GfxMode3D%mode",bbGfxMode3D );
	rtSym( "%GfxMode3DExists%width%height%depth",bbGfxMode3DExists );
	rtSym( "%GfxModeDepth%mode",bbGfxModeDepth );
	rtSym( "%GfxModeExists%width%height%depth",bbGfxModeExists );
	rtSym( "%GfxModeHeight%mode",bbGfxModeHeight );
	rtSym( "%GfxModeWidth%mode",bbGfxModeWidth );
	rtSym( "GrabImage%image%x%y%frame=0",bbGrabImage );
	rtSym( "Graphics%width%height%depth=0%mode=0",bbGraphics );
	rtSym( "Graphics3D%width%height%depth=0%mode=0",bbGraphics3D );
	rtSym( "%GraphicsBuffer",bbGraphicsBuffer );
	rtSym( "%GraphicsDepth",bbGraphicsDepth );
	rtSym( "%GraphicsHeight",bbGraphicsHeight );
	rtSym( "%GraphicsLost",bbGraphicsLost );
	rtSym( "%GraphicsOpen",bbGraphicsOpen );
	rtSym( "%GraphicsWidth",bbGraphicsWidth );
	rtSym( "HandleImage%image%x%y",bbHandleImage );
	rtSym( "%ImageBuffer%image%frame=0",bbImageBuffer );
	rtSym( "%ImageHeight%image",bbImageHeight );
	rtSym( "%ImageRectCollide%image%x%y%frame%rect_x%rect_y%rect_width%rect_height",bbImageRectCollide );
	rtSym( "%ImageRectOverlap%image%x%y%rect_x%rect_y%rect_width%rect_height",bbImageRectOverlap );
	rtSym( "%ImageWidth%image",bbImageWidth );
	rtSym( "%ImageXHandle%image",bbImageXHandle );
	rtSym( "%ImageYHandle%image",bbImageYHandle );
	rtSym( "%ImagesCollide%image1%x1%y1%frame1%image2%x2%y2%frame2",bbImagesCollide );
	rtSym( "%ImagesOverlap%image1%x1%y1%image2%x2%y2",bbImagesOverlap );
	rtSym( "$Input$prompt=\"\"",bbInput );
	rtSym( "%LoadAnimImage$bmpfile%cellwidth%cellheight%first%count",bbLoadAnimImage );
	rtSym( "%LoadBuffer%buffer$bmpfile",bbLoadBuffer );
	rtSym( "%LoadImage$bmpfile",bbLoadImage );
	rtSym( "Locate%x%y",bbLocate );
	rtSym( "LockBuffer%buffer=0",bbLockBuffer );
	rtSym( "MaskImage%image%red%green%blue",bbMaskImage );
	rtSym( "MidHandle%image",bbMidHandle );
	rtSym( "Print$string=\"\"",bbPrint );
	rtSym( "%ReadPixel%x%y%buffer=0",bbReadPixel );
	rtSym( "%ReadPixelFast%x%y%buffer=0",bbReadPixelFast );
	rtSym( "%RectsOverlap%x1%y1%width1%height1%x2%y2%width2%height2",bbRectsOverlap );
	rtSym( "ResizeImage%image#width#height",bbResizeImage );
	rtSym( "RotateImage%image#angle",bbRotateImage );
	rtSym( "%SaveBuffer%buffer$bmpfile",bbSaveBuffer );
	rtSym( "%SaveImage%image$bmpfile%frame=0",bbSaveImage );
	rtSym( "ScaleImage%image#xscale#yscale",bbScaleImage );
	rtSym( "%ScanLine",bbScanLine );
	rtSym( "SetBuffer%buffer",bbSetBuffer );
	rtSym( "SetGamma%src_red%src_green%src_blue#dest_red#dest_green#dest_blue",bbSetGamma );
	rtSym( "SetGfxDriver%driver",bbSetGfxDriver );
	rtSym( "TFormFilter%enable",bbTFormFilter );
	rtSym( "TFormImage%image#a#b#c#d",bbTFormImage );
	rtSym( "TileBlock%image%x=0%y=0%frame=0",bbTileBlock );
	rtSym( "TileImage%image%x=0%y=0%frame=0",bbTileImage );
	rtSym( "%TotalVidMem",bbTotalVidMem );
	rtSym( "UnlockBuffer%buffer=0",bbUnlockBuffer );
	rtSym( "UpdateGamma%calibrate=0",bbUpdateGamma );
	rtSym( "VWait%frames=1",bbVWait );
	rtSym( "%Windowed3D",bbWindowed3D );
	rtSym( "Write$string",bbWrite );
	rtSym( "WritePixel%x%y%argb%buffer=0",bbWritePixel );
	rtSym( "WritePixelFast%x%y%argb%buffer=0",bbWritePixelFast );
}
#endif
