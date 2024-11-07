#include "Node.h"
#include <cstring>

Node::Node(const char* songName) {
    strcpy(this->song, songName);
    next = nullptr;
    prev = nullptr;
}
