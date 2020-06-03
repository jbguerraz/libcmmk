file(REMOVE_RECURSE
  "libcmmk.pdb"
  "libcmmk.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/cmmk_static.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
