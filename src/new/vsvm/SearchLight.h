/**
 * SearchLight.h
 *
 *  Created on: 16.04.2012
 *      Author: Tilo Buschmann
 */

#ifndef SEARCHLIGHT_H
#define SEARCHLIGHT_H

#include <cfloat>
#include <vector>
#include <string>

#include "boost/multi_array.hpp"

#define DEFAULT_SEARCHLIGHT_SCALE_LOWER 0
#define DEFAULT_SEARCHLIGHT_SCALE_UPPER 1
#define DEFAULT_SEARCHLIGHT_RADIUS      3
#define DEFAULT_SEARCHLIGHT_DO_SHOW_PROGRESS false


#include "MriTypes.h"
#include "MriSvm.h"

#define _DENSE_REP
#include "libsvm-dense/svm.h"

using std::vector;


class SearchLight {
public:
  SearchLight(int number_of_bands,
              int number_of_rows,
              int number_of_columns,
              int number_of_samples,
              int number_of_features_per_voxel,
              sample_3d_array_type sample_features,
              vector<int> classes,
              double radius,
              double extension_band,
              double extension_row,
              double extension_column
      );

  virtual ~SearchLight();
  void printConfiguration();
  sample_validity_array_type calculate();
  void calculate_permutations(permutated_validities_type &permutated_validities, int number_of_permutations);
  void scale();

private:
  void shuffle(int *array);
  vector<coords_3d>     radius_pixels();
  bool                  is_voxel_zero(int,int,int);
  bool                  are_coordinates_valid(int,int,int);
  double                cross_validate(int,int,int,vector<coords_3d>&);
  struct svm_parameter  getDefaultParameters();
  void                  scale_voxel_feature(int band, int row, int column,int feature);
  int                   prepare_for_mrisvm(sample_features_array_type &sample_features,int band, int row, int column,vector<coords_3d> &relative_coords);
  void                  cross_validate_permutations(permutated_validities_type &permutated_validities,
                                                    int number_of_permutations,
                                                    permutations_array_type &permutations,
                                                    int band, 
                                                    int row, 
                                                    int column,
                                                    vector<coords_3d> &relative_coords);

  int      number_of_bands_;
  int      number_of_rows_;
  int      number_of_columns_;
  int      number_of_samples_;
  int      number_of_features_per_voxel_;
  sample_3d_array_type sample_features_;
  vector <int>  classes_;
  double  radius_;

  int     svm_type_;
  int     svm_kernel_type_;
  
  double  extension_band_,extension_row_,extension_column_;
  
  bool    do_show_progress;

};

#endif // SEARCHLIGHT_H 
