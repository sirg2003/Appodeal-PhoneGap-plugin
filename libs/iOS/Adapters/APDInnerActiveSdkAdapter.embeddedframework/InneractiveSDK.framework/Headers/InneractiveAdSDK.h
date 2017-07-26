//
//  InneractiveAdSDK.h
//  InneractiveAdSDK
//
//  Created by Inneractive.
//  Copyright (c) 2015 Inneractive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <InneractiveSDK/InneractiveAdSDK-AdConfig.h>
#import <InneractiveSDK/InneractiveAdSDK-AdView.h>
#import <InneractiveSDK/InneractiveAdSDK-NativeAd.h>
#import <InneractiveSDK/InneractiveAdSDK-AdDelegate.h>
#import <InneractiveSDK/InneractiveAdSDK-GeneralConfig.h>

#pragma mark - Inneractive Ad SDK API

/**
 * The Inneractive iOS AD SDK API allows retrieving and displaying ads from Inneractive's Ad Server. */

@interface InneractiveAdSDK : NSObject {}

#pragma mark - Inneractive Ad SDK Singleton Initialization

/**---------------------------------------------------------------------------------------
 @name InneractiveAdSDK Access
 * ---------------------------------------------------------------------------------------
 */

/**  Returns the single-instance of the Inneractive SDK class.
 
 The single-instance can be used to initiate ad requests and manage any Inneractive ads inside your application.
 
 Example Usage: 
        <pre><code> [[InneractiveAdSDK sharedInstance] loadAd:myAdView]; </pre></code>
 
 @return initialized Inneractive SDK ad manager single shared instance / nil on error.
 */
+ (instancetype)sharedInstance;


/** Entry point to which can be used in order to initialize the Inneractive Ad SDK.
 
 This initialization should normally be added to - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions .
 It is recommended to intialize the SDK prior to loading ads, in order for any remote settings to take affect before any ads are requested, however
 if this method is not called on app. startup, the SDK will be lazy-loaded upon the first loading of an ad.
 
 Example Usage:
    <pre><code> [[InneractiveAdSDK sharedInstance] initialize]; </pre></code>
 */
- (void)initialize;

#pragma mark - Inneractive Ad SDK API Methods

/**---------------------------------------------------------------------------------------
 * @name API
 * ---------------------------------------------------------------------------------------
 */

/** Loads an Inneractive ad.
 
 @param IaAd ad A pre-initialized IaAd object which holds the ad configuration and the ad events delegate.
 
 @note The InneractiveAdLoaded and InneractiveAdFailed delegate event methods should be implemented in order to get notified of any async. ad-loading success / failure.
 */
- (void)loadAd:(IaAd *)ad;

/** Removes saved ad resources and discards the ad. Can be used for cleanup.
 
 This method should be called only after loading an ad using the loadAd function.
 InneractiveAdLoaded and InneractiveAdFailed delegate events should also be implemented in order to get notified of any async. failure / success.
 
 @param ad A pre-initialized IaAd object which holds the ad configuration and the ad events delegate.
 */
- (void)removeAd:(IaAd *)ad;

/** Shows a pre-loaded Interstitial Ad.
 
 This method should be called only after loading an Interstitial ad using the loadAd function and with an adView.adConfig.adType = IaAdType_InterstitialAd, 
 prefereably only inside the InneractiveAdLoaded / InneractiveDefaultAdLoaded delegate functions.
 
 @param adView A pre-initialized IaAdView object which holds the Interstitial ad configuration and the ad events delegate.
 */
- (void)showInterstitialAd:(IaAdView *)adView;

/** Checks if an Interstitial Ad has finished pre-loading and is ready to be displayed.
 
 This method should be called only after loading an interstitial ad using the loadAd function.
 
 @param adView A pre-initialized IaAdView object which holds the Interstitial ad configuration and the ad events delegate.
 */
- (BOOL)isInterstitialReady:(IaAdView *)adView;

#pragma mark - Native Ad methods

/** Shows a pre-loaded Native Ad loaded using the loadAd method.
 This method should be called only after loading a native ad ad using the loadAd function and with an nativeAd.adConfig.adType = IaAdType_NativeAd / IaAdType_InFeedNativeAd.
 
 @param nativeAd A pre-initialized nativeAd object which holds the native ad ad configuration and the ad events delegate.
 @param viewForNativeAd A view that implements 'layoutAdAssets:' method
 */
- (void)showNativeAd:(IaNativeAd *)nativeAd atView:(UIView<IaNativeAdRenderingDelegate> *)viewForNativeAd;

/** Shows a pre-loaded Native Ad inside a table view loaded using the loadAd method.
 
 This method should be called only after loading a native ad ad using the loadAd function and with an nativeAd.adConfig.adType = IaAdType_NativeAd / IaAdType_InFeedNativeAd.

 @param nativeAd A pre-initialized nativeAd object which holds the native ad ad configuration and the ad events delegate.
 */
- (void)showNativeAd:(IaNativeAd *)nativeAd atCell:(UIView<IaNativeAdCellRenderingDelegate> *)cell;

/**
 Loads a pre-loaded FB Native ad icon into a supplied UIImageView.
 Call to this method from 'layoutAdAssets:' method.
 
 @param iconImageView A UIImageView object which will contain FB Native ad icon.
 @param nativeAd A pre-loaded nativeAd object which holds the native ad ad configuration and the ad events delegate.
 */
- (void)loadIconIntoImageView:(UIImageView *)iconImageView withNativeAd:(IaNativeAd *)nativeAd;

/**
 Loads a pre-loaded Native ad title into a supplied UILabel.
 Call to this method from 'layoutAdAssets:' method.
 
 @param titleLabel A UILabel object which will contain FB Native ad title.
 @param nativeAd A pre-loaded nativeAd object which holds the native ad ad configuration and the ad events delegate.
 */
- (void)loadTitleIntoTitleLabel:(UILabel *)titleLabel withNativeAd:(IaNativeAd *)nativeAd;

/**
 Loads a pre-loaded Native ad body text into a supplied UILabel.
 Call to this method from 'layoutAdAssets:' method.
 
 @param bodyTextLabel A UILabel object which will contain FB Native ad body text.
 @param nativeAd A pre-loaded nativeAd object which holds the native ad ad configuration and the ad events delegate.
 */
- (void)loadBodyTextIntoTitleLabel:(UILabel *)bodyTextLabel withNativeAd:(IaNativeAd *)nativeAd;

/**
 Loads a pre-loaded Native ad "call to action" text into a supplied UILabel.
 Call to this method from 'layoutAdAssets:' method.
 
 @param callToActionLabel A UILabel object which will contain FB Native ad "call to action" text.
 @param nativeAd A pre-loaded nativeAd object which holds the native ad ad configuration and the ad events delegate.
 */
- (void)loadCallToActionIntoLabel:(UILabel *)callToActionLabel withNativeAd:(IaNativeAd *)nativeAd;

/**
 Loads a pre-loaded Native Ad Video or Image into a UIView.
 Call to this method from 'layoutAdAssets:' method.
 
 @param view A UIView object which will contain the native ad loaded video.
 @param nativeAd A pre-loaded nativeAd object which holds the native ad ad configuration and the ad events delegate.
 */
- (void)loadMainAssetIntoView:(UIView *)view withNativeAd:(IaNativeAd *)nativeAd;

/**
 Loads a pre-loaded FB Native ad social context text into a supplied UILabel.
 Call to this method from 'layoutAdAssets:' method.
 
 @param socialContextLabel A UILabel object which will contain FB Native ad social context text.
 @param nativeAd A pre-loaded nativeAd object which holds the native ad ad configuration and the ad events delegate.
 */
- (void)loadSocialContextIntoSocialContextLabel:(UILabel *)socialContextLabel withNativeAd:(IaNativeAd *)nativeAd;

- (void)loadStarRatingIntoView:(UIView *)starRatingView withNativeAd:(IaNativeAd *)nativeAd;

#pragma mark - Special Optional Methods

/** Optional method for notfiying the adView of manual rotation changes in case the application doesn't use autorotation.
 @param toInterfaceOrientation the UIInterfaceOrientation which the ad should rotate to.
 */
- (void)rotateAdView:(IaAdView *)adView ToOrientation:(UIInterfaceOrientation)toInterfaceOrientation;

#pragma mark - Mediation

/*
 * IaAdMediationType Enum
 * - IaAdMediationType_None - The regular use case - not running inside an ad mediation platform.
 * - IaAdMediationType_Mopub - Running inside the Mopub mediation platform.
 * - IaAdMediationType_AdMob - Running inside the AdMob mediation platform.
 * - IaAdMediationType_Other - Running inside some other mediation platform.
 */
typedef NS_ENUM(NSUInteger, IaAdMediationType) {
    IaAdMediationType_None = 0,
    IaAdMediationType_Mopub = 1,
    IaAdMediationType_AdMob = 2,
    IaAdMediationType_Other = 3
};

/**
 * Optional method to notify that the ad is running under a mediation platform.
 * setting the mediation type to anything other than the default (IaAdMediationType_None) disables
 * automatic ad refreshes.
 @param mediationType the Mediation the ad is running under.
 */
- (void)setAdMediationType:(IaAdMediationType)mediationType;

/**
 * Use this method to set Facebook Native ads placement id and enable FB Native ads
 */
- (void)setFacebookNativeAdPlacementID:(NSString *)facebookNativeAdPlacementID;

#pragma mark - Utilities

/**----------------------------------------------------------------------------------
 * @name Utilities
 * ----------------------------------------------------------------------------------
 */

/*
 * IaLogLevel Enum
 * - IaLogLevel_Debug - Includes debug information, general info., warnings and error logging.
 * - IaLogLevel_Info - Includes general info., warnings and error logging.
 * - IaLogLevel_Warn - Includes warnings and error logging.
 * - IaLogLevel_Error - Includes error logging only.
 */
typedef NS_ENUM(NSUInteger, IaLogLevel) {
    IaLogLevel_Debug = 1,
    IaLogLevel_Info = 2,
    IaLogLevel_Warn = 3,
    IaLogLevel_Error = 4
};

/**
 * Sets the log level which is outputted to XCode's console.
 */
+ (void)setLogLevel:(IaLogLevel)logLevel;

/**
 Returns the current SDK version number.
 @return sdkVersion as a float number (e.g., 5.01)
 */
+ (float)sdkVersion;

// The alloc, init and new methods should not be used to initialize and use the InneractiveSDK class. [InneractiveAdSDK sharedInstance] should be used instead.
- (instancetype)init __attribute__((unavailable("init not available, call [InneractiveAdSDK sharedInstance] instead")));
+ (instancetype)new __attribute__((unavailable("new not available, call [InneractiveAdSDK sharedInstance] instead")));

#pragma mark - General SDK Configuration

/**
 * The sdkConfig object can be used to set the general SDK configuration InneractiveAdSDKGeneralConfig (e.g., general video behaviour etc.)
 */
@property (nonatomic, strong, readonly) InneractiveAdSDKGeneralConfig *sdkConfig;

- (void)testRemoteConfig:(NSString *)config;

@end
