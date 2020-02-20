#ifndef EDGE_H
#define EDGE_H

class Vertex;

class Edge
{
    friend class Vertex;
public:
    Edge(Vertex *BeingCalled) : Called(BeingCalled){};
    Vertex *returnCalled() {return Called;};

private:
    Vertex *Called{nullptr};
};

#endif