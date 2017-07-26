//
//  InneractiveAdSDK-AdConfig.h
//  InneractiveAdSDK
//
//  Created by Inneractive.
//  Copyright (c) 2015 Inneractive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#pragma mark - Ad Types

/**
 * IaAdType Enum:
 *
 * IaAdType_Banner              - Banner Ad
 *
 * IaAdType_Interstitial        - Interstitial Ad
 *
 * IaAdType_Rectangle           - Rectangular Ad
 *
 * IaAdType_NativeAd            - Native Ad
 *
 * IaAdType_InFeedNativeAd      - In-Feed Native Ad
 */
typedef NS_ENUM(NSUInteger, IaAdType) {
    IaAdType_Banner = 1,
    IaAdType_Rectangle = 2,
	IaAdType_Interstitial = 3,
    IaAdType_NativeAd = 4,
    IaAdType_InFeedNativeAd = 5
};

/**
 * IaNativeVideoCounterPosition Enum:
 *
 * IaNativeVideoCounterPositionTopLeft      - top left position
 *
 * IaNativeVideoCounterPositionTopRight     - top right position
 *
 * IaNativeVideoCounterPositionBottomRight  - bottom right position
 *
 * IaNativeVideoCounterPositionBottomLeft   - bottom left position
 */
typedef NS_ENUM(NSUInteger, IaNativeVideoCounterPosition) {
    IaNativeVideoCounterPositionTopLeft = 1,
    IaNativeVideoCounterPositionTopRight = 2,
    IaNativeVideoCounterPositionBottomRight = 3,
    IaNativeVideoCounterPositionBottomLeft = 4
};

@class IaNativeAdAssetDescription;

#pragma mark - IaAdConfig Interface

/**
 * IaAdConfig class holds the ad configuration parameters
 */
@interface IaAdConfig : NSObject {}

/**
 * The Inneractive App ID for this ad view.
 *
 * App IDs are created in the Inneractive console website (at http://console.inner-active.com).
 * An ad spot is a defined placement in your application set aside for advertising.
 */
@property (nonatomic, copy) NSString *appId;

/**
 * The Ad type (e.g., IaAdType_Banner for banner only ads, IaAdType_Interstitial for interstitial ads and IaAdType_Rectangle for rectangle ads).
 */
@property (nonatomic, assign) IaAdType adType;

/**
 * The Inneractive ad refresh interval in seconds once the ad is displayed. This interval is only applicable for Banner and Rectangle ads. Interstitial ads are never refreshed on  display.
 */
@property (nonatomic, assign) int refreshIntervalInSec;

/**
 * A string representing a set of keywords that should be passed to Inneractive's Ad Server in order
 * to receive more relevant advertising.
 */
@property (nonatomic, strong) NSString *adKeyWords;

/**
 * Used to pass the user's gender, if available, as a string which can contain the values: M / m / F / f / Male / Female .
 */
@property (nonatomic, strong) NSString *userGender;

/**
 * Used to pass the user's zip-code. A valid zip code must consist of a group of 5 numbers or a group of 5 numbers and then 4 numbers,
 * with an optional dash in between.
 */
@property (nonatomic, strong) NSString *zipCode;

/**
 * Used to pass the user's age in years, if available, as an integer number between 0 and 150.
 */
@property (nonatomic, assign) NSUInteger userAge;

/**
 * A 'CLLocation' object representing a user's location that should be passed to Inneractive's Ad Server
 * in order to receive more relevant advertising.
 */
@property (nonatomic, copy) CLLocation *location;

/**
 * This flag overrides the 'location' property above and gets the user location automatically if permission has already been granted. It can be used for convinience. The default value is - 'NO'.
 * Please Note: You are responsible for requesting the user's permission for using location data in your app. and popping up the location permissions alert dialog. Only if the app. 
 * has been granted permissions previously by the app. code itself, and this flag is set to 'YES', will the Inneractive SDK use the iOS significant location changes mechanism to get the user location  automatically.
 */
@property (nonatomic, assign) BOOL shouldAutomaticallyGetLocationData;

#pragma mark - Native Ad (Common) parameters

/**
 * Native Ad Assets configuration;
 * Should be defined for better compatibility between publisher and advertiser;
 */
@property (nonatomic, readonly) IaNativeAdAssetDescription *nativeAdAssetsDescription;

#pragma mark - In-Feed Native Ad parameters

/**
 * Native Ad start position inside a feed. For use with an adapter tableView.
 */
@property (nonatomic) NSInteger nativeAdStartPosition;

/**
 Native Ad repeating interval inside a feed. For use with an adapter tableView.
 */
@property (nonatomic) NSInteger nativeAdRepeatingInterval;

/**
 * Remaining time counter position in video when is not full screen.
 * The default value is: IaNativeVideoCounterPositionTopLeft.
 * The position will be updated even if the video and the counter are visible on the screen already
 */
@property (nonatomic, assign) IaNativeVideoCounterPosition nativeVideoCounterPosition;

@end

/**
 * Enum, that is used to define whether asset can be optional, is required by publisher or will not be displayed at all */

typedef NS_ENUM(NSInteger, IaNativeAdAssetPriority) {
    IaNativeAdAssetPriorityNone,
    IaNativeAdAssetPriorityOptional,
    IaNativeAdAssetPriorityRequired
};

/**
 * Each supported asset can be defined, whether will be used at all and it's importance. */

@interface IaNativeAdAssetDescription : NSObject

@property (nonatomic) CGSize mainAssetMinSize;

@property (nonatomic) IaNativeAdAssetPriority titleAssetPriority;

@property (nonatomic) IaNativeAdAssetPriority imageIconAssetPriority;
@property (nonatomic) CGSize imageIconAssetMinSize;

@property (nonatomic) IaNativeAdAssetPriority callToActionTextAssetPriority;

@property (nonatomic) IaNativeAdAssetPriority descriptionTextAssetPriority;

@end
