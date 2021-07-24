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
    // model view projection
    // 物体是在 model 模型空间定义的，---> 使用模型矩阵 将模型放到 世界坐标系中
    // 视口矩阵，就是将眼睛摆在世界坐标系中
    // 投影矩阵，眼睛看到的东西如何将其变成2D，就是靠投影矩阵
    
    glMatrixMode(GL_PROJECTION); // 选中projection矩阵
    gluPerspective(45.0f, width/height, 0.1f, 1000.0f); // 设置投影矩阵（通过这些参数算出投影矩阵）
    //
    
    glMatrixMode(GL_MODELVIEW); // 选中modelview矩阵 (固定管线 将model矩阵和view矩阵合并了)
    glLoadIdentity(); // 给model矩阵设置为单位矩阵
    
    // 点 Pos => M*Pos 先将这个点放到世界坐标系
    // => V*M*Pos 在将这个点给摄像机看
    // => P*V*M*Pos 在和投影矩阵相乘 形成2D画面
}

void Render(){
    // ^ + i // 格式化
    glClearColor(0.1f, 0.4f, 0.7f, 1.0f); // 设置擦除gpu中的颜色缓冲区的颜色 （gpu缓冲区：颜色，深度，蒙版缓冲区）
    
    glClear(GL_COLOR_BUFFER_BIT); // 颜色缓冲区: GL_COLOR_BUFFER_BIT  深度缓冲区: GL_DEPTH_BUFFER_BIT（擦除深度缓冲区也有个默认的值） 蒙版缓冲区：GL_STENCIL_BUFFER_BIT （擦除蒙版缓冲区也有个默认的值）
    
    // 执行上面两句指令，可能保存到glContext上下文指令队列中，不一定到gpu中
    glFlush(); // glFlush 就是将指令队列刷新给gpu，是否执行glFlush它不管
}
