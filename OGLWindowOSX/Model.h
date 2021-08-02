//
//  Model.hpp
//  OGLWindowOSX
//
//  Created by Kenny on 2021/8/3.
//

#ifndef Model_hpp
#define Model_hpp

#include <stdio.h>

// 点
struct VertexData{
    float mPosition[3]; // 位置
    float mTexcoord[2];
    float mNormal[3];
};

class Model{
public:
    VertexData* mVertexes;
    unsigned int *mIndexes;
    int mIndexCount;
    
    void Init(const char* path);
    void Draw();
};

#endif /* Model_hpp */
