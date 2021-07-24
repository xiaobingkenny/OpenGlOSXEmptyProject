//
//  OGLView.h
//  OGLWindowOSX
//
//  Created by zhaozhenhui on 2021/7/24.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface OGLView : NSOpenGLView
+(OGLView*)Instance;
-(void)InitWithRect:(CGRect)rect;

@end

NS_ASSUME_NONNULL_END
