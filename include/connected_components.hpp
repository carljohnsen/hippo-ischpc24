#ifndef CC_HPP
#define CC_HPP

#include "hippo.hpp"

// Functions
void apply_renaming(std::vector<int64_t> &img, std::vector<int64_t> &to_rename);
void apply_renaming(int64_t *__restrict__ img, const int64_t n, const std::vector<int64_t> &to_rename);
std::vector<idx3d> canonical_name(std::vector<int64_t> &img, int64_t n_labels, const idx3d &global_strides);
void connected_components(const std::string &base_path, std::vector<int64_t> &n_labels, const idx3d &global_shape);
std::tuple<mapping, mapping> get_mappings(std::vector<int64_t> &a, int64_t n_labels_a, std::vector<int64_t> &b, int64_t n_labels_b);
std::vector<int64_t> get_sizes(std::vector<int64_t> &img, int64_t n_labels);
std::vector<std::vector<std::tuple<int64_t, int64_t>>> generate_adjacency_tree(const int64_t chunks);
std::vector<idx3d> merge_canonical_names(std::vector<idx3d> &names_a, std::vector<idx3d> &names_b);
std::vector<int64_t> merge_labels(mapping &mapping_a, mapping &mapping_b, std::vector<int64_t> &to_rename_b);
int64_t recount_labels(mapping &mapping_a, mapping &mapping_b, std::vector<int64_t> &to_rename_a, std::vector<int64_t> &to_rename_b);
void rename_mapping(mapping &mapping_a, std::vector<int64_t> &to_rename_other);
std::tuple<std::vector<int64_t>, std::vector<int64_t>, int64_t> relabel(std::vector<int64_t> &a, int64_t n_labels_a, std::vector<int64_t> &b, int64_t n_labels_b);

// Debugging functions
void print_canonical_names(std::vector<idx3d> &names_a);
void print_mapping(mapping &mapping_);
void print_rename(std::vector<int64_t> &to_rename);

#endif // CC_HPP