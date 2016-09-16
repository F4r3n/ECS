#pragma once
#include <unordered_map>
#include <typeinfo>
#include "ComponentType.h"
#include <bitset>
#include <vector>
class ComponentTypeManager {
public:
  static int registerComponent(const std::type_info &info) {
      if(registered.find(&info) != registered.end()) return registered[&info]->id;
      else {
          ComponentType *t = new ComponentType();
          registered[&info] = t;
          return t->id;
      }
  }
  template <size_t size>
  static void getBitSets(std::bitset<size> &bits, const std::vector<const std::type_info*> infos) {
      for(auto info : infos) {
          bits.set(registered[info]->id, 1);
      }
  }
static std::unordered_map<const std::type_info*, ComponentType*> registered;  
};