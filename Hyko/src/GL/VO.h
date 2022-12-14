#pragma once

#include <vector>

class VO {
private:
    unsigned int m_VAO;
    unsigned int m_VBO;
    unsigned int m_EBO;
public:
    VO() {
        m_VAO = 0;
        m_VBO = 0;
        m_EBO = 0;
    }

    unsigned int createVertexObjects(std::vector<float> vertices, int verticesCount, std::vector<unsigned int> indices);

    void bind();
    void unBind();

    void deleteVO();

    unsigned int getVAO() { return m_VAO; }

    ~VO();
};