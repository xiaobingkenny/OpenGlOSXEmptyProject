//
//  main.m
//  OGLWindowOSX
//
//  Created by zhaozhenhui on 2021/7/24.
//

#import <Cocoa/Cocoa.h>
#import "AppDelegate.h"

int main(int argc, const char * argv[]) {
    NSApplication* app = [NSApplication sharedApplication];
    [app setDelegate:[[AppDelegate alloc]init] ];
    [NSApp run];
    return 0;
}
