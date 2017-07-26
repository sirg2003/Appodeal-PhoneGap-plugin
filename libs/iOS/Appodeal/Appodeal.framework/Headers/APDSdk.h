//
//  APDSdk.h
//  Appodeal
//
//  AppodealSDK version 2.1.0-ReleaseCandidate-5
//
//  Copyright © 2017 Appodeal, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Appodeal/APDUserInfo.h>
#import <Appodeal/APDDefines.h>

/*!
 * Main sdk object, that managed network request, ad modules and statistics data.
 * You should initilize sdk before you start loading any ad types.
 * You can do this in 
 * @discussion - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 
 * @discussion for example.
 * @warning You must call sharedSdkWithApiKey:(NSString *)apiKey firstly. 
 * @discussion For example initializiton code can be something like this:
 * @code 
 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [[APDSdk sharedSdkWithApiKey: YOUR_API_KEY] initializeForAdTypes: APDAdTypeInterstitialAd];
 return YES;
 }
 * @endcode

 * After sdk initialization you can get instanse of sdk by calle [APDSdk sharedSdk];
 * You can additional set other sdk settings before/after sdk initialization
 */
@interface APDSdk : NSObject

/*!
 *  Unuvailabale initializer
 *
 *  @return nil
 */
- (instancetype)init NS_UNAVAILABLE;

/*!
 *  Unuvailabale initializer
 *
 *  @return nil
 */
+ (instancetype)new NS_UNAVAILABLE;

/*!
 *  Singleton instance of APDSdk
 *
 *  @discussion Objective-C
 *  @code [APDSdk sharedSdkWithApiKey:@"API_KEY"]; @endcode
 *
 *  @discussion Swift
 *  @code APDSdk.sharedSdkWithApiKey("API_KEY") @endcode
 *
 *  @param apiKey String API key parameter from Appodeal Dashboard
 *
 *  @return Singleton instance of APDSdk
 */
+ (instancetype)sharedSdkWithApiKey:(NSString *)apiKey;


/*!
 *  Always returns same instance SDK returned by first call of +sharedSdkWithApiKey:
 *
 *  @discussion Objective-C
 *  @code [APDSdk sharedSdk]; @endcode
 *
 *  @discussion Swift
 *  @code APDSdk.sharedSdk() @endcode
 *
 *  @return Instance of APDSdk
 */
+ (instancetype)sharedSdk;

/*!
 *  Call this method to specify framework before initialization
 *
 *  @discussion Objective-C
 *  @code [[APDSdk sharedSdk] setFramework:APDFrameworkNative]; @endcode
 *
 *  @discussion Swift
 *  @code APDSdk.sharedSdk().setFramework(APDFramework.native) @endcode
 *
 *  @param framework Type of framework. Default is native iOS SDK
 */
- (void)setFramework:(APDFramework)framework;

/*!
 *  Call this method to specify framework before initialization
 *  
 *  @param pluginVersion - NSString version plugin
 */
- (void)setPluginVersion:(NSString *)pluginVersion;

/*!
 *  Initializtion of sdk for types
 *
 *  @discussion Objective-C
 *  @code [[APDSdk sharedSdk] initializeForAdTypes:AppodealAdTypeInterstitial | AppodealAdTypeRewardedVideo]; @endcode
 *
 *  @discussion Swift
 *  @code 
    let adTypes: AppodealAdType = [.banner, .interstitial]
    APDSdk.sharedSdk().initializeForAdTypes(adTypes) @endcode
 *
 *  @param adTypes APDAdTypeInterstitialAd, APDAdTypeSkippableVideo, APDAdTypeBanner, APDAdTypeNativeAd, APDAdTypeRewardedVideo, APDAdTypeMREC
 */
- (void)initializeForAdTypes:(APDType)adTypes;

/*!
 *  Check that sdk is initialized for ad type
 *
 *  @discussion Objective-C
 *  @code [[APDSdk sharedSdk] isInitializedForAdType:AppodealAdTypeInterstitial]; @endcode
 *
 *  @discussion Swift
 *  @code APDSdk.sharedSdk().isInitializedForAdType(APDAdType.interstitial) @endcode
 *
 *  @param adType APDAdType value
 *
 *  @return YES if sdk initialized for this type, or NO if not
 */
- (BOOL)isInitializedForAdType:(APDType)adType;

/*!
 *  If you set YES to this method you get only
 *  test ad with 0$ eCPM
 *  @warning use this method before initilized sdk
 *  @discussion Objective-C
 *  @code [[APDSdk sharedSdk] setTesingMode:YES]; @endcode
 *
 *  @discussion Swift
 *  @code APDSdk.sharedSdk().setTesingMode(true) @endcode
 *
 *  @param enabled Boolean flag
 */
- (void)setTesingMode:(BOOL)enabled;

/*!
 *  Set targeting for more satisfying ads
 *
 *  @discussion Objective-C
 *  @code 
    APDUserInfo * userInfo = [APDUserInfo new];
    userInfo.age = 25;
    [[APDSdk sharedSdk] setUserInfo:userInfo];
 *  @endcode
 *
 *  @discussion Swift
 *  @code 
    let userInfo = APDUserInfo()
    userInfo.age = 25
    APDSdk.sharedSdk().setUserInfo(userInfo) 
 *  @endcode
 *
 *  @param userInfo Insatance of APDUserInfo class
 */
- (void)setUserInfo:(APDUserInfo *)userInfo;

/*!
 *  If you does not want to some ad network
 *  get user info call this method
 *
 *  @discussion Objective-C
 *  @code [[APDSdk sharedSdk] disableUserInfoForNetworkName:@"NETWORK_NAME"]; @endcode
 *
 *  @discussion Swift
 *  @code APDSdk.sharedSdk().disableUserInfoForNetworkName("NETWORK_NAME") @endcode
 *
 *  @param networkName Appodeal ad network name for example: @"mopub", @"admob"
 */
- (void)disableUserInfoForNetworkName:(NSString *)networkName;

/*!
 *  You can set custom rule by usage this method.
 *  Configure rules for segments in <b>Appodeal Dashboard</b>.
 *  @discussion For example, you want to use segment, when user complete 20 or more levels
 *  You create rule in dashboard with name "completedLevels" of type Int,
 *  operator GreaterThanOrEqualTo and value 10, now you implement folowing code:
 *
 *  @discussion Objective-C
 *  @code 
    NSDictionary * customRule = {@"completedLevels" : CURRENT_NUMBER_OF_COMPLETED_LEVELS};
    [[APDSdk sharedSdk] setCustomRule: customRule];
 *  @endcode
 *
 *  @discussion Swift
 *  And then CURRENT_NUMBER_OF_COMPLETED_LEVELS become 10 or greater
 *  You segments settings become available
 *
 *  @param customRule NSDictionary instance with keys that similar to  keys that you tune in Appodeal Dashboard's Segment settings block and values of similar types
 */
- (void)setCustomRule:(NSDictionary *)customRule;


/*!
 *  Appodeal SDK supports multiple log level for internal logging,
 *  and ONLY one (VERBOSE) log level for third party ad networks.
 *  To enable third party ad networks logging set log level to APDLogLevelVerbose.
 *  If log level other than APDLogLevelVerbose, all third party ad networks logging will be suppressed (if possible).
 *
 *  @param logLevel APDLogLevel value
 */
- (void)setLogLevel:(APDLogLevel)logLevel;

/*!
 *  Disabling/enabling loction tracking
 *
 *  @param enabled By default set to NO
 */
- (void)setLocationTracking:(BOOL)enabled;

/*!
 *  Reset UUID for tracking/targeting ad
 */
- (void)resetUUID;

/*!
 *  Enable memory monitoring for ad type. If current memory consuming higher than requiered level all caching ad objects will be released
 *  @warning loaded ad will return and could not be shown
 *  
 *  @param percentage Minimum percent of RAM is free from 1 to 100. If NSNotFound memory monitor is unactive
 *  @param observeSystemWarnings enable system warnings observing
 *  @param type Type of ad to use
 */
- (void)setMinimumFreeMemoryPercentage:(NSUInteger)percentage
                 observeSystemWarnings:(BOOL)observeSystemWarnings
                             forAdType:(APDType)type;

- (void)setChildDirectedTreatment:(BOOL)childDirectedTreatment;

@end


@interface APDSdk (InAppPurchase)

/*!
 *  In-app purchase tracking.
 *  Call this method after user make some in-app purchase
 *
 *  @param amount   Amount of in-app purchase, for example @0.99
 *  @param currency In-app purchase currency, for example @"USD"
 */
- (void)trackInAppPurchase:(NSNumber *)amount currency:(NSString *)currency;

@end
