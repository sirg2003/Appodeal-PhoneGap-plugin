//
//  SOMAVideoAdController.h
//  iSoma
//
//  Created by Aman Shaikh on 24/01/2017.
//  Copyright © 2017 Smaato Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SOMAAdSettings.h"
#import "SOMAAdViewDelegate.h"

@class SOMAVideoAdController;
@protocol SOMAVideoAdControllerDelegate <NSObject>
- (UIViewController*)somaRootViewController;
- (void)somaVideoAdWillLoadAd:(SOMAVideoAdController *)adview;
- (void)somaVideoAdDidLoadAd:(SOMAVideoAdController *)adview;
- (void)somaVideoAd:(SOMAVideoAdController*) adview didFailToReceiveAdWithError:(NSError *)error;
- (void)somaVideoAdWillEnterFullscreen:(SOMAVideoAdController *)adview;
- (void)somaVideoAdApplicationWillGoBackground:(SOMAVideoAdController *)adview;
- (void)somaVideoAdDidExitFullscreen:(SOMAVideoAdController *)adview;
- (void)somaVideoAd:(SOMAVideoAdController *)adview didReceiveVideoAdEvent:(SOMAVideoAdTrackingEvent)event;
- (void)somaVideoAd:(SOMAVideoAdController *)adview didReceiveVideoAdEvent:(SOMAVideoAdTrackingEvent)event withURLCount:(NSUInteger)count;
@end

@interface SOMAVideoAdController : UIViewController
@property NSURL* vastURL;
@property SOMAAdSettings* adSettings;
@property(readonly, getter=isReady) BOOL ready;
@property(nonatomic, weak) id<SOMAVideoAdControllerDelegate> delegate;
- (void)loadRewardedVideo;
- (void)load;
- (void)show;
@end
