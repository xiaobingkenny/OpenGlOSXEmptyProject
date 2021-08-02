//
//  Model.cpp
//  OGLWindowOSX
//
//  Created by Kenny on 2021/8/3.
//

#include "Model.h"
#include "Utils.h"
#include <vector>
#include <sstream>
#include <string>
#include <string.h>

void Model::Init(const char *path){
    int filesize = 0;
    unsigned char* fileContent = LoadFileContent(path, filesize);
    
    struct FloatData{
        float v[3];
    };
    
    // 定义点
    struct VertexDefine{
        int position_index;
        int texcoord_index;
        int normal_index;
    };
    
    std::vector<FloatData> position, texcoords, normals;
    std::vector<VertexDefine> vertexes;
    std::vector<int> indexes;
    
    std::stringstream ssFileContent((char*)fileContent);
    std::string temp;
    
    char szOneLine[256];
    while(!ssFileContent.eof()){
        memset(szOneLine, 0, 256);
        ssFileContent.getline(szOneLine, 256);
        if(strlen(szOneLine) > 0){
            if(szOneLine[0] == 'v'){
                std::stringstream ssOneLine(szOneLine);
                if(szOneLine[1] == 't'){ // 纹理坐标
                    ssOneLine>>temp;
                    
                    FloatData fd;
                    ssOneLine>>fd.v[0];
                    ssOneLine>>fd.v[1];
                    
                    texcoords.push_back(fd);
                }else if(szOneLine[1] == 'n'){ // 法线
                    ssOneLine>>temp;
                    
                    FloatData fd;
                    ssOneLine>>fd.v[0];
                    ssOneLine>>fd.v[1];
                    ssOneLine>>fd.v[2];
                    
                    normals.push_back(fd);
                }else { // 位置
                    ssOneLine>>temp;
                    
                    FloatData fd;
                    ssOneLine>>fd.v[0];
                    ssOneLine>>fd.v[1];
                    ssOneLine>>fd.v[2];
                    
                    position.push_back(fd);
                }
            }else if(szOneLine[0] == 'f'){
                std::stringstream ssOneLine(szOneLine);
                ssOneLine>>temp;
                std::string tempStr;
                for (int i = 0; i < 3; i++) {
                    ssOneLine>>tempStr;
                    size_t pos = tempStr.find_first_of('/');
                    std::string pos_index_str = tempStr.substr(0, pos);
                    
                    size_t pos2 = tempStr.find_first_of('/', pos + 1);
                    std::string texcoord_index_str = tempStr.substr(pos + 1, pos2 - 1 - pos);
                    
                    std::string normal_index_str = tempStr.substr(pos2 + 1, tempStr.length() - 1 - pos2);
                    
                    VertexDefine vd;
                    vd.position_index = atoi(pos_index_str.c_str()) - 1;
                    vd.texcoord_index = atoi(texcoord_index_str.c_str()) - 1;
                    vd.normal_index = atoi(normal_index_str.c_str()) - 1;
                    
                    int nCurrentVertexIndex = -1;
                    int nCurrentVertexCount = (int)vertexes.size();
                    
                    for (int j = 0; j < nCurrentVertexCount; j++) {
                        if(vertexes[j].position_index == vd.position_index &&
                           vertexes[j].texcoord_index == vd.texcoord_index &&
                           vertexes[j].normal_index == vd.normal_index){
                            nCurrentVertexIndex = j;
                            break;
                        }
                    }
                    
                    if(nCurrentVertexIndex == -1){
                        nCurrentVertexIndex = nCurrentVertexCount;
                        vertexes.push_back(vd);
                    }
                    indexes.push_back(nCurrentVertexIndex);
                }
            }
        }
    }
    
    delete [] fileContent;
    
    mIndexCount = indexes.size();
    mIndexes = new unsigned int[mIndexCount];
    
    for (int i = 0; i < mIndexCount; i++) {
        mIndexes[i] = indexes[i];
        
        printf("%d : %d\n", i, mIndexes[i]);
    }
    
    int vertex_count = vertexes.size();
    mVertexes = new VertexData[vertex_count];
    
    for (int i = 0; i < vertex_count; i++) {
        memcpy(mVertexes[i].mPosition, position[vertexes[i].position_index].v, sizeof(float) * 3);
        memcpy(mVertexes[i].mTexcoord, texcoords[vertexes[i].texcoord_index].v, sizeof(float) * 3);
        memcpy(mVertexes[i].mNormal, normals[vertexes[i].normal_index].v, sizeof(float) * 3);
        
        printf("%d : %f, %f, %f\n", i, mVertexes[i].mPosition[0], mVertexes[i].mPosition[1], mVertexes[i].mPosition[2]);
    }
}

void Model::Draw(){
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < mIndexCount; i++) {
        
        int index = mIndexes[i];
        glTexCoord2f(mVertexes[index].mTexcoord[0], mVertexes[index].mTexcoord[1]);
        printf("%d : %f %f\n", i, mVertexes[index].mTexcoord[0], mVertexes[index].mTexcoord[1]);
        glNormal3fv(mVertexes[index].mNormal);
        glVertex3fv(mVertexes[index].mPosition);
    }
    glEnd();
}
