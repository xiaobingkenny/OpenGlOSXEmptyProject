//
//  Utils.hpp
//  OGLWindowOSX
//
//  Created by Kenny on 2021/7/30.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>


unsigned char* LoadFileContent(const char* path, int &filesize);
unsigned char* DecodeBMP(unsigned char* bmpFile, int &width, int &height);

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl3.h>
GLuint CreateTexture(unsigned char* pixeldata, int width, int height, GLenum type);

#endif /* Utils_hpp */
