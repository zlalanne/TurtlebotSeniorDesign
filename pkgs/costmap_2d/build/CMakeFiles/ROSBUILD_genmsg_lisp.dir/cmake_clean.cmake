FILE(REMOVE_RECURSE
  "../src/costmap_2d/msg"
  "../msg_gen"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_lisp"
  "../msg_gen/lisp/VoxelGrid.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_VoxelGrid.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
