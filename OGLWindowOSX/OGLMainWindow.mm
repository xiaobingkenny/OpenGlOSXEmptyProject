//
//  OGLMainWindow.m
//  OGLWindowOSX
//
//  Created by zhaozhenhui on 2021/7/24.
//

#import "OGLMainWindow.h"

static OGLMainWindow* sOGLMainWindow=nullptr;
@implementation OGLMainWindow
+(OGLMainWindow*)Instance{
    if(nullptr==sOGLMainWindow){
        sOGLMainWindow = [OGLMainWindow alloc];
    }
    return sOGLMainWindow;
}
-(id)initWithContentRect:(NSRect)contentRect styleMask:(NSWindowStyleMask)style backing:(NSBackingStoreType)backingStoreType defer:(BOOL)flag{
    self = [super initWithContentRect:contentRect styleMask:style backing:backingStoreType defer:flag];
    [self setTitle:@"OGLWindowOSX"];
    [self makeKeyAndOrderFront:self];
    [self makeMainWindow];
    return self;
}
@end
