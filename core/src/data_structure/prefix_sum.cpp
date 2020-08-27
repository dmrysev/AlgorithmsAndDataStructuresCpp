#include "data_structure/prefix_sum.h"

namespace DataStructure::PrefixSum {

std::vector<int> initPrefixSum(const std::vector<int>& values) {
    std::vector<int> prefixSum(values.size() + 1);
    prefixSum[0] = 0;
    for(size_t i = 0; i < values.size(); i++) {
        prefixSum[i+1] = prefixSum[i] + values[i];
    }
    return prefixSum;
}


}
