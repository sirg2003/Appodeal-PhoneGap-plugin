//
//  InneractiveAdSDK-AdView.h
//  InneractiveAdSDK
//
//  Created by Inneractive.
//  Copyright (c) 2015 Inneractive. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <InneractiveSDK/InneractiveAdSDK-Ad.h>

#pragma mark - IaAd Interface

@protocol InneractiveAdDelegate;

#pragma mark - IaAdView Interface

/**
 * The IaAdView class provides a UIView which can display banner, rectangle and interstitial ads.
 */
@interface IaAdView : IaAd

/**
 * Used to initialize the IaAdView object.
 *
 * @param NSString appId  The App Id as a string, registered on Inneractive's console (e.g., @"MyCompany_MyApp").
 * @param IaAdType adType The type of ad (e.g., IaAdType_Banner / IaAdType_Interstitial etc.)
 * @param id <InneractiveAdDelegate> adDelegate The Delegate parameter is a class implementing the <InneractiveAdDelegate> protocol.
 */
- (instancetype)initWithAppId:(NSString*)appId adType:(IaAdType)adType delegate:(id<InneractiveAdDelegate>)adDelegate;

- (instancetype)init __attribute__((unavailable("init should not be used for an IaAdView. call [[IaAdView alloc] initWithDelegate:adDelegate] instead.")));
- (instancetype)initWithFrame:(CGRect)frame __attribute__((unavailable("initWithFrame should not be used for an IaAdView. call [[IaAdView alloc] initWithFrame:frame andDelegate:adDelegate] instead.")));
- (instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((unavailable("initWithCoder should not be used for an IaAdView. call [[IaAdView alloc] initWithDelegate:adDelegate] instead.")));

/**
 * Optional method to limit the ad load time.
 */
- (void)setAdLoadTimeoutInSec:(NSTimeInterval)loadTimeout;

@end
