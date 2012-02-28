//#line 2 "/opt/ros/electric/stacks/driver_common/dynamic_reconfigure/templates/ConfigType.h"
// *********************************************************
// 
// File autogenerated for the base_local_planner package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

/***********************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 ***********************************************************/

// Author: Blaise Gassend


#ifndef __base_local_planner__BASELOCALPLANNERCONFIG_H__
#define __base_local_planner__BASELOCALPLANNERCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/config_init_mutex.h>

namespace base_local_planner
{
  class BaseLocalPlannerConfigStatics;
  
  class BaseLocalPlannerConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(BaseLocalPlannerConfig &config, const BaseLocalPlannerConfig &max, const BaseLocalPlannerConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const BaseLocalPlannerConfig &config1, const BaseLocalPlannerConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, BaseLocalPlannerConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const BaseLocalPlannerConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, BaseLocalPlannerConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const BaseLocalPlannerConfig &config) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T BaseLocalPlannerConfig::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (BaseLocalPlannerConfig::* field);

      virtual void clamp(BaseLocalPlannerConfig &config, const BaseLocalPlannerConfig &max, const BaseLocalPlannerConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const BaseLocalPlannerConfig &config1, const BaseLocalPlannerConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, BaseLocalPlannerConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const BaseLocalPlannerConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, BaseLocalPlannerConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const BaseLocalPlannerConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }
    };

//#line 16 "../cfg/BaseLocalPlanner.cfg"
      double acc_lim_x;
//#line 17 "../cfg/BaseLocalPlanner.cfg"
      double acc_lim_y;
//#line 18 "../cfg/BaseLocalPlanner.cfg"
      double acc_lim_theta;
//#line 20 "../cfg/BaseLocalPlanner.cfg"
      double max_vel_x;
//#line 21 "../cfg/BaseLocalPlanner.cfg"
      double min_vel_x;
//#line 23 "../cfg/BaseLocalPlanner.cfg"
      double max_vel_theta;
//#line 24 "../cfg/BaseLocalPlanner.cfg"
      double min_vel_theta;
//#line 25 "../cfg/BaseLocalPlanner.cfg"
      double min_in_place_vel_theta;
//#line 27 "../cfg/BaseLocalPlanner.cfg"
      double sim_time;
//#line 28 "../cfg/BaseLocalPlanner.cfg"
      double sim_granularity;
//#line 30 "../cfg/BaseLocalPlanner.cfg"
      double pdist_scale;
//#line 31 "../cfg/BaseLocalPlanner.cfg"
      double gdist_scale;
//#line 32 "../cfg/BaseLocalPlanner.cfg"
      double occdist_scale;
//#line 34 "../cfg/BaseLocalPlanner.cfg"
      double oscillation_reset_dist;
//#line 35 "../cfg/BaseLocalPlanner.cfg"
      double escape_reset_dist;
//#line 36 "../cfg/BaseLocalPlanner.cfg"
      double escape_reset_theta;
//#line 38 "../cfg/BaseLocalPlanner.cfg"
      int vx_samples;
//#line 39 "../cfg/BaseLocalPlanner.cfg"
      int vtheta_samples;
//#line 41 "../cfg/BaseLocalPlanner.cfg"
      double heading_lookahead;
//#line 43 "../cfg/BaseLocalPlanner.cfg"
      bool holonomic_robot;
//#line 45 "../cfg/BaseLocalPlanner.cfg"
      double escape_vel;
//#line 47 "../cfg/BaseLocalPlanner.cfg"
      bool dwa;
//#line 49 "../cfg/BaseLocalPlanner.cfg"
      bool heading_scoring;
//#line 50 "../cfg/BaseLocalPlanner.cfg"
      double heading_scoring_timestep;
//#line 52 "../cfg/BaseLocalPlanner.cfg"
      bool simple_attractor;
//#line 54 "../cfg/BaseLocalPlanner.cfg"
      double angular_sim_granularity;
//#line 56 "../cfg/BaseLocalPlanner.cfg"
      std::string y_vels;
//#line 58 "../cfg/BaseLocalPlanner.cfg"
      bool restore_defaults;
//#line 138 "/opt/ros/electric/stacks/driver_common/dynamic_reconfigure/templates/ConfigType.h"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        if ((*i)->fromMessage(msg, *this))
          count++;
      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("BaseLocalPlannerConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toMessage(msg, *this);
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      __toMessage__(msg, __param_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->fromServer(nh, *this);
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const BaseLocalPlannerConfig &__max__ = __getMax__();
      const BaseLocalPlannerConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const BaseLocalPlannerConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const BaseLocalPlannerConfig &__getDefault__();
    static const BaseLocalPlannerConfig &__getMax__();
    static const BaseLocalPlannerConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    
  private:
    static const BaseLocalPlannerConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void BaseLocalPlannerConfig::ParamDescription<std::string>::clamp(BaseLocalPlannerConfig &config, const BaseLocalPlannerConfig &max, const BaseLocalPlannerConfig &min) const
  {
    return;
  }

  class BaseLocalPlannerConfigStatics
  {
    friend class BaseLocalPlannerConfig;
    
    BaseLocalPlannerConfigStatics()
    {
//#line 16 "../cfg/BaseLocalPlanner.cfg"
      __min__.acc_lim_x = 0.0;
//#line 16 "../cfg/BaseLocalPlanner.cfg"
      __max__.acc_lim_x = 20.0;
//#line 16 "../cfg/BaseLocalPlanner.cfg"
      __default__.acc_lim_x = 1.0;
//#line 16 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("acc_lim_x", "double", 0, "The acceleration limit of the robot in the x direction", "", &BaseLocalPlannerConfig::acc_lim_x)));
//#line 17 "../cfg/BaseLocalPlanner.cfg"
      __min__.acc_lim_y = 0.0;
//#line 17 "../cfg/BaseLocalPlanner.cfg"
      __max__.acc_lim_y = 20.0;
//#line 17 "../cfg/BaseLocalPlanner.cfg"
      __default__.acc_lim_y = 1.0;
//#line 17 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("acc_lim_y", "double", 0, "The acceleration limit of the robot in the y direction", "", &BaseLocalPlannerConfig::acc_lim_y)));
//#line 18 "../cfg/BaseLocalPlanner.cfg"
      __min__.acc_lim_theta = 0.0;
//#line 18 "../cfg/BaseLocalPlanner.cfg"
      __max__.acc_lim_theta = 20.0;
//#line 18 "../cfg/BaseLocalPlanner.cfg"
      __default__.acc_lim_theta = 1.0;
//#line 18 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("acc_lim_theta", "double", 0, "The acceleration limit of the robot in the theta direction", "", &BaseLocalPlannerConfig::acc_lim_theta)));
//#line 20 "../cfg/BaseLocalPlanner.cfg"
      __min__.max_vel_x = 0.0;
//#line 20 "../cfg/BaseLocalPlanner.cfg"
      __max__.max_vel_x = 20.0;
//#line 20 "../cfg/BaseLocalPlanner.cfg"
      __default__.max_vel_x = 0.55;
//#line 20 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("max_vel_x", "double", 0, "The maximum x velocity for the robot in m/s", "", &BaseLocalPlannerConfig::max_vel_x)));
//#line 21 "../cfg/BaseLocalPlanner.cfg"
      __min__.min_vel_x = 0.0;
//#line 21 "../cfg/BaseLocalPlanner.cfg"
      __max__.min_vel_x = 20.0;
//#line 21 "../cfg/BaseLocalPlanner.cfg"
      __default__.min_vel_x = 0.0;
//#line 21 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("min_vel_x", "double", 0, "The minimum x velocity for the robot in m/s", "", &BaseLocalPlannerConfig::min_vel_x)));
//#line 23 "../cfg/BaseLocalPlanner.cfg"
      __min__.max_vel_theta = 0.0;
//#line 23 "../cfg/BaseLocalPlanner.cfg"
      __max__.max_vel_theta = 20.0;
//#line 23 "../cfg/BaseLocalPlanner.cfg"
      __default__.max_vel_theta = 1.0;
//#line 23 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("max_vel_theta", "double", 0, "The absolute value of the maximum rotational velocity for the robot in rad/s", "", &BaseLocalPlannerConfig::max_vel_theta)));
//#line 24 "../cfg/BaseLocalPlanner.cfg"
      __min__.min_vel_theta = 0.0;
//#line 24 "../cfg/BaseLocalPlanner.cfg"
      __max__.min_vel_theta = 20.0;
//#line 24 "../cfg/BaseLocalPlanner.cfg"
      __default__.min_vel_theta = -1.0;
//#line 24 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("min_vel_theta", "double", 0, "The absolute value of the minimum rotational velocity for the robot in rad/s", "", &BaseLocalPlannerConfig::min_vel_theta)));
//#line 25 "../cfg/BaseLocalPlanner.cfg"
      __min__.min_in_place_vel_theta = 0.0;
//#line 25 "../cfg/BaseLocalPlanner.cfg"
      __max__.min_in_place_vel_theta = 20.0;
//#line 25 "../cfg/BaseLocalPlanner.cfg"
      __default__.min_in_place_vel_theta = 0.4;
//#line 25 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("min_in_place_vel_theta", "double", 0, "The absolute value of the minimum in-place rotational velocity the controller will explore", "", &BaseLocalPlannerConfig::min_in_place_vel_theta)));
//#line 27 "../cfg/BaseLocalPlanner.cfg"
      __min__.sim_time = 0.0;
//#line 27 "../cfg/BaseLocalPlanner.cfg"
      __max__.sim_time = 10.0;
//#line 27 "../cfg/BaseLocalPlanner.cfg"
      __default__.sim_time = 1.7;
//#line 27 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("sim_time", "double", 0, "The amount of time to roll trajectories out for in seconds", "", &BaseLocalPlannerConfig::sim_time)));
//#line 28 "../cfg/BaseLocalPlanner.cfg"
      __min__.sim_granularity = 0.0;
//#line 28 "../cfg/BaseLocalPlanner.cfg"
      __max__.sim_granularity = 5.0;
//#line 28 "../cfg/BaseLocalPlanner.cfg"
      __default__.sim_granularity = 0.025;
//#line 28 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("sim_granularity", "double", 0, "The granularity with which to check for collisions along each trajectory in meters", "", &BaseLocalPlannerConfig::sim_granularity)));
//#line 30 "../cfg/BaseLocalPlanner.cfg"
      __min__.pdist_scale = 0.0;
//#line 30 "../cfg/BaseLocalPlanner.cfg"
      __max__.pdist_scale = 5.0;
//#line 30 "../cfg/BaseLocalPlanner.cfg"
      __default__.pdist_scale = 0.6;
//#line 30 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("pdist_scale", "double", 0, "The weight for the path distance part of the cost function", "", &BaseLocalPlannerConfig::pdist_scale)));
//#line 31 "../cfg/BaseLocalPlanner.cfg"
      __min__.gdist_scale = 0.0;
//#line 31 "../cfg/BaseLocalPlanner.cfg"
      __max__.gdist_scale = 5.0;
//#line 31 "../cfg/BaseLocalPlanner.cfg"
      __default__.gdist_scale = 0.8;
//#line 31 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("gdist_scale", "double", 0, "The weight for the goal distance part of the cost function", "", &BaseLocalPlannerConfig::gdist_scale)));
//#line 32 "../cfg/BaseLocalPlanner.cfg"
      __min__.occdist_scale = 0.0;
//#line 32 "../cfg/BaseLocalPlanner.cfg"
      __max__.occdist_scale = 5.0;
//#line 32 "../cfg/BaseLocalPlanner.cfg"
      __default__.occdist_scale = 0.01;
//#line 32 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("occdist_scale", "double", 0, "The weight for the obstacle distance part of the cost function", "", &BaseLocalPlannerConfig::occdist_scale)));
//#line 34 "../cfg/BaseLocalPlanner.cfg"
      __min__.oscillation_reset_dist = 0.0;
//#line 34 "../cfg/BaseLocalPlanner.cfg"
      __max__.oscillation_reset_dist = 5.0;
//#line 34 "../cfg/BaseLocalPlanner.cfg"
      __default__.oscillation_reset_dist = 0.05;
//#line 34 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("oscillation_reset_dist", "double", 0, "The distance the robot must travel before oscillation flags are reset, in meters", "", &BaseLocalPlannerConfig::oscillation_reset_dist)));
//#line 35 "../cfg/BaseLocalPlanner.cfg"
      __min__.escape_reset_dist = 0.0;
//#line 35 "../cfg/BaseLocalPlanner.cfg"
      __max__.escape_reset_dist = 5.0;
//#line 35 "../cfg/BaseLocalPlanner.cfg"
      __default__.escape_reset_dist = 0.1;
//#line 35 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("escape_reset_dist", "double", 0, "The distance the robot must travel before oscillation flags are reset, in meters", "", &BaseLocalPlannerConfig::escape_reset_dist)));
//#line 36 "../cfg/BaseLocalPlanner.cfg"
      __min__.escape_reset_theta = 0.0;
//#line 36 "../cfg/BaseLocalPlanner.cfg"
      __max__.escape_reset_theta = 5.0;
//#line 36 "../cfg/BaseLocalPlanner.cfg"
      __default__.escape_reset_theta = 1.57079632679;
//#line 36 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("escape_reset_theta", "double", 0, "The distance the robot must travel before oscillation flags are reset, in meters", "", &BaseLocalPlannerConfig::escape_reset_theta)));
//#line 38 "../cfg/BaseLocalPlanner.cfg"
      __min__.vx_samples = 1;
//#line 38 "../cfg/BaseLocalPlanner.cfg"
      __max__.vx_samples = 300;
//#line 38 "../cfg/BaseLocalPlanner.cfg"
      __default__.vx_samples = 20;
//#line 38 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<int>("vx_samples", "int", 0, "The number of samples to use when exploring the x velocity space", "", &BaseLocalPlannerConfig::vx_samples)));
//#line 39 "../cfg/BaseLocalPlanner.cfg"
      __min__.vtheta_samples = 1;
//#line 39 "../cfg/BaseLocalPlanner.cfg"
      __max__.vtheta_samples = 300;
//#line 39 "../cfg/BaseLocalPlanner.cfg"
      __default__.vtheta_samples = 20;
//#line 39 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<int>("vtheta_samples", "int", 0, "The number of samples to use when exploring the theta velocity space", "", &BaseLocalPlannerConfig::vtheta_samples)));
//#line 41 "../cfg/BaseLocalPlanner.cfg"
      __min__.heading_lookahead = 0.0;
//#line 41 "../cfg/BaseLocalPlanner.cfg"
      __max__.heading_lookahead = 5.0;
//#line 41 "../cfg/BaseLocalPlanner.cfg"
      __default__.heading_lookahead = 0.325;
//#line 41 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("heading_lookahead", "double", 0, "How far the robot should look ahead of itself when differentiating between different rotational velocities", "", &BaseLocalPlannerConfig::heading_lookahead)));
//#line 43 "../cfg/BaseLocalPlanner.cfg"
      __min__.holonomic_robot = 0;
//#line 43 "../cfg/BaseLocalPlanner.cfg"
      __max__.holonomic_robot = 1;
//#line 43 "../cfg/BaseLocalPlanner.cfg"
      __default__.holonomic_robot = 1;
//#line 43 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<bool>("holonomic_robot", "bool", 0, "Set this to true if the robot being controlled can take y velocities and false otherwise", "", &BaseLocalPlannerConfig::holonomic_robot)));
//#line 45 "../cfg/BaseLocalPlanner.cfg"
      __min__.escape_vel = -2.0;
//#line 45 "../cfg/BaseLocalPlanner.cfg"
      __max__.escape_vel = 2.0;
//#line 45 "../cfg/BaseLocalPlanner.cfg"
      __default__.escape_vel = -0.1;
//#line 45 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("escape_vel", "double", 0, "The velocity to use while backing up", "", &BaseLocalPlannerConfig::escape_vel)));
//#line 47 "../cfg/BaseLocalPlanner.cfg"
      __min__.dwa = 0;
//#line 47 "../cfg/BaseLocalPlanner.cfg"
      __max__.dwa = 1;
//#line 47 "../cfg/BaseLocalPlanner.cfg"
      __default__.dwa = 0;
//#line 47 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<bool>("dwa", "bool", 0, "Set this to true to use the Dynamic Window Approach, false to use acceleration limits", "", &BaseLocalPlannerConfig::dwa)));
//#line 49 "../cfg/BaseLocalPlanner.cfg"
      __min__.heading_scoring = 0;
//#line 49 "../cfg/BaseLocalPlanner.cfg"
      __max__.heading_scoring = 1;
//#line 49 "../cfg/BaseLocalPlanner.cfg"
      __default__.heading_scoring = 0;
//#line 49 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<bool>("heading_scoring", "bool", 0, "Set this to true to use the Dynamic Window Approach, false to use acceleration limits", "", &BaseLocalPlannerConfig::heading_scoring)));
//#line 50 "../cfg/BaseLocalPlanner.cfg"
      __min__.heading_scoring_timestep = 0.0;
//#line 50 "../cfg/BaseLocalPlanner.cfg"
      __max__.heading_scoring_timestep = 1.0;
//#line 50 "../cfg/BaseLocalPlanner.cfg"
      __default__.heading_scoring_timestep = 0.1;
//#line 50 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("heading_scoring_timestep", "double", 0, "How far to look ahead in time when we score heading based trajectories", "", &BaseLocalPlannerConfig::heading_scoring_timestep)));
//#line 52 "../cfg/BaseLocalPlanner.cfg"
      __min__.simple_attractor = 0;
//#line 52 "../cfg/BaseLocalPlanner.cfg"
      __max__.simple_attractor = 1;
//#line 52 "../cfg/BaseLocalPlanner.cfg"
      __default__.simple_attractor = 0;
//#line 52 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<bool>("simple_attractor", "bool", 0, "Set this to true to allow simple attraction to a goal point instead of intelligent cost propagation", "", &BaseLocalPlannerConfig::simple_attractor)));
//#line 54 "../cfg/BaseLocalPlanner.cfg"
      __min__.angular_sim_granularity = 0.0;
//#line 54 "../cfg/BaseLocalPlanner.cfg"
      __max__.angular_sim_granularity = 1.57079632679;
//#line 54 "../cfg/BaseLocalPlanner.cfg"
      __default__.angular_sim_granularity = 0.025;
//#line 54 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<double>("angular_sim_granularity", "double", 0, "The distance between simulation points for angular velocity should be small enough that the robot doesn't hit things", "", &BaseLocalPlannerConfig::angular_sim_granularity)));
//#line 56 "../cfg/BaseLocalPlanner.cfg"
      __min__.y_vels = "";
//#line 56 "../cfg/BaseLocalPlanner.cfg"
      __max__.y_vels = "";
//#line 56 "../cfg/BaseLocalPlanner.cfg"
      __default__.y_vels = "-0.3,-0.1,0.1,-0.3";
//#line 56 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<std::string>("y_vels", "str", 0, "A comma delimited list of the y velocities the controller will explore", "", &BaseLocalPlannerConfig::y_vels)));
//#line 58 "../cfg/BaseLocalPlanner.cfg"
      __min__.restore_defaults = 0;
//#line 58 "../cfg/BaseLocalPlanner.cfg"
      __max__.restore_defaults = 1;
//#line 58 "../cfg/BaseLocalPlanner.cfg"
      __default__.restore_defaults = 0;
//#line 58 "../cfg/BaseLocalPlanner.cfg"
      __param_descriptions__.push_back(BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr(new BaseLocalPlannerConfig::ParamDescription<bool>("restore_defaults", "bool", 0, "Retore to the default configuration", "", &BaseLocalPlannerConfig::restore_defaults)));
//#line 239 "/opt/ros/electric/stacks/driver_common/dynamic_reconfigure/templates/ConfigType.h"
    
      for (std::vector<BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        __description_message__.parameters.push_back(**i);
      __max__.__toMessage__(__description_message__.max, __param_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__); 
    }
    std::vector<BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    BaseLocalPlannerConfig __max__;
    BaseLocalPlannerConfig __min__;
    BaseLocalPlannerConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;
    static const BaseLocalPlannerConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static BaseLocalPlannerConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &BaseLocalPlannerConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const BaseLocalPlannerConfig &BaseLocalPlannerConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const BaseLocalPlannerConfig &BaseLocalPlannerConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const BaseLocalPlannerConfig &BaseLocalPlannerConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<BaseLocalPlannerConfig::AbstractParamDescriptionConstPtr> &BaseLocalPlannerConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const BaseLocalPlannerConfigStatics *BaseLocalPlannerConfig::__get_statics__()
  {
    const static BaseLocalPlannerConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = BaseLocalPlannerConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __BASELOCALPLANNERRECONFIGURATOR_H__