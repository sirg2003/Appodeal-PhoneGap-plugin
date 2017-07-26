//
//  APDDefines.h
//  Appodeal
//
//  AppodealSDK version 2.1.0-ReleaseCandidate-5
//
//  Copyright © 2017 Appodeal, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

FOUNDATION_EXPORT const CGSize kAppodealUnitSize_320x50;
FOUNDATION_EXPORT const CGSize kAppodealUnitSize_300x250;
FOUNDATION_EXPORT const CGSize kAppodealUnitSize_728x90;

FOUNDATION_EXPORT NSArray * AppodealAvailableUnitSizes();

FOUNDATION_EXPORT BOOL AppodealIsUnitSizeSupported(const CGSize size, NSArray *supportedSizes);
FOUNDATION_EXPORT BOOL AppodealIsUnitSizeAvailable(const CGSize size);


FOUNDATION_EXPORT CGSize AppodealNearestUnitSizeForSize(CGSize size);

/*!
 *  Appodeal ads types
 */
typedef NS_OPTIONS(NSInteger, AppodealAdType) {
    /*!
     *  Interstitial
     */
    AppodealAdTypeInterstitial      = 1 << 0,
    /*!
     *  Skippable video (can be skipped by user after several seconds of watch)
     */
    AppodealAdTypeSkippableVideo __attribute__((deprecated("Use AppodealAdTypeInterstitial")))   = 1 << 1,
    /*!
     *  Banner ads
     */
    AppodealAdTypeBanner            = 1 << 2,
    /*!
     *  Native ads
     */
    AppodealAdTypeNativeAd          = 1 << 3,
    /*!
     *  Rewarded video (return reward parameter in finish callback, can not be skipped by user)
     */
    AppodealAdTypeRewardedVideo     = 1 << 4,
    /*!
     *  Rectangle banner of size 300 x 250
     */
    AppodealAdTypeMREC              = 1 << 5,
    /*!
     *  Non skippable video (does not return reward parameter in finish callback, can not be skipped by user)
     */
    AppodealAdTypeNonSkippableVideo = 1 << 6,
};

/*!
 *  Appodeal styles to show
 */
typedef NS_OPTIONS(NSInteger, AppodealShowStyle) {
    /*!
     *  Show interstial ads
     */
    AppodealShowStyleInterstitial       = 1 << 0,
    /*!
     *  Show skippable ads
     */
    AppodealShowStyleSkippableVideo __attribute__((deprecated("Use bit mask AppodealShowStyleInterstitial")))  = AppodealShowStyleInterstitial,
    /*!
     *  - If both ready, show ad that eCPM heigher
     *  @discussion - If one of this types ready, show with ad
     *  @discussion - If no one ready, waiting for first ready
     */
    AppodealShowStyleVideoOrInterstitial __attribute__((deprecated("Use bit mask AppodealShowStyleInterstitial"))) = AppodealShowStyleInterstitial,
    /*!
     *  Show banner at top of screen
     */
    AppodealShowStyleBannerTop          = 1 << 2,
    /*!
     *  Show banner at bottom of screen
     */
    AppodealShowStyleBannerBottom       = 1 << 3,
    /*!
     *  Show rewareded video
     */
    AppodealShowStyleRewardedVideo      = 1 << 4,
    /*!
     *  Show non skippable video
     */
    AppodealShowStyleNonSkippableVideo  = 1 << 5
};

typedef NS_ENUM(NSUInteger, AppodealUserGender) {
    AppodealUserGenderOther = 0,
    AppodealUserGenderFemale,
    AppodealUserGenderMale
};

typedef NS_ENUM(NSUInteger, AppodealUserOccupation) {
    AppodealUserOccupationOther = 0,
    AppodealUserOccupationWork,
    AppodealUserOccupationSchool,
    AppodealUserOccupationUniversity
};

typedef NS_ENUM(NSUInteger, AppodealUserRelationship) {
    AppodealUserRelationshipOther = 0,
    AppodealUserRelationshipSingle,
    AppodealUserRelationshipDating,
    AppodealUserRelationshipEngaged,
    AppodealUserRelationshipMarried,
    AppodealUserRelationshipSearching
};

typedef NS_ENUM(NSUInteger, AppodealUserSmokingAttitude) {
    AppodealUserSmokingAttitudeNegative = 1,
    AppodealUserSmokingAttitudeNeutral,
    AppodealUserSmokingAttitudePositive
};

typedef NS_ENUM(NSUInteger, AppodealUserAlcoholAttitude) {
    AppodealUserAlcoholAttitudeNegative = 1,
    AppodealUserAlcoholAttitudeNeutral,
    AppodealUserAlcoholAttitudePositive
};

/*!
 *  Declaration of banner delegate
 */
@protocol AppodealBannerDelegate <NSObject>

@optional
/*!
 *  Method called when precache (cheap and fast load) or usual banner view did load
 *
 *  @param precache If precache is YES it's mean that precache loaded
 */
- (void)bannerDidLoadAdIsPrecache:(BOOL)precache;

/*!
 *  Method called when banner did load and ready to show
 */
- (void)bannerDidLoadAd __attribute__((deprecated("Use -bannerDidLoadAdisPrecache:precache: instead")));

/*!
 *  Method called when banner refresh
 */
- (void)bannerDidRefresh __attribute__((deprecated("Use -bannerDidShow instead")));

/*!
 *  Method called if banner mediation failed
 */
- (void)bannerDidFailToLoadAd;

/*!
 *  Method called when user tap on banner
 */
- (void)bannerDidClick;

/*!
 *  Method called when banner show or refresh
 */
- (void)bannerDidShow;

@end

/*!
 *  Interstital delegate declaration
 */
@protocol AppodealInterstitialDelegate <NSObject>

@optional

/*!
 *  Method called when usual interstitial view did load
 *
 */
- (void)interstitialDidLoadAd __attribute__((deprecated("Use -interstitialDidLoadAdisPrecache: instead")));

/*!
 *  Method called when precache (cheap and fast load) or usual interstitial view did load
 *  @warning If you want show only expensive ad, ignore this callback call with precache equal to YES
 *
 *  @param precache If precache is YES it's mean that precache loaded
 */
- (void)interstitialDidLoadAdisPrecache:(BOOL)precache;

/*!
 *  Method called if interstitial mediation failed
 */
- (void)interstitialDidFailToLoadAd;

/*!
 *  Method called if interstitial mediation was success, but ready ad network can't show ad or
 *  ad presentation was to frequently according your placement settings
 */
- (void)interstitialDidFailToPresent;

/*!
 *  Method called when interstitial will display on screen
 */
- (void)interstitialWillPresent;

/*!
 *  Method called after interstitial leave screeen
 */
- (void)interstitialDidDismiss;

/*!
 *  Method called when user tap on interstitial
 */
- (void)interstitialDidClick;

@end


/*!
 *  Rewarded video delegate declaration
 */
@protocol AppodealRewardedVideoDelegate <NSObject>

@optional

/*!
 *  Method called when rewarded video did load
 */
- (void)rewardedVideoDidLoadAd;

/*!
 *  Mehtod called if rewarded video mediation failed
 */
- (void)rewardedVideoDidFailToLoadAd;

/*!
 *  Method called if interstitial mediation was success, but ready ad network can't show ad or
 *  ad presentation was to frequently according your placement settings
 */
- (void)rewardedVideoDidFailToPresent;

/*!
 *  Method called after rewarded video start displaying
 */
- (void)rewardedVideoDidPresent;

/*!
 *  Methof called before rewarded video leave screen
 */
- (void)rewardedVideoWillDismiss;

/*!
 *  Method called after fully watch of video
 *  @warning After call this method rewarded video can stay on screen and show postbanner
 *
 *  @param rewardAmount Amount of app curency tuned via Appodeal Dashboard
 *  @param rewardName   Name of app curency tuned via Appodeal Dashboard
 */
- (void)rewardedVideoDidFinish:(NSUInteger)rewardAmount name:(NSString *)rewardName;

/*!
 *  Method called after user tap on screen
 *  @warning Not all ad networks provides this callback!
 */
- (void)rewardedVideoDidClick __attribute__((deprecated("Not all ad networks return this action")));

@end


/*!
 *  Non skippable video delegate
 */
@protocol AppodealNonSkippableVideoDelegate <NSObject>

@optional

/*!
 *  Method called when non skippable video did load
 */
- (void)nonSkippableVideoDidLoadAd;

/*!
 *  Mehtod called if non skippable video mediation failed
 */
- (void)nonSkippableVideoDidFailToLoadAd;

/*!
 *  Method called after non skippable video start displaying
 */
- (void)nonSkippableVideoDidPresent;

/*!
 *  Method called if non skippable mediation was success, but ready ad network can't show ad or
 *  ad presentation was to frequently according your placement settings
 */
- (void)nonSkippableVideoDidFailToPresent;

/*!
 *  Methof called before non skippable video leave screen
 */
- (void)nonSkippableVideoWillDismiss;

/*!
 *  Method called after fully watch of video
 *  @warning After call this method non skippable video can stay on screen and show postbanner
 *
 */
- (void)nonSkippableVideoDidFinish;

/*!
 *  Method called after user tap on screen
 *  @warning Not all ad networks provides this callback!
 */
- (void)nonSkippableVideoDidClick __attribute__((deprecated("Not all ad networks return this action")));

@end



/*!
 *  Skippable video delegate
 */
@protocol AppodealSkippableVideoDelegate <NSObject>

@optional

/*!
 *  Method called when skippable video did load
 */
- (void)skippableVideoDidLoadAd;

/*!
 *  Mehtod called if skippable video mediation failed
 */
- (void)skippableVideoDidFailToLoadAd;

/*!
 *  Method called after skippable video start displaying
 */
- (void)skippableVideoDidPresent;

/*!
 *  Methof called before skippable video leave screen
 */
- (void)skippableVideoWillDismiss;

/*!
 *  Method called after fully watch of video, if user skipp video this callback not called
 *  @warning After call this method skippable video can stay on screen and show postbanner
 *  @warning Not all ad networks provides this callback!
 *
 */
- (void)skippableVideoDidFinish;

/*!
 *  Method called after user tap on screen
 *  @warning Not all ad networks provides this callback!
 */
- (void)skippableVideoDidClick;

@end


@protocol AppodealNativeAdDelegate <NSObject>

/*!
 *  Method called after native ads did load
 */
- (void)didLoadNativeAds:(NSInteger)count;

/*!
 *  Method called if native ads get some error while loading
 */
- (void)didFailToLoadNativeAdsWithError:(NSError *)error;

@end


/*!
 *  Default APDBanner sizes
 */
extern const CGSize kAPDAdSize320x50;
extern const CGSize kAPDAdSize728x90;
extern const CGSize kAPDAdSize300x250;

/*!
 *  Used in native ad image
 *  Equals to CGSizeZero
 */
extern const CGSize kAPDImageSizeUndefined;

/*!
 *  Size validation
 *
 *  @param size kAPDAdSize320x50, kAPDAdSize728x90, kAPDAdSize300x250
 *
 *  @return BOOL
 */
extern BOOL   APDIsAdSizeValid(const CGSize size);

/*!
 *  Getter of nearest appodeal valid size
 *
 *  @param size CGSize
 *
 *  @return kAPDAdSize320x50, kAPDAdSize728x90, kAPDAdSize300x250
 */
extern CGSize APDNearestValidAdSizeForCGSize(const CGSize size);

/*!
 *  Getter of current sdk version
 *
 *  @return current sdk version
 */
NSString * APDSdkVersionString();

extern NSString * const kAPDErrorDomain;

/*!
 *  Appodeal sdk error types
 */
typedef NS_ENUM(NSInteger, APDError) {
    /*!
     *  Unknown error
     */
    APDUnknownError = 195944097,
    /*!
     * Inconsistency error, occure for example if some kind 
     * of ads start loading, but APDSdk does not initialized 
     * for this type
     */
    APDInternalInconsistencyError,
    /*!
     *  Any network error, for example server is not available
     */
    APDNetworkingError,
    /*!
     *  Errors of this type occure if some network responses contains
     *  data of unsupported/unexpected type
     */
    APDJSONDecodeError,
    /*!
     *  Ad network returns no fill
     */
    APDNoFillError,
    /*!
     *  Mediation failed
     */
    APDMediationError,
    /*!
     *  Presentation failed
     */
    APDPresentationError,
    /*!
     *  Device offline or ready ad not conforms presentation settings
     */
    APDInconsistencyPresentationError,
    /*!
     *  Inconsistency size
     */
    APDInvalidAdSizeError,
    /*!
     *  Handled exception size
     */
    APDHandledExceptionError,
    /*!
     *  Invalid type was loaded
     */
    APDInvalidAdTypeError,
    /*!
     *  Ad unit returned from server contains invalid data
     */
    APDIncorrectAdUnitError,
    /*!
     *  Error while unarchiving cached data
     */
    APDUnarchiveError,
    /*!
     *  Insufficiently device's current memory
     */
    APDLowMemoryError
};


/*!
 *  Log flags
 */
typedef NS_OPTIONS(NSUInteger, APDLogFlag) {
    /*!
     *  Only error messages is writed to console.
     *  If you see this messages, you must to 
     *  check your integration
     */
    APDLogFlagError   = 1 << 0,
    /*!
     *  Warning and error messages is writed to console.
     *  Different warnings occured while sdk work
     */
    APDLogFlagWarning = 1 << 1,
    /*!
     *  Erorr, warning and information messages is writed to console.
     */
    APDLogFlagInfo    = 1 << 2,
    /*!
     *  Debug messages writed to console
     */
    APDLogFlagDebug   = 1 << 3,
    /*!
     *  All sdk messages writed to console
     */
    APDlogFlagVerbose = 1 << 4
};

/*!
 *  Log levels. Set some value to [APDSdk setLogLevel:]
 */
typedef NS_ENUM(NSUInteger, APDLogLevel) {
    /*!
     *  Log levels
     */
    APDLogLevelOff     = 0,
    /*!
     *  Only error messages is writed to console.
     *  If you see this messages, you must to
     *  check your integration
     */
    APDLogLevelError   = APDLogFlagError,
    /*!
     *  Warning and error messages is writed to console.
     *  Different warnings occured while sdk work
     */
    APDLogLevelWarning = APDLogLevelError   | APDLogFlagWarning,
    /*!
     *  Erorr, warning and information messages is writed to console.
     */
    APDLogLevelInfo    = APDLogLevelWarning | APDLogFlagInfo,
    /*!
     *  Debug messages writed to console
     */
    APDLogLevelDebug   = APDLogLevelInfo    | APDLogFlagDebug,
    /*!
     *  All sdk messages writed to console
     */
    APDLogLevelVerbose = APDLogLevelDebug   | APDlogFlagVerbose
};

/*!
 *  APDSdk supported ad types. You can initialize sdk with
 *  several ad types, by usage binary operand |
 *  For example: APDAdTypeInterstitialAd | APDAdTypeSkippableVideo
 */
typedef NS_OPTIONS(NSUInteger, APDType) {
    /*!
     *  Interstital ad
     */
    APDTypeInterstitialAd = 1 << 0,
    /*!
     *  Skippable video ad
     */
    APDTypeSkippableVideo __attribute__((deprecated("Use APDAdTypeInterstitialAd instead"))) = 1 << 1,
    /*!
     *  Banner ad
     */
    APDTypeBanner         = 1 << 2,
    /*!
     *  Native ad
     */
    APDTypeNativeAd       = 1 << 3,
    /*!
     *  Rewarded ad
     */
    APDTypeRewardedVideo  = 1 << 4,
    /*!
     *  Rectangle banner (banner of size 300x250)
     */
    APDTypeMREC           = 1 << 5
};

/*!
 *  Native ad types
 */
typedef NS_ENUM(NSUInteger, APDNativeAdType) {
    /*!
     * Native ad loaded can contains video
     * It's depend filled ad network
     */
    APDNativeAdTypeAuto = 0,
    /*!
     *  Native ad contains video
     */
    APDNativeAdTypeVideo,
    /*!
     *  Native ad  does not contain video
     */
    APDNativeAdTypeNoVideo
};

/*!
 *  Gender enum
 */
typedef NS_ENUM(NSUInteger, APDUserGender) {
    /*!
     *  User's gender is undefined
     */
    APDUserGenderOther = 0,
    /*!
     *  Female
     */
    APDUserGenderFemale,
    /*!
     *  Male
     */
    APDUserGenderMale
};

/*!
 *  User ocupation
 */
typedef NS_ENUM(NSUInteger, APDUserOccupation) {
    /*!
     *  User's occupation is undefined / not contains in other values
     */
    APDUserOccupationOther = 0,
    /*!
     *  Work
     */
    APDUserOccupationWork,
    /*!
     *  School
     */
    APDUserOccupationSchool,
    /*!
     *  University
     */
    APDUserOccupationUniversity
};

/*!
 *  User relationship
 */
typedef NS_ENUM(NSUInteger, APDUserRelationship) {
    /*!
     *  User's relationship is undefined / not contains in other values
     */
    APDUserRelationshipOther = 0,
    /*!
     *  Single
     */
    APDUserRelationshipSingle,
    /*!
     *  Dating
     */
    APDUserRelationshipDating,
    /*!
     *  Engaged
     */
    APDUserRelationshipEngaged,
    /*!
     *  Married
     */
    APDUserRelationshipMarried,
    /*!
     *  Searching
     */
    APDUserRelationshipSearching
};

/*!
 *  User smoking attitued
 */
typedef NS_ENUM(NSUInteger, APDUserSmokingAttitude) {
    /*!
     *  Doesn't smoke
     */
    APDUserSmokingAttitudeNegative = 1,
    /*!
     *  Neutral position
     */
    APDUserSmokingAttitudeNeutral,
    /*!
     *  Smoke
     */
    APDUserSmokingAttitudePositive
};

/*!
 *  Alcohol attitude
 */
typedef NS_ENUM(NSUInteger, APDUserAlcoholAttitude) {
    /*!
     *  Negative
     */
    APDUserAlcoholAttitudeNegative = 1,
    /*!
     *  Neutral
     */
    APDUserAlcoholAttitudeNeutral,
    /*!
     *  Positive
     */
    APDUserAlcoholAttitudePositive
};

typedef NS_ENUM(NSUInteger, APDFramework) {
    APDFrameworkNative = 1,
    APDFrameworkUnity,
    APDFrameworkCocos2d,
    APDFrameworkMarmalade,
    APDFrameworkPhoneGap,
    APDFrameworkGiderosMobile,
    APDFrameworkAdobeAir,
    APDFrameworkCordova,
    APDFrameworkXamarin,
    APDFrameworkGameMaker,
    APDFrameworkMonkeyX,
    APDFrameworkSC2,
    APDFrameworkLibGDX,
    APDFrameworkQt,
    APDFrameworkUE4,
    APDFrameworkReactNative,
    APDFrameworkCorona,
    APDFrameworkStencyl,
    APDFrameworkSDKBox,
    APDFrameworkDefold
};


