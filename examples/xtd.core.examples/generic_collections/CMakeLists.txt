cmake_minimum_required(VERSION 3.20)

project(generic_collections)
find_package(xtd REQUIRED)

add_projects(
  generic_dictionary
  generic_dictionary_constructor_with_idicationary
  generic_icollection
  generic_ienumerable
  generic_ienumerable2
  generic_ienumerable3
  generic_ienumerator
  generic_ilist
  generic_list
  generic_list2
  generic_list3
  generic_list4
  generic_list_as_read_only
  generic_list_binary_search
  generic_list_convert_all
  generic_list_exists
  generic_list_for_each
  generic_list_reverse
)
