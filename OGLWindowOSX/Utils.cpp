//
//  Utils.cpp
//  OGLWindowOSX
//
//  Created by Kenny on 2021/7/30.
//

#include "Utils.h"
#include <string.h>

unsigned char* DecodeBMP(unsigned char* bmpFile, int &width, int &height){
//    if(0x4d42 == *((unsigned short*)bmpFile)){
//        printf("I am a bmp\n");
//    }
    if(memcmp(bmpFile, "BM", 2) == 0){
        printf("I am a bmp\n");
        int pixel_bgr_data_offset = *((int*)(bmpFile + 10));
        width = *((int*)(bmpFile+18));
        height = *((int*)(bmpFile+22));
        
        unsigned char* bgr_data = bmpFile + pixel_bgr_data_offset;
        
        // bgr->rgb
        for (int i=0; i<width*height; i++) {
            int current_pixel_index = i*3;
            unsigned char b = bgr_data[current_pixel_index];
            //unsigned char g = bgr_data[current_pixel_index + 1];
            unsigned char r = bgr_data[current_pixel_index + 2];
            
            bgr_data[current_pixel_index] = r;
            bgr_data[current_pixel_index + 2] = b;
        }
        return bgr_data;
    }
    return nullptr;
}

GLuint CreateTexture(unsigned char* pixeldata, int width, int height, GLenum type){
    GLuint texture;
    glGenTextures(1, &texture); // gpu将资源标记为一个编号
    glBindTexture(GL_TEXTURE_2D, texture); // 设置Opengl的context中的当前纹理
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 设置当前纹理的
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, pixeldata);
    glBindTexture(GL_TEXTURE_2D, 0); // 设置为0号纹理，防止其他地方改动我们自己的纹理texture的数据（一般0号纹理没人用）
    return texture;
}
