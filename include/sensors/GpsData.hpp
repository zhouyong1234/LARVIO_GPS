/*
 * @Descripttion: Types of IMU sensor data.
 * @Author: Xiaochen Qiu
 */


#ifndef GPS_DATA_HPP
#define GPS_DATA_HPP


#include "Eigen/Core"
#include "Eigen/Dense"

namespace larvio {

struct GpsData {
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    GpsData (double t, 
             double lon,   double lat,   double hei, 
             double cov00, double cov01, double cov02, 
             double cov10, double cov11, double cov12, 
             double cov20, double cov21, double cov22) {
        timeStampToSec = t;
        lla << lon, lat, hei;
        cov << cov00, cov01, cov02,
               cov10, cov11, cov12,
               cov20, cov21, cov22;
    }

    GpsData (double t, const Eigen::Vector3d& lon_lat_hei, const Eigen::Matrix3d& position_covariance) {
        timeStampToSec = t;
        lla = lon_lat_hei;
        cov = position_covariance;
    }

    double timeStampToSec;
    // longitude latitude altitude
    Eigen::Vector3d lla;
    // position_covariance
    Eigen::Matrix3d cov;
};

}


#endif // GPS_DATA_HPP