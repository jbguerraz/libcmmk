file(REMOVE_RECURSE
  "libcmmk.pdb"
  "libcmmk.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/cmmk_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
