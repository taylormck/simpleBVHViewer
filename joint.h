#ifndef __JOINT_H__
#define __JOINT_H__

#include <vector>
#include <cstring>
#include <map>

#include "./bvh_defs.h"
#include "./vec.h"

using namespace std;

class SceneGraph {
  public:
    // I decided to make everything public so I can access it from
    // the main.
    // It's not the "right" way to do it, but it's a small
    // project and I'd like to keep it simple
    struct Joint {
      char* name;
      Joint* parent;
      vector<uint32_t> children;
      uint32_t id;
      float offset[3];
      uint16_t jointType;
      uint16_t numChannels;
      int channelOrder[6];
      uint16_t channelFlags;
      uint32_t index;

      Joint();
      Joint(const char* _name, uint32_t _id, uint16_t type);
      ~Joint();
    };

    uint32_t root;
    map<uint32_t, Joint> joints;
    float frameTime;
    uint32_t numFrames;
    uint32_t frameSize;
    vector<float*> frames;
    uint32_t currentFrame;
    SceneGraph();
    ~SceneGraph();

    void CreateRoot(const char * name, uint32_t id);
    void CreateJoint(const char * name, uint32_t id);
    void CreateEndSite(const char * name, uint32_t id);
    void SetChild(uint32_t parent, uint32_t child);
    void SetOffset(uint32_t id, float * offset);
    void SetNumChannels(uint32_t id, uint16_t num);
    void SetChannelFlags(uint32_t id, uint16_t flags);
    void SetChannelOrder(uint32_t id, int * order);
    void SetFrameIndex(uint32_t id, uint32_t index);
    void SetFrameTime(float delta);
    void SetNumFrames(uint32_t num);
    void SetFrameSize(uint32_t size);
    void AddFrame(float * data);
    void SetCurrentFrame(uint32_t frameNumber);
};


#endif

