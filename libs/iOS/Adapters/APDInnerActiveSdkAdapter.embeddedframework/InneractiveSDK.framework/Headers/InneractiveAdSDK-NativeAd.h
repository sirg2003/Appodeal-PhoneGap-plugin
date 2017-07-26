//
//  InneractiveAdSDK-NativeAd.h
//  InneractiveAdSDK
//
//  Created by Inneractive.
//  Copyright (c) 2015 Inneractive. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <InneractiveSDK/InneractiveAdSDK-Ad.h>
#import <InneractiveSDK/InneractiveAdSDK-AdConfig.h>

#pragma mark - Native Ad Interface

@interface IaNativeAd : IaAd

/**
 * Used to initialize the IaNativeAd object.
 *
 * @param NSString appId  The App Id as a string, registered on Inneractive's console (e.g., @"MyCompany_MyApp").
 * @param IaAdType adType The type of ad (e.g., IaAdType_NativeAd / IaAdType_InFeedNativeAd etc.)
 * @param id <InneractiveAdDelegate> adDelegate The Delegate parameter is a class implementing the <InneractiveAdDelegate> protocol.
 */
- (instancetype)initWithAppId:(NSString*)appId adType:(IaAdType)adType delegate:(id <InneractiveAdDelegate>)adDelegate;

/**
 * Plays a pre-loaded video ad.
 */
- (void)playVideo;

/**
 * Pauses a pre-loaded video ad.
 */
- (void)pauseVideo;

/**
 * Can be used to mute / unmute the video ad.
 * @param BOOL enabled Should the video be muted or not.
 */
- (void)muteVideo:(BOOL)enabled;

/**
 * Reloads the native video ad.
 */
- (void)reloadAd;

/**
 The alloc, init and new methods should not be used to initialize and use the IaNativeAd class. initWithAppId:adType:delegate: should be used instead.
*/
- (instancetype) init __attribute__((unavailable("init not available, call initWithAppId:adType:delegate: instead")));
+ (instancetype) new __attribute__((unavailable("new not available, call initWithAppId:adType:delegate: instead")));

@end

#pragma mark - Native Ad Rendering Delegate Protocol Methods

/**
 * IaNativeAdRenderingDelegate protocol 
 *
 * This protocol should be implemented in order to connect between returned ad views to 
 * app. views.
 */
@protocol IaNativeAdRenderingDelegate <NSObject>

@required
/*!
 * @abstract Lays Out Native Ad Assets on respectable views
 * @discussion Can be used to match native ad views to publisher app. views
 * @param adObject the returned native ad
 * @since InneractiveAdSDK-5.05
 */
- (void)layoutAdAssets:(IaNativeAd *)adObject;

@end

/**
 * IaNativeAdCellRenderingDelegate protocol
 *
 * This protocol should be implemented in order to set the size (i.e., CGSize) of
 * a tableview cell which includes a native ad.
 */
@protocol IaNativeAdCellRenderingDelegate <IaNativeAdRenderingDelegate>

@required

/*!
 * @abstract Size of the native ad cell
 * @discussion Return the wanted size for the native ad cell here.
 * @since InneractiveAdSDK-5.05
 */
+ (CGSize)sizeForNativeAdCell;

@end


#pragma mark - Native Ad Table Adapter

@interface IaNativeAdTableAdapter : NSObject

/*
 * A UITableView instance, that is passed to and managed by IaNativeTableAdapter.
 */
@property (nonatomic, strong, readonly) UITableView *table;

/*
 * A class that will be used for reusing ad cells.
 */
@property (nonatomic, strong, readonly) Class adCellRegisteringClass;

- (id)initWithNativeAd:(IaNativeAd *)nativeAd table:(UITableView *)table adCellRegisteringClass:(Class)adCellRegisteringClass;

// The alloc, init and new methods should not be used to initialize and use the IaNativeAdTableAdapter class.
// initWithNativeAd:table:adCellRegisteringClass: should be used instead.
- (instancetype)init __attribute__((unavailable("init not available, call initWithNativeAd:table:adCellRegisteringClass: instead")));
+ (instancetype)new __attribute__((unavailable("new not available, call initWithNativeAd:table:adCellRegisteringClass: instead")));

@end

#pragma mark - UITableView IaNativeAdTableAdapter Category

@interface UITableView (IaNativeAdTableAdapter)

/**
 * Sets the table view's data source.
 *
 * If your application needs to change a table view's data source after it has instantiated an ad
 * placer using that table view, use this method rather than -[UITableView setDataSource:].
 *
 * @param dataSource The new table view data source.
 */
- (void)ia_setDataSource:(id<UITableViewDataSource>)dataSource;

/**
 * Returns the original data source of the table view.
 *
 * When you instantiate a table adapater using a table view, the table adapter replaces the table view's
 * original data source object. If your application needs to access the original data source, use
 * this method instead of -[UITableView dataSource].
 *
 * @return The original table view data source.
 */
- (id<UITableViewDataSource>)ia_dataSource;

/**
 * Sets the table view's delegate.
 *
 * If your application needs to change a table view's delegate after it has instantiated an ad
 * placer using that table view, use this method rather than -[UITableView setDelegate:].
 *
 * @param delegate The new table view delegate.
 */
- (void)ia_setDelegate:(id<UITableViewDelegate>)delegate;

/**
 * Returns the original delegate of the table view.
 *
 * When you instantiate a table adapter using a table view, the table adapter replaces the table view's
 * original delegate object. If your application needs to access the original delegate, use this
 * method instead of -[UITableView delegate].
 *
 * @return The original table view delegate.
 */
- (id<UITableViewDelegate>)ia_delegate;

/* 
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_reloadData;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_reloadSectionIndexTitles NS_AVAILABLE_IOS(3_0);   // reloads the index bar.

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (NSInteger)ia_numberOfSections;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (NSInteger)ia_numberOfRowsInSection:(NSInteger)section;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (CGRect)ia_rectForSection:(NSInteger)section;                                    // includes header, footer and all rows

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (CGRect)ia_rectForHeaderInSection:(NSInteger)section;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (CGRect)ia_rectForFooterInSection:(NSInteger)section;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (CGRect)ia_rectForRowAtIndexPath:(NSIndexPath *)indexPath;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (NSIndexPath *)ia_indexPathForRowAtPoint:(CGPoint)point;                         // returns nil if point is outside of any row in the table

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (NSIndexPath *)ia_indexPathForCell:(UITableViewCell *)cell;                      // returns nil if cell is not visible

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (NSArray *)ia_indexPathsForRowsInRect:(CGRect)rect;                              // returns nil if rect not valid

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (UITableViewCell *)ia_cellForRowAtIndexPath:(NSIndexPath *)indexPath;            // returns nil if cell is not visible or index path is out of range

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (NSArray *)ia_visibleCells;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (NSArray *)ia_indexPathsForVisibleRows;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (UITableViewHeaderFooterView *)ia_headerViewForSection:(NSInteger)section NS_AVAILABLE_IOS(6_0);

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (UITableViewHeaderFooterView *)ia_footerViewForSection:(NSInteger)section NS_AVAILABLE_IOS(6_0);

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_scrollToRowAtIndexPath:(NSIndexPath *)indexPath atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_scrollToNearestSelectedRowAtScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_beginUpdates;   // allow multiple insert/delete of rows and sections to be animated simultaneously. Nestable

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_endUpdates;     // only call insert/delete/reload calls or change the editing state inside an update block.  otherwise things like row count, etc. may be invalid.

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_insertSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_deleteSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_reloadSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation NS_AVAILABLE_IOS(3_0);

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_moveSection:(NSInteger)section toSection:(NSInteger)newSection NS_AVAILABLE_IOS(5_0);

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_insertRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_deleteRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_reloadRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation NS_AVAILABLE_IOS(3_0);

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_moveRowAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath NS_AVAILABLE_IOS(5_0);

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (NSIndexPath *)ia_indexPathForSelectedRow;                                                // returns nil or index path representing section and row of selection.

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (NSArray *)ia_indexPathsForSelectedRows NS_AVAILABLE_IOS(5_0); // returns nil or a set of index paths representing the sections and rows of the selection.

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_selectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UITableViewScrollPosition)scrollPosition;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (void)ia_deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;

/**
 * Returns a reusable table-view cell object for the specified reuse identifier.
 *
 * @param identifier A string identifying the cell object to be reused. This parameter must not be
 * `nil`.
 * @param indexPath  The index path specifying the location of the cell. The data source receives
 * this information when asked for the cell and should just pass it along.
 *
 * @return A `UITableViewCell` object with the associated reuse identifier.
 */
- (id)ia_dequeueReusableCellWithIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath *)indexPath;

/*
 *  IA replacement for tableview method. Use this method when setting inneractive as your tableview's delegate.
 */
- (id)ia_dequeueReusableHeaderFooterViewWithIdentifier:(NSString *)identifier NS_AVAILABLE_IOS(6_0);  // like dequeueReusableCellWithIdentifier:, but for headers/footers

@end
