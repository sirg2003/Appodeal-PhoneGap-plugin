//
//  SOMAAdSettings.h
//  iSoma
//
//  Created by Aman Shaikh on 31/05/14.
//  Copyright (c) 2014 Smaato Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SOMATypes.h"
#import "SOMAUserProfile.h"
#import <CoreGraphics/CoreGraphics.h>

@interface SOMAAdSettings : NSObject<NSCopying>
@property(nonatomic, assign) SOMAAdType type;
@property(nonatomic, assign) SOMAVideoAdType videoType;
@property(nonatomic, assign) SOMAAdSize size;
@property(nonatomic, assign) SOMAAdDimension dimension;
@property(nonatomic, assign, getter = isDimensionStrict) BOOL dimensionStrict;
@property(nonatomic, assign, getter = isFormatStrict) BOOL formatStrict;

@property(nonatomic, copy) SOMAUserProfile* userProfile;
@property(nonatomic, assign, getter = isCoppaEnabled) BOOL coppaEnabled;

@property(nonatomic, assign) int bannerWidth;
@property(nonatomic, assign) int bannerHeight;

@property(nonatomic, strong) NSString* keywords;
@property(nonatomic, strong) NSString* searchQuery;

@property(nonatomic, strong) NSString* nsupport;// for native ad, IOS-513

@property(nonatomic, assign) NSInteger publisherId;
@property(nonatomic, assign) NSInteger adSpaceId;
@property(nonatomic, assign) CGFloat longitude;
@property(nonatomic, assign) CGFloat latitude;

/**
 Setting it YES will request HTTPS creatives only, may result in low fill
 This settings is for all kinds of ad except Video, like banner, interstitial, native etc
 
 Default value is NO
 */
@property(nonatomic, assign) BOOL httpsOnly;

/**
 This settings is for video ads only. 
 Settting it YES, requires the publisher to disable ATS to show videos with HTTP url.
 
 Default value is NO
 */
@property(nonatomic, assign) BOOL allowHTTPVideo;




@property(nonatomic, assign, getter = isFrequencyCappingEnabled) BOOL frequencyCappingEnabled;
@property(nonatomic, assign, getter = isTestModeEnabled) BOOL testModeEnabled;

@property(nonatomic, assign, getter = isAutoReloadEnabled) BOOL autoReloadEnabled;
@property(nonatomic, assign) int autoReloadInterval;



/**
 * Only used for Interstitial/VAST video.
 *
 * Interstitial/VAST video fullscreen will show skip button after the number of seconds as assigned here.
 *
 * Default value is 5 i.e. it will show skip button after 5 seconds.
 *
 * Minimum value is 1 second. If the value is less than 1, SDK will assign 1 second automatically.
 */

@property(nonatomic, assign) int videoSkipInterval;


/**
 * Only used for RewardedVideo.
 *
 * Rewarded video fullscreen interstitial will automatically close after the number of seconds as assigned here.
 *
 * Default value is 3 i.e. it will auto close after 3 seconds.
 *
 * If the value is 0 or less than 1, it will close automatically.
 */
@property(nonatomic, assign) unsigned int videoAutocloseInterval;

/**
 * Only used for RewardedVideo. If set YES, rewarded video will never close automatically, the
 * `rewardedVideoAutocloseInterval` parameter is ignored and has no effect.
 *
 * Default is NO
 */
@property(nonatomic, assign) BOOL videoAutocloseDisabled;

@end

