FILE(REMOVE_RECURSE
  "../src/costmap_2d/msg"
  "../msg_gen"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_gencfg_cpp"
  "../cfg/cpp/costmap_2d/Costmap2DConfig.h"
  "../docs/Costmap2DConfig.dox"
  "../docs/Costmap2DConfig-usage.dox"
  "../src/costmap_2d/cfg/Costmap2DConfig.py"
  "../docs/Costmap2DConfig.wikidoc"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gencfg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
