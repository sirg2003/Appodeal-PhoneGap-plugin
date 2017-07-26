//
//  InneractiveAdSDK-AdDelegate.h
//  InneractiveAdSDK
//
//  Created by Inneractive.
//  Copyright (c) 2015 Inneractive. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IaAd;

#pragma mark - InneractiveAdDelegate Ad Events Protocol

/**
 * InneractiveAdDelegate Protocol for Inneractive Ad Events
 *
 * The delegate of an `IaAd` (i.e., an IaAdView / IaNativeAd) object must adopt the `InneractiveAdDelegate` protocol.
 * It must implement `viewControllerForPresentingModalView` to provide a root view controller from which
 * the ad view should present modal content.
 *
 * Optional methods of this protocol allow the delegate to be notified of ad success or failure, as well as other Ad lifecycle events. */

@protocol InneractiveAdDelegate <NSObject>

@required

#pragma mark - Required Ad Delegate Events

/**
 * REQUIRED: The View Controller from which the ad's landing page / The Interstitial ad can be shown modally. */

- (UIViewController *)viewControllerForPresentingModalView;

@optional

#pragma mark -  Main Ad Delegate Events

/**
 * Called when a paying ad was loaded and is ready to be displayed. */

- (void)InneractiveAdLoaded:(IaAd *)ad;

/**
 * Called when a default "House Ad" was loaded. Can be used to show an ad in the ad placement even if it is a non-paying one. */

- (void)InneractiveDefaultAdLoaded:(IaAd *)ad;

/** Called when there was an error loading the ad. 
 */
- (void)InneractiveAdFailedWithError:(NSError *)error withAdView:(IaAd *)ad;

/**
 * Called when the ad opens a modal view. The app. can perform logic such as pausing a running game here. */

- (void)InneractiveAdAppShouldSuspend:(IaAd *)ad;

/**
 * Called when the ad closes it's final modal view. The app. can perform logic such as re-running a paused game here. */

- (void)InneractiveAdAppShouldResume:(IaAd *)ad;

#pragma mark - Ad User Interaction Delegate Events

- (void)InneractiveAdClicked:(IaAd *)ad;

/**
 * Called before the ad will open an external application (e.g., Safari, the Telephone/Messages/Email apps. etc.) */

- (void)InneractiveAdWillOpenExternalApp:(IaAd *)ad;

#pragma mark - Interstitial Ad Delegate Events

/**
 * Called before an interstitial ad will be presented on the screen. */

- (void)InneractiveInterstitialAdWillShow:(IaAdView *)adView;

/**
 * Called after the interstitial ad is presented on the screen. */

- (void)InneractiveInterstitialAdDidShow:(IaAdView *)adView;

/**
 * Called when an Interstitial close /skip button was pressed. */

- (void)InneractiveInterstitialAdDismissed:(IaAdView *)adView;

#pragma mark -  Rich Media (MRAID 2.0) Ad Delegate Events

/**
 * Called when mraid.resize(...) is called inside the MRAID ad. */

- (void)InneractiveAdWillResize:(IaAdView *)adView toFrame:(NSValue *)frameAsValue;;
- (void)InneractiveAdDidResize:(IaAdView *)adView toFrame:(NSValue *)frameAsValue;

/**
 * Called when mraid.expand(...) is called inside the MRAID ad. */

- (void)InneractiveAdWillExpand:(IaAdView *)adView toFrame:(NSValue *)frameAsValue;
- (void)InneractiveAdDidExpand:(IaAdView *)adView toFrame:(NSValue *)frameAsValue;

#pragma mark - Video Ad (Interstitial / Native) Delegate Events

/**
 * Called when video did finish playing to end successfully. */

- (void)InneractiveVideoCompleted:(IaAd *)ad;

@end
