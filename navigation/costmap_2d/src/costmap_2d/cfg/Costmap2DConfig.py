## *********************************************************
## 
## File autogenerated for the costmap_2d package 
## by the dynamic_reconfigure package.
## Please do not edit.
## 
## ********************************************************/

##**********************************************************
## Software License Agreement (BSD License)
##
##  Copyright (c) 2008, Willow Garage, Inc.
##  All rights reserved.
##
##  Redistribution and use in source and binary forms, with or without
##  modification, are permitted provided that the following conditions
##  are met:
##
##   * Redistributions of source code must retain the above copyright
##     notice, this list of conditions and the following disclaimer.
##   * Redistributions in binary form must reproduce the above
##     copyright notice, this list of conditions and the following
##     disclaimer in the documentation and/or other materials provided
##     with the distribution.
##   * Neither the name of the Willow Garage nor the names of its
##     contributors may be used to endorse or promote products derived
##     from this software without specific prior written permission.
##
##  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
##  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
##  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
##  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
##  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
##  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
##  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
##  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
##  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
##  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
##  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
##  POSSIBILITY OF SUCH DAMAGE.
##**********************************************************/

config_description = [{'srcline': 15, 'description': 'Specifies the delay in transform (tf) data that is tolerable in seconds.', 'max': 10.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'transform_tolerance', 'edit_method': '', 'default': 0.3, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 17, 'description': 'The frequency in Hz for the map to be updated.', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'update_frequency', 'edit_method': '', 'default': 5.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 18, 'description': 'The frequency in Hz for the map to be publish display information.', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'publish_frequency', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 20, 'description': 'The maximum height of any obstacle to be inserted into the costmap in meters.', 'max': 50.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'max_obstacle_height', 'edit_method': '', 'default': 2.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 21, 'description': 'The default maximum distance from the robot at which an obstacle will be inserted into the cost map in meters.', 'max': 50.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'max_obstacle_range', 'edit_method': '', 'default': 2.5, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 22, 'description': 'The default range in meters at which to raytrace out obstacles from the map using sensor data.', 'max': 50.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'raytrace_range', 'edit_method': '', 'default': 3.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 23, 'description': 'A scaling factor to apply to cost values during inflation.', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'cost_scaling_factor', 'edit_method': '', 'default': 10.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 25, 'description': 'The radius in meters to which the map inflates obstacle cost values.', 'max': 50.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'inflation_radius', 'edit_method': '', 'default': 0.55, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 26, 'description': 'The footprint of the robot specified in the robot_base_frame coordinate frame as a list in the format: [ [x1, y1], [x2, y2], ...., [xn, yn] ].', 'max': '', 'cconsttype': 'const char * const', 'ctype': 'std::string', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'footprint', 'edit_method': '', 'default': '[]', 'level': 0, 'min': '', 'type': 'str'}, {'srcline': 27, 'description': 'The radius of the robot in meters, this parameter should only be set for circular robots, all others should use the footprint parameter described above.', 'max': 10.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'robot_radius', 'edit_method': '', 'default': 0.46, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 29, 'description': 'Whether or not to use the static map to initialize the costmap.', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'static_map', 'edit_method': '', 'default': True, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 30, 'description': 'Whether or not to use a rolling window version of the costmap.', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'rolling_window', 'edit_method': '', 'default': False, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 31, 'description': 'The value for which a cost should be considered unknown when reading in a map from the map server.', 'max': 255, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'unknown_cost_value', 'edit_method': '', 'default': 0, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 34, 'description': 'The width of the map in meters.', 'max': 20, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'width', 'edit_method': '', 'default': 0, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 35, 'description': 'The height of the map in meters.', 'max': 20, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'height', 'edit_method': '', 'default': 10, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 36, 'description': 'The resolution of the map in meters/cell.', 'max': 50.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'resolution', 'edit_method': '', 'default': 0.05, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 37, 'description': 'The x origin of the map in the global frame in meters.', 'max': 'std::numeric_limits<double>::infinity()', 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'origin_x', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 38, 'description': 'The y origin of the map in the global frame in meters.', 'max': 'std::numeric_limits<double>::infinity()', 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'origin_y', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 40, 'description': 'Whether or not to publish the underlying voxel grid for visualization purposes.', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'publish_voxel_map', 'edit_method': '', 'default': False, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 41, 'description': 'The threshold value at which to consider a cost lethal when reading in a map from the map server.', 'max': 255, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'lethal_cost_threshold', 'edit_method': '', 'default': 100, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 42, 'description': 'The topic that the costmap subscribes to for the static map.', 'max': '', 'cconsttype': 'const char * const', 'ctype': 'std::string', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'map_topic', 'edit_method': '', 'default': 'map', 'level': 0, 'min': '', 'type': 'str'}, {'srcline': 45, 'description': 'What map type to use. voxel or costmap are the supported types', 'max': '', 'cconsttype': 'const char * const', 'ctype': 'std::string', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'map_type', 'edit_method': "{'enum_description': 'An enum to set the map type', 'enum': [{'srcline': 13, 'description': 'Use VoxelCostmap2D', 'srcfile': '../cfg/Costmap2D.cfg', 'cconsttype': 'const char * const', 'value': 'voxel', 'ctype': 'std::string', 'type': 'str', 'name': 'voxel_const'}, {'srcline': 13, 'description': 'Use Costmap2D', 'srcfile': '../cfg/Costmap2D.cfg', 'cconsttype': 'const char * const', 'value': 'costmap', 'ctype': 'std::string', 'type': 'str', 'name': 'costmap_const'}]}", 'default': 'costmap', 'level': 0, 'min': '', 'type': 'str'}, {'srcline': 46, 'description': 'The z origin of the map in meters.', 'max': 'std::numeric_limits<double>::infinity()', 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'origin_z', 'edit_method': '', 'default': 0.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 47, 'description': 'The z resolution of the map in meters/cell.', 'max': 50.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'z_resolution', 'edit_method': '', 'default': 0.2, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 48, 'description': 'The number of voxels to in each vertical column.', 'max': 16, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'z_voxels', 'edit_method': '', 'default': 10, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 49, 'description': 'The number of unknown cells allowed in a column considered to be known', 'max': 16, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'unknown_threshold', 'edit_method': '', 'default': 15, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 50, 'description': 'The maximum number of marked cells allowed in a column considered to be free', 'max': 16, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'mark_threshold', 'edit_method': '', 'default': 0, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 51, 'description': 'Specifies whether or not to track what space in the costmap is unknown', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'track_unknown_space', 'edit_method': '', 'default': False, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 53, 'description': 'Restore to the original configuration', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '../cfg/Costmap2D.cfg', 'name': 'restore_defaults', 'edit_method': '', 'default': False, 'level': 0, 'min': False, 'type': 'bool'}]

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

for param in config_description:
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

Costmap2D_voxel_const = 'voxel'
Costmap2D_costmap_const = 'costmap'
