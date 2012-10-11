#include <stdio.h>
#include <stdint.h>
#include <iostream>

#include "./joint.h"

using namespace std;

SceneGraph::Joint::Joint()
: id(0), parent(0), numchans(0), chanflags(0), index(0) {}

// Code for SceneGraph
SceneGraph::SceneGraph()
: root(0), frames(NULL), addFrameIndex(0), frameSize(0) , numFrames(0) {}

SceneGraph::~SceneGraph() {
  delete[] frames;
}

void SceneGraph::CreateJoint(const char* name, uint32_t _id, unsigned char t) {
  Joint joint;
  joint.type = t;
  joint.id = _id;
  // check-code complains when I try sizeof(int) or sizeof(float)
  int x;
  float y;
  memset(joint.order, 0, 6 * sizeof(x));
  memset(joint.offset, 0, 3 * sizeof(y));
  joint.name = new char[strlen(name) + 1];
  memcpy(joint.name, name, strlen(name) + 1);

  joints.push_back(joint);
}

void SceneGraph::CreateRoot(const char * name, uint32_t id) {
  CreateJoint(name, id, 0);
}

void SceneGraph::CreateJoint(const char * name, uint32_t id) {
  CreateJoint(name, id, 1);
}

void SceneGraph::CreateEndSite(const char * name, uint32_t id) {
  CreateJoint(name, id, 2);
}

void SceneGraph::SetChild(uint32_t parent, uint32_t child) {
  joints[child].parent = parent;
  joints[parent].children.push_back(child);
}

void SceneGraph::SetOffset(uint32_t id, float * offset) {
  memcpy(joints[id].offset, offset, 3 * sizeof(*offset));
}

void SceneGraph::SetNumChannels(uint32_t id, uint16_t num) {
  joints[id].numchans = num;
}

void SceneGraph::SetChannelFlags(uint32_t id, uint16_t flags) {
  joints[id].chanflags = flags;
}

void SceneGraph::SetChannelOrder(uint32_t id, int * order) {
  memcpy(joints[id].order, order, 6 * sizeof(*order));
}

void SceneGraph::SetFrameIndex(uint32_t id, uint32_t index) {
  joints[id].index = index;
}

void SceneGraph::SetFrameTime(float delta) {
  frameTime = delta;
}

// In case SetNumFrames and SetFrameSize are called in reverse
// order, they both call this function, which then call this function
void SceneGraph::InitFramesArray() {
  if (numFrames > 0 && frameSize > 0) {
    frames = new float[numFrames * frameSize];
  }
}

void SceneGraph::SetNumFrames(uint32_t num) {
  numFrames = num;
  InitFramesArray();
}

void SceneGraph::SetFrameSize(uint32_t size) {
  frameSize = size;
  InitFramesArray();
}

void SceneGraph::AddFrame(float * data) {
  memcpy(&(frames[addFrameIndex * frameSize]),
      data, frameSize * sizeof(*data));
  addFrameIndex++;
}

void SceneGraph::SetCurrentFrame(uint32_t frameNumber) {
  currentFrame = frameNumber;
}

void SceneGraph::nextFrame() {
  currentFrame++;
  if (currentFrame == numFrames) {
    currentFrame = 0;
  }
}
