#pragma once

#include <gsl/gsl>
#include <assimp/scene.h>
#include <assimp/cimport.h>

struct aiUtils {
  static float animation_time(const aiAnimation* animation, float time_in_seconds)
  {
    float time_in_ticks = time_in_seconds * ticks_per_second(animation);
    return fmod(time_in_ticks, (float)animation->mDuration);
  }

  static float ticks_per_second(const aiAnimation* animation)
  {
    return static_cast<float>(animation->mTicksPerSecond != 0 ? animation->mTicksPerSecond : 25.0f);
  }

  static float tick(const aiAnimation* animation, float frames)
  {
    return ticks_per_second(animation) / frames;
  }

  static float max_tick(const aiAnimation* animation)
  {
    return static_cast<float>(animation->mDuration / ticks_per_second(animation));
  }

  static gsl::span<aiNodeAnim*> channels(const aiAnimation* animation)
  {
    return {animation->mChannels, animation->mNumChannels};
  }

  static gsl::span<aiMeshAnim*> mesh_channels(const aiAnimation* animation)
  {
    return {animation->mMeshChannels, animation->mNumMeshChannels};
  }

  static gsl::span<aiAnimMesh*> anim_meshes(const aiMesh* mesh)
  {
    return {mesh->mAnimMeshes, mesh->mNumAnimMeshes};
  }

  static gsl::span<aiBone*> bones(const aiMesh* mesh)
  {
    return {mesh->mBones, mesh->mNumBones};
  }

  static gsl::span<aiFace> faces(const aiMesh* mesh)
  {
    return {mesh->mFaces, mesh->mNumFaces};
  }

  static gsl::span<aiVertexWeight> weights(const aiBone* bone)
  {
    return {bone->mWeights, bone->mNumWeights};
  }

  static gsl::span<unsigned int> indices(const aiFace& face)
  {
    return gsl::span<unsigned int>(face.mIndices, face.mNumIndices);
  }

  static gsl::span<aiNode*> children(const aiNode* scene)
  {
    return {scene->mChildren, scene->mNumChildren};
  }

  static gsl::span<aiAnimation*> animations(const aiScene* scene)
  {
    return {scene->mAnimations, scene->mNumAnimations};
  }

  static gsl::span<aiCamera*> cameras(const aiScene* scene)
  {
    return {scene->mCameras, scene->mNumCameras};
  }

  static gsl::span<aiLight*> lights(const aiScene* scene)
  {
    return {scene->mLights, scene->mNumLights};
  }

  static gsl::span<aiMesh*> meshes(const aiScene* scene)
  {
    return {scene->mMeshes, scene->mNumMeshes};
  }

  static gsl::span<aiVector3D> vertices(const aiMesh* mesh)
  {
    return {mesh->mVertices, mesh->mNumVertices};
  }

  static gsl::span<aiMaterial*> materials(const aiScene* scene)
  {
    return {scene->mMaterials, scene->mNumMaterials};
  }

  static gsl::span<aiTexture*> textures(const aiScene* scene)
  {
    return {scene->mTextures, scene->mNumTextures};
  }
};
