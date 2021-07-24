//
//  OGLView.m
//  OGLWindowOSX
//
//  Created by zhaozhenhui on 2021/7/24.
//

#import "OGLView.h"
#include <Opengl/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl3.h>
#include "Scene.h"

static OGLView* sOGLView = nullptr;
@implementation OGLView
+(OGLView*)Instance{
    if(nullptr == sOGLView){
        sOGLView = [OGLView alloc];
        return sOGLView;
    }
    return sOGLView;
}
-(void)InitWithRect:(CGRect)rect{
    NSOpenGLPixelFormatAttribute pixel_format[]={
        NSOpenGLPFAOpenGLProfile,  NSOpenGLProfileVersionLegacy, //NSOpenGLProfileVersion4_1Core,
        NSOpenGLPFAColorSize, 32,
        NSOpenGLPFADepthSize, 24,
        NSOpenGLPFAStencilSize, 8,
        NSOpenGLPFAAlphaSize, 8,
        NSOpenGLPFAAccelerated,
        0
    };
    NSOpenGLPixelFormat* format = [[NSOpenGLPixelFormat alloc] initWithAttributes:pixel_format];
    [self initWithFrame:rect pixelFormat:format];
    [[self openGLContext]makeCurrentContext];

    
    NSLog(@"%s", glGetString(GL_VERSION));
    
    Init(rect.size.width, rect.size.height);
    
}

-(void)drawRect:(NSRect)dirtyRect{
    [super drawRect:dirtyRect];
    
//    glClearColor(0.1f, 0.4f, 0.7f, 1.0f);
//
//    glClear(GL_COLOR_BUFFER_BIT);
//    glFlush();
    Render();
    
    // Drawing code here.
}

@end
