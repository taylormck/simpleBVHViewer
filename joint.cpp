#include <stdint.h>
#include <iostream>

#include "./joint.h"

using namespace std;

// Code for joint class

SceneGraph::Joint::Joint()
  : name(NULL), id(0), numChannels(0),  channelFlags(0),
    index(0), jointType(0) {}

SceneGraph::Joint::Joint(const char* _name, uint32_t _id, uint16_t type)
  : name(NULL), id(_id), numChannels(0), channelOrder(NULL),
    channelFlags(0), index(0), jointType(type) {
  name = new char[sizeof(_name)];
  //  Couldn't use strcpy() because the check-code was complaining
  memcpy(name, _name, sizeof(_name));
}

SceneGraph::Joint::~Joint() {}

// Code for SceneGraph
SceneGraph::SceneGraph()
  : root(0) {}

SceneGraph::~SceneGraph() {
  joints.clear();
}

void SceneGraph::CreateRoot(const char * name, uint32_t id) {
  cout << "createRoot:name=" << name << " id=" << id << endl;
  root = id;
  joints[id] = Joint(name, id, BVH_ROOT);
}

void SceneGraph::CreateJoint(const char * name, uint32_t id) {
  cout << "createJoint:name=" << name << " id=" << id << endl;
  joints[id] = Joint(name, id, BVH_JOINT);
}

void SceneGraph::CreateEndSite(const char * name, uint32_t id) {
  cout << "createEndSite:name=" << name << " id=" << id;
  joints[id] = Joint(name, id, BVH_END_SITE);
}

void SceneGraph::SetChild(uint32_t parent, uint32_t child) {
  cout << "setChild:parent=" << parent << " child=" << child << endl;
  joints[parent].children.push_back(child);
}

void SceneGraph::SetOffset(uint32_t id, float * offset) {
  cout << "setOffset:id=" << id << " offset=(" << offset[0] << ","
       << offset[1]<< "," << offset[2] << ")" << endl;
  if(joints[id].offset == NULL){
    joints[id].offset = malloc(3 * sizeof(float));
  }
  memcpy(joints[id].offset, offset, 3 * sizeof(float));
}

void SceneGraph::SetNumChannels(uint32_t id, uint16_t num) {
  cout << "setNumChannels:id=" << id << " num=" << num << endl;
  joints[id].numChannels = num;
}

void SceneGraph::SetChannelFlags(uint32_t id, uint16_t flags) {
  cout << "setChannelFlags:id=" << id << " flags=" << flags << endl;
  joints[id].channelFlags = flags;
}

void SceneGraph::SetChannelOrder(uint32_t id, int * order) {
  cout  << "setChannelOrder:id=" << id << endl;
  memcpy(joints[id].channelOrder, order, 6 * sizeof(int));
}

void SceneGraph::SetFrameIndex(uint32_t id, uint32_t index) {
  cout << "setFrameIndex:id=" << id << " index=" << index << endl;
  joints[id].index = index;
}

void SceneGraph::SetFrameTime(float delta) {
  cout << "setFrameTime:delta=" << delta << endl;
  frameTime = delta;
}

void SceneGraph::SetNumFrames(uint32_t num) {
  cout << "setNumFrames:num=" << num << endl;
  numFrames = num;
}

void SceneGraph::SetFrameSize(uint32_t size) {
  cout << "setFrameSize:size=" << size << endl;
  frameSize = size;
}

void SceneGraph::AddFrame(float * data) {
  cout << "addFrame" << endl;
  frames.push_back(*data);
}

void SceneGraph::SetCurrentFrame(uint32_t frameNumber) {
  cout << "setCurrentFrame:frameNumber=" << frameNumber << endl;
  currentFrame = frameNumber;
}
