//
//  AppDelegate.m
//  OGLWindowOSX
//
//  Created by zhaozhenhui on 2021/7/24.
//

#import "AppDelegate.h"
#import "OGLMainWindow.h"
#import "OGLView.h"
@interface AppDelegate ()


@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
    NSRect rect = NSMakeRect(0, 0, 1280, 720);
    NSInteger style = NSWindowStyleMaskTitled|NSWindowStyleMaskClosable;
    [[OGLMainWindow Instance]initWithContentRect:rect styleMask:style backing:NSBackingStoreBuffered defer:NO];
    [[OGLView Instance]InitWithRect:[[[OGLMainWindow Instance]contentView]bounds]];
    [[[OGLMainWindow Instance]contentView]addSubview:[OGLView Instance]];
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


@end
