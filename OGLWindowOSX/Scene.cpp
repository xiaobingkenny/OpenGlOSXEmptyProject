//
//  Scene.cpp
//  OGLWindowOSX
//
//  Created by zhaozhenhui on 2021/7/25.
//

#include "Scene.h"
#include <Opengl/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl3.h>

void Init(float width, float height){
    
}

void Render(){
    // ^ + i // 格式化
    glClearColor(0.1f, 0.4f, 0.7f, 1.0f); // 设置擦除gpu中的颜色缓冲区的颜色 （gpu缓冲区：颜色，深度，蒙版缓冲区）
    
    glClear(GL_COLOR_BUFFER_BIT); // 颜色缓冲区: GL_COLOR_BUFFER_BIT  深度缓冲区: GL_DEPTH_BUFFER_BIT（擦除深度缓冲区也有个默认的值） 蒙版缓冲区：GL_STENCIL_BUFFER_BIT （擦除蒙版缓冲区也有个默认的值）
    
    // 执行上面两句指令，可能保存到glContext上下文指令队列中，不一定到gpu中
    glFlush(); // glFlush 就是将指令队列刷新给gpu，是否执行glFlush它不管
}
