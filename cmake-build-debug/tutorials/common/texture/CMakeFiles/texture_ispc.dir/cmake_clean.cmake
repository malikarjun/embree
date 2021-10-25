file(REMOVE_RECURSE
  "../../../libtexture_ispc.a"
  "../../../libtexture_ispc.pdb"
  "texture2d.dev.o"
  "texture2d_ispc.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/texture_ispc.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
