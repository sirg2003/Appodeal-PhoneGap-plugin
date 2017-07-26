//
//  InneractiveAdSDK-GeneralConfig.h
//  InneractiveAdSDK
//
//  Created by Inneractive.
//  Copyright (c) 2015 Inneractive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <InneractiveSDK/InneractiveAdSDK-Ad.h>

/**
 * The InneractiveAdSDKGeneralConfig class enables setting the global InneractiveAdSDK configuration.
 */
@interface InneractiveAdSDKGeneralConfig : NSObject

/**
 * @param bitrateMaxWifi The max video bitrate above which the video will be filtered out from the received playlist, when connected through WiFi.
 */
- (NSInteger)bitrateMaxWifi;

- (void)setBitrateMaxWifi:(NSInteger)bitrateMaxWifi;

/**
 * @param bitrateMax3g The max video bitrate above which the video will be filtered out from the playlist when connected to a cellular data network.
 */
- (NSInteger)bitrateMax3g;

- (void)setBitrateMax3g:(NSInteger)bitrateMax3g;

/**
 * @param buffWifiTimeout The timeout for video buffering in Wifi.
 */
- (NSInteger)buffWifiTimeout;

- (void)setBuffWifiTimeout:(NSInteger)buffWifiTimeout;

/**
 * @param buff3gTimeout The timeout for video buffering when connected to a cellular data network.
 */
- (NSInteger)buff3gTimeout;

- (void)setBuff3gTimeout:(NSInteger)buff3gTimeout;

/**
 * @param prerollWifiTimeout The timeout for video loading in Wifi.
 */
- (NSInteger)prerollWifiTimeout;

- (void)setPrerollWifiTimeout:(NSInteger)prerollWifiTimeout;

/**
 * @param preroll3gTimeout The timeout for video loading when connected to a cellular data network.
 */
- (NSInteger)preroll3gTimeout;

- (void)setPreroll3gTimeout:(NSInteger)preroll3gTimeout;

/**
 * @param refreshOnNoAd Start refresh automatically X seconds after video ad returned no-ad.
 */
- (NSInteger)refreshOnNoAd;

- (void)setRefreshOnNoAd:(NSInteger)refreshOnNoAd;

/**
 * @param refreshOnError Start refresh automatically X seconds after video ad error.
 */
- (NSInteger)refreshOnError;

- (void)setRefreshOnError:(NSInteger)refreshOnError;

/**
 * @param refreshOnComplete  Start refresh automatically X seconds after video ad completed playing.
 */
- (NSInteger)refreshOnComplete;

- (void)setRefreshOnComplete:(NSInteger)refreshOnComplete;

/**
 * @param disableAutoFetch Should / should not disable auto fetching videos.
 */
- (BOOL)disableAutoFetch;

- (void)setDisableAutoFetch:(BOOL)disableAutoFetch;

/**
 * @param showCompanion Should / should not display companion ads.
 */
- (BOOL)showCompanion;

- (void)setShowCompanion:(BOOL)showCompanion;

/**
 * @param nativeVideoShouldAutoplay
 */
- (BOOL)nativeVideoShouldAutoplay;

- (void)setNativeVideoShouldAutoplay:(BOOL)nativeVideoShouldAutoplay;

/**
 * @param nativeVideoShouldBeMuted
 */
- (BOOL)nativeVideoShouldBeMuted;

- (void)setNativeVideoShouldBeMuted:(BOOL)nativeVideoShouldBeMuted;

typedef NS_ENUM(NSInteger, InneractiveInterstitialVideoSkipMode) {
    InneractiveInterstitialVideoSkipModeDefault = 0,
    InneractiveInterstitialVideoSkipModeMinTime = 1,
    InneractiveInterstitialVideoSkipModeDisabled = 2
};
- (InneractiveInterstitialVideoSkipMode)interstitialVideoSkipMode;
- (void)setInterstitialVideoSkipMode:(InneractiveInterstitialVideoSkipMode)interstitialVideoSkipMode;

@end
