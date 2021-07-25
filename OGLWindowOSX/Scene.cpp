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
    
//    glEnable(GL_CULL_FACE);// 反面剔除
//    glFrontFace(GL_CW); // 设置顺时针是正面（默认逆时针 GL_CCW）
    
//    glBegin(GL_TRIANGLES); // 开始绘制三角形了,下面指定每三个点绘制成三角形
//    // 默认情况下摄像机是从{0, 0, 0} 看向{0, 0, -1}的，
//    // 而视椎体 z轴的范围：0.1-> (-1000 + 0.1) 所以下面的z坐标需要给小于0.1的值(如-0.5f，-1.5f)
//    float z = -1.5f;
//    // opengl默认逆时针是正面，如果OpenGL开启反面剔除，顺时针的反面，就绘制不出来了
//    glVertex3f(-0.5f, -0.5f, z);
//    glVertex3f(0.5f, -0.5f, z);
//    glVertex3f(0.0f, 0.5f, z);
//
////    glVertex3f(-0.5f+0.2f, -0.5f, z);
////    glVertex3f(0.5f+0.2f, -0.5f, z);
////    glVertex3f(0.0f+0.2f, 0.5f, z);
//
//    glEnd();
    
    glPolygonMode(GL_FRONT, GL_LINE); // 启用线框模式GL_LINE 不是GL_LINES , GL_FILL填充模式
    
//    glBegin(GL_TRIANGLE_STRIP);// 三角条 用于绘制四边形
//    float z = -2.0f;
//    glVertex3f(-0.5f, -0.5f, z);
//    glVertex3f(0.5f, -0.5f, z);
//    glVertex3f(-0.5f, 0.5f, z);
//    glVertex3f(0.5f, 0.5f, z);
//
//    glVertex3f(-0.5f, 0.6f, z);
//    glVertex3f(0.5f, 0.7f, z);
//    glEnd();
    
//    glBegin(GL_TRIANGLE_FAN); // 扇
//    float z = -2.0f;
//    glVertex3f(0.0f, 0.0f, z); // 扇心
//
//    glVertex3f(-0.5f, -0.5f, z);
//    glVertex3f(0.0f, -0.5f, z);
//    glVertex3f(0.5f, -0.5f, z);
//    glEnd();
    
    glPointSize(32.0f); // 2D的长32，宽32 （这个点要求（厂商最大值 最小必须是64），所以设置1000.0f 也不会很大）
    glEnable(GL_POINT_SMOOTH); // 绘制圆点
    
    glBegin(GL_POINTS); // 点 固定管线成像原理==> 先将3D的点映射到2D后，再设置点的大小
    float z = -2.0f;
    glVertex3f(0.0f, 0.0f, z);
    glVertex3f(-0.5f, -0.5f, z);
    glVertex3f(0.0f, -0.5f, z);
    glVertex3f(0.5f, -0.5f, z);
    glEnd();
    
    // 执行上面两句指令，可能保存到glContext上下文指令队列中，不一定到gpu中
    glFlush(); // glFlush 就是将指令队列刷新给gpu，是否执行glFlush它不管
}
