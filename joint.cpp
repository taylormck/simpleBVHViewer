#include <stdio.h>
#include <stdint.h>
#include <iostream>

#include "./joint.h"

using namespace std;

// Code for joint class

SceneGraph::Joint::Joint()
: name(NULL), id(0), numChannels(0),  channelFlags(0),
  index(0), jointType(0) {}

SceneGraph::Joint::Joint(const char* _name, uint32_t _id, uint16_t type)
: name(NULL), id(_id), numChannels(0),
  channelFlags(0), index(0), jointType(type) {
  name = new char[sizeof(_name)];
  snprintf(name, strlen(_name) + 1, "%s", _name);
}

SceneGraph::Joint::~Joint() {}

// Code for SceneGraph
SceneGraph::SceneGraph()
: root(0), frames(NULL), addFrameIndex(0), frameSize(0) {}

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
  memcpy(joints[id].offset, offset, 3 * sizeof(*offset));
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
  memcpy(joints[id].channelOrder, order, 6 * sizeof(*order));
}

void SceneGraph::SetFrameIndex(uint32_t id, uint32_t index) {
  cout << "setFrameIndex:id=" << id << " index=" << index << endl;
  joints[id].index = index;
}

void SceneGraph::SetFrameTime(float delta) {
  cout << "setFrameTime:delta=" << delta << endl;
  frameTime = delta;
}

// In case SetNumFrames and SetFrameSize are called in reverse
// order, they both call this function, which then call this function
void SceneGraph::InitFramesArray() {
  if (numFrames > 0 && frameSize > 0) {
    cout << "Attempting to allocate array" << endl;
    frames = new float[numFrames * frameSize];
  }
}

void SceneGraph::SetNumFrames(uint32_t num) {
  cout << "setNumFrames:num=" << num << endl;
  numFrames = num;
  InitFramesArray();
}

void SceneGraph::SetFrameSize(uint32_t size) {
  cout << "setFrameSize:size=" << size << endl;
  frameSize = size;
  InitFramesArray();
}

void SceneGraph::AddFrame(float * data) {
  cout << "addFrame" << endl;
  // array[i][j] == array[i * size + j]
  memcpy(&(frames[addFrameIndex * frameSize]),
      data, frameSize * sizeof(*data));
  addFrameIndex++;
}

void SceneGraph::SetCurrentFrame(uint32_t frameNumber) {
  cout << "setCurrentFrame:frameNumber=" << frameNumber << endl;
  currentFrame = frameNumber;
}
