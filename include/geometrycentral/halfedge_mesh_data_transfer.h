#pragma once

// Transfer data between halfedge meshes after a mesh.copy()
// (so we assume exactly discrete correspondence)
// Don't make this yourself; the maps get populated when you call
// HalfedgeMesh::copy();

#include <unordered_map>

namespace geometrycentral {

class HalfedgeMeshDataTransfer {

public:

  HalfedgeMeshDataTransfer();
  HalfedgeMeshDataTransfer(HalfedgeMesh* oldMesh, HalfedgeMesh* newMesh);
  
  // Transfer data
  template<class T> VertexData<T> transfer(VertexData<T>& inData);
  template<class T> FaceData<T> transfer(FaceData<T>& inData);
  template<class T> EdgeData<T> transfer(EdgeData<T>& inData);
  template<class T> HalfedgeData<T> transfer(HalfedgeData<T>& inData);
  template<class T> CornerData<T> transfer(CornerData<T>& inData);

  // Maps to transfer data map[oldPtr] --> newPtr
  HalfedgeData<HalfedgePtr> heMap;
  VertexData<VertexPtr> vMap;
  EdgeData<EdgePtr> eMap;
  FaceData<FacePtr> fMap;

  // Relevant meshes
  HalfedgeMesh* oldMesh = nullptr;
  HalfedgeMesh* newMesh = nullptr;
};

}  // namespace geometrycentral