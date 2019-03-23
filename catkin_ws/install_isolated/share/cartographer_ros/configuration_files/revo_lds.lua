options = {

  map_builder = MAP_BUILDER,

  sensor_bridge = {

    horizontal_laser_min_range = 0.3,

    horizontal_laser_max_range = 8,

    horizontal_laser_missing_echo_ray_length = 1.2,

    constant_odometry_translational_variance = 0.,

    constant_odometry_rotational_variance = 0.,

  },

  map_frame = "map",

  tracking_frame = "laser",

  published_frame = "laser",

  odom_frame = "odom",

  provide_odom_frame = true,

  use_odometry_data = false,

  use_constant_odometry_variance = true,

  constant_odometry_translational_variance = 1e-2,

  constant_odometry_rotational_variance = 1e-1,

  use_horizontal_laser = true,

  use_horizontal_multi_echo_laser = false,
  
  horizontal_laser_min_range = 0.1,
  
  horizontal_laser_max_range = 30.,
  
  horizontal_laser_missing_echo_ray_length = 5.,

  num_lasers_3d = 0,

  lookup_transform_timeout_sec = 0.2,

  submap_publish_period_sec = 0.3,

  pose_publish_period_sec = 5e-3,

}

MAP_BUILDER.use_trajectory_builder_2d = true

TRAJECTORY_BUILDER_2D.use_imu_data = false

TRAJECTORY_BUILDER_2D.use_online_correlative_scan_matching = true

SPARSE_POSE_GRAPH.optimization_problem.huber_scale = 1e2

return options
