
#include "../../stdutil/stdutil.h"
#include "runtime.html.h"

#include <bb/blitz2d.gles2/blitz2d.gles2.h>
#include <bb/blitz3d.gles2/blitz3d.gles2.h>

class Canvas : public GLES2B2DDefaultCanvas{
public:
	Canvas( int mode,int flags ):GLES2B2DDefaultCanvas(mode,flags){
	}

	int getWidth()const{
		return 1280;
	}

	int getHeight()const{
		return 768;
	}

	void getViewport( int *x,int *y,int *w,int *h )const{
		*x=0;*y=0;*w=getWidth();*h=getHeight();
	}
};


class HtmlRuntime : public BBRuntime, public BBContextDriver, public GLES2B3DGraphics, public B2DGraphics{
public:
	HtmlRuntime(){
		front_canvas=d_new Canvas( 0,0 );
		back_canvas=d_new Canvas( 0,0 );

		bbContextDriver=this;
		bbSceneDriver=this;
	}

	// context

	int numGraphicsDrivers(){
		return 1;
	}
	void graphicsDriverInfo( int driver,std::string *name,int *c ){
	}

	int numGraphicsModes( int driver ){
		return 1;
	}

	void graphicsModeInfo( int driver,int mode,int *w,int *h,int *d,int *c ){
	}

	void windowedModeInfo( int *c ){
	}

	BBGraphics *openGraphics( int w,int h,int d,int driver,int flags ){
		return this;
	}

	void closeGraphics( BBGraphics *graphics ){
	}

	bool graphicsLost(){
		return false;
	}

	void flip( bool vwait ){
	}

	// graphics

	void backup(){
	}
	bool restore(){
	}

	//MANIPULATORS
	void vwait(){
	}

	//SPECIAL!
	void copy( BBCanvas *dest,int dx,int dy,int dw,int dh,BBCanvas *src,int sx,int sy,int sw,int sh ){
	}

	//NEW! Gamma control!
	void setGamma( int r,int g,int b,float dr,float dg,float db ){
	}
	void getGamma( int r,int g,int b,float *dr,float *dg,float *db ){
	}
	void updateGamma( bool calibrate ){
	}

	//ACCESSORS
	int getWidth()const{
		return 0;
	}
	int getHeight()const{
		return 0;
	}
	int getDepth()const{
		return 0;
	}
	int getScanLine()const{
		return 0;
	}
	int getAvailVidmem()const{
		return 0;
	}
	int getTotalVidmem()const{
		return 0;
	}

	BBFont *getDefaultFont()const{
		return 0;
	}

	//OBJECTS
	BBCanvas *createCanvas( int width,int height,int flags ){
		return 0;
	}
	BBCanvas *loadCanvas( const std::string &file,int flags ){
		return 0;
	}


	// b2dgraphics

	BBMovie *openMovie( const std::string &file,int flags ){
		return 0;
	}
	BBMovie *verifyMovie( BBMovie *movie ){
		return 0;
	}
	void closeMovie( BBMovie *movie ){
	}

	BBFont *loadFont( const std::string &font,int height,int flags ){
		return 0;
	}
	BBFont *verifyFont( BBFont *font ){
		return 0;
	}
	void freeFont( BBFont *font ){
	}

	// runtime

	void asyncStop(){}
	void asyncRun(){}
	void asyncEnd(){}

	bool idle(){ return true; }

	void *window(){ return 0; }

	void moveMouse( int x,int y ){}
	void setPointerVisible( bool vis ){}
};

BBRuntime *bbCreateHTMLRuntime(){
	return d_new HtmlRuntime();
}

// TODO: find a more sensible approach...
BBRuntime *bbCreateOpenGLRuntime() {
	return bbCreateHTMLRuntime();
}

BBMODULE_CREATE( runtime_html ){
	return true;
}

BBMODULE_DESTROY( runtime_html ){
	return true;
}
