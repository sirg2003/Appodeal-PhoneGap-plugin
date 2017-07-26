//
//  InneractiveAdSDK-Ad.h
//  InneractiveAdSDK
//
//  Created by Inneractive.
//  Copyright (c) 2015 Inneractive. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IaAdConfig;
@protocol InneractiveAdDelegate;

/**
 * The IaAd class provides a base class for Inneractive ads - either display ads (IaAdView) or native ads (IaNativeAd).
 *
 * It contains an IaAdConfig ad configuration - through which the
 * ad configuration is supplied, before first loading an ad,
 * and a delegate which conforms to the InneractiveAdDelegate protocol.
 */
@interface IaAd : UIView

@property (nonatomic, strong) IaAdConfig *adConfig;
@property (nonatomic, weak) id<InneractiveAdDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame __attribute__((unavailable("initWithFrame should not be used for an IaAd. An IaAdView or an IaNativeAd object should be instantiated instead.")));
- (instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((unavailable("initWithCoder should not be used for an IaAd.  An IaAdView or an IaNativeAd object should be instantiated instead.")));

/**
 * Check, whether the interstitial ad is video ad.
 * Please use this method after 'InneractiveAdLoaded:' event has been received.
 */
- (BOOL)isVideoAd;

#pragma mark - Ad Load Calibration and Debugging

/**
 * @name Methods Used For Calibrating and Debugging
 */

/**
 * Optional method to limit the connection request time to Inneractive's Server when retrieving the ad.
 * if the connection timeout is reached and no ad is recevied from Inneractive's Server - an adFailed event will be thrown.
 * the default connection timeout is 8.0 seconds and the minimum that can be set is 3.0 seconds.
 * @param connectionTimeout the connection timeout in seconds
 */
- (void)setAdRequestConnectionTimeoutInSec:(NSTimeInterval)connectionTimeoutInSeconds;

- (void)testEnvironmentAddress:(NSString *)name;

/**
 * @param portalsString contains portals separated by dot (.) symbol.
 * For example: @"7714.7715"
 */
- (void)testEnvironmentPortal:(NSString *)portalsString;

- (void)testEnvironmentResponse:(NSString *)responseType;

@end
