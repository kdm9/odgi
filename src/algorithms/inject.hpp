#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <omp.h>
#include "hash_map.hpp"
#include "position.hpp"
#include <handlegraph/types.hpp>
#include <handlegraph/iteratee.hpp>
#include <handlegraph/util.hpp>
#include <handlegraph/handle_graph.hpp>
#include <handlegraph/path_handle_graph.hpp>
#include <handlegraph/mutable_path_deletable_handle_graph.hpp>
//#include <atomic_bitvector.hpp>
#include <deps/ips4o/ips4o.hpp>

namespace odgi {

namespace algorithms {

using namespace handlegraph;

/// Modify the graph to include the named intervals as paths
/// This will cut nodes at interval start/ends and then embed them in the graph
void inject_ranges(MutablePathDeletableHandleGraph& graph,
                   const ska::flat_hash_map<path_handle_t, std::pair<std::string, std::vector<interval_t>>>& path_intervals);

void chop_at(MutablePathDeletableHandleGraph &graph,
             const ska::flat_hash_map<handle_t, std::vector<size_t>>& cut_points,
             const uint64_t &nthreads, const bool &show_info);

}

}
