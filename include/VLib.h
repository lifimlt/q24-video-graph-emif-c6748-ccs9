/****************************************************************************/
/*                                                                          */
/*              ��Ƶ���������ӻ���                                          */
/*                                                                          */
/*              2014��09��02��                                              */
/*                                                                          */
/****************************************************************************/
#include <VLIB_afast12_detectCorners.h>
#include <VLIB_afast9_detectCorners.h>
#include <VLIB_aFast_nonmaxSuppression.h>
#include <VLIB_bhattacharyaDistance_U32.h>
#include <VLIB_binarySkeleton.h>
#include <VLIB_blockMedian.h>
#include <VLIB_blockStatistics.h>
#include <VLIB_Canny_Edge_Detection.h>
#include <VLIB_Connected_Components_Labeling.h>
#include <VLIB_convertUYVYint_to_HSLpl.h>
#include <VLIB_convertUYVYint_to_LABpl.h>
#include <VLIB_convertUYVYint_to_LABpl_LUT.h>
#include <VLIB_convertUYVYint_to_RGBpl.h>
#include <VLIB_convertUYVYint_to_YUV420pl.h>
#include <VLIB_convertUYVYint_to_YUV422pl.h>
#include <VLIB_convertUYVYint_to_YUV444pl.h>
#include <VLIB_convertUYVYpl_to_YUVint.h>
#include <VLIB_convertUYVYsemipl_to_YUVpl.h>
#include <VLIB_coOccurrenceMatrix.h>
#include <VLIB_dilate_bin_cross.h>
#include <VLIB_dilate_bin_mask.h>
#include <VLIB_dilate_bin_square.h>
#include <VLIB_disparity_SAD16.h>
#include <VLIB_disparity_SAD8.h>
#include <VLIB_disparity_SAD_firstRow16.h>
#include <VLIB_disparity_SAD_firstRow8.h>
#include <VLIB_erode_bin_cross.h>
#include <VLIB_erode_bin_mask.h>
#include <VLIB_erode_bin_singlePixel.h>
#include <VLIB_erode_bin_square.h>
#include <VLIB_extract8bitBackgroundS16.h>
#include <VLIB_extractLumaFromUYUV.h>
#include <VLIB_extractLumaFromYUYV.h>
#include <VLIB_gauss5x5PyramidKernel_16.h>
#include <VLIB_gauss5x5PyramidKernel_8.h>
#include <VLIB_goodFeaturestoTrack.h>
#include <VLIB_gradientH5x5PyramidKernel_8.h>
#include <VLIB_gradientV5x5PyramidKernel_8.h>
#include <VLIB_grayscale_morphology.h>
#include <VLIB_hammingDistance.h>
#include <VLIB_harrisScore_7x7.h>
#include <VLIB_harrisScore_7x7_S32.h>
#include <VLIB_histogram_1D_Init_U16.h>
#include <VLIB_histogram_1D_Init_U8.h>
#include <VLIB_histogram_1D_U16.h>
#include <VLIB_histogram_1D_U8.h>
#include <VLIB_histogram_equal_8.h>
#include <VLIB_histogram_nD_U16.h>
#include <VLIB_houghLineFromList.h>
#include <VLIB_hysteresisThresholding.h>
#include <VLIB_imagePyramid16.h>
#include <VLIB_imagePyramid8.h>
#include <VLIB_image_rescale.h>
#include <VLIB_initMeanWithLumaS16.h>
#include <VLIB_initMeanWithLumaS32.h>
#include <VLIB_initUYVYint_to_LABpl_LUT.h>
#include <VLIB_initVarWithConstS16.h>
//#include <VLIB_initVarWithConstS32.h>
#include <VLIB_insertLumaIntoYUYV.h>
#include <VLIB_integralImage16.h>
#include <VLIB_integralImage8.h>
#include <VLIB_kalmanFilter_2x4_Correct.h>
#include <VLIB_kalmanFilter_2x4_Predict.h>
#include <VLIB_kalmanFilter_4x6_Correct.h>
#include <VLIB_kalmanFilter_4x6_Predict.h>
#include <VLIB_L1DistanceS16.h>
#include <VLIB_legendreMoments.h>
#include <VLIB_legendreMoments_Init.h>
#include <VLIB_mixtureOfGaussiansS16.h>
#include <VLIB_mixtureOfGaussiansS32.h>
#include <VLIB_nonMaxSuppress_3x3_S16.h>
#include <VLIB_nonMaxSuppress_5x5_S16.h>
#include <VLIB_nonMaxSuppress_7x7_S16.h>
#include <VLIB_nonMaxSuppress_U16.h>
#include <VLIB_nonMaxSuppress_U32.h>
#include <VLIB_normalFlow_16.h>
#include <VLIB_ORB_bestFeaturesToFront.h>
#include <VLIB_ORB_computeOrientation.h>
#include <VLIB_ORB_computeRBrief.h>
#include <VLIB_ORB_getHarrisScore.h>
#include <VLIB_originalfast12_detectCorners.h>
#include <VLIB_originalfast12_score.h>
#include <VLIB_originalfast9_detectCorners.h>
#include <VLIB_originalfast9_score.h>
#include <VLIB_packMask32.h>
#include <VLIB_recursiveFilterHoriz1stOrderS16.h>
#include <VLIB_recursiveFilterHoriz1stOrder.h>
#include <VLIB_recursiveFilterVert1stOrderS16.h>
#include <VLIB_recursiveFilterVert1stOrder.h>
#include <VLIB_simplex_3D.h>
#include <VLIB_simplex.h>
#include <VLIB_subtractBackgroundS16.h>
#include <VLIB_subtractBackgroundS32.h>
#include <VLIB_trackFeaturesLucasKanade_7x7.h>
#include <VLIB_unpackMask32.h>
#include <VLIB_updateEWRMeanS16.h>
#include <VLIB_updateEWRMeanS32.h>
#include <VLIB_updateEWRVarianceS16.h>
#include <VLIB_updateEWRVarianceS32.h>
#include <VLIB_updateUWRMeanS16.h>
#include <VLIB_updateUWRVarianceS16.h>
#include <VLIB_weightedHistogram_1D_U16.h>
#include <VLIB_weightedHistogram_1D_U8.h>
#include <VLIB_weightedHistogram_nD_U16.h>
#include <VLIB_xyGradientsAndMagnitude.h>
#include <VLIB_xyGradients.h>
#include <VLIB_xyGradients_Magnitude_Orientations.h>