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
#include <GLUT/glut.h>
#include <math.h>
//#include <stdlib.h>
//#include <stdio.h>
#include <iostream>

//void Init(float width, float height){
//    // model view projection
//    // 物体是在 model 模型空间定义的，---> 使用模型矩阵 将模型放到 世界坐标系中
//    // 视口矩阵，就是将眼睛摆在世界坐标系中
//    // 投影矩阵，眼睛看到的东西如何将其变成2D，就是靠投影矩阵
//
//    glMatrixMode(GL_PROJECTION); // 选中projection矩阵
//    gluPerspective(45.0f, width/height, 0.1f, 1000.0f); // 设置投影矩阵（通过这些参数算出投影矩阵）
//    //
//
//    glMatrixMode(GL_MODELVIEW); // 选中modelview矩阵 (固定管线 将model矩阵和view矩阵合并了)
//    glLoadIdentity(); // 给model矩阵设置为单位矩阵
//
//    // 点 Pos => M*Pos 先将这个点放到世界坐标系
//    // => V*M*Pos 在将这个点给摄像机看
//    // => P*V*M*Pos 在和投影矩阵相乘 形成2D画面
//}

//void Render() {
//    glClearColor(0.1f, 0.4f, 0.7f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glEnable(GL_BLEND); // 开启混合模式
//    glDisable(GL_DEPTH_TEST); // 关闭深度测试
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//    glColor4f(1,0,0,1);
//    glRectf(-0.8,-0.8,0.5,0.5);
//    glColor4f(0, 1, 0, 1);
//    glRectf(-0.5f, -0.5f, 0.8, 0.8);
//    glFinish();
//}

//void Render(){
//    glClear(GL_COLOR_BUFFER_BIT);
//    int i;
//    float Pi = 3.1415926f;
//    glShadeModel(GL_FLAT); // 取消颜色的渐变，改为单一颜色
//    glBegin(GL_TRIANGLE_FAN);
//
//    glColor3f(1.0f, 1.0f, 1.0f); // 设置第一个点的颜色
//    glVertex2f(0.0f, 0.0f);
//
//    for(i = 0; i <= 6; ++i){
//        int red = i & 0x04;
//        int green = i & 0x02;
//        int blue = i & 0x01;
//        glColor3f(red, green, blue); // 设置各个顶点的颜色
//        std::cout << red << " " << green << " " << blue << std::endl;
//        //NSLog("%d, %d, %d", red, green, blue);
//
//        //printf("%d, %d, %d", red, green, blue);
//
//
//        glVertex2f(cos(i * Pi/4), sin(i * Pi/4));
//    }
//
//    glEnd();
//    glFlush();
//}

//void Render(){
//    glClearColor(1, 1, 0.8, 1);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glTranslatef(0.6, 0, 0);
//    glRotatef(45, 0, 0, 1);
//    glScalef(0.5, 0.5, 0.5);
//
//    glLoadIdentity();
//
//    glColor3f(1, 0, 1);
//
//    glBegin(GL_POLYGON);
//    {
//        glVertex2f(-0.4, -0.4);
//        glVertex2f(-0.4, 0.4);
//        glVertex2f(0.4, 0.4);
//        glVertex2f(0.4, -0.4);
//    }
//    glEnd();
//
//    glFlush();
//}

//void Init(float width, float height){
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(60.0, width/height, 4, 10.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(0.0, 0.0, 5.0,
//              0.0, 0.0, 0.0,
//              0.0, 1.0, 0.0);
//}


//void Render() {
//    glClearColor(1, 1, 1, 0);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0, 0, 1.0f); // 画笔蓝色
//    glLoadIdentity();
//    gluLookAt(0.0, 5.0, 0.0, // 相机在世界坐标中的位置
//              0, 0, 0,       // 定义相机正对着的世界坐标系中的点的位置坐标，成像后这一点会位于画板的中心位置
//              1.0, 0.0, 0);  // 定义相机本身的朝向
//    glutWireTeapot(1.3);
//    glutSwapBuffers();
//
//    glFlush();
//}

void RenderBack(){
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
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
//    glBegin(GL_POINTS); // 点 固定管线成像原理==> 先将3D的点映射到2D后，再进行点的扩散，设置点的大小，点是没有近大远小
//    float z = -2.0f;
//    glVertex3f(0.0f, 0.0f, z);
//    glVertex3f(-0.5f, -0.5f, z);
//    glVertex3f(0.0f, -0.5f, z);
//    glVertex3f(0.5f, -0.5f, z);
//    glEnd();
    
//    glBegin(GL_LINES); // 每两个点连成一条线
//    float z = -2.0f;
//    glVertex3f(0.0f, 0.0f, z);
//    glVertex3f(-0.5f, -0.5f, z);
//    glVertex3f(0.0f, -0.5f, z);
//    glVertex3f(0.5f, -0.5f, z);
//    glEnd();
    
//    glBegin(GL_LINE_STRIP); // 将每个点依次连起来
//    float z = -2.0f;
//    glVertex3f(0.0f, 0.0f, z);
//    glVertex3f(-0.5f, -0.5f, z);
//    glVertex3f(0.0f, -0.5f, z);
//    glVertex3f(0.5f, -0.5f, z);
//    glEnd();
    
//    glBegin(GL_LINE_LOOP); // 将每个点依次连成一个闭环
//    float z = -2.0f;
//    glVertex3f(0.0f, 0.0f, z);
//    glVertex3f(-0.5f, -0.5f, z);
//    glVertex3f(0.0f, -0.5f, z);
//    glVertex3f(0.5f, -0.5f, z);
//    glEnd();
    
//    glBegin(GL_QUADS); // 连成四边形
//    float z = -2.0f;
//    glVertex3f(0.0f, 0.0f, z);
//    glVertex3f(-0.5f, -0.5f, z);
//    glVertex3f(0.0f, -0.2f, z);
//    glVertex3f(0.5f, -0.5f, z);
//    glEnd();
    
//    glBegin(GL_QUAD_STRIP);
//    float z = -2.0f;
//    glVertex3f(0.0f, 0.0f, z);
//    glVertex3f(-0.5f, -0.5f, z);
//    glVertex3f(0.0f, -0.2f, z);
//    glVertex3f(0.5f, -0.5f, z);
//    glEnd();
    
    glBegin(GL_POLYGON); // 多边形
    float z = -2.0f;
    glVertex3f(0.0f, 0.0f, z);
    glVertex3f(-0.5f, -0.5f, z);
    glVertex3f(0.0f, -0.2f, z);
    glVertex3f(0.5f, -0.5f, z);
    glEnd();
    
    // 执行上面两句指令，可能保存到glContext上下文指令队列中，不一定到gpu中
    glFlush(); // glFlush 就是将指令队列刷新给gpu，是否执行glFlush它不管
}

void Init(float width, float height){
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, width/height, 0.1f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Render(){
    glClearColor(0.1f, 0.4f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    glLoadIdentity(); // 1. 重置模型视口矩阵
                        //（注：a.最近选中的矩阵是glMatrixMode(GL_MODELVIEW)，在没有选中其他矩阵的时候，后续的操作都是对GL_MODELVIEW操作的；
                        //   b.在这重置了，防止之前有修改过这个矩阵）
    glPointSize(32.0f);
    glEnable(GL_POINT_SMOOTH);
    
    glPushMatrix(); // 压栈 （保存了当前选中的矩阵，压栈出栈可以嵌套）
        glTranslatef(0.0f, 0.0f, -2.0f); // 2. 将模型视口矩阵拉到z=-2.0f位置，后面绘制三角形式就居于这个位置绘制
        
        glBegin(GL_TRIANGLES);
            glColor3ub(255, 255, 0); // 颜色也是在opengl的context里保存的，绘制点的时候，根据opengl状态机，context的颜色的信息绘制点
            glVertex3f(-0.5f, -0.5f, 0.0f);
            glColor3ub(255, 0, 255);
            glVertex3f(0.5f, -0.5f, 0.0f);
            glColor3ub(0, 255, 255);
            glVertex3f(0.0f, 0.5f, 0.0f);
        glEnd();
    glPopMatrix(); // 出栈
    
    // opengl的context里面有projection矩阵和modeview矩阵，每次修改矩阵后，都会修改context的矩阵
    
    glFlush();
}
