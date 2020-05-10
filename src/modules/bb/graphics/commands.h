#ifndef BB_GRAPHICS_COMMANDS_H
#define BB_GRAPHICS_COMMANDS_H

#include <bb/blitz/commands.h>

#ifdef __cplusplus
class BBCanvas;
class bbImage;
extern "C" {
#else
typedef void BBCanvas;
typedef void bbImage;
#endif

//general graphics functions
int		 BBCALL bbCountGfxDrivers();
BBStr *	 BBCALL bbGfxDriverName( int n );
BBStr *	 BBCALL bbGfxDriverDesc( int n );
void	 BBCALL bbSetGfxDriver( int n );
int		 BBCALL bbGfxModeExists( int w,int h,int d );
int		 BBCALL bbGfxDriver3D( int n );
int		 BBCALL bbCountGfxModes3D();
int		 BBCALL bbGfxMode3DExists( int w,int h,int d );
int		 BBCALL bbGfxMode3D( int n );
int		 BBCALL bbWindowed3D();
int		 BBCALL bbCountGfxModes();
int		 BBCALL bbGfxModeWidth( int n );
int		 BBCALL bbGfxModeHeight( int n );
int		 BBCALL bbGfxModeDepth( int n );
int		 BBCALL bbGraphicsWidth();
int		 BBCALL bbGraphicsHeight();
int		 BBCALL bbGraphicsDepth();
int		 BBCALL bbAvailVidMem();
int		 BBCALL bbTotalVidMem();

//mode functions
void	 BBCALL bbGraphics( int w,int h,int d,int mode );
void	 BBCALL bbGraphics3D( int w,int h,int d,int mode );
BBCanvas * BBCALL bbFrontBuffer();
BBCanvas * BBCALL bbBackBuffer();
void	 BBCALL bbEndGraphics();
int		 BBCALL bbGraphicsLost();
int		 BBCALL bbGraphicsOpen();
void	 BBCALL bbSetGamma( int r,int g,int b,float dr,float dg,float db );
void	 BBCALL bbUpdateGamma( int calibrate );
float	 BBCALL bbGammaRed( int n );
float	 BBCALL bbGammaGreen( int n );
float	 BBCALL bbGammaBlue( int n );
void	 BBCALL bbCopyPixel( int src_x,int src_y,BBCanvas *src,int dest_x,int dest_y,BBCanvas *buff );
void	 BBCALL bbCopyPixelFast( int src_x,int src_y,BBCanvas *src,int dest_x,int dest_y,BBCanvas *buff );
int		 BBCALL bbScanLine();
void	 BBCALL bbVWait( int n );
void	 BBCALL bbFlip( int vwait );

//graphics buffer functions
void	 BBCALL bbSetBuffer( BBCanvas *buff );
BBCanvas * BBCALL bbGraphicsBuffer();
int		 BBCALL bbLoadBuffer( BBCanvas *surf,BBStr *str );
int		 BBCALL bbSaveBuffer( BBCanvas *surf,BBStr *str );
void	 BBCALL bbBufferDirty( BBCanvas *c );


//fast read/write operations...
void	 BBCALL bbLockBuffer( BBCanvas *buff );
void	 BBCALL bbUnlockBuffer( BBCanvas *buff );
int		 BBCALL bbReadPixel( int x,int y,BBCanvas *buff );
void	 BBCALL bbWritePixel( int x,int y,int argb,BBCanvas *buff );
int		 BBCALL bbReadPixelFast( int x,int y,BBCanvas *buff );
void	 BBCALL bbWritePixelFast( int x,int y,int argb,BBCanvas *buff );
void	 BBCALL bbCopyRect( int sx,int sy,int w,int h,int dx,int dy,BBCanvas *src,BBCanvas *dest );

//image functions
bbImage* BBCALL bbLoadImage( BBStr *s );
bbImage* BBCALL bbCopyImage( bbImage *i );
bbImage* BBCALL bbCreateImage( int w,int h,int n );
bbImage* BBCALL bbLoadAnimImage( BBStr *s,int w,int h,int first,int cnt );
void	 BBCALL bbFreeImage( bbImage *i );
int		 BBCALL bbSaveImage( bbImage *i,BBStr *filename,int frame );
void	 BBCALL bbGrabImage( bbImage *i,int x,int y,int n );
BBCanvas * BBCALL bbImageBuffer( bbImage *i,int n );
void	 BBCALL bbDrawImage( bbImage *i,int x,int y,int frame );
void	 BBCALL bbDrawBlock( bbImage *i,int x,int y,int frame );
void	 BBCALL bbTileImage( bbImage *i,int x,int y,int frame );
void	 BBCALL bbTileBlock( bbImage *i,int x,int y,int frame );
void	 BBCALL bbDrawImageRect( bbImage *i,int x,int y,int r_x,int r_y,int r_w,int r_h,int frame );
void	 BBCALL bbDrawBlockRect( bbImage *i,int x,int y,int r_x,int r_y,int r_w,int r_h,int frame );
void	 BBCALL bbMaskImage( bbImage *i,int r,int g,int b );
void	 BBCALL bbHandleImage( bbImage *i,int x,int y );
void	 BBCALL bbScaleImage( bbImage *i,float w,float h );
void	 BBCALL bbResizeImage( bbImage *i,float w,float h );
void	 BBCALL bbRotateImage( bbImage *i,float angle );
void	 BBCALL bbTFormImage( bbImage *i,float a,float b,float c,float d );
void	 BBCALL bbTFormFilter( int enable );
void	 BBCALL bbAutoMidHandle( int enable );
void	 BBCALL bbMidHandle( bbImage *i );
int		 BBCALL bbImageWidth( bbImage *i );
int		 BBCALL bbImageHeight( bbImage *i );
int		 BBCALL bbImageXHandle( bbImage *i );
int		 BBCALL bbImageYHandle( bbImage *i );
int		 BBCALL bbImagesOverlap( bbImage *i1,int x1,int y1,bbImage *i2,int x2,int y2 );
int		 BBCALL bbImagesCollide( bbImage *i1,int x1,int y1,int f1,bbImage *i2,int x2,int y2,int f2 );
int		 BBCALL bbRectsOverlap( int x1,int y1,int w1,int h1,int x2,int y2,int w2,int h2 );
int		 BBCALL bbImageRectOverlap( bbImage *i,int x,int y,int r_x,int r_y,int r_w,int r_h );
int		 BBCALL bbImageRectCollide( bbImage *i,int x,int y,int f,int r_x,int r_y,int r_w,int r_h );

//simple print functions
void	 BBCALL bbWrite( BBStr *str );
void	 BBCALL bbPrint( BBStr *str );
BBStr *	 BBCALL bbInput( BBStr *prompt );
void	 BBCALL bbLocate( int x,int y );

#ifdef __cplusplus
}
#endif

#endif
