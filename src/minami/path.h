#ifndef PATH_H
#define PATH_H

#include "Snap.h"
#include "factory.h"
#include "shortest_path.h"

#include <vector>
#include <map>
#include <fstream>
#include <string>

class MNM_Path
{
public:
  MNM_Path();
  ~MNM_Path();
  std::string node_vec_to_string();
  std::vector<TInt> m_link_vec;
  std::vector<TInt> m_node_vec;
  inline bool operator==(const MNM_Path& rhs)
  {if (m_link_vec.size() != rhs.m_link_vec.size()) return false; 
  for (size_t i=0; i<rhs.m_link_vec.size(); ++i){if (rhs.m_link_vec[i] != m_link_vec[i]) return false;} return true;}
};



class MNM_Pathset
{
public:
  MNM_Pathset();
  ~MNM_Pathset();
  std::vector<MNM_Path*> m_path_vec;
  bool is_in(MNM_Path* path);
};

typedef std::map<TInt, std::map<TInt, MNM_Pathset*>*> Path_Table;

namespace MNM {
  MNM_Path *extract_path(TInt origin_ID, TInt dest_ID, std::map<TInt, TInt> &output_map, PNEGraph &graph);
  Path_Table *build_pathset(PNEGraph &graph, MNM_OD_Factory *od_factory, MNM_Link_Factory *link_factory);
  int save_path_table(Path_Table *path_table, MNM_OD_Factory *m_od_factory);
}

#endif