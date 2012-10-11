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
    struct Joint {
      unsigned char type;  // 0=root, 1=joint, 2=end site
      uint32_t id;
      char* name;
      uint32_t parent;
      uint16_t numchans;
      ushort chanflags;
      int order[6];
      float offset[3];
      uint32_t index;
      vector<uint32_t> children;

      Joint();
    };

    uint32_t root;
    vector<Joint> joints;
    float* frames;
    float frameTime;
    uint32_t numFrames;
    uint32_t frameSize;
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

    void nextFrame();

    void clear();

  private:
    int addFrameIndex;

    void InitFramesArray();
    void CreateJoint(const char*, uint32_t, unsigned char);
};


#endif

