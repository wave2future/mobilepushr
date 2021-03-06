//
//  PushablePhotos
//
//  Created by Chris Lee on 2007-09-26.
//  Copyright (c) 2007. All rights reserved.
//

#import <UIKit/UIView.h>
#import <UIKit/UITable.h>
#import <UIKit/UIImageAndTextTableCell.h>

@class NSArray, NSString, MobilePushr, PushablePhotosTable, RemovablePhotoCell;

@interface PushablePhotos : UIView
{
	PushablePhotosTable *_table;
	NSArray *_photoList;
	MobilePushr *_pushr;
	UIWindow *_mainWindow;
}

- (id)initWithFrame: (struct CGRect)frame application: (MobilePushr *)pushr inWindow: (UIWindow *)window;
- (void)emptyRoll;
- (NSArray *)photosToPush;
- (void)promptUserToEditPhotos: (NSArray *)photoList;

@end

@interface PushablePhotosTable : UITable
{
	NSMutableArray *_photos;
	MobilePushr *_pushr;
	UIWindow *_mainWindow;
}

- (void)setPhotos: (NSArray *)photos;
- (void)setApp: (MobilePushr *)pushr inWindow: (UIWindow *)window;
- (void)removePhoto: (RemovablePhotoCell *)photoCell;
- (NSArray *)pushablePhotos;

@end

@interface RemovablePhotoCell : UIImageAndTextTableCell 
{
    PushablePhotosTable *_table;
    NSString *_path;
}

- (void)setTable: (PushablePhotosTable *)table;
- (void)setPath: (NSString *)path;
- (NSString *)path;

@end
